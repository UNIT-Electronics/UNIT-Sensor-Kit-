/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
  https://blog.uelectronics.com/tarjetas-desarrollo/arduino/tutorial-sensor-de-metal-modulo-ky-036/
 */
 
                              //Declaración de pines y variables 
int led = 10 ;                // Pin 10 para Led de salida
int touch = 3;                // Pin 3 Entrada Digital que enviara la señal cuando estemos tocando el sensor
int potenciometro = A0;       // Pin A0 Entrada Analógica que se llamara potenciometro 
int valsensor = 0;            // Variable para el potenciometro
int val = 0;                  // Variable para detección del sensor 


void setup ()

{
  Serial.begin (9600);              //Inicio de monitor serial a 9600 baud/seg
  pinMode (led, OUTPUT) ;           // Definimos el pin de led como salida
  pinMode (potenciometro, INPUT) ;  // Definimos potenciómetro como entrada
}

void loop ()
{
  valsensor = analogRead (potenciometro);   //se asigna a valsensor el valor de la lectura del potenciometro
  Serial.println (valsensor);               //en el monitor serial se imprimirá el valor de lectura del potenciometro
  val = digitalRead(touch);                 // val se le asignara el valor de salida de touch - Pin 3
  if (val == HIGH)                          //Condición , si el sensor es tocado y val es ALTO-HIGH entonces 
  {                                         
    digitalWrite (led, HIGH);               //prendera el led que se encuentra en la salida del pin 10
  }
  else                                     //De lo contrario , si el sensor no ha sido tocado...
  {
    digitalWrite (led, LOW);               //no se prendera el led del pin 10
  }
} 
