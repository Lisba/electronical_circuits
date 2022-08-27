/* 
Declaro una variable que indique qué
LED se encuentra encendido, y lo inicializo
en 10, que es donde está conectado el LED del
medio.
*/
int ledEncendido = 10;

void setup()
{
  // Inicializo los pines 8 a 12 como salida.
  for(int i=8; i<13; i++){
  	pinMode(i, OUTPUT);
  }
  
  //Inicializo los pines 3 y 4 como entrada.
  pinMode(3, INPUT); // Botón derecho
  pinMode(4, INPUT); // Botón izquierdo
  
  // Enciendo desde el principio el led del medio.
  digitalWrite(ledEncendido, HIGH);
}

/*
Declaro dos variables para almacenar el 
estado de los botones en el loop previo.
*/
int botonIzquierdoAntes = 0;
int botonDerechoAntes   = 0;

void loop()
{
  /*
  Leo los botones y almaceno el valor
  en dos variables.
  */
  int botonIzquierdoAhora = digitalRead(4);
  int botonDerechoAhora   = digitalRead(3);
  
  /*
  Uso un if para evaluar si el botón izquierdo se
  está presionando, si no se está presionando, 
  utilizo else-if para ver si se está presionando
  el botón derecho. Si no se cumple ninguna 
  condición, significa que no se presionó 
  ningún botón y no tengo que realizar ninguna acción.
  Agrego al if y else-if la condición de que, además de
  que se esté presionando el botón ahora, antes no se
  haya presionado, para esto uso las variables
  declaradas antes del loop (botonIzquierdoAntes y
  botonDerechoAntes).
  */
  if(botonIzquierdoAhora == 1 && botonIzquierdoAntes == 0){
    /*
    Si la condición previa se cumple, quiere decir que 
    se presionó el botón izquierdo y antes no se estaba
    presionando, por lo tanto tengo que "mover" la luz
    hacia la izquierda, a menos que haya llegado al LED
    que está máz a la izquierda.
    */
    if(ledEncendido < 12){
      /* 
      Si se cumple la condición de arriba, quiere decir
      que el LED encendido NO es el de más a la izquierda
      */
      
      /*
      Apago el LED que está encendido, incremento el
      valor de la variable y enciendo el que 
      corresponda
      */
      digitalWrite(ledEncendido,  LOW);
      ledEncendido++;
      digitalWrite(ledEncendido, HIGH);
    }
  }else if(botonDerechoAhora == 1 && botonDerechoAntes == 0){
     /*
     Si la condición previa se cumple, quiere decir que 
     se presionó el botón derecho y antes no se estaba
     presionando, por lo tanto tengo que "mover" la luz
     hacia la derecha, a menos que haya llegado al LED
     que está máz a la derecha.
     */
     if(ledEncendido > 8){
       /* 
       Si se cumple la condición de arriba, quiere decir
       que el LED encendido NO es el de más a la derecha
       */
       
       /*
       Apago el LED que está encendido, resto 1 al
       valor de la variable y enciendo el que 
       corresponda
       */
       digitalWrite(ledEncendido,  LOW);
       ledEncendido--;
       digitalWrite(ledEncendido, HIGH);
     }
  }
  
  /*
  Antes de completar el loop, guardo el estado
  de los botones en las variables que corresponda
  para poder utilizarlos en el siguiente loop
  */
  botonIzquierdoAntes = botonIzquierdoAhora;
  botonDerechoAntes   = botonDerechoAhora;
  
  /*
  Agrego un delay de 10ms para que la simulación
  sea más fluida
  */
  delay(10);
  
}
