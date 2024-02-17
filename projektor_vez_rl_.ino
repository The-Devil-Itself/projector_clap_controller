#include <Serial.h>
int a,b=1;
void setup() {
  Serial_begin(115200);
  pinMode(PD2, OUTPUT);
  pinMode(PD3, INPUT);
}

//0x07 0x14 0x00 0x05 0x00 0x34 0x00 0x00 0x11 0x00 0x5E
void projectorsense()
{
  Serial_write(0x07);
  Serial_write(0x14);
  Serial_write(0x00);
  Serial_write(0x05);
  Serial_write(0x00);
  Serial_write(0x34);
  Serial_write(0x00);
  Serial_write(0x00);
  Serial_write(0x11);
  Serial_write(0x00);
  Serial_write(0x5E);
}

//0x06 0x14 0x00 0x04 0x00 0x34 0x11 0x00 0x00 0x5D
void turn_on()
{
  Serial_write(0x06);
  Serial_write(0x14);
  Serial_write(0x00);
  Serial_write(0x04);
  Serial_write(0x00);
  Serial_write(0x34);
  Serial_write(0x11);
  Serial_write(0x00);
  Serial_write(0x00);
  Serial_write(0x5D);
}

//0x06 0x14 0x00 0x04 0x00 0x34 0x11 0x01 0x00 0x5E
void turn_off()
{
  Serial_write(0x06);
  Serial_write(0x14);
  Serial_write(0x00);
  Serial_write(0x04);
  Serial_write(0x00);
  Serial_write(0x34);
  Serial_write(0x11);
  Serial_write(0x01);
  Serial_write(0x00);
  Serial_write(0x5E);
}

void loop() {
  a=analogRead(PD3);
  if (a>=300){digitalWrite(PD2, HIGH);
  delay(200);
  digitalWrite(PD2, LOW);
  delay(200); 
  digitalWrite(PD2, HIGH);
  b=b+1;
  }
  if (b==2){digitalWrite(PD2,HIGH);turn_off();}
  if (b==3){digitalWrite(PD2,LOW);b=1;turn_on();}
  
}
