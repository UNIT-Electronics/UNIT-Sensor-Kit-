/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
  https://blog.uelectronics.com/tarjetas-desarrollo/arduino/sensor-magnetico-ky-003/
*/

int laser = 13;      // Pin de salida digital para el módulo KY-008 Laser
int ky03 = 9;        // Pin de entrada para el sensor de campo magnético KY-003
int iman;             // Variable para almacenar el estado del sensor (0 = sin campo magnético, 1 = detecta campo magnético)

void setup() {
  Serial.begin(9600);         // Inicializa la comunicación serial a 9600 baudios
  pinMode(ky03, INPUT);       // Configura el pin del sensor KY-003 como entrada
  pinMode(laser, OUTPUT);     // Configura el pin del láser como salida
}

void loop() {
  iman = digitalRead(ky03);   // Lee el estado del pin del sensor y lo guarda en la variable 'iman'
  Serial.println(iman);       // Imprime en el Monitor Serial el estado del sensor (0 o 1)

  if (iman == HIGH) {         // Si el sensor detecta un campo magnético (estado alto)
    digitalWrite(laser, LOW); // El láser no emite luz y el LED L13 del Arduino no se enciende
  } else {                    // Si no detecta un campo magnético (estado bajo)
    digitalWrite(laser, HIGH);// El láser emite luz y el LED L13 del Arduino se enciende
  }

  delay(100);                 // Pequeña pausa para estabilizar la lectura y el proceso
}
