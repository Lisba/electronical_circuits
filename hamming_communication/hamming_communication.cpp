void setup()
{
  for(int i=2; i<=8; i++){
  	pinMode(i, INPUT);
  }
  Serial.begin(9600);
}

int p1;
int p2;
int d1;
int p3;
int d2;
int d3;
int d4;

void loop()
{
  p1 = digitalRead(2);
  p2 = digitalRead(3);
  d1 = digitalRead(4);
  p3 = digitalRead(5);
  d2 = digitalRead(6);
  d3 = digitalRead(7);
  d4 = digitalRead(8);
  
  int grupo_p1 = (p1 + d1 + d2 + d4) % 2;
  int grupo_p2 = (p2 + d1 + d3 + d4) % 2;
  int grupo_p3 = (p3 + d2 + d3 + d4) % 2;
  
  int posicionError = grupo_p1 * 1 + grupo_p2 * 2 + grupo_p3 * 4;
  
  switch(posicionError){
    case 1:
    p1 = !p1;
    break;
    case 2:
    p2 = !p2;
    break;
    case 3:
    d1 = !d1;
    break;
    case 4:
    p3 = !p3;
    break;
    case 5:
    d2 = !d2;
    break;
    case 6:
    d3 = !d3;
    break;
    case 7:
    d4 = !d4;
    break;
  }
  
  Serial.print(p1);
  Serial.print(p2);
  Serial.print(d1);
  Serial.print(p3);
  Serial.print(d2);
  Serial.print(d3);
  Serial.println(d4);
}