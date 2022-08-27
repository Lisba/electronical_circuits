#include <Servo.h>

Servo miServo;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  miServo.attach(3);
  
  Serial.begin(9600);
}

void loop()
{
  int valorSensor = analogRead(A0);
  int temperatura = map(valorSensor, 20, 358, -40, 125);
  int valorLeds;
  int i;

  Serial.println(temperatura);
  
  valorLeds = map(temperatura, -40, 125, 2, 6);
  for(i=2;i<=valorLeds;i++){
      digitalWrite(i, HIGH);
  }
  for(i=valorLeds+1;i<=6;i++){
      digitalWrite(i, LOW);
  }
  
  miServo.write(0);
  delay(1000);
  miServo.write(45);
  delay(1000);
    
  
  delay(25);
  
}