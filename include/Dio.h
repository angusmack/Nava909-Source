#ifndef _dio_h
#define _dio_h

void InitIO();
void ScanDin();
void SetDoutLed(unsigned int stepLed, unsigned int configLed, byte menuLed);
void SetDoutTrig(unsigned int value);
void ResetDoutTrig();
void SetDacA(byte velocity);
void ScanDinBoot();

#endif