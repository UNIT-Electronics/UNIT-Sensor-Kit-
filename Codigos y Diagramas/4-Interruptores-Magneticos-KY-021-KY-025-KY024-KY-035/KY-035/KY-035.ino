/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
  https://blog.uelectronics.com/tarjetas-desarrollo/comparacion-entre-interruptores-magneticos-ky-021-ky-025ky-024-y-ky-35/
*/
int senal = A0;                // Pin analógico A0 del Arduino para el KY-035
int valor;                     // Variable para guardar el valor leído por el sensor
int Led = 13;                  // Pin 13 para el LED

void setup() {
  Serial.begin(9600);           // Inicializa el puerto serial a 9600 baudios
  pinMode(senal, INPUT);        // Declara el pin senal como entrada analógica
  pinMode(Led, OUTPUT);         // Declara el pin Led como salida
}

void loop() {
  valor = analogRead(senal);              // Lee el valor del KY-035 y lo guarda en la variable valor
  Serial.println(valor);                  // Imprime el valor leído en el Monitor Serial
                                          // Esto ayuda a entender el comportamiento del sensor y los valores que arroja cuando detecta o no un imán
  delay(500);                             // La lectura se realiza cada medio segundo

  if (valor >= 518 && valor <= 528) {     // Si el valor está en el rango de 518 a 528, no hay presencia magnética
    Serial.println("NO hay Imán");        // Imprime "NO hay Imán" en el Monitor Serial
    digitalWrite(Led, LOW);               // Apaga el LED
  } else {                                // Si los valores analógicos están fuera de este rango
    Serial.println("Hay Imán");           // Imprime "Hay Imán" en el Monitor Serial
    digitalWrite(Led, HIGH);              // Enciende el LED
  }
}
