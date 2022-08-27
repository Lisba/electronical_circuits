#include <LiquidCrystal.h>

#define NOBOTON 0
#define BOTON1 1
#define BOTON2 2
#define BOTON3 3
#define BOTON4 4

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("TEMP=   !120.00");
  lcd.setCursor(0,1);
  lcd.print("MIN=-40  MAX=100");
}

int min = -39;
int max = 124;
int botonAntes = NOBOTON;

void loop()
{
float lectura = leerTemperatura();

      int botonAhora = leerBoton();

    if(botonAhora != NOBOTON && botonAhora != botonAntes)
    {
        switch(botonAhora)
        {
        case BOTON1:
            if (max < 124)
            {
                max++;
            }
            break;
        case BOTON2:
            if (max > min + 1)
            {
                max--;
            }
            break;
        case BOTON3:
            if (min < max - 1)
            {
                min++;
            }
            break;
        case BOTON4:
            if (min > -39)
            {
                min--;
            }
            break;
        }
    }

    if(lectura > max || lectura < min)
    {
        lcd.setCursor(0, 0);
        lcd.print("TEMP=    !");
        if ((lectura > -10 && lectura < 0) || (lectura >= 10 && lectura < 100))
        {
            lcd.print(" ");
        }
        if (lectura >= 0 && lectura < 10)
        {
            lcd.print("  ");
        }
        lcd.print(lectura);
   	}
    else
    {
        lcd.setCursor(0, 0);
        lcd.print("TEMP=     ");
        if ((lectura > -10 && lectura < 0) || (lectura >= 10 && lectura < 100))
        {
            lcd.print(" ");
        }
        if (lectura >= 0 && lectura < 10)
        {
            lcd.print("  ");
        }
        lcd.print(lectura);
     }



    lcd.setCursor(0, 1);
    lcd.print("MIN=");
    if ((min > -10 && min < 0) || (min >= 10 && min < 100))
    {
        lcd.print(" ");
    }
    if (min >= 0 && min < 10)
    {
        lcd.print("  ");
    }
    lcd.print(min);
 

    lcd.setCursor(9, 1);
    lcd.print("MAX=");
    if ((max > -10 && max < 0) || (max >= 10 && max < 100))
    {
        lcd.print(" ");
    }
    if (max >= 0 && max < 10)
    {
        lcd.print("  ");
    }
    lcd.print(max);

    botonAntes = botonAhora;

    delay(25);
}

int leerBoton()
{
    int valorA1 = analogRead(A0);
    if (valorA1 >= 0 && valorA1 <= 30)
    {
        return BOTON1;
    }
    if (valorA1 <= 371 && valorA1 >= 311)
    {
        return BOTON2;
    }
    if (valorA1 <= 468 && valorA1 >= 408)
    {
        return BOTON3;
    }
    if (valorA1 <= 507 && valorA1 >= 447)
    {
        return BOTON4;
    }
    return NOBOTON;
}

float leerTemperatura()
{
    int pinA0 = analogRead(A1);
    float volts = pinA0 * 5.0;
    volts = volts / 1024.0;
    float temperatura = (volts - 0.5) * 100;
    return temperatura;
}
