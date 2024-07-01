/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
  https://blog.uelectronics.com/tarjetas-desarrollo/comparacion-entre-interruptores-magneticos-ky-021-ky-025ky-024-y-ky-35/
*/

int Led = 13;             // Define el pin 13 de la tarjeta UNO R3 para el LED
int ky21 = 2;             // Define el pin 2 digital para el sensor magnético KY-021
int interruptor;          // Variable 'interruptor' para guardar el dato del KY-021

void setup() {
  Serial.begin(9600);       // Inicializa el puerto serial a 9600 baudios
  pinMode(Led, OUTPUT);     // Declara el pin 13 como salida
  pinMode(ky21, INPUT);     // Declara el pin 2 (KY-021) como entrada
}

void loop() {
  interruptor = digitalRead(ky21);  // Lee el estado del KY-021 y asigna el valor a 'interruptor'
  Serial.println(interruptor);      // Imprime el valor leído por el KY-021 en el Monitor Serial
                                    // Se comprobó que en estado de reposo el sensor arroja un 1 lógico
  if (interruptor == HIGH) {        // Si el valor es alto (1), apaga el LED
    digitalWrite(Led, LOW);
  } else {                          // De lo contrario, si detecta un imán (valor bajo, 0)
    digitalWrite(Led, HIGH);        // Enciende el LED
    Serial.println("Campo magnético detectado");  // Imprime mensaje en el Monitor Serial
  }
}
