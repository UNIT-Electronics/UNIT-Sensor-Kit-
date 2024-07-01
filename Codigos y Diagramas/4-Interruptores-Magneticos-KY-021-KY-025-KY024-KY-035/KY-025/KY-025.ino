/*
  Derechos de autor © UNIT Electronics
  Este codigo se proporciona "tal cual", sin garantías de ningún tipo.

  Para más información, visita nuestro blog:
  https://blog.uelectronics.com/tarjetas-desarrollo/comparacion-entre-interruptores-magneticos-ky-021-ky-025ky-024-y-ky-35/
*/
// Definimos el pin 12 para controlar el LED
int led = 12; 

// Definimos el pin 3 para la entrada del sensor kyD
int kyD = 3; 

void setup(){
  // Inicia la comunicación serie a 9600 baudios
  Serial.begin(9600); 
  
  // Configura el pin del LED como salida
  pinMode(led, OUTPUT); 
  
  // Configura el pin del sensor kyD como entrada
  pinMode(kyD, INPUT); 
}

void loop(){
  // Lee el valor analógico del pin A0 y lo almacena en la variable iman
  int iman = analogRead(A0); 
  
  // Imprime el valor leído por el pin A0 en el monitor serie
  Serial.println(iman); 
  
  // Espera 1 milisegundo
  delay(1); 
  
  // Lee el valor digital del pin kyD y lo almacena en la variable val
  int val = digitalRead(kyD); 
  
  // Si el valor leído del pin kyD es alto (HIGH)
  if (val == HIGH) {
    // Enciende el LED
    digitalWrite(led, HIGH); 
  }
  else {
    // Apaga el LED
    digitalWrite(led, LOW); 
  }
}
