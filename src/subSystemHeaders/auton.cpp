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
//ERROR: For some reason this is not working, prob because of no sensor

void RedPos() {
    chassis.setPose(0,0, 0);

    Intake.move(127);
    
    // chassis.follow(redPos_txt, 55, 2000);

    // chassis.moveToPose(40, 60, 55, 2000);

    chassis.moveToPoint(95, 0, 2000);
    chassis.moveToPose(0, 0, 180, 2000);
    Hook.move(100);
    chassis.moveToPoint(25, 10, 1500);

    // chassis.moveToPose(40,40,180,2000);
    // chassis.moveToPoint(-5, -5, 2000, {}, false);
    // Hook.move(127);
    // chassis.moveToPoint(-20, -20, 2000);
    // chassis.moveToPose(0, 30, 20, 2000);

}

void RedNeg() {

    chassis.setPose(0,0, 0);

    Intake.move(127);

    // chassis.follow(redNeg_txt, 2, 5);
    chassis.moveToPoint(20, 20, 2000);
}

void BlueNeg() {

  chassis.setPose(0, 0, 0);

  Intake.move(127);

//   chassis.follow(blueNeg_txt, 5, 2);
    chassis.moveToPose(20, 20, 15, 2000);
}

void BluePos() {

    chassis.setPose(0,0, 0);

    Intake.move(127);

    // chassis.follow(redNeg_txt, 2, 5);
    chassis.moveToPose(20, 20, 70, 2000);
}
