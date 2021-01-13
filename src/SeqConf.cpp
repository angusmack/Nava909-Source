//-------------------------------------------------
//                  NAVA v1.x
//                 SEQ configuration
//-------------------------------------------------
#include "define.h"
#include "Seq.h"
#include "SeqConf.h"
#include "MIDI.h"
#include "MidiLocal.h"
#include "timer.h"
#include "lcd.h"
#include "EEpromLocal.h"

/////////////////////Function//////////////////////
void SeqConfiguration()
{
  if(seq.syncChanged){
    //Sync configuration
    switch (seq.sync){
    case MASTER:
      DisconnectMidiHandleRealTime();
      TimerStart();//cf timer
      break;
    case SLAVE:
      TimerStop();
      MIDI.setHandleClock(HandleClock);
      MIDI.setHandleStart(HandleStart);
      MIDI.setHandleStop(HandleStop);
      MIDI.setHandleContinue(HandleContinue);
      break;
    }
    seq.syncChanged = FALSE;
  }
  if (seq.setupNeedSaved && enterBtn.justPressed){
    SaveSeqSetup();
    seq.setupNeedSaved = FALSE;
    LcdPrintSaved();
  }
  if (!seq.configMode) seq.setupNeedSaved = FALSE;
    
}




