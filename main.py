# ---------------------------------------------------------------------------- #
#                                                                              #
# 	Module:       main.py                                                      #
# 	Author:     michael.crawford LeeAna                                              #
# 	Created:      10/28/2024, 3:03:56 PM                                       #
# 	Description:  V5 project                                                   #
#                                                                              #
# ---------------------------------------------------------------------------- #

# 30 seconds


# Library imports
from vex import *

control = Controller(PRIMARY)

# Axis for controller 
# left = axis3 Up&down on left joystick
# Left = axis4 up&down on left Joystick
# right Axis 2 up&down on right joystick
# Right Axis 1 up&down on right joystick

rc_enabled = True

# Controller buttons for stuff``
aBut = control.buttonA
r1 = control.buttonR1
r2 = control.buttonR2



# For anyone, make sure you change motors before running
# Bot has 2 motors, 2 wheel dt
m1 = Motor(Ports.PORT19, GearSetting.RATIO_18_1, False)
m2 = Motor(Ports.PORT18, GearSetting.RATIO_18_1, True)
# m3 = Motor(Ports.PORTX, GearSetting.RATIO_18_1, False)
# m4 = Motor(Ports.PORTX, GearSetting.RATIO_18_1, False)
# m5 = Motor(Ports.PORTX, GearSetting.RATIO_18_1, False)
# m6 = Motor(Ports.PORTX, GearSetting.RATIO_18_1, False)
# ^ make motor in this fashion

Hook = Motor(Ports.PORT16, GearSetting.RATIO_36_1, False)

# Convayer belt

Con1 = Motor(Ports.PORT10, GearSetting.RATIO_18_1, True)
Con2 = Motor(Ports.PORT1, GearSetting.RATIO_18_1, False)

ConGB = MotorGroup(Con1, Con2)

# ^ make sure to add button functionality)
# TODO: Wheelbase is the distance between the wheels
dt = DriveTrain(m1, m2, 11.81, 13, 11.25, INCHES)
#NOTE: The amount of rotations per 1 tile is 2.03 rotations (A tile is around 24 in), diagonal is 33.94 inches
# Num of Rotations for diagonal is 2.87
# TODO Need to find the size of current wheels, diameter and radius, as rotation is dictated by the wheelbase

# Track width: 13 in
# Wheel Base : 8 in
# 
dt_l_need_stop = False
dt_r_need_stop = False 

# Constants declaration
l = LEFT 
r = RIGHT 
d = DEGREES
t = TURNS
p = PERCENT
r = REVERSE
i = INCHES
f = FORWARD

def rc_control():
    global dt_l_need_stop, dt_r_need_stop, rc_enabled


    while True:
        if rc_enabled:
            
            dt_left_side = control.axis3.position() + control.axis1.position()
            dt_right_side = control.axis3.position() - control.axis1.position()

            if dt_left_side < 5 and dt_left_side > -5:
                if dt_l_need_stop:
                    m1.stop()

                    dt_l_need_stop = False 
            else:
                dt_l_need_stop = True
            if dt_right_side < 5 and dt_right_side > -5:
                if dt_r_need_stop:
                    m2.stop()

                    dt_r_need_stop = False
            else:
                dt_r_need_stop = True

            if dt_l_need_stop:
                m1.set_velocity(dt_left_side, PERCENT)
                m1.spin(FORWARD)
            
            if dt_r_need_stop:
                m2.set_velocity(dt_right_side, PERCENT)
                m2.spin(FORWARD)
            
            # if this is correct, should just store the prev value as what ever it 

        wait(20, MSEC)

def congb_spin():
    ConGB.spin(FORWARD, 60, PERCENT)

def congb_stop():
    # ConGB.stop()
    ConGB.spin(REVERSE, 60, PERCENT)

def hook_spin():
    pos = Hook.position()
    # Hook.set_position(5, DEGREES) # 180 for open? I don't know
    Hook.spin_to_position(180, DEGREES)
    
def hook_button():
    global btn_state
    
    if control.ButtonA.pressing():
        wait(200, MSEC)
        
        btn_state = not btn_state
        
        if btn_state:
            hook_spin()
        else:
            hook_stop()

def hook_open():
    Hook.spin_to_position(-10, DEGREES)

def autoon():
    task = Thread(autorun)
    while(comp.is_autonomous() and comp.is_enabled()):
        wait(10, MSEC)

    task.stop()

def autorun():
    # this is the function for doing the autonomous section, edit this
    # dt.set_drive_velocity(100, PERCENT)
    # ConGB.set_velocity(100, PERCENT)
    # dt.drive_for(REVERSE, 6, INCHES, 100, PERCENT)
    # ConGB.spin_for(FORWARD, 5, TURNS) # Adjust if needed, random value
    # dt.turn(RIGHT, 50, PERCENT)
    
    control.screen.clear_screen()


    # ^ This is because i hate having to type capitial letters 

    # ADJUST THESE VALUES BEFORE COMP, MIGHT NOT BE CORRECT, THIS IS A MUST-NEED
    # TODO FIX VALUES, AND GET WORKING AUTON THAT DOES WHAT WE WANT
    # IDEA BOARD HERE 
    # https://excalidraw.com/#json=gppTx7ikdzoEI9YJy2uus,wFbsS-WYsYQU216MKCsA8w
    # 
    dt.set_drive_velocity(100, PERCENT)
    control.screen.set_cursor(1, 1)
    control.screen.print("Auton code atm")
    congb_spin()
    hook_open()
    dt.turn_for(l, 25, DEGREES) # Hopefully angle ourselves in line with the first stake
    dt.drive_for(r, 5, INCHES, wait=False)  # Maybe make this go reverse so we can already have a hold on the stake?
    hook_spin()
    dt.turn_for(l, 65, DEGREES) # Turn into line with the first stack of donuts, hopefully get blue one
    dt.drive_for(f, 6, i, wait=False)
    dt.turn_for(LEFT, 90, DEGREES , wait=False)
    dt.drive_for(f, 2, INCHES)
    dt.turn_for(l, 15, DEGREES)
    dt.drive_for(r, 20, i)
    hook_open()  
    dt.drive_for(f, 5, i)
    dt.drive_for(REVERSE, 6, INCHES, 100, PERCENT)
    # ConGB.spin_for(FORWARD, 5, TURNS) # Adjust if needed, random value
    dt.turn(330, DEGREES)#
    dt.stop()


def driverThread():
    dthread = Thread(rc_control)
    control.buttonL1.pressed(congb_spin)
    control.buttonL2.pressed(congb_stop)
    r1.pressed(hook_spin)
    r2.pressed(hook_open)
    while(comp.is_driver_control and comp.is_enabled):
        congb_spin()
        hook_button()
        # aBut.pressed(hook_spin)
        # control.buttonB.pressed(hook_open)
        wait(10, MSEC)

    
    dthread.stop()


debug = False
############
# ^ DONT FORGET TO CHANGE THIS BEFORE COMP
# THIS WILL ALLOW FOR DRIVING AND AUTON WIHTOUT THE SPECIFIC SECTION AND THE COMP BRAIN
#
############

if debug is True: 
    control.buttonL2.pressed(autoon)
    while True: 
        rc_control()


comp = Competition(driverThread, autoon) # Make sure to change the 


# Brain should be defined by default
brain=Brain()



        
