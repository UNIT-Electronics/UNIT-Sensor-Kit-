/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
  https://blog.uelectronics.com/tarjetas-desarrollo/control-de-leds-mediante-modulo-sensor-encoder-ky-040/
 */
 
#define outCLK 2       // Definición del pin de salida CLK/A del encoder
#define outDT 3        // Definición del pin de salida DT/B del encoder
#define boton 4        // Definición del pin del pulsador del encoder

int paso = 0;           // Variable para contabilizar los pasos del encoder
int edoCLK;             // Estado actual del pin CLK/A
int anteriorCLK;        // Estado anterior del pin CLK/A

void setup() {
  Serial.begin(9600);                     // Inicialización del puerto serial a 9600 baudios
  pinMode(outCLK, INPUT);                 // Pin de entrada CLK/A del encoder
  pinMode(outDT, INPUT);                  // Pin de entrada DT/B del encoder
  pinMode(boton, INPUT_PULLUP);           // Configuración del pulsador con resistencia pull-up interna
  
  anteriorCLK = digitalRead(outCLK);      // Lectura inicial del estado de CLK/A
}

void loop() {
  edoCLK = digitalRead(outCLK);           // Lectura del estado actual de CLK/A
  
  if (edoCLK != anteriorCLK) {            // Si hay un cambio en el estado de CLK/A
    if (digitalRead(outDT) != edoCLK) {   // Verifica el estado de DT/B para determinar dirección
      paso--;                             // Si DT/B es diferente a CLK/A, el encoder gira a la derecha (incremento negativo)
    } else {
      paso++;                             // Si DT/B es igual a CLK/A, el encoder gira a la izquierda (incremento positivo)
    }
    Serial.print("Ubicación: ");           // Impresión en el monitor serial para mostrar la ubicación actual del encoder
    Serial.println(paso);                  
  }
  
  anteriorCLK = edoCLK;                   // Actualiza el estado anterior de CLK/A
  
  bool Bot = digitalRead(boton);          // Lee el estado del pulsador del encoder
  
  if (!Bot) {                             // Si el pulsador está presionado (estado bajo)
    Serial.println("Botón pulsado: Reinicia a 0");  // Muestra un mensaje indicando que se reinicia el conteo de pasos
    paso = 0;                             // Reinicia el contador de pasos a 0
    delay(300);                            // Espera 300 milisegundos para evitar rebotes
  }
}
