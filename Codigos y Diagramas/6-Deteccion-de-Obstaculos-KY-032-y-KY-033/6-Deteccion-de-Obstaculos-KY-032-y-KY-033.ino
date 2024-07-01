/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
  https://blog.uelectronics.com/tarjetas-desarrollo/arduino/deteccion-de-obstaculos-por-medio-de-los-modulos-ky-032-y-ky-033/
*/

int valor, KY = 3;                      // Variable 'valor' para almacenar los datos del sensor KY, y 'KY' para el pin del sensor
int cuenta = 0;                         // Variable para el conteo de detección de objetos
int dato;                               // Variable para almacenar el dato del conteo

void setup() {
  Serial.begin(9600);                   // Inicialización del puerto serial a 9600 baudios
  pinMode(KY, INPUT);                   // Configuración del pin del sensor KY como entrada
}

void loop() {
  valor = digitalRead(KY);              // Lectura del valor digital del sensor KY y asignación a la variable 'valor'
  
  if (valor == 1) {                     // Si el valor leído es 1...
    Serial.println("Libre");            // No hay detección de obstáculo
  } else if (valor == 0) {              // De lo contrario, si el valor leído es 0...
    Serial.println("Obstáculo");        // Se detecta un obstáculo
    dato = cuenta++;                    // Incrementa el contador y almacena el valor en 'dato'
    Serial.print("Veces Detectadas: "); // Imprime el texto "Veces Detectadas: "
    Serial.println(dato);               // Imprime el número de veces que se ha detectado un obstáculo
  }
  
  delay(500);                           // Espera 0.5 segundos antes de repetir el proceso
}
