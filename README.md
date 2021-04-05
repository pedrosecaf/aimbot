# Aimbot

University of South Florida - Foundations of Engineering (EGN 3000L)

Dr. Chung Seop Jeong (Instructor)

## Group Members

Varennyam Joshi (Project Engineering Lead)

Meena Kukkadam (Design Engineering Lead)

Manan Ahuja (Product Development Lead)

Pedro Secaf Rodrigues Nunes (Software Engineering Lead)

Derek Lewis (Test Engineering Lead)

## Objectives

The project was created to engage K12 kids in STEM learning. The purpose of the project is to provide a companion robot for these kids, combining a human follower device with an aiming apparatus.

## Project Description

The project consists of a 4-wheeled robot (2 motorized and 2 independent wheels) controlled by an ultrasonic sensor. If the distance between the user and the robot is equal to or less than 20 cm, the robot moves forwards. Otherwise, it stays stationary. Through a remote controller, the user can turn the robot on/off, adjust the speed (two options), and instruct the robot to make left/right turns. Moreover, a target attached to the chassis of the robot provides an additional entertainment to the user.

## Material

- Arduino Uno
- H-bridge L298N
- 2 DC motors
- 4 wheels
- Mini breadboard
- Ultrasonic sensor (HC-SR04)
- 9V battery
- Remote Control
- IR receiver
- Female-to-male wires
- Jumper wires
- AC to DC plug
- PLA filaments
- Stickers

## Code Description

The Arduino code was written using C++

#### Lines 1-2

Imports the IRremote library (Version 2.0).

#### Line 4

Defines the Arduino pin that will receive the signals from the IR receiver.

#### Line 6

Enables the receiver pin to receive signals from the remote controller.

#### Line 8

Stores the information emitted by the remote controler.

#### Lines 10-11

Defines the Arduino pins that will work as Trigger and Echo pins. Trigger pin is used to trigger the ultrasonic sound pulses. Echo pin produces a pulse when the reflected signal is received. The length of the pulse is proportional to the time it took for the transmitted signal to be detected (https://lastminuteengineers.com/arduino-sr04-ultrasonic-sensor-tutorial/).

#### Line 13

Initializes the variables duration_us and distance_cm, which will be used later.

#### Lines 15-17

Defines the variables power, velocity, and moving to control the robot's operations.


Power = 0 indicates that the robot is powered off

Power = 1 indicates that the robot is powered on


Velocity = 255 indicates that the robot is configured to move at high speed

Velocity = 150 indicates that the robot is configured to move at low speed


Moving = 0 indicates that 

Moving = 1 indicates that

#### Lines 19-22

Defines the Arduino pins that will control the motors.

#### Lines 24-25

Defines the variables low_speed and high_speed as 155 and 255, respectively.

#### Line 27

Initializes the definition of the setup() function, which is called when a sketch starts. It is used to initialize variables, pin modes, start using libraries, etc. The setup() function will only run once, after each powerup or reset of the Arduino board (https://www.arduino.cc/reference/tr/language/structure/sketch/setup/). Lines 28-42 consist of the definition of the setup() function.

#### Lines 28-31



## Final Product
