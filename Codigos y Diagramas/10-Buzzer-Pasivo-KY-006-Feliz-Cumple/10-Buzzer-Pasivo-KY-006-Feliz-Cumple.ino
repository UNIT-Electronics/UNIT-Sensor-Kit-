/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
  https://blog.uelectronics.com/tarjetas-desarrollo/arduino/haz-que-el-zumbador-buzzer-pasivo-modulo-ky-006-cante-feliz-cumpleanos-por-ti/
*/

int buzzer = 9;                                   // Pin de salida hacia el buzzer KY-006
int length = 28;                                  // Cantidad de notas en la canción
char notas[] = "GGAGcB GGAGdc GGxecBA yyecdc";    // Notas de la canción a replicar
int beats[] = { 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8, 8, 8, 16, 1, 2, 2, 8, 8, 8, 16 };
                                                 // Duración de cada nota en relación al tempo
int tempo = 110;                                  // Velocidad de reproducción (cuanto menor el valor, más rápido)

// Función para reproducir un tono específico durante cierta duración
void repTono(int tone, int duracion) {
  for (long i = 0; i < duracion * 1000L; i += tone * 2) {
    digitalWrite(buzzer, HIGH);     // Enciende el buzzer
    delayMicroseconds(tone);        // Espera la duración del tono
    digitalWrite(buzzer, LOW);      // Apaga el buzzer
    delayMicroseconds(tone);        // Espera la duración del tono antes de pasar al siguiente
  }
}

// Función para reproducir una nota específica durante cierta duración
void repNota(char nota, int duracion) {
  char notas[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B', 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'x', 'y'};
  int tonos[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014, 956, 834, 765, 593, 468, 346, 224, 622, 715}; // Frecuencia de los tonos
  int SPEE = 5; // Factor de velocidad para ajustar la duración de la nota

  for (int i = 0; i < 17; i++) {
    if (notas[i] == nota) {
      int nuevaDuracion = duracion / SPEE; // Ajusta la duración de la nota según el factor de velocidad
      repTono(tonos[i], nuevaDuracion);   // Llama a la función para reproducir el tono correspondiente
    }
  }
}

void setup() {
  pinMode(buzzer, OUTPUT); // Configura el pin del buzzer como salida
}

void loop() {
  for (int i = 0; i < length; i++) {
    if (notas[i] == ' ') {
      delay(beats[i] * tempo); // Pausa según la duración indicada en 'beats' multiplicada por el tempo
    } else {
      repNota(notas[i], beats[i] * tempo); // Reproduce la nota según la duración indicada en 'beats' multiplicada por el tempo
    }
    delay(tempo); // Pausa entre notas según el tempo
  }
}
