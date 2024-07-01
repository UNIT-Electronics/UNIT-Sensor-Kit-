/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
https://blog.uelectronics.com/tarjetas-desarrollo/arduino/funcionamiento-de-los-sensores-de-inclinacion-ky-020-ky-027-y-ky-017/
*/

int ky17 = 7;       // Pin del sensor
int inclina;        // Variable para almacenar el estado del sensor

void setup() {
    Serial.begin(9600);     // Inicia el Monitor Serial a 9600 baudios
    pinMode(ky17, INPUT);   // Configura el pin del sensor como entrada
}

void loop() {
    inclina = digitalRead(ky17);   // Lee el estado digital del sensor y lo guarda en 'inclina'
    Serial.println(inclina);       // Imprime el valor de 'inclina' en el Monitor Serial
    delay(1000);                   // Espera 1 segundo antes de la próxima lectura
}
