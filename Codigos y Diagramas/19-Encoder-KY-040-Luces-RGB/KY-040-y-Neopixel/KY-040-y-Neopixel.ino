/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
  https://blog.uelectronics.com/tarjetas-desarrollo/control-de-leds-mediante-modulo-sensor-encoder-ky-040/
 */
 
// Incluimos librerías necesarias para NeoPixel y configuraciones específicas para diferentes plataformas
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>      // Configuración específica para plataformas AVR
#endif

// Definimos los pines de conexión para el encoder KY-040 y NeoPixel
#define outCLK 2        // Salida A del encoder (CLK)
#define outDT 3         // Salida B del encoder (DT)
#define boton 4         // Salida del pulsador del encoder
#define led 5           // Pin de datos de salida para la NeoPixel
#define NUMPIXELS 16    // Número total de LEDs en la tira NeoPixel

Adafruit_NeoPixel pixels(NUMPIXELS, led, NEO_GRB + NEO_KHZ800); // Inicialización de la NeoPixel

int paso = 0;           // Variable para contabilizar los pasos del encoder
int edoCLK;             // Estado actual del pin CLK
int anteriorCLK;        // Estado anterior del pin CLK
int leds;               // Posición actual del LED encendido en la NeoPixel
int cuenta, dato;       // Variables para contar pulsos del encoder y guardar el dato

void setup() {
  Serial.begin(9600);   // Inicia la comunicación serial a 9600 baudios
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1); // Ajustes para plataformas específicas AVR a 16 MHz
  #endif
  
  pixels.begin();       // Inicialización de la NeoPixel
  pinMode(outCLK, INPUT);   // Configura el pin CLK del encoder como entrada
  pinMode(outDT, INPUT);    // Configura el pin DT del encoder como entrada
  pinMode(boton, INPUT_PULLUP); // Configura el pin del botón con resistencia pull-up
  
  anteriorCLK = digitalRead(outCLK); // Lee el estado inicial del pin CLK
}

void loop() {
  edoCLK = digitalRead(outCLK);   // Lee el estado actual del pin CLK
  
  if (edoCLK != anteriorCLK) {    // Si hay un cambio en el estado de CLK
    if (digitalRead(outDT) != edoCLK) {
      paso--;   // Si DT es diferente de CLK, el encoder gira a la derecha (decrementa paso)
    } else {
      paso++;   // Si DT es igual a CLK, el encoder gira a la izquierda (incrementa paso)
    }
    
    // Ajuste para asegurar que el paso esté en el rango válido de LEDs (0-15)
    if (paso >= 16) {
      paso = 0;
    } else if (paso < 0) {
      paso = 15;
    }
    
    leds = paso;   // Actualiza la posición del LED encendido
    
    Serial.print("Ubicación: ");   // Muestra la ubicación actual del encoder en el monitor serial
    Serial.println(paso);
  }
  
  anteriorCLK = edoCLK;   // Actualiza el estado anterior de CLK
  
  bool Bot = digitalRead(boton);   // Lee el estado del botón del encoder
  
  if (Bot == 0) {   // Si el botón está presionado (estado bajo)
    dato = cuenta++;   // Incrementa el contador de pulsos y guarda el dato actual del encoder
    delay(300);   // Espera para evitar rebotes del botón
    
    // Reinicia el contador de pulsos si supera el valor límite (en este caso 7)
    if (dato > 7) {
      cuenta = 0;
      dato = cuenta;
    }
  }
  
  color(dato, leds);   // Llama a la función para actualizar el color de la NeoPixel según dato y leds
}

// Función para manejar los colores de la NeoPixel en base al dato recibido
void color(int dato, int leds) {
  switch (dato) {
    case 1:
      pixels.setPixelColor(leds, pixels.Color(150, 0, 0));   // Rojo
      pixels.show();
      break;
    case 2:
      pixels.setPixelColor(leds, pixels.Color(0, 150, 0));   // Verde
      pixels.show();
      break;
    case 3:
      pixels.setPixelColor(leds, pixels.Color(0, 0, 150));   // Azul
      pixels.show();
      break;
    case 4:
      pixels.setPixelColor(leds, pixels.Color(150, 150, 0)); // Amarillo
      pixels.show();
      break;
    case 5:
      pixels.setPixelColor(leds, pixels.Color(150, 36, 0));  // Naranja
      pixels.show();
      break;
    case 6:
      pixels.setPixelColor(leds, pixels.Color(128, 0, 128)); // Morado
      pixels.show();
      break;
    case 7:
      pixels.setPixelColor(leds, pixels.Color(138, 43, 226)); // Blanco
      pixels.show();
      break;
    case 0:
      pixels.setPixelColor(leds, pixels.Color(0, 0, 0));     // Apagado
      pixels.show();
      break;
  }
}
