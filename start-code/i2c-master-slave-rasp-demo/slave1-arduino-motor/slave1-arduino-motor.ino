// i2c slave code
// upload code of the slave first
// hook them up seperately to upload code
//https://www.youtube.com/watch?v=Jndb2vpAWwU

#include<Wire.h>
#define SLAVE2_ADD 0x04

void setup(){

  Wire.begin(SLAVE2_ADD);// device with address SLAVE2_ADD
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
 // digitalWrite(LED_BUILTIN,LOW);
}

void loop(){
  
}

void receiveEvent(int howMany){

  while(Wire.available()){
    char c = Wire.read();
    Serial.print("c ; ");Serial.println(c);
    if(c == '1'){
      Serial.println("H");
      digitalWrite(LED_BUILTIN,HIGH);
    }
    else if( c == '0'){
      digitalWrite(LED_BUILTIN,LOW);
      Serial.println("L");
    }else{
      Serial.println("Invalid command");
    }
  }
}
