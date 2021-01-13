#ifndef _midilocal_h_
#define _midilocal_h_

void InitMidiRealTime();
void InitMidiNoteOff();
void MidiSendNoteOff (byte channel, byte value);
void MidiSendNoteOn (byte channel, byte value, byte velocity);
void HandleClock();
void HandleStart();
void HandleStop();
void HandleContinue();
void DisconnectMidiHandleRealTime();
void HandleNoteOn(byte channel, byte pitch, byte velocity);
void HandleNoteOff(byte channel, byte pitch, byte velocity);
void MidiTrigOn(byte inst, byte velocity);
void MidiTrigOff(byte inst);
void SendAllNoteOff();

#endif