#include "main.h"
#include "lemlib/api.hpp"

// AutonType, an enum that has each auton state, we uuse this to check what button has changed Auton too.
enum AutonType {
    BLUE_POS,
    BLUE_NEG,
    RED_POS,
    RED_NEG,
};

// We are going to use the same system that I built for the auton switcher and modify it for the control.

enum ControlType {
    TankStyle,
    ArcadeStyle,
};

extern AutonType auton;
extern ControlType controlStyle;

extern lemlib::Drivetrain drivetrain;
extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;
extern lemlib::Chassis chassis;


extern pros::MotorGroup LeftMotor;
extern pros::MotorGroup right_motor;

//Hook
extern pros::Motor Hook;

// Conveyor
extern pros::Motor Con1;
extern pros::Motor Con2;

extern pros::MotorGroup ConGP;

extern pros::Controller Controller;


// GUI STUFF


