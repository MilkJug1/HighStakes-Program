# Robotics
This is all of the robotics code, ideas, and more for the 1624 team for the '24-'25 Vex High Stakes compeition, this is so that other teams can look at our program and maybe even fork this to base theirs off of.

This will be Updated constantly, with work from 2 different programmers.

Utilizing Purdue Pros and Lemlib, with other libraries might be brought in later on.

Currently, we are switching from using the VexCode V5 Python and C++ to the Purdue Pros and Lemlib, but I am uploading the previous program file for not only us to base our next one off of, but to have others see the design process of our bots.

This was heavily inspired, at least to make a repo, by 1516X's Repository. They gave me the idea that I should do this and I thank them for that. 


## Engineering Notebook/Programming Notebook

I plan to find a way to have this act as a notebook for all the changes with our bot, and also function as a way to write down ideas, design philosophy and much more for our team.

(I do wish that I could get my school to have a Github, will start talking and discussing it with them and see what happens)

Full notebook design will be very similar to how the Rust Docs look, though currently at the moment, not being made since I have to focus on the actual program.


## Info about Bot(s) and Program

This is going to be a multipurpose program for all of the bots that my team builds during this competition year, for all 3-4 bots that may or may not get played, so structure and everything else will be influnced by such things.

File/folder structure will be massively affected by this, currently thinking about having the more specific tweaks for each bot in each folder, and that are defined/included into the main file via a flag. This is only just concept and the final product may or may not be how this works.

What the program *plans* to feature

- Control input Switcher
- Full controller input
    - Tank Control
    - Regular Control(Left Joystick to move up and down, Right Joystick to move left to right)
- Auton for all sides
    - Auton for Pos/Neg Blue/Red sides
    - Auton Switcher
    - UI to switch Auton
    - A much more improved functioning Auton
- Easy iterations
- Clean Structure
- A custom Brain display, complete with branding for my school
- Test Cases
- A sensible plan (:\)
- And more I can't remember at this current moment, will be restructing everything again


## How to Install

Included is a udev rules file for all my Linux people who want to compile this, it has a rule set for any ttyACM* device to give it 666 for permissions, got tired of trying to run the command every time I had to plug it in.

Next, after downloading this, make sure you have pros and do this:
```sh 
pros mu
```
