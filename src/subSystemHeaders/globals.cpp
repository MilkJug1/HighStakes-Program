#include "main.h"
#include <cstddef>

// Motors that are reversed have a negative port number
//

AutonType auton;
ControlType controlStyle;

// NOTE: controller stuff here
// https://lemlib.readthedocs.io/en/stable/tutorials/3_driver_control.html#double-stick-arcade

pros::Controller Controller(pros::E_CONTROLLER_MASTER);

// pros::Motor LeftMotor(10, pros::MotorGearset::green);
// pros::Motor right_motor(19);

pros::MotorGroup
    LeftMotor({10}); // Even tho we have only 1 motor on each side, a 2
                     // drivetrain, i have to declare this as a motor group :/
pros::MotorGroup right_motor({19});

// TODO: Change Track width measurements
lemlib::Drivetrain drivetrain(&LeftMotor, &right_motor, 10,
                              lemlib::Omniwheel::NEW_4, 360, 2);

// NOTE: Talk to Matt and everyone else about Tracking wheels, its how to use
// the shaft encoder.

// TODO: FIGURE OUT WHAT A PID CONTROLLER IS?

// lateral PID controller
lemlib::ControllerSettings
    lateral_controller(10,  // proportional gain (kP)
                       0,   // integral gain (kI)
                       3,   // derivative gain (kD)
                       3,   // anti windup
                       1,   // small error range, in inches
                       100, // small error range timeout, in milliseconds
                       3,   // large error range, in inches
                       500, // large error range timeout, in milliseconds
                       20   // maximum acceleration (slew)
    );

// angular PID controller
lemlib::ControllerSettings
    angular_controller(2,   // proportional gain (kP)
                       0,   // integral gain (kI)
                       10,  // derivative gain (kD)
                       3,   // anti windup
                       1,   // small error range, in degrees
                       100, // small error range timeout, in milliseconds
                       3,   // large error range, in degrees
                       500, // large error range timeout, in milliseconds
                       0    // maximum acceleration (slew)
    );

// input curve for throttle input during driver control
lemlib::ExpoDriveCurve
    throttle_curve(3,    // joystick deadband out of 127
                   10,   // minimum output where drivetrain will move out of 127
                   1.019 // expo curve gain
    );

// input curve for steer input during driver control
lemlib::ExpoDriveCurve
    steer_curve(3,    // joystick deadband out of 127
                10,   // minimum output where drivetrain will move out of 127
                1.019 // expo curve gain
    );

// We don't have any sensors other than some encoders on a bot, we can't use
// them.
lemlib::OdomSensors nullsensors(nullptr, nullptr, nullptr, nullptr, nullptr);

// create the chassis
lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller,
                        nullsensors, &throttle_curve, &steer_curve);

// AutonType auton = AutonType::BLUE_NEG;

// pros::Motor LeftMotor(19, pros::E_MOTOR_GEARSET_18, true,
// pros::E_MOTOR_ENCODER_COUNTS);
//
// pros::Motor right_motor(18, pros::E_MOTOR_GEARSET_18, false,
// pros::E_MOTOR_ENCODER_COUNTS);
//
//
// pros::Motor Hook(16, pros::E_MOTOR_GEARSET_36, pros::E_MOTOR_ENCODER_COUNTS);
//
//
// pros::Motor Con1(10, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_COUNTS);
// pros::Motor Con2(1, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_COUNTS);
// // pros::Motor Con1(10, pros::v5::MotorGears::green,
// pros::v5::MotorUnits::counts);
// // pros::Motor Con2(1, pros::v5::MotorGears::green,
// pros::v5::MotorUnits::counts);
//
// std::vector<pros::Motor> motors{Con1, Con2};
//
// pros::MotorGroup ConGP({10, 1});
//
// pros::Controller Controller(pros::E_CONTROLLER_MASTER);

// MISC

// Hook Pos
