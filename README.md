# Nava909-Source

This is the Nava 909 firmware code (version 1.017 from here https://github.com/e-licktronic/Nava-v1.0-code) ported for development using PlatformIO and VS Code rather than Arduino IDE.

No other changes have been made to the code other than to get it to build and compile. I have only got it to build - it is not tested on my Nava! YMMV

If you read the forums http://www.e-licktronic.com/forum/viewtopic.php?f=25&t=864, this code has lots of issues, which have mostly been solved by the creator (e-licktronic) and another person (zabox) but it's closed source so no chance to assist and share.

The idea here is to try and build on the public version, improve it and then share it with the community.

Any assistance greatly appreciated! 

It was a bit of a pain to get it to compile correctly and I'm still not sure it will work, so if someone can take a look and as well that would be awesome.

Thanks!!!!

The to do list comes from the release notes from the forum. I guess this would be a good place to start to get things moving.

# To do List
- ~~Import v1.017 soure code~~
- ~~Migrate to Platform IO and VS Code as dev env~~

- Develop v1.018:
    - Fix Total Accent issue on crash and ride instruments

- Develop v1.019:
    - Fix Middle Tom low volume
    - Respond to Midi note ON velocity 0 message as a Midi note OFF message

- Develop v1.020:
    - Fix CH and OH bug in MIDI play
    - Add a config page that allow you to set the sequencer pattern change SYNC or FREE: 
    Push Tempo button twice while holding SHIFT button to access to the second config page. 
    Use the encoder to select "pCH" (pattern change) SYN => SYNC or FRE => FREE. push the enter button to store new sequencer setup

- Develop v1.021:
    - Fix Tap Bug fixed
    - Allow velocity HH save
    - Fix OH Velocity and Total ACC conflict
    - Improve BD, SD and HC velocity response
    - Fix RX Midi channel issue 
    - Improve Buttons functions 
    - Test sync in slave mode with a external source e.g. TR505 or Ableton and Midi interface.
    Sync with hardware is perfect but Nava loose some clock signal when sync with a software thru a Midi interface.
    Replace R365 value by 1K and R314 value by 4K7 to increase Midi signal should solve this issue

- Develop v1.022:
    - Fix OH select Bug

- Develop v1.023:
    - Fix HH ticks background noise
    - Improve velocity on all instruments
    - Clear pattern should  set minimum velocity that increase velocity response
    - Fix CH Tap Mode bug
    - Improve Slave sync when pattern save/change#
        (Please Keep up to date on improving sync cause we do not have this issue with our Midi interface)
    - Hardware
        - Replace C89 and C163 by 10nF (Build manual and Mouser BOM updated) ;)
***
Cut off for not having the new Mux Board mod
***
- Develop v1.024:
    - Improve accent response (WORKS ONLY WITH THE MUX/SH BOARD MODS)
    - Set Trig out length to 10ms

- Develop v1.025:
    - Fix MIDI play mode
    - Implement  Pattern play button to alternate access to Step and Play mode (no need to press shift again)
    - Pattern Group should increment in MUTE mode (fixed)
    - Improve Tap mode HH
    - Various bug fixes????

- Develop v1.026 by (zabox):
    - Fix:
        - Mux issue with external trigger
        - Mux settling times
        - External trigger length drop
        - Din clock phase
        - Midi clock out lag
        - Pattern group bugs in step write and pattern play mode
        - Shuffle update in tap mode
        - Crash when deleting more than the last track position
        - Double midi real time messages on midi out in slave mode
        - Various other bugfixes
    - Updates:
        - Instruments mute while holding clear
        - In tap mode: hold clear + instrument to delete steps
        - Seperate CH/OH mute (can be set to combined mute again in global settings page 2)
        - Pattern numbers match the step button numbers
        - Track and external instrument positions start at 1

- Develop v1.027 by zabox :
    - Fix:
        - Pattern change bug in slave mode
        - Hihat cuts in tap mode
        - Short trig-1 pulse when played over midi
