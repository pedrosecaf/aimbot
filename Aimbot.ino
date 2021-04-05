#include <IRremote.h>
#include <IRremoteInt.h>

int RECV_PIN = 6;

IRrecv irrecv(RECV_PIN);

decode_results results;


int trigPin = 12;    // connect TRIG pin to Arduino pin 12
int echoPin = 11;    // connect ECHO pin to Arduino pin 11
float duration_us, distance_cm;

int power = 0;
int velocity = 255;
int moving = 0;

int motor1pin1 = 9;
int motor1pin2 = 8;
int motor2pin1 = 5;
int motor2pin2 = 4;


int low_speed = 150;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin2, LOW);  
  analogWrite(9, 0);
  analogWrite(5, 0);

  Serial.begin(9600);
  irrecv.enableIRIn();  

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  while (irrecv.decode(&results) == 0){
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration_us = pulseIn(echoPin, HIGH);
    distance_cm = 0.017 * duration_us;
    Serial.print("distance: ");
    Serial.print(distance_cm);
    Serial.println(" cm");
    delay(500);
    if ( power == 1 ) {
      if ( distance_cm <= 20 ) {
        if (moving == 0) {
          forward(velocity);
        }
      } else {
        if ( moving == 1 ) {
          forward(0);
        }
      }
    }
  }
  Serial.println(results.value, HEX);
  
  if (results.value == 0xFFA25D) {
    Serial.println("Power Button");
    if ( power == 1 ) {
      power = 0;
      forward(0);
    } else {
      power = 1;
      forward(velocity);
    }
  }
  if (results.value == 0xFF906F) {
    Serial.println("Increase Speed");
    velocity = 255;
    forward(velocity);
  }
  if (results.value == 0xFFE01F) {
    Serial.println("Decrease Speed");
    velocity = low_speed;
    forward(velocity);
  }
  if (results.value == 0xFFC23D) {
    Serial.println("Turn Right");
    right();
    delay(500);
    forward(velocity);
  }

  if (results.value == 0xFF22DD) {
    Serial.println("Turn Left");
    left();
    delay(500);
    forward(velocity);
  }
  
  delay(500);
  irrecv.resume(); // Receive the next value
}


void forward (int vel) {
  Serial.print("Forward: ");
  Serial.println(vel);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin2, LOW);  

  analogWrite(5, vel);
  analogWrite(9, vel);
  if ( vel != 0 ) {
    moving = 1;
  } else {
    moving = 0;
  }
}

void right () {
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin2, LOW);  

  analogWrite(5, low_speed);
  analogWrite(9, 255);

}

void left () {
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin2, LOW);  

  analogWrite(5, 255);
  analogWrite(9, low_speed);

}