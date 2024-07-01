/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
  https://blog.uelectronics.com/tarjetas-desarrollo/visualizar-los-datos-del-sensor-de-humedad-y-temperatura-ky-015/
*/

#include <DHT.h>                 // Incluimos la librería DHT para el sensor de humedad y temperatura
#include <Adafruit_GFX.h>        // Librería para gráficos en dispositivos como pantallas OLED
#include <Adafruit_SSD1306.h>    // Librería para controlar pantallas OLED basadas en el controlador SSD1306

#define OLED_RESET 13            // Pin de reset para la pantalla OLED
#define DHTTYPE 11               // Tipo de sensor DHT (DHT11 en este caso)
#define DHTPIN 8                 // Pin al que está conectado el sensor DHT11
float h, t;                       // Variables para almacenar humedad y temperatura

Adafruit_SSD1306 display(OLED_RESET);   // Objeto para controlar la pantalla OLED

// Verificación de la altura de la pantalla OLED (debe ser 32 para la pantalla de 128x32 píxeles)
#if (SSD1306_LCDHEIGHT != 32)
#error("Altura incorrecta, cambie en la librería de Adafruit_SSD1306.h!");
#endif

DHT dht(DHTPIN, DHTTYPE);     // Creación de un objeto DHT para interactuar con el sensor

void setup() {
  Serial.begin(9600);         // Inicia la comunicación serial a 9600 baudios
  dht.begin();                // Inicia el sensor DHT
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Inicia la comunicación I2C con la pantalla OLED (0x3C es la dirección I2C predeterminada)
}

void loop() {
  display.clearDisplay();     // Borra el contenido anterior en la pantalla OLED
  display.setTextSize(1);     // Establece el tamaño de la fuente
  display.setTextColor(WHITE);  // Establece el color del texto

  h = dht.readHumidity();     // Lee la humedad del sensor DHT
  t = dht.readTemperature();  // Lee la temperatura del sensor DHT

  // Muestra la humedad en la pantalla OLED
  display.setCursor(0, 10);   // Establece la posición del texto
  display.println("Humedad");
  display.setCursor(60, 10);  // Establece la posición del valor de la humedad
  display.println(h);         // Muestra el valor de la humedad
  display.setCursor(0, 20);   // Establece la posición del texto
  display.println("Temperatura");
  display.setCursor(80, 20);  // Establece la posición del valor de la temperatura
  display.println(t);         // Muestra el valor de la temperatura
  display.setCursor(110, 20); // Establece la posición de la unidad de temperatura (Celsius)
  display.println("C");
  display.setCursor(0, 30);   // Establece la posición para una línea separadora
  display.println("********************************************************************");
  display.display();          // Actualiza la pantalla para mostrar los cambios

  // Muestra los valores de humedad y temperatura en el Monitor Serie
  Serial.print("Humedad: "); Serial.print(h); Serial.println(" %");
  Serial.print("Temperatura: "); Serial.print(t); Serial.println(" C");

  delay(2000);                // Espera 2 segundos antes de la siguiente lectura
}
