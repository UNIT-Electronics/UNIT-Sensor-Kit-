/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
  https://blog.uelectronics.com/tarjetas-desarrollo/arduino/detecta-tu-ritmo-cardiaco-a-traves-del-ky-039/
 */
 
int ky039 = A0;           // Pin analógico para la señal del sensor KY039
int latido = 0;           // Contador de latidos por ciclo
int rangoT;               // Variable para almacenar los valores brutos del KY039
int lateMin = 300;        // Umbral mínimo para calcular el número de latidos por minuto

double factor = 0.75;     // Constante para el filtro paso bajo (EMA)
double minval = 0.0;      // Valor mínimo de la señal filtrada
double VFiltrado;         // Valor filtrado por el filtro paso bajo (EMA)
double cambio;            // Cambio entre el valor filtrado actual y el anterior

float antes = 512;        // Valor de referencia (mitad de 1023) para el valor filtrado anterior (An-1)
float maxval = 0.0;       // Valor máximo de la señal filtrada

void setup() {
  Serial.begin(9600);    // Inicialización del puerto serial a 9600 baudios
  pinMode(13, OUTPUT);   // Configuración del pin 13 como salida para indicador LED
}

void loop() {
  static unsigned long LPMtime = millis();  // Tiempo actual en milisegundos para calcular latidos por minuto
  static unsigned long LPMQR = millis();    // Tiempo actual en milisegundos para medir intervalos entre latidos

  rangoT = analogRead(ky039);  // Lectura del valor analógico del sensor KY039 (0 a 1023)

  // Filtrado de la señal utilizando un filtro paso bajo (EMA)
  VFiltrado = factor * antes + (1 - factor) * rangoT;  // Filtro paso bajo (EMA)
  cambio = VFiltrado - antes;                          // Cálculo del cambio entre el valor filtrado y el anterior
  antes = VFiltrado;                                   // Actualización del valor anterior con el valor filtrado actual

  // Condición para detectar un latido (pico de señal)
  if ((cambio >= maxval) && (millis() > LPMQR + minval)) {
    maxval = cambio;          // Actualiza el valor máximo con el cambio detectado
    digitalWrite(13, HIGH);   // Enciende el LED en el pin 13 para indicar detección de latido
    LPMQR = millis();         // Actualiza el tiempo del último latido detectado
    latido++;                 // Incrementa el contador de latidos
  } else {
    digitalWrite(13, LOW);    // Apaga el LED en el pin 13 si no se detecta latido
  }

  maxval = maxval * 0.97;     // Decaimiento del 3% en el valor máximo de la señal

  // Condición para calcular latidos por minuto (LPM)
  if (millis() >= LPMtime + 15000) {  // Si han pasado al menos 15 segundos desde el último cálculo
    int LPM = latido * 4;            // Calcula los latidos por minuto multiplicando los latidos por 4
    Serial.print("LPM: ");           // Imprime el valor calculado de latidos por minuto
    Serial.println(LPM);             
    latido = 0;                      // Reinicia el contador de latidos
    LPMtime = millis();              // Actualiza el tiempo para el próximo cálculo de LPM
  }

  delay(50);  // Pequeña pausa para actualizar el ciclo
}
