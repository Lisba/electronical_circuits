void setup()
{
  /*
  Inicializo los pines 4, 5 y 6 como salida.
  En estos pines están conectados los ánodos
  de cada uno de los LEDs.
  */
  pinMode(4, OUTPUT); // LED rojo
  pinMode(5, OUTPUT); // LED amarillo
  pinMode(6, OUTPUT); // LED verde
}
void loop()
{
  /*
  Apago el LED amarillo. Esto se hace por las
  dudas que haya quedado encendido del loop 
  anterior. 
  Luego enciendo el LED rojo, y espero 10 
  segundos.
  */
  digitalWrite(5,  LOW);
  digitalWrite(4, HIGH);
  delay(10000);
  
  /*
  Apago el LED rojo y enciendo el amarillo
  para hacer la transición hacia el verde.
  Espero medio segundo.
  */
  digitalWrite(4,  LOW);
  digitalWrite(5, HIGH);
  delay(500);
  
  /*
  Apago el LED amarillo encendido previamente
  y enciendo el verde. Espero luego 10 segundos.
  */
  digitalWrite(5,  LOW);
  digitalWrite(6, HIGH);
  delay(10000);
  
  /*
  Apago el LED verde y enciendo el amarillo para
  hacer la transición hacia el rojo. Como la 
  transición dura medio segundo, hacemos la llamada
  al delay(500), luego de estas instrucciones, se 
  completa un ciclo del loop, y el siguiente 
  comenzará nuevamente apagando el amarillo y 
  encendiendo el rojo.
  */
  digitalWrite(5, HIGH);
  digitalWrite(6,  LOW);
  delay(500);  
}