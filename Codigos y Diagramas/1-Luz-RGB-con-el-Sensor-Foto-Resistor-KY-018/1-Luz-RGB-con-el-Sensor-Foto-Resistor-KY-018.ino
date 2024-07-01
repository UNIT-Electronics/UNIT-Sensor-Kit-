/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.
  
  Para más información, visita nuestro blog:
  https://blog.uelectronics.com/tarjetas-desarrollo/arduino/realiza-un-modulador-de-luz-rgb-con-el-sensor-foto-resistor-ky-018/
*/

int ky18 = 2;            // Define Pin 2 analógico para la entrada de datos analógicos del sensor KY-018
int LedR = 11;           // Define PWM Pin 11 para el LED Rojo (R)
int LedV = 10;           // Define PWM Pin 10 para el LED Verde (G)
int LedA = 9;            // Define PWM Pin 9 para el LED Azul (B)
int valor;               // La variable 'valor' almacenará los datos del sensor KY-018
int luz;                 // La variable 'luz' almacenará los valores que tendrán los LEDs (0-255)

void setup() {
  Serial.begin(9600);        // Inicia el puerto serial a 9600 baudios
  pinMode(ky18, INPUT);      // Declara el pin ky18 como entrada
  pinMode(LedR, OUTPUT);     // Declara el pin LedR como salida
  pinMode(LedA, OUTPUT);     // Declara el pin LedA como salida
  pinMode(LedV, OUTPUT);     // Declara el pin LedV como salida
}

void loop() {
  // Reinicia los valores de los LEDs RGB al comenzar la rutina
  analogWrite(LedR, 0);      // Los valores de los LEDs van de 0 (menor intensidad) a 255 (mayor intensidad)
  analogWrite(LedV, 0);
  analogWrite(LedA, 0);

  valor = analogRead(ky18);  // Guarda en la variable 'valor' los datos del sensor fotoresistor
  Serial.println(valor, DEC); // Imprime la intensidad de luz; valores altos = oscuridad, valores bajos = alta iluminación

  // Asigna valores a 'luz' dependiendo de los datos del sensor usando la función map
  luz = map(valor, 4, 1018, 0, 255);

  Serial.print("luz: ");     // Imprime el mensaje "luz" y...
  Serial.println(luz);       // ... el valor registrado por la función map

  // Los valores de los LEDs Rojo, Verde y Azul serán variables según la información de 'luz'
  analogWrite(LedR, luz);
  analogWrite(LedV, luz);
  analogWrite(LedA, luz);

  delay(500);                // El proceso durará medio segundo
}
