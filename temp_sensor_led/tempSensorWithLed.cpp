void setup()
{
  for(int i=2; i<7; i++)
  {
	pinMode(i, OUTPUT);
  }
  
   pinMode(A0, INPUT);
   Serial.begin(9600);
}

int valorSensor;
int temperatura;
int ledAEncender;

void loop()
{
  valorSensor = analogRead(A0);
  temperatura = map(valorSensor, 20, 358, -40, 125);
  encenderLed(LedsToTurnOn(temperatura));
  
  Serial.println(temperatura);
  Serial.println(LedsToTurnOn(temperatura));
  
  delay(25);
}

int LedsToTurnOn(int temperatura)
{
	ledAEncender = map(temperatura, -40, 125, 1, 6);
  	return ledAEncender;
}

void encenderLed(int ledAEncender)
{
	switch(ledAEncender)
    {
      case 1:
      		digitalWrite(2, LOW);
      		digitalWrite(3, LOW);
      		digitalWrite(4, LOW);
      		digitalWrite(5, LOW);
            digitalWrite(6, LOW);
      		break;
    	case 2:
      		digitalWrite(2, HIGH);
      		digitalWrite(3, LOW);
      		digitalWrite(4, LOW);
      		digitalWrite(5, LOW);
            digitalWrite(6, LOW);
      		break;
    	case 3:
      		digitalWrite(2, HIGH);
      		digitalWrite(3, HIGH);
      		digitalWrite(4, LOW);
      		digitalWrite(5, LOW);
      		digitalWrite(6, LOW);
      		break;
        case 4:
      		digitalWrite(2, HIGH);
      		digitalWrite(3, HIGH);
      		digitalWrite(4, HIGH);
      		digitalWrite(5, LOW);
      		digitalWrite(6, LOW);
      		break;
        case 5:
      		digitalWrite(2, HIGH);
      		digitalWrite(3, HIGH);
      		digitalWrite(4, HIGH);
      		digitalWrite(5, HIGH);
      		digitalWrite(6, LOW);
      		break;
        case 6:
      		digitalWrite(2, HIGH);
      		digitalWrite(3, HIGH);
      		digitalWrite(4, HIGH);
      		digitalWrite(5, HIGH);
      		digitalWrite(6, HIGH);
      		break;
    }
}