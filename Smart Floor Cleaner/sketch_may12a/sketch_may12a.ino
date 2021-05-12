#include <Servo.h>
Servo myServo;

int r_motor_n = 10; //PWM control Right Motor +
int r_motor_p = 11; //PWM control Right Motor -
int l_motor_p = 9; //PWM control Left Motor -
int l_motor_n = 6; //PWM control Left Motor +
int pump = 4;
int mop = 5;
int serv = 3;
int speedy = 255;
int incomingByte = 0; // for incoming serial data

void setup()
{
  myServo.attach(3);
  myServo.write(0);  
  pinMode(r_motor_n, OUTPUT); //Set control pins to be outputs
  pinMode(r_motor_p, OUTPUT);
  pinMode(l_motor_p, OUTPUT);
  pinMode(l_motor_n, OUTPUT);

  pinMode(2, OUTPUT);
  digitalWrite(r_motor_n, LOW); //set both motors off for start-up
  digitalWrite(r_motor_p, LOW);
  digitalWrite(l_motor_p, LOW);
  digitalWrite(l_motor_n, LOW);
  digitalWrite(2, HIGH);
  Serial.begin(9600);
}
void loop()
{

  if (Serial.available() > 0) 
  {
    incomingByte = Serial.read();
  }
  switch(incomingByte)
  {

    case 'S': // control to stop the robot
    digitalWrite(r_motor_n, LOW); 
    digitalWrite(r_motor_p, LOW);
    digitalWrite(l_motor_p, LOW);
    digitalWrite(l_motor_n, LOW);
    Serial.println("Stop");
    incomingByte='*';
    break;

    case 'R': //control for right
    analogWrite(r_motor_n, speedy); 
    digitalWrite(r_motor_p, LOW);
    analogWrite(l_motor_p, speedy);
    digitalWrite(l_motor_n, LOW);
    Serial.println("right");
    incomingByte='*';
    break;
    
    case 'L': //control for left
    analogWrite(r_motor_n, LOW); 
    digitalWrite(r_motor_p, speedy);
    analogWrite(l_motor_p, LOW);
    digitalWrite(l_motor_n, speedy);
    Serial.println("right");
    incomingByte='*';
    break;
    
    case 'F': //control for forward
    analogWrite(r_motor_n, speedy); 
    digitalWrite(r_motor_p, LOW);
    analogWrite(l_motor_p, LOW);
    digitalWrite(l_motor_n, speedy);
    Serial.println("right");
    incomingByte='*';
    break;
    break;
    delay(5000);
  }
}




  
