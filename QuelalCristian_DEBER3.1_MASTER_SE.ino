/* 
 * CAPITULO III: MODULOS DE COMUNICACIÓN I2C.
 * CÓDIGO DEBER 3.1:Mediante comunicación I2C configurar 1 maestro y 3 esclavos 
 * NOMBRE: CRISTIAN QUELAL                     
 */
//////////////////////MASTER///////////////////////////
 #include <Wire.h>
 char dat;                     //incremento de dato
void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("BIENVENIDO");
  Serial.println("a=Activar el primer esclavo");
  Serial.println("b=Activar el segundo esclavo");
  Serial.println("c=Activar el tercer esclavo");
  }

void loop() {
  if(Serial.available()>0){    //condición de bytes disponibles.
    dat=Serial.read();         //lee o alamecena el dato en la variable
    Serial.println();          //visualización de caracter y salto
    Wire.beginTransmission(1); //empieza la transmision con la id 
    Wire.write(dat);           //envio del dato a los esclavos
    Wire.endTransmission();    //finaliza
  }
}
