/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
  https://blog.uelectronics.com/tarjetas-desarrollo/arduino/control-de-un-servomotor-sg90-con-el-sensor-push-button-ky-004/
 */

#include <Servo.h>             // Incluimos la librería para el control del servo SG90

Servo sg90;                    // Creamos un objeto servo llamado sg90
int ky04 = 8;                  // Pin de entrada para detectar la pulsación del botón
int boton;                     // Variable para almacenar el estado del botón (0 = presionado, 1 = no presionado)

void setup() {
  Serial.begin(9600);          // Iniciamos la comunicación serial a 9600 baudios
  pinMode(ky04, INPUT);        // Configuramos el pin del botón como entrada
  sg90.attach(10);             // Asociamos el pin 10 al servo sg90
  sg90.write(0);               // Inicializamos el servo en posición inicial (0 grados)
}

void loop() {
  boton = digitalRead(ky04);   // Leemos el estado del botón y lo almacenamos en la variable 'boton'

  if (boton == LOW) {          // Si el botón está presionado (nivel bajo)
    // Abre el servo (sentido antihorario)
    for (int i = 0; i <= 180; i++) {   // Incrementa el ángulo de 0 a 180 grados
      sg90.write(i);                  // Envía el ángulo al servo
      delay(5);                       // Pequeña pausa para suavizar el movimiento
      Serial.println(i);              // Imprime el ángulo actual en el puerto serial
    }

    // Cierra el servo (sentido horario)
    for (int i = 180; i > 0; i--) {    // Decrementa el ángulo de 180 a 0 grados
      sg90.write(i);                  // Envía el ángulo al servo
      delay(20);                      // Pausa más larga para un movimiento más lento
      Serial.println(i);              // Imprime el ángulo actual en el puerto serial
    }
  } else {                        // Si el botón no está presionado (nivel alto)
    sg90.write(0);                // Vuelve el servo a la posición inicial (0 grados)
  }
}
