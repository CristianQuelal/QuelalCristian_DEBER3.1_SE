/* 
 * CAPITULO III: MODULOS DE COMUNICACIÓN I2C.
 * CÓDIGO DEBER 3.1:Mediante comunicación I2C configurar 1 maestro y 3 esclavos 
 * NOMBRE: CRISTIAN QUELAL                     
 */
 //////////// SLAVE2 /////////
 #include <Wire.h>;           //libreria I2C
 char dat;                    //variable de almacenamiento de dato
 const int led4=8;            //led1 en pin8
 const int led5=9;            //led1 en pin9
 const int led6=10;           //led1 en pin10
  
void setup() {
  Wire.begin(1);              //ide esclavo
  Wire.onReceive(receiveEvent2);
  Serial.begin(9600);
  pinMode(led4,OUTPUT);       //pin8 como salida 
  pinMode(led5,OUTPUT);       //pin9 como salida 
  pinMode(led6,OUTPUT);       //pin10 como salida 
}

void loop() { 
}

void receiveEvent2(int bytes){
  while(Wire.available()){           
    dat=Wire.read();
    while(dat=='b') 
    {
      digitalWrite(led4,HIGH);       //led 4 se prende
      delay(500);                   //determinación tiempo
      digitalWrite(led4,LOW);        //led 4 se apaga
      delay(500);                   //tiempo de apagado
      digitalWrite(led5,HIGH);       //led 5 se prende
      delay(500);                   //determinación tiempo
      digitalWrite(led5,LOW);        //led 5 se apaga
      delay(500);                   //tiempo de apagado
      digitalWrite(led6,HIGH);       //led 6 se prende
      delay(500);                   //determinación tiempo
      digitalWrite(led6,LOW);        //led 6 se apaga
      delay(8000);                   //tiempo de apagado
      dat=(' ');                  
    }
  }
}
