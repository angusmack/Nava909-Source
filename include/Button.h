#ifndef _button_h_
#define _button_h_

void ButtonGet();
void ButtonGet( Button *button, unsigned int pin);
unsigned int StepButtonGet(byte mode);
unsigned int InstValueGet(unsigned int value);
void MuteButtonGet();
byte FirstBitOn();
byte SecondBitOn();
void InitButtonCounter();
void InitMuteBtnCounter();

#endif