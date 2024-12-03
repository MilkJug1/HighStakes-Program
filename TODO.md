## All TODOS for Bots
This is a TODO list for everything that needs to be done for the bot(Programming wise, per bot), everything will be listed here to get done.


To add one, follow the template of adding check boxes, please (Since the school banned git and github and what not atm), please date, if possible
to date the completed items.

Each section is for different things for the program and each bot. This program will be made to accomodate each bot, but also will have stuff listed for us to do for that specific bot. Should be a good thing.

I think we can abuse the `#define` & `#include`'s since that should allow us to incorporate sections of code that may or may not be needed, especially stuff for debugging. 

Think about QMK's way of handling RGB and other things in it's `config.h`, might be a good idea to pull from that.

~~Also hoping towards the end of the year, once we get some free time for us to work on the bots, maybe switch to using Rust? Would be fun thing to do. [V5 Rust]()~~


### General Program

Work on getting the base of the program down, I'm assuming all of the other bots are going to be very similar, minus changing a few parameters to get it to work. This will help a lot with Auton and also everything to do with control, only issue is the size of the bots. That shouldn't matter with PROS and LemLib. 
- [ ] AN ACTUAL DAMN VERSION CONTROL SYSTEM THAT IS SANE, Really annoying to run back and forth with a USB.
- [ ] Work on porting all Auton code to CPP, finish getting the base done
    - [ ] Bot Setup
        - [x] Motor, Controller, and Driving ability (Somewhat at the moment, mostly implemented)
    - [ ] Competition Ready
    - [ ] Rework File naming conventions
<br>
- [ ] Tweak Auton
- [ ] Simpilfy code structure, plus create clean code.
- [ ] Control Switcher,
    - [ ] Tank Control
    - [ ] Regular Control
    <br>
    ^ Luckily we have access to a weird thing that allows the control to switch depending on flags, really nice for a couple of the people here.
- [ ] Auton Switcher
    - [ ] Auton for Pos Red
    - [ ] Auton for Neg Red
    - [ ] Auton for Pos Blue
    - [ ] Auton for Neg Blue
    - [ ] Finish mockup of UI and implement it.
    <br>
    Again, basing this off of other people's code, there is a way to do something that allows for auton switching, I did start making a mockup of this such thing, but will finish it later. Both in terms of ideas, and the look of the UI for this Auton Switcher
    - [ ] Finish designing the menu for auton switcher
- Maybe decide on having the control be also on the main screen, maybe alongside the auton switcher, just in a sub menu?
- [ALL BOTS] Maybe add some form of an encoder so we can track the position of the motors, so we can use Odometry?



### Levi's & Katherine's Bot 


### Colten, Ryddik, and Michael's Bot 

### Aidan and Jacobi's Bot


## Examples and Documentation

[LemLib](https://github.com/LemLib/LemLib/blob/stable/src/main.cpp)

[LemLib Docs](https://lemlib.readthedocs.io/en/stable/index.html)

[Purdue SigBots](https://wiki.purduesigbots.com/) We saw these guys at the Competition at a booth, close to the skills section funnily enough.

[Pros Docs](https://pros.cs.purdue.edu/v5/index.html) (Thank god for Purdue for saving my life with this.)

[1516X's Codebase For High Stakes](https://github.com/calhighrobotics/high_stakes_x)
<br>
^ Yes, this is an actual team that has uploaded their code for the High Stakes game, going to be basing a lot of our code off of this, not entirely but a lot.
Mainly just to understand it.


[Path Generator/Visualizer for High Stakes](https://path.jerryio.com/)
