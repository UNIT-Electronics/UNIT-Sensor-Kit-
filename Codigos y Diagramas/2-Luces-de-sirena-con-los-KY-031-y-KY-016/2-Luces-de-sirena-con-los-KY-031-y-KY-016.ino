/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
  https://blog.uelectronics.com/tarjetas-desarrollo/arduino/crea-un-sistema-con-el-sensor-de-impacto-y-luces-de-sirena-con-los-modulos-ky-031-y-ky-016/
*/

int ky31 = 3;             // Pin para el módulo de impacto KY-031
int LR = 11;              // Pin para el LED Rojo del módulo KY-016
int LA = 10;              // Pin para el LED Azul del módulo KY-016
int LV = 9;               // Pin para el LED Verde del módulo KY-016
int valor;                // Variable para guardar el dato del KY-031

void setup() {
  Serial.begin(9600);         // Inicializa el Monitor Serial a 9600 baudios
  pinMode(ky31, INPUT);       // Declara el pin ky31 como entrada
  pinMode(LR, OUTPUT);        // Declara el pin LR como salida
  pinMode(LA, OUTPUT);        // Declara el pin LA como salida
  pinMode(LV, OUTPUT);        // Declara el pin LV como salida
}

void loop() {
  valor = digitalRead(ky31);  // Asigna el dato registrado por el KY-031 a la variable 'valor'

  if (valor == LOW) {         // Si 'valor' está en estado BAJO (LOW/0)
    Serial.print("Inactivo");    // Imprime "Inactivo" en el Monitor Serial
    Serial.println(valor);       // Imprime el valor registrado
    digitalWrite(LA, LOW);       // Apaga el LED Azul
    digitalWrite(LV, HIGH);      // Enciende el LED Verde
    digitalWrite(LR, LOW);       // Apaga el LED Rojo
  } else {                     // Si 'valor' está en estado ALTO (HIGH/1)
    Serial.print("Sirena");       // Imprime "Sirena" en el Monitor Serial
    for (int t = 0; t < 10; t++) { // Loop de 10 repeticiones de la secuencia de colores
      digitalWrite(LA, LOW);      // Enciende el LED Rojo
      digitalWrite(LV, LOW);
      digitalWrite(LR, HIGH);
      delay(100);                // Duración del LED Rojo encendido (0.1 segundos)
      
      digitalWrite(LA, HIGH);    // Enciende el LED Azul
      digitalWrite(LV, LOW);
      digitalWrite(LR, LOW);
      delay(100);                // Duración del LED Azul encendido (0.1 segundos)
      
      digitalWrite(LA, LOW);     // Apaga todos los LEDs
      digitalWrite(LV, LOW);
      digitalWrite(LR, LOW);
    }
  }
}
