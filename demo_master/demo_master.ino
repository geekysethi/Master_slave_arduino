#include <SPI.h>
void setup(void) {
  Serial.begin(15200);
  digitalWrite(SS,HIGH);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
}

void loop(void) {
byte Mysent,Myreceived;
digitalWrite(SS,LOW);
for(int jj=0;jj<255;jj++)
{
  Mysent = jj;
  Myreceived=SPI.transfer(Mysent);
  Serial.print("sent: ");
  Serial.print(Mysent);
  Serial.print("\t Received: ");
  Serial.print(Myreceived);
  delay(200);  
}
digitalWrite(SS,HIGH);
delay(1000);

  
}
