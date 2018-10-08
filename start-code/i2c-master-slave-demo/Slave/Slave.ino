// i2c slave code
// upload code of the slave first
// hook them up seperately to upload code

#include<Wire.h>

void setup(){

  Wire.begin(5);// device # 5
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
    if(c == 'H'){
      Serial.println("H");
      digitalWrite(LED_BUILTIN,HIGH);
    }
    else if( c == 'L'){
      digitalWrite(LED_BUILTIN,LOW);
      Serial.println("L");
    }else{
      Serial.println("Invalid command");
    }
  }
}
