//-------------------------------------------------
//                  NAVA v1.x
//                  main program
//-------------------------------------------------

/////////////////////Include/////////////////////
#include <Arduino.h>
#include <SPI.h>
#include <LiquidCrystal.h>
#include <WireN.h>
#include "define.h"
#include "mystrings.h"
#include "EEpromLocal.h"
#include "MIDI.h"
#include "MidiLocal.h"
#include "Dio.h"
#include "Button.h"
#include "I2CIO.h"
#include "Seq.h"
#include "SeqConf.h"
#include "SeqFunc.h"
#include "Enc.h"
#include "key.h"
#include "Led.h"
#include "LCD.h"

//#include <MemoryFree.h>
LiquidCrystal lcd(18, 19, 20, 21, 22, 23);

////////////////////////Setup//////////////////////
void setup()
{

  InitIO();            //cf Dio
  InitButtonCounter(); //cf Button

  lcd.createChar(0, (uint8_t *)font0);
  lcd.createChar(1, font1);
  lcd.createChar(2, font2);
  lcd.createChar(3, font3);
  lcd.createChar(4, font4);
  lcd.createChar(5, font5);
  lcd.begin(16, 2);

  ScanDinBoot();
  //Init EEprom-------------------------------------
  if (btnPlayStopByte == (BTN_PLAY | BTN_STOP))
  {
    LcdPrintEEpromInit();
    bootElapseTime = millis();
    while (1)
    {
      ButtonGet();
      if ((millis() - bootElapseTime) > BOOTLOADER_TIME)
        break;
      if (playBtn.pressed && enterBtn.pressed)
      {
        InitEEprom();
        //InitEEpromTrack();//problem with init pattern 0 to 18: to be solved
        //InitSeqSetup();
        break;
      }
    }
  }
  //TM2 adjustement for velocity
  else if (btnEnterByte == BTN_ENTER)
  {
    LcdPrintTM2Adjust();
    while (1)
    {
      SetDacA(MAX_VEL);
    }
  }

  InitSeq(); // cf Seq
      //Load default track
  LoadTrack(0);
  //Load default pattern
  LoadPattern(0);
  ptrnBuffer = !ptrnBuffer;
  InitPattern();
  SetHHPattern();
  InstToStepWord();
  SetDoutTrig(0);

  MIDI.begin(); //Serial1.begin(MIDI_BAUD);
  MIDI.setHandleNoteOn(HandleNoteOn);
  MIDI.setHandleNoteOff(HandleNoteOff);

#if DEBUG
  // Serial.begin(115200);
  // Serial.print("freeMemory()=");
  // Serial.println(freeMemory());
#endif
  sei();

  //-----------------------------------------------

  lcd.setCursor(0, 0);
  lcd.print("  NAVA v1.017   ");
  lcd.setCursor(0, 1);
  lcd.print("by e-licktronic ");
  delay(1000);
}

////////////////////////Loop///////////////////////
void loop()
{
  InitMidiRealTime();
  MIDI.read();
  //SetMux();//!!!! if SetMUX() loop there is noise on HT out and a less noise on HH noise too !!!!
  ButtonGet();
  EncGet();
  SetLeds();
  SeqConfiguration();
  SeqParameter();
  KeyboardUpdate();
  LcdUpdate();
}