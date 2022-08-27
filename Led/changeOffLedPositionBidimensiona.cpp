int ledApagado = 2;

void setup()
{
  for(int i = 0; i < 10; i++)
  {
  	pinMode(i, OUTPUT);
  }
  
  pinMode(A0, INPUT); // Botón Izquierdo.
  pinMode(A1, INPUT); // Botón Arriba.
  pinMode(A2, INPUT); // Botón Derecho.
  pinMode(A3, INPUT); // Botón Abajo.
  
  for(int i = 3; i < 10; i++)
  {
    digitalWrite(i, HIGH); //Enciende todos menos el led 2.
  }  
}

//Para no redeclararlas en cada ciclo del loop.
int botonArribaAntes = 0;
int botonDerechaAntes = 0;
int botonAbajoAntes = 0;
int botonIzquierdaAntes = 0;

//Para no redeclararlas en cada ciclo del loop.
int botonArribaAhora = 0;
int botonDerechaAhora = 0;
int botonAbajoAhora = 0;
int botonIzquierdaAhora = 0;

void loop()
{
  botonArribaAhora = digitalRead(A1);
  botonDerechaAhora = digitalRead(A2);
  botonAbajoAhora = digitalRead(A3);
  botonIzquierdaAhora = digitalRead(A0);
  
  if(botonArribaAhora == 1 && botonArribaAntes == 0)
  {
    if(ledApagado > 5) // Valida el limite superior.
    {
      digitalWrite(ledApagado, HIGH);
      ledApagado = ledApagado - 4;
      digitalWrite(ledApagado, LOW);
    }
  }
  else if(botonDerechaAhora == 1 && botonDerechaAntes == 0)
  {
    if(ledApagado != 2 && ledApagado != 6) // Valida el limite derecho.
    {
      digitalWrite(ledApagado, HIGH);
      ledApagado = ledApagado - 1;
      digitalWrite(ledApagado, LOW);
    }
  }
  else if(botonAbajoAhora == 1 && botonAbajoAntes == 0)
  {
    if(ledApagado < 6) // Valida el limite inferior.
    {
      digitalWrite(ledApagado, HIGH);
      ledApagado = ledApagado + 4;
      digitalWrite(ledApagado, LOW);
    }
  }
  else if(botonIzquierdaAhora == 1 && botonIzquierdaAntes == 0)
  {
    if(ledApagado != 5 && ledApagado != 9) // Valida el limite izquierdo.
    {
      digitalWrite(ledApagado, HIGH);
      ledApagado = ledApagado + 1;
      digitalWrite(ledApagado, LOW);
    }
  }
  
  botonArribaAntes = botonArribaAhora;
  botonDerechaAntes = botonDerechaAhora;
  botonAbajoAntes = botonAbajoAhora;
  botonIzquierdaAntes = botonIzquierdaAhora;
  
  delay(10); //Para una simulacion mas fluida.
}