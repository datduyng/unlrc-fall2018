// i2c slave code
// upload code of the slave first
// hook them up seperately to upload code
//https://www.youtube.com/watch?v=Jndb2vpAWwU

#include<Wire.h>

//Wiring Connections for motor
#define ENA 10  // Pin #10 or Any pin that supports PWM output, for variable speed control
#define DR1 9   // Pin #9 or Any pin with digital output, for directional control
#define DR2 8   // Pin #8 or Any pin with digital output, for directional control

#define SLAVE1_ADD 0x04

/**FUNCTION prototype**/
void runMotorCW();
void stopMotor();

void setup(){

  Wire.begin(SLAVE1_ADD);// device with address SLAVE2_ADD
  
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);

  //config motor
  // All motor control pins are outputs
  pinMode(ENA, OUTPUT);
  pinMode(DR1, OUTPUT);
  pinMode(DR2, OUTPUT);

  
}

void loop(){
  
}

void receiveEvent(int howMany){

  while(Wire.available()){
    char c = Wire.read();
    Serial.print("c ; ");Serial.println(c);
    if(c == '1'){
      Serial.println("H");
        runMotorCW();
       
    }
    else if( c == '0'){
      stopMotor();
    }else{
      Serial.println("Invalid command");
    }
  }
}

void runMotorCW(){
  // Set the motor to run in one direction, this depends on your wiring
  digitalWrite(DR1, HIGH);
  digitalWrite(DR2, LOW);

  for( int i = 0; i < 256 ; i++ ){
    // Slowly ramp up the speed
    analogWrite(ENA, i);
    // Adding a bit of delay
    delay(2);
  }
}

void stopMotor(){
  // Stop the motor
  digitalWrite(DR1, LOW);
  digitalWrite(DR2, LOW);
  analogWrite(ENA, 0);
}
