/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
  https://blog.uelectronics.com/tarjetas-desarrollo/arduino/indicador-de-cierre-y-apertura-con-el-sensor-foto-interruptor-ky-010-y-led-bicolor-ky-011/
*/

int ky010 = 8;            // Define el pin para el fotointerruptor KY-010
int val;                  // Define la variable 'val' que almacenará los datos del KY-010

void setup() {
  pinMode(9, OUTPUT);       // Define el pin 9 como salida para el LED Rojo
  pinMode(6, OUTPUT);       // Define el pin 6 como salida para el LED Verde
  pinMode(ky010, INPUT);    // Define el pin ky010 como entrada para el fotointerruptor KY-010
}

void loop() {
  val = digitalRead(ky010);  // Lee el estado del fotointerruptor y asigna el valor a 'val'

  if (val == HIGH) {         // Si el KY-010 está bloqueado (val == 1)
    analogWrite(9, 255);     // Enciende el LED Rojo (valor máximo de 255)
    analogWrite(6, 0);       // Apaga el LED Verde (valor de 0)
    delay(1000);             // Mantén el estado por 1 segundo
  } else {                   // De lo contrario (val == 0)
    analogWrite(9, 0);       // Apaga el LED Rojo (valor de 0)
    analogWrite(6, 255);     // Enciende el LED Verde (valor máximo de 255)
    delay(1000);             // Mantén el estado por 1 segundo
  }
}
