void setup()
{
  pinMode(3, OUTPUT);
}

int intensity = 0;
bool turningOn = true;

void loop()
{
  if(turningOn){
    analogWrite(3, intensity);
    intensity++; // Cuando llegue a 255 hace overflow y baja a 0.
    
    if(intensity == 255){
      turningOn = false;
    }
    delay(5); 
  }
  else
  {
  	analogWrite(3, intensity);
    intensity--;
    
    if(intensity == 0){
      turningOn = true;
    }
    delay(5); 
  }
}