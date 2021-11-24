/* 
 * CAPITULO III: MODULOS DE COMUNICACIÓN I2C.
 * CÓDIGO DEBER 3.1:Mediante comunicación I2C configurar 1 maestro y 3 esclavos 
 * NOMBRE: CRISTIAN QUELAL                     
 */
 //////////// SLAVE3 /////////
#include <Wire.h>;            //libreria I2C
 char dat;                    //variable de almacenamiento de dato
 const int led7=8;            //led1 en pin8
 const int led8=9;            //led1 en pin9
 const int led9=10;           //led1 en pin10
  
void setup() {
  Wire.begin(1);              //ide esclavo
  Wire.onReceive(receiveEvent3);
  Serial.begin(9600);
  pinMode(led7,OUTPUT);       //pin8 como salida 
  pinMode(led8,OUTPUT);       //pin9 como salida 
  pinMode(led9,OUTPUT);       //pin10 como salida 
}

void loop() { 
}

void receiveEvent3(int bytes){
  while(Wire.available()){          
    dat=Wire.read();
    while(dat=='c')
    {
      digitalWrite(led7,HIGH);       //led 7 se prende
      delay(500);                   //determinación tiempo
      digitalWrite(led7,LOW);        //led 7 se apaga
      delay(500);                   //tiempo de apagado
      digitalWrite(led8,HIGH);       //led 8 se prende
      delay(500);                   //determinación tiempo
      digitalWrite(led8,LOW);        //led 8 se apaga
      delay(500);                   //tiempo de apagado
      digitalWrite(led9,HIGH);       //led 9 se prende
      delay(500);                   //determinación tiempo
      digitalWrite(led9,LOW);        //led 9 se apaga
      delay(8000);                   //tiempo de apagado
      dat=(' ');                  
    }
  }
}
