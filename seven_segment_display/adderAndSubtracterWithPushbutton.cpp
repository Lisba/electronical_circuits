/* 
Para que sea más fácil codificar los segmentos,
declaro constantes que tengan de nombre cada segmento
y como valor el pin asociado en Arduino
*/
#define A 5
#define B 6
#define C 7
#define D 8
#define E 9
#define F 10
#define G 11

/*
Declaro una variable para guardar el número que se muestra
en la pantalla
*/
int numero = 0;

void setup()
{
  
  // Inicializo los pines del display como salida
  for(int i=5; i<12; i++){
    pinMode(i, OUTPUT);
  }
  
  // Inicializo los pines de los pulsadores como entrada
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  
  mostrarNumero(numero);
}


/*
Declaro variables para almacenar los estados de los botones
y poder comparar luego si el botón se mantuvo apretado o no.
*/
int botonIzquierdoAntes = 0;
int botonDerechoAntes    = 0;

void loop()
{
  // Leo el estado de los botones y lo guardo en dos variables.
  int botonIzquierdoAhora = digitalRead(4);
  int botonDerechoAhora = digitalRead(3);
  
  if(botonIzquierdoAhora == HIGH && botonIzquierdoAntes == LOW){
    /*
	Si se cumple la condición del if anterior, quiere decir que 
	en este momento se está presionando el botón izquierdo y en 
	el loop anterior no. En ese caso restamos uno a la variable
	que guarda el número y lo mostramos por pantalla.
	*/
    numero--;
	// Si el número es -1, tenemos que volver a escribir un 9.
    if(numero==-1) numero=9;
	mostrarNumero(numero);
  } else if (botonDerechoAhora == HIGH && botonDerechoAntes == LOW) {
	/*
	Si se cumple la condición del if anterior, quiere decir que 
	en este momento se está presionando el botón derecho y en 
	el loop anterior no. En ese caso sumamos uno a la variable
	que guarda el número y lo mostramos por pantalla.
	*/
    numero++;
	// Si el número es 10, tenemos que volver a escribir un 0.
    if(numero==10) numero=0;
	mostrarNumero(numero);
  }
  /*
  Guardamos los estados de los botones ahora para usarlos en el 
  siguiente loop
  */
  botonIzquierdoAntes = botonIzquierdoAhora;
  botonDerechoAntes = botonDerechoAhora;
  
  delay(10); // Delay para que se agilice la simulación en Tinkercad
}

/*
Declaro una función para mostrar los números en el 
display.
*/
void mostrarNumero(int numero){
  /* 
  Apago todos los segmentos del display antes de encender
  los que corresponda
  */
  for(int i=5; i<12; i++){
    digitalWrite(i, LOW);
  }
  /*
  Utilizo un switch para encender los segmentos del display
  que corresponda, en función del número que se recibe por 
  parámetro
  */
  switch(numero){
    case 0:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      break;
    case 1:
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    case 2:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      break;
    case 3:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 4:
      digitalWrite(G, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(F, HIGH);
      break;
    case 5:
      digitalWrite(A, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(F, HIGH);
      break;  
    case 6:
      digitalWrite(A, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      break;
    case 7:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    case 8:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 9:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
  }
}