/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
  https://blog.uelectronics.com/tarjetas-desarrollo/como-utilizar-el-sensor-infrarrojo-emisor-ky-005-tutorial-funcionamiento/
*/

#include <IRremote.h>            // Incluye la librería IRremote para el control de IR

int recibe = 11;                 // Pin al que está conectado el módulo receptor IR KY-022, en el pin 11
IRrecv irrecv(recibe);           // Objeto para recibir paquetes IR utilizando el pin especificado
decode_results results;          // Variable para almacenar los resultados de la decodificación IR

void setup() {
  Serial.begin(9600);            // Inicia la comunicación serial a 9600 baudios
  irrecv.enableIRIn();           // Habilita la recepción de señales IR
}

void loop() {
  if (irrecv.decode(&results)) { // Si se ha recibido un código IR
    Serial.println(results.value, HEX);  // Imprime el valor recibido en formato hexadecimal
    irrecv.resume();             // Reinicia el receptor IR para recibir el siguiente código
  }
  delay(100);                    // Espera antes de volver a verificar la recepción de IR
}
