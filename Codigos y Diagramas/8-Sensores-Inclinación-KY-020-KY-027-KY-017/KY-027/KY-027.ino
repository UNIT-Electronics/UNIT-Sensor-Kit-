/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
https://blog.uelectronics.com/tarjetas-desarrollo/arduino/funcionamiento-de-los-sensores-de-inclinacion-ky-020-ky-027-y-ky-017/
*/

int ky27L = 5;      // Pin del LED del sensor
int ky27 = 7;       // Pin de entrada del sensor
int inclina;        // Variable para almacenar el estado del sensor

void setup() {
  Serial.begin(9600);       // Inicia el Monitor Serial a 9600 baudios
  pinMode(ky27L, OUTPUT);   // Configura el pin del LED como salida
  pinMode(ky27, INPUT);     // Configura el pin del sensor como entrada
}

void loop() {
  inclina = digitalRead(ky27);       // Lee el estado digital del sensor y lo asigna a 'inclina'
  Serial.println(inclina);           // Imprime el estado del sensor en el Monitor Serial
  delay(1000);                       // Espera 1 segundo
  
  if (inclina == 1) {                // Si el sensor detecta inclinación (estado HIGH)
    digitalWrite(ky27L, HIGH);       // Enciende el LED del sensor
  } else {                           // Si no hay inclinación detectada (estado LOW)
    digitalWrite(ky27L, LOW);        // Apaga el LED del sensor
  }
}
