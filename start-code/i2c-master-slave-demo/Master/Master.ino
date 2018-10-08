// i2c Master code(master...slave
// https://www.youtube.com/watch?v=Jndb2vpAWwU

// WIRING DIAGRAM
/**
 * 
 * Master arduino uno trigger slave to turn on led by 
 * prompting for user a character 'H'(on) or 'L'(low)
 * master 
 * A4(master) -> A4(slave)
 * A5(master) -> A5(slave)
 * GND(master) -> GND(slave)
 * 5v(master) -> 5v(slave)
 */
#include<Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin();// init i2c bus as master

}

void loop() {
   while(Serial.available()){
    char c = Serial.read();
 
    if(c == 'H'){
      Wire.beginTransmission(5);// specify the address of the device
                               // anything from 1  - 127 
                             // remember the number 
      Wire.write('H');
      Wire.endTransmission(); 
    }else if(c == 'L') {
      Wire.beginTransmission(5);// device 5
      Wire.write('L');
      Wire.endTransmission();
    }else{
      Wire.beginTransmission(5);// device 5
      Wire.write(c);
      Wire.endTransmission();
    }
    
 }
}
