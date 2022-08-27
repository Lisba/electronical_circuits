int oldValue = LOW;
int state = LOW;
int buttonPin = 5;
int ledPin = 10;

void setup()
{
  pinMode(10, OUTPUT);
  pinMode(5, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int currentValue = digitalRead(5);
  Serial.println(currentValue);
  
  if(currentValue == HIGH && oldValue == LOW)
  {
    state = !state;
  	digitalWrite(ledPin, state);
  }
  
  oldValue = currentValue;
  delay(50);
}