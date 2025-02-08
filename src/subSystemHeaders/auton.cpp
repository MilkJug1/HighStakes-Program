#include "main.h"

// TODO: Start working on ideas for the other Auton states
//  Autons Needing worked on
//  - Blue Neg x
//  - Red Pos x
//  - Red Neg x 
//
//  All Auton done(I think)
//
// NOTE: Got bot working driving, now time for auton, so happy right now
//
//
ASSET(example_txt);
ASSET(blueNeg_txt);
ASSET(bluePos_txt);
ASSET(redNeg_txt);
ASSET(redPos_txt);
void RedPos() {
    chassis.setPose(0,0, 0);

    Intake.move(127);
    
    chassis.follow(redPos_txt, 2, 5);

}

void RedNeg() {

    chassis.setPose(0,0, 0);

    Intake.move(127);

    chassis.follow(redNeg_txt, 2, 5);
}

void BlueNeg() {

  chassis.setPose(0, 0, 0);

  Intake.move(127);

  chassis.follow(blueNeg_txt, 5, 2);
}

void BluePos() {

    chassis.setPose(0,0, 0);

    Intake.move(127);

    chassis.follow(redNeg_txt, 2, 5);
}
