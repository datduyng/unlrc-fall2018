//Wiring Connections
#define ENA 10  // Pin #10 or Any pin that supports PWM output, for variable speed control
#define DR1 9   // Pin #9 or Any pin with digital output, for directional control
#define DR2 8   // Pin #8 or Any pin with digital output, for directional control
 
void setup(){
  // All motor control pins are outputs
  pinMode(ENA, OUTPUT);
  pinMode(DR1, OUTPUT);
  pinMode(DR2, OUTPUT);
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

void runMotorCCW(){// turn motor the otherway. 
  digitalWrite(DR1, LOW);
  digitalWrite(DR2, HIGH);

  for( int i = 0; i < 256 ; i++ ){
    // Slowly ramp up the speed
    analogWrite(ENA, i);
    // Adding a bit of delay
    delay(2);
  }
  
  delay(100);
}

void stopMotor(){
  // Stop the motor
  analogWrite(ENA, 0);
}

void loop(){
  runMotorCW();
  delay(1000);
  runMotorCCW();
  delay(1000);
  stopMotor();
}
