/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
  https://blog.uelectronics.com/tarjetas-desarrollo/arduino/visualizacion-de-datos-del-sensor-temperatura-ky-001-en-un-display-oled-ssd1306/
*/

// Incluimos las librerías necesarias
#include <OneWire.h>                   // Librería para el bus OneWire del DS18B20
#include <Adafruit_GFX.h>              // Librería para gráficos básicos (Adafruit graphics library)
#include <Adafruit_SSD1306.h>          // Librería para pantallas OLED basadas en SSD1306
#include <DallasTemperature.h>         // Librería para la lectura del sensor de temperatura DS18B20

#define ONE_WIRE_BUS 10                // Pin al que está conectado el bus OneWire
#define OLED_RESET 13                  // Pin de reset del display OLED

OneWire oneWire(ONE_WIRE_BUS);         // Objeto OneWire para la comunicación con el sensor DS18B20
DallasTemperature celsius(&oneWire);   // Objeto para la lectura de temperatura
float temp;                            // Variable para almacenar la temperatura

Adafruit_SSD1306 display(OLED_RESET);  // Objeto para controlar la pantalla OLED

void setup() {
  celsius.begin();                             // Inicializa la comunicación con el sensor DS18B20
  Serial.begin(9600);                          // Inicializa la comunicación serial a 9600 baudios
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);   // Inicia la comunicación I2C con la pantalla OLED (0x3C para 128x32)

  // Verificación de la altura de la pantalla OLED
#if (SSD1306_LCDHEIGHT != 32)
#error("Altura incorrecta, cambie en la librería de Adafruit_SSD1306.h!");
#endif
}

void loop() {
  display.clearDisplay();         // Borra el buffer de la pantalla OLED
  display.setTextSize(2);         // Establece el tamaño de la fuente
  display.setTextColor(WHITE);    // Establece el color del texto

  celsius.requestTemperatures();  // Solicita la temperatura al sensor DS18B20
  temp = celsius.getTempCByIndex(0); // Obtiene la temperatura en grados Celsius

  // Muestra la temperatura en la pantalla OLED
  display.setCursor(0, 0);
  display.println("~~~~~~~~~~");
  display.setCursor(0, 5);
  display.println("Temp:");
  display.setCursor(55, 10);
  display.println(temp);
  display.setCursor(115, 10);
  display.println("C");
  display.setCursor(0, 27);
  display.println("~~~~~~~~~~");
  display.display();  // Muestra los cambios en la pantalla OLED

  // Muestra la temperatura en el puerto serial
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println(" C");

  delay(2000);  // Espera 2 segundos antes de la siguiente lectura
}
