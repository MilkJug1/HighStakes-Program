#include "main.h"
#include "lemlib/api.hpp"
#include "pros/misc.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  screenInit();
  chassis.calibrate();

  // LeftMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  // right_motor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  // // ConGP.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  // Con1.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  // Con2.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
  screenInit();

  int leftY = Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  int rightY = Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  int leftX = Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
  int rightX = Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

  switch (controlStyle) {
  case ControlType::ArcadeStyle:
    chassis.arcade(leftY, rightX);
    break;
  case ControlType::TankStyle:
    chassis.tank(leftY, rightY);
    break;
  case ControlType::CurvatureControl:
    chassis.curvature(leftY, rightX);
    break;
  }
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {

  switch (auton) {
  case AutonType::RED_NEG:
    printf("Test for Red Neg\n");
    RedNeg();
    break;
  case AutonType::RED_POS:
    printf("Test for Red Pos\n");
    RedPos();
    break;
  case AutonType::BLUE_NEG:
    printf("test for Blue Neg\n");
    BlueNeg();
    break;
  case AutonType::BLUE_POS:
    printf("Test for Blue Pos\n");
    BluePos();
    break;
  }
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
  pros::Controller master(pros::E_CONTROLLER_MASTER);
  // pros::Motor left_mtr(1);
  // pros::Motor right_mtr(2);
  //
  while (true) {

    // TODO: Get the correct configuration of the bots

    // Just defined all of these so that we can switch control styles.
    // TODO: Get working on inputs for the other specific controls, handling
    // hook and what not.
    int leftY = Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rightY = Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    int leftX = Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
    int rightX = Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

    switch (controlStyle) {
    case ControlType::ArcadeStyle:
      chassis.arcade(leftY, rightX);

      break;
    case ControlType::TankStyle:
      chassis.tank(leftY, rightY);
      break;
    case ControlType::CurvatureControl:
      chassis.curvature(leftY, rightX);
      break;
    }

    if (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
      Conveyor.move(127);
      Intake.move(-127);
    }

    if (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
      Conveyor.move(-127);
      Intake.move(127);
    }

    if (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            Hook.move_absolute(-100, 500);
    }

    if (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      Hook.move(127);
    }
    // get left y and right x positions
    // int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    // int leftX = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
    //
    // // move the robot
    // chassis.curvature(leftY, leftX);

    // printf("X: %f\n", chassis.getPose().x);
    // printf("Y: %f\n", chassis.getPose().y);
    // printf("Theta: %f\n", chassis.getPose().theta);
    //

    pros::delay(20);
  }
}
