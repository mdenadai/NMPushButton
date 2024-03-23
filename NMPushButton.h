#ifndef _NMPushButton_H_
#define _NMPushButton_H_

#include "Arduino.h"

//--------------------------------------------------------------------------------------
class NMPushButton
{
private:
  unsigned char Fpin;
  bool Finiciado;
  void init();
  unsigned char Fmodo;
public:
  // modo em que considera o botao acionado
  NMPushButton(unsigned char pin, unsigned char modo=LOW);
  bool isPressed();
  bool isLongPressed();
  void waitRelease();
};


#endif
