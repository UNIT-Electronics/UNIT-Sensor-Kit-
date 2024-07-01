/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
  https://blog.uelectronics.com/tarjetas-desarrollo/arduino/control-de-servomotores-sg90-con-modulo-ky-023-sensor-joystick/
 */
#include <Servo.h>     // Incluimos la librería para controlar el servo

Servo SX;             // Servo para el eje X (derecha-izquierda)
Servo SY;             // Servo para el eje Y (arriba-abajo)

// Declaración de pines analógicos para el joystick del módulo KY-023
int JoyX = 0;         // Pin analógico del joystick RX conectado a A0
int JoyY = 1;         // Pin analógico del joystick RY conectado a A1

int valX;             // Variable para almacenar los valores del eje X del joystick
int valY;             // Variable para almacenar los valores del eje Y del joystick

// Valores máximos y mínimos del joystick para los ejes X e Y
int Valor_Xmax = 1023; // Valor máximo del eje X (para el lado izquierdo)
int Valor_Xmin = 0;    // Valor mínimo del eje X (para el lado derecho)
int Valor_Ymax = 1023; // Valor máximo del eje Y (para apuntar hacia arriba)
int Valor_Ymin = 0;    // Valor mínimo del eje Y (para apuntar hacia abajo)

void setup() {
  Serial.begin(9600);  // Iniciamos la comunicación serial a 9600 baudios para la depuración
  SX.attach(5);        // Asociamos el servo SX al pin PWM D5
  SY.attach(6);        // Asociamos el servo SY al pin PWM D6
}

void loop() {
  valX = analogRead(JoyX);  // Leemos el valor actual del joystick en el eje X
  valY = analogRead(JoyY);  // Leemos el valor actual del joystick en el eje Y

  // Determinamos los rangos de valores máximos y mínimos para los ejes X e Y
  if (valX > 511) {                   // Movimiento del eje X hacia la izquierda desde el centro (valor 511)
    Valor_Xmax = 1023 - valX + 511;   // Nuevo valor máximo del eje X
    Valor_Xmin = 0;                   // Mantenemos el valor mínimo del eje X
  } else if (valX < 511) {            // Movimiento del eje X hacia la derecha desde el centro (valor 511)
    Valor_Xmax = 1023;                // Mantenemos el valor máximo del eje X
    Valor_Xmin = 511 - valX;          // Nuevo valor mínimo del eje X
  }

  if (valY > 511) {                   // Movimiento del eje Y hacia arriba desde el centro (valor 511)
    Valor_Ymax = 1023 - valY + 511;   // Nuevo valor máximo del eje Y
    Valor_Ymin = 0;                   // Mantenemos el valor mínimo del eje Y
  } else if (valY < 511) {            // Movimiento del eje Y hacia abajo desde el centro (valor 511)
    Valor_Ymax = 1023;                // Mantenemos el valor máximo del eje Y
    Valor_Ymin = 511 - valY;          // Nuevo valor mínimo del eje Y
  }

  // Mapeamos los valores leídos del joystick a un rango de 0 a 180 grados para los servos
  valX = map(valX, Valor_Xmin, Valor_Xmax, 0, 180);  // Mapeo del eje X al rango del servo (0° a 180°)
  SX.write(valX);                                   // Enviamos el ángulo calculado al servo SX

  valY = map(valY, Valor_Ymin, Valor_Ymax, 0, 180);  // Mapeo del eje Y al rango del servo (0° a 180°)
  SY.write(valY);                                   // Enviamos el ángulo calculado al servo SY

  delay(50);  // Pequeña pausa antes de la siguiente lectura del joystick
}
