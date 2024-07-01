/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
  https://blog.uelectronics.com/tarjetas-desarrollo/comparacion-entre-interruptores-magneticos-ky-021-ky-025ky-024-y-ky-35/
*/

int Led = 12;                  // Pin 12 para el LED
int Dky25 = 3;                 // Pin para la interfaz digital del KY-025
int Aky25 = A0;                // Pin para la interfaz analógica del KY-025
int D;                         // Variable para almacenar valores digitales del KY-025

void setup() {
  pinMode(Led, OUTPUT);        // Declara el pin 12 como salida para el LED
  pinMode(Dky25, INPUT);       // Declara el pin Dky25 como entrada digital
  Serial.begin(9600);          // Inicialización del puerto serial a 9600 baudios
}

void loop() {
  Serial.print("Digital");                // Imprime "Digital" en el Monitor Serial para identificar...
  Serial.print("-");                      // ...los valores de lectura por puerto digital o...
  Serial.println("Analógico");            // ...analógico
  Serial.print(digitalRead(Dky25));       // Imprime los valores provenientes del pin digital
  Serial.print("-");
  Serial.println(analogRead(Aky25));      // Imprime los valores provenientes del pin analógico 

  D = digitalRead(Dky25);                 // Lee el valor del pin digital Dky25 y lo guarda en la variable D

  if (D == 0) {                           // Si D es igual a 0 (no hay detección de imán)
    digitalWrite(Led, LOW);               // Apaga el LED
  } else {                                // Si D es diferente de 0 (hay detección de imán, D = 1)
    digitalWrite(Led, HIGH);              // Enciende el LED
    delay(8000);                          // Espera 8 segundos (8000 milisegundos)
  }
}
