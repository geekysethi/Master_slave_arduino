#include <SPI.h>
volatile boolean process_it;
volatile byte Svalsent,Svalreceived;
int i=0;

void setup(void) {
  pinMode(MISO,OUTPUT);
  //turn on SPI in slave mode
  SPCR |=_BV(SPE);
  //for intrrupts
  process_it = false;
  //turn on inturrpts
  SPI.attachInterrupt();
}
ISR(SPI_STC_vect)
{
  Svalreceived= SPDR;
  process_it = true;
}

void loop(void) {
  if(process_it)
  {

    Svalsent = i;
    SPDR = Svalsent;
    i++;
    if(i>254) i=0;
    process_it = false;
  }


  
}
