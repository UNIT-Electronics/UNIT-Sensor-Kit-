/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
https://blog.uelectronics.com/tarjetas-desarrollo/arduino/uso-del-sensor-de-vibracion-ky-002-como-alarma/
*/

int buzz = 13;    // Definimos el pin del Buzzer, conectado al pin digital 13 (auxiliar es salida del Led13 en la PCB del Arduino)
int ky02 = 9;     // Definimos el pin de detección de vibración
int alarma;       // Variable para almacenar el estado del sensor (0: detecta vibración, 1: sin perturbación)

void setup() {
  pinMode(ky02, INPUT);   // Configuramos el pin del sensor de vibración como entrada
  pinMode(buzz, OUTPUT);  // Configuramos el pin del Buzzer como salida
}

void loop() {
  alarma = digitalRead(ky02);   // Leemos el estado digital del pin conectado al sensor y lo asignamos a 'alarma'
  
  if (alarma == HIGH) {         // Si el sensor está sin perturbación (estado HIGH)
    digitalWrite(buzz, LOW);    // El Buzzer está apagado
    // El LED L13 del Arduino también estará apagado si está conectado al mismo pin
  } else {                      // Si el sensor detecta vibración (estado LOW)
    tone(buzz, 1479, 1000);     // Se activa el Buzzer con un tono de 1479Hz durante 1000 milisegundos (1 segundo)
    digitalWrite(buzz, HIGH);   // Se enciende el Buzzer
    // El LED L13 del Arduino también estará encendido si está conectado al mismo pin
  }
}
