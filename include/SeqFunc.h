#ifndef _seqfunc_h_
#define _seqfunc_h_

void InitSeq();
void SetHHPattern();
void CopyPatternToBuffer(byte patternNum);
void PasteBufferToPattern(byte patternNum);
void InitPattern();
void InstToStepWord();
void ShiftLeftPattern();
void ShiftRightPattern();

#endif