int number = 0;
int oldValue = LOW;

void setup()
{
  pinMode(4, INPUT);
  
  for(int i=5; i<12; i++){
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  int currentValue = digitalRead(4);
  
  if(currentValue == HIGH && oldValue == LOW)
  {
    switch(number)
    {
      	case 0:
    	case 1:
      	case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
      		number = ++number;
      		break;
        case 9:
      		number = 0;
      		break;
    }
  }
  
  oldValue = currentValue;
  displayNumber(number);
  
  delay(10);
}

void displayNumber(int number){
  for(int i=5; i<12; i++){
   	digitalWrite(i, LOW); 
  }
  switch(number){
    case 0:
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
   	  digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
   	  digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
    break;
    case 1:
      digitalWrite(6, HIGH);
   	  digitalWrite(7, HIGH);
    break;
    case 2:
      digitalWrite(5, HIGH);
   	  digitalWrite(6, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
    break;
    case 3:
      digitalWrite(5, HIGH);
   	  digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(11, HIGH);
    break;
    case 4:
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(10, HIGH);
   	  digitalWrite(11, HIGH);
    break;
    case 5:
      digitalWrite(5, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
   	  digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
    break;
    case 6:
      digitalWrite(5, HIGH);
      digitalWrite(7, HIGH);
   	  digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
    break;
    case 7:
      digitalWrite(5, HIGH);
   	  digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
    break;
    case 8:
      digitalWrite(5, HIGH);
   	  digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
    break;
    case 9:
      digitalWrite(5, HIGH);
   	  digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
    break;
  }
}

