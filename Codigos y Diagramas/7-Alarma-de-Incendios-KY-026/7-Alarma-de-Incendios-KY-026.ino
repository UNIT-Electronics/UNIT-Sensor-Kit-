/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
https://blog.uelectronics.com/tarjetas-desarrollo/alarma-de-incendios-con-modulo-ky-026/
*/

int KY026a = A0, BUZZ = 11, valor, KY026d = 2;   // Declaración de las variables y pines utilizados

void setup() {
  Serial.begin(9600);                           // Inicialización del puerto serial a 9600 baudios
  pinMode(KY026d, INPUT);                       // Configuración del pin de entrada DIGITAL del sensor KY-026
  pinMode(KY026a, INPUT);                       // Configuración del pin de entrada ANALÓGICA del sensor KY-026
  pinMode(BUZZ, OUTPUT);                        // Configuración del pin de salida para el buzzer
}

void loop() {
  valor = analogRead(KY026a);       // Lectura del valor analógico del sensor KY-026 y asignación a la variable 'valor'
  Serial.println(valor);            // Impresión del valor analógico en el monitor serial
  delay(500);                       // Espera 0.5 segundos antes de continuar

  valor = digitalRead(KY026d);      // Lectura del valor digital del sensor KY-026 y asignación a la variable 'valor'
  Serial.println(valor);            // Impresión del valor digital en el monitor serial

  if (valor == 1) {                 // Si el valor digital es HIGH (1), indicando presencia de fuego
    digitalWrite(BUZZ, HIGH);       // Se activa el buzzer como alarma
    delay(4000);                    // El buzzer se mantiene activado durante 4 segundos
    digitalWrite(BUZZ, LOW);        // Se desactiva el buzzer después del tiempo establecido
  } else {
    digitalWrite(BUZZ, LOW);        // Si no hay presencia de fuego, el buzzer se mantiene apagado
  }
}
