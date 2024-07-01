/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
https://blog.uelectronics.com/tarjetas-desarrollo/arduino/funcionamiento-de-los-sensores-de-inclinacion-ky-020-ky-027-y-ky-017/
*/

#define buzz 9   // Definimos el pin del Buzzer Activo
#define ky20 7    // Definimos el pin del sensor
int inclina;       // Variable para almacenar el estado del sensor

void setup() {
  Serial.begin(9600);        // Inicialización del Monitor Serial a 9600 baudios
  pinMode(buzz, OUTPUT);     // Configuración del Buzzer como dispositivo de salida
  pinMode(ky20, INPUT);      // Configuración del pin del sensor como entrada
}

void loop() {
  inclina = digitalRead(ky20);      // Lectura del estado digital del sensor y asignación a 'inclina'
  Serial.println(inclina);          // Impresión del valor de 'inclina' en el Monitor Serial
  delay(1000);                      // Retardo de 1 segundo
  
  if (inclina == 1) {               // Si el sensor detecta un estado alto (HIGH)
    digitalWrite(buzz, HIGH);       // Se activa el Buzzer
  } else {                          // Si el sensor no detecta un estado alto (LOW)
    digitalWrite(buzz, LOW);        // Se apaga el Buzzer
  }
}
