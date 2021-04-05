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

#### Lines 1-3

Imports the IRremote library (Version 2.0).

#### Lines 4-17

Defines a forward() function that accepts a speed value as parameter. The program prints the speed to the serial monitor, digitally sets motor1pin2 and motor2pin2 with low voltage (0V), and sets the voltage of motor2pin1 and motor1pin1 to the speed value passed as argument. If the speed value is greater than 0, the program updated the variable moving to 1. Otherwise, it updates the variable moving to 0. In short, the forward() function instructs the robot to move forward with a configured speed.

#### Lines 18-24

Defines a right() function. The program digitally sets motor1pin2 and motor2pin2 with low voltage (0V), and sets the voltage of motor2pin1 and motor1pin1 to low_speed and high_speed, respectively. In short, the right() function instructs the robot to turn right.

#### Lines 25-31

Defines a left() function. The program digitally sets motor1pin2 and motor2pin2 with low voltage (0V), and sets the voltage of motor2pin1 and motor1pin1 to high_speed and low_speed, respectively. In short, the left() function instructs the robot to turn left.

### setup()

#### Line 32

Initializes the definition of the setup() function, which is called when a sketch starts. It is used to initialize variables, pin modes, start using libraries, etc. The setup() function will only run once, after each powerup or reset of the Arduino board (https://www.arduino.cc/reference/tr/language/structure/sketch/setup/).

#### Lines 33-34

Defines the Arduino pin that will receive the signals from the IR receiver.

#### Lines 35-36

Enables the receiver pin to receive signals from the remote controller.

#### Lines 37-38

Stores the information emitted by the remote controler.

#### Lines 39-41

Defines the Arduino pins that will work as Trigger and Echo pins. Trigger pin is used to trigger the ultrasonic sound pulses. Echo pin produces a pulse when the reflected signal is received. The length of the pulse is proportional to the time it took for the transmitted signal to be detected (https://lastminuteengineers.com/arduino-sr04-ultrasonic-sensor-tutorial/).

#### Lines 42-43

Initializes the variables duration_us and distance_cm, which will be used later.

#### Lines 44-47

Defines the variables power, velocity, and moving to control the robot's operations.

Power = 0 indicates that the robot is powered off.

Power = 1 indicates that the robot is powered on.

Velocity = 255 indicates that the robot is configured to move at high speed.

Velocity = 150 indicates that the robot is configured to move at low speed.

Moving = 0 indicates that the robot is stationary.

Moving = 1 indicates that the robot is moving.

#### Lines 48-52

Defines the Arduino pins that will control the motors.

#### Lines 53-55

Defines the variables low_speed and high_speed as 155 and 255, respectively.

#### Lines 56-60

Configures the motor pins to output mode.

#### Lines 61-62

Digitally sets motor1pin2 and motor2pin2 with low voltage (0V).

#### Lines 63-65

Sets motor1pin1 and motor2pin1 with low voltage (0V) using analogWrite().

#### Line 66-68

Initializes the serial monitor.

#### Line 69-72

Configures trigPin and echoPin to output and input modes, respectively.

### loop()

#### Line 73

Initializes the definition of the loop() function, which loops consecutively, allowing the program to change and respond. It is used to actively control the Arduino board (https://www.arduino.cc/reference/en/language/structure/sketch/loop/).

#### Lines 74-95

Creates a while loop to iterate until a button is clicked on the remote controller.

###### Lines 75-77

Generates a 10-microsecond pulse to trigPin.

###### Line 78

Measures the duration of pulse from echoPin.

###### Line 79

Calculates the distance between the robot and the object/human.

###### Lines 80-82

Prints the distance to the serial monitor.

###### Line 83

Pauses the program for 500 miliseconds.

###### Lines 84-95

If the robot is powered on, the distance is equal to or less than 20 cm, and the robot is stationary, the function forward() is called with the last configured velocity as argument (the robot is instructed to start moving). Also, if the robot is powered on, the distance is more than 20 cm, and the robot is moving, the function forward() is called with 0 as argument (the robot is istructed to stop).

#### Lines 96-97

For the program to exit the while loop, a button must be clicked on the remote controller. Therefore, this line instruct the program to print o the serial monitor the hexadecimal number associated with the clicked button.

#### Lines 98-107

If the hexadecimal number is equal to 0xFFA25D, it means that the power button was clicked. Therefore, the program prints the name of the button to the serial monitor. If the robot is powered on, the program powers it off and call the forward() function with 0 as argument (the robot is istructed to stop). If the robot is powered off, the program powers it on and call the forward() function with the last configured velocity as argument (the robot is instructed to start moving).

#### Lines 108-112

If the hexadecimal number is equal to 0xFF906F, it means that the increase speed button (up arrow) was clicked. Therefore, the program prints the name of the button to the serial monitor, sets the velocity to high speed, and calls the forward() function with high_speed as argument.

#### Lines 113-117

If the hexadecimal number is equal to 0xFFE01F, it means that the decrease speed button (down arrow) was clicked. Therefore, the program prints the name of the button to the serial monitor, sets the velocity to low speed, and calls the forward() function with low_speed as argument.

#### Lines 118-123

If the hexadecimal number is equal to 0xFFC23D, it means that the turn right button (right arrow) was clicked. Therefore, the program prints the name of the button to the serial monitor, calls the right() function, waits for 500 miliseconds, and calls the forward() function with the last configured velocity as argument (the robot makes a slight curve to the right and keeps going forward).

#### Lines 124-130

If the hexadecimal number is equal to 0xFF22DD, it means that the turn left button (left arrow) was clicked. Therefore, the program prints the name of the button to the serial monitor, calls the left() function, waits for 500 miliseconds, and calls the forward() function with the last configured velocity as argument (the robot makes a slight curve to the left and keeps going forward). 

#### Lines 131-133

Waits for 500 miliseconds and resumes the process of receiving IR signals.

## Video

Link: https://usfedu-my.sharepoint.com/:v:/g/personal/psecafrodrig_usf_edu/EbqxybTKl19HhzCr1qYRJEsBZZM-fB5Hkg3UIJMVThhR2w?e=Bdx7mp
