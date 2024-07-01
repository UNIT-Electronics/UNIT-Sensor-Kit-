/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
  https://blog.uelectronics.com/tarjetas-desarrollo/como-utilizar-el-sensor-infrarrojo-emisor-ky-005-tutorial-funcionamiento/
*/

#include <IRremote.h>       // Incluye la librería IRremote para el control de IR

IRsend irsend;            // Objeto para enviar comandos IR utilizando el pin 3 automáticamente
int b = 11;               // Definición del pin donde está conectado el botón
int valor;                // Variable para almacenar el estado del botón (HIGH o LOW)

void setup() {
  Serial.begin(9600);     // Inicialización del puerto serial a 9600 baudios
  pinMode(b, INPUT);      // Configura el pin del botón como entrada
}

void loop() {
  valor = digitalRead(b); // Lee el estado del botón (HIGH o LOW)

  if (valor == HIGH) {    // Si el botón está pulsado (estado HIGH)
    irsend.sendNEC(0x00000001, 32);   // Envía un paquete de 32 bits utilizando el protocolo NEC
    Serial.println("send");           // Imprime "send" en el Monitor Serial como confirmación
    delay(100);                       // Espera 100 milisegundos antes de enviar otra señal
  }
}
