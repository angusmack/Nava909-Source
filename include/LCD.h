#ifndef _mylcd_h_
#define _mylcd_h_

void LcdUpdate();
void LcdClearLine();
void LcdPrintScale();
void LcdPrintTempo();
void LcdPrintSaved();
void LcdPrintTotalAcc();
void LcdPrintEEpromInit();
void LcdPrintTM2Adjust();
void LcdPrintLine(byte);

#endif