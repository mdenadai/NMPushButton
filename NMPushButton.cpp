#include "Arduino.h"
#include "NMPushButton.h"

//--------------------------------------------------------------------------------------
NMPushButton::NMPushButton(unsigned char pin, unsigned char modo)
{
  Finiciado=false;
  Fmodo=modo;
  Fpin=pin;
}
//--------------------------------------------------------------------------------------
void NMPushButton::init()
{
  if (!Finiciado) {
    Finiciado=true;
    pinMode(Fpin, INPUT_PULLUP);
    delay(10);
  }
}
//--------------------------------------------------------------------------------------
bool NMPushButton::isPressed()
{
  init();
  return (digitalRead(Fpin) == Fmodo);
}
//--------------------------------------------------------------------------------------
bool NMPushButton::isLongPressed()
{
  init();
  for ( int i=0 ; i < 100 ; i++ ) {
    if (digitalRead(Fpin) != Fmodo) return false;
    delay(10);
  }
  return true;
}
//--------------------------------------------------------------------------------------
void NMPushButton::waitRelease()
{
  while (isPressed()) delay(10);
}