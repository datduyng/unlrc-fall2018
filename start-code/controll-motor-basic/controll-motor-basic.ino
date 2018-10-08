//Wiring Connections
#define ENA 10  // Pin #10 or Any pin that supports PWM output, for variable speed control
#define DR1 9   // Pin #10 or Any pin with digital output, for directional control
#define DR2 8   // Pin #10 or Any pin with digital output, for directional control
 
void setup(){
  // All motor control pins are outputs
  pinMode(ENA, OUTPUT);
  pinMode(DR1, OUTPUT);
  pinMode(DR2, OUTPUT);
}

void loop(){
  // Set the motor to run in one direction, this depends on your wiring
  digitalWrite(DR1, HIGH);
  digitalWrite(DR2, LOW);

  for( int i = 0; i < 256 ; i++ ){
    // Slowly ramp up the speed
    analogWrite(ENA, i);
    // Adding a bit of delay
    delay(2);
  }
  
  delay(100);
  // Stop the motor
  analogWrite(ENA, 0);
  
  digitalWrite(DR1, LOW);
  digitalWRite(DR2, HIGH);

  for( int i = 0; i < 256 ; i++ ){
    // Slowly ramp up the speed
    analogWrite(ENA, i);
    // Adding a bit of delay
    delay(2);
  }
  
  delay(100);
  // Stop the motor
  analogWrite(ENA, 0);
  

}
