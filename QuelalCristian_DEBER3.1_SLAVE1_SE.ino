/* 
 * CAPITULO III: MODULOS DE COMUNICACIÓN I2C.
 * CÓDIGO DEBER 3.1:Mediante comunicación I2C configurar 1 maestro y 3 esclavos 
 * NOMBRE: CRISTIAN QUELAL                     
 */
 //////////// SLAVE1 /////////
 #include <Wire.h>;           //libreria I2C
 char dat;                    //variable de almacenamiento de dato
 const int led1=8;            //led1 en pin8
 const int led2=9;            //led1 en pin9
 const int led3=10;           //led1 en pin10
  
void setup() {
  Wire.begin(1);              //ide esclavo
  Wire.onReceive(receiveEvent1);
  Serial.begin(9600);
  pinMode(led1,OUTPUT);       //pin8 como salida 
  pinMode(led2,OUTPUT);       //pin9 como salida 
  pinMode(led3,OUTPUT);       //pin10 como salida 
}

void loop() { 
}

void receiveEvent1(int bytes){
  while(Wire.available()){           
    dat=Wire.read();
    while(dat=='a')                  
    {
      digitalWrite(led1,HIGH);       //led 1 se prende
      delay(500);                   //determina tiempo
      digitalWrite(led1,LOW);        //led 1 se apaga
      delay(500);                   //tiempo de apagado
      digitalWrite(led2,HIGH);       //led 2 se prende
      delay(500);                   //determinación tiempo
      digitalWrite(led2,LOW);        //led 2 se apaga
      delay(500);                   //tiempo de apagado
      digitalWrite(led3,HIGH);       //led 3 se prende
      delay(500);                   //determina tiempo
      digitalWrite(led3,LOW);        //led 3 se apaga
      delay(500);                    //tiempo de apagado
      dat=(' ');                      
  }
 }
}
