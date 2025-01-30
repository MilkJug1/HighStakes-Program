#include "main.h"

// TODO: Start working on ideas for the other Auton states
//  Autons Needing worked on
//  - Blue Neg
//  - Red Pos
//  - Red Neg
//
// TODO: Port the Python code for the auton, then work on the others.
// NOTE: Got bot working driving, now time for auton, so happy right now
//
//
ASSET(example_txt);

void RedPos() { chassis.moveToPose(10, 10, 90, 1000); }

void RedNeg() { chassis.moveToPose(20, 20, 90, 1000); }

void BlueNeg() {

  chassis.setPose(0, 0, 0);

  chassis.moveToPose(35, 35, 45, 1000);
  chassis.follow(example_txt, 2, 2000);
}

void BluePos() { chassis.moveToPose(15, 15, 30, 1000); }
