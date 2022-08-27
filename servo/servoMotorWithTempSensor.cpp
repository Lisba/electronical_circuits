#include<Servo.h>

Servo miServo;

void setup(){
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  //pinMode(3, OUTPUT); Led conectado antiguamente
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  miServo.attach(3); //le digo donde esta conectado
  
  Serial.begin(9600);
}

void loop(){
  
  
  int servoAngle;
  int valorSensor = analogRead(A0);
  int temperatura = map(valorSensor, 20, 358, -40, 125);
  int valorLeds;
  int i;
  Serial.println(temperatura);
  servoAngle = map(temperatura,-40,125,180,0);
  valorLeds = map(temperatura, -40, 125, 2, 6);
  
  miServo.write(servoAngle);
  
  delay(50);
}