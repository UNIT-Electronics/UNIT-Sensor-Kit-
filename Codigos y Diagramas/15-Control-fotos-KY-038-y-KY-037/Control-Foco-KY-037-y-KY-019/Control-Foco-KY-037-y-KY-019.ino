/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
  https://blog.uelectronics.com/tarjetas-desarrollo/uso-de-los-sensores-de-sonido-ky-038-ky-037-para-controlar-el-encendido-de-un-foco/
*/

// Nota: Ajustar la sensibilidad del micrófono con el trimpot

int reley = 13;    // Pin 13 para controlar el relé que activará el foco
int KY037 = 4;     // Pin 4 para la salida digital del sensor KY-037
int FlancoKY = 0;  // Variable para contar los flancos detectados por el sensor

void setup() {
  Serial.begin(9600);        // Inicialización del puerto serial a 9600 baudios
  pinMode(reley, OUTPUT);    // Configura el pin del relé como salida
  pinMode(KY037, INPUT);     // Configura el pin del KY-037 como entrada para recibir datos
}

void loop() {
  if (digitalRead(KY037) == HIGH) {   // Si se detecta un sonido (nivel alto en el pin del KY-037)
    FlancoKY++;                      // Incrementa el contador de flancos
    Serial.print("Número de Flancos: ");  // Imprime un mensaje indicando el número de flancos detectados
    Serial.println(FlancoKY, DEC);         // Imprime el valor actual del contador en formato decimal

    if (FlancoKY == 4) {              // Si el contador llega a 4 (valor calibrado según el sistema)
      Serial.println(FlancoKY);      // Imprime el valor del flanco = 4
      digitalWrite(reley, HIGH);     // Activa el relé para encender el foco
    } else if (FlancoKY == 8) {       // Si el contador llega a 8 (indicando un nuevo ciclo de detección)
      Serial.println(FlancoKY);      // Imprime el valor del flanco = 8
      digitalWrite(reley, LOW);      // Desactiva el relé para apagar el foco
      FlancoKY = 0;                  // Reinicia el contador de flancos para el siguiente ciclo
    }
  }
}
