/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
  https://blog.uelectronics.com/tarjetas-desarrollo/sensores-de-temperatura-ky-028-y-ky-013/
*/

int ledR = 10;       // Pin del LED Rojo del módulo KY-029
int ledV = 9;        // Pin del LED Verde del módulo KY-029
int ky013 = A0;      // Pin de entrada analógica para el termistor KY-013
int valor;           // Variable para almacenar los datos de entrada del KY-013

// Variables para la ecuación Steinhart-Hart
float R1 = 10000;    // Valor de la resistencia R1 en la PCB (10k ohmios)
float logR2, R2, TK, TC;  // Variables para los cálculos de la ecuación Steinhart-Hart
float A = 0.001129148, B = 0.000234125, C = 0.0000000876741; // Coeficientes de la ecuación Steinhart-Hart para un NTC de 10k ohmios y temperaturas de -55°C a 125°C

void setup() {
  Serial.begin(9600);             // Inicialización del puerto serial
  pinMode(ledR, OUTPUT);          // Configuración del pin del LED Rojo como salida
  pinMode(ledV, OUTPUT);          // Configuración del pin del LED Verde como salida
}

void loop() {
  valor = analogRead(ky013);      // Lectura del valor analógico del termistor y asignación a la variable 'valor'
  Serial.print("Valor Analógico:"); // Impresión del texto "Valor Analógico:"
  Serial.println(valor);          // Impresión del valor leído (0-1023), útil para conocer el rango de reposo del termistor

  // Mapeo del valor analógico a un rango de temperatura en grados Celsius
  valor = map(valor, 0, 650, -55, 125); // Mapeo del rango de entrada (0-650) al rango de temperatura (-55 a 125 °C)
  
  // Conversión de valores analógicos a grados Celsius
  R2 = R1 * (1023.0 / (float)valor - 1.0); // Cálculo de la resistencia del termistor
  logR2 = log(R2);  // Cálculo del logaritmo de la resistencia del termistor
  TK = (1.0 / (A + B * logR2 + C * logR2 * logR2 * logR2)); // Cálculo de la temperatura en Kelvin usando la ecuación Steinhart-Hart
  TC = TK - 273.15; // Conversión de la temperatura de Kelvin a Celsius
  TC = TC * (-1);   // Inversión del valor de la temperatura Celsius
  Serial.print("Temperatura es:"); // Impresión del texto "Temperatura es:"
  Serial.println(TK);  // Impresión del valor de la temperatura en Celsius
  
  delay(500);  // Pausa de medio segundo
  
  digitalWrite(ledR, LOW);  // Apagado del LED Rojo
  digitalWrite(ledV, LOW);  // Apagado del LED Verde
  
  if (TC >= 23) {  // Si la temperatura es mayor o igual a 23°C
    digitalWrite(ledR, HIGH); // Encendido del LED Rojo
  } else {  // Si la temperatura es menor a 23°C
    digitalWrite(ledV, HIGH); // Encendido del LED Verde
  }
}
