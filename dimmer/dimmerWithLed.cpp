void setup()
{
  pinMode(A0, INPUT);
  pinMode(5, OUTPUT);
}

int brillo = 0;

void loop()
{
  brillo = analogRead(A0)/4;
  analogWrite(5, brillo);
  delay(10); //Para un simulador fluido.
}