# Motor_Control_Basic
In this tutorial, a simple motor driver, dual-channel H-bridge is used. It allows control of bi-directional and variable speed of up to two motors. 

# H-bridge
In a nutshell, a H-bridge is a circuit that allow a DC output to be bi-directional and variable voltage at it output. As shown in the diagram below, it consists of four switches, usually FET (Field Effect Transistors), and the motor or any electronic that needs bi-directional variable voltages will sit in the middle and a DC voltage is supplied at the both ends.
![h_bridge](https://user-images.githubusercontent.com/35666615/46635901-950cce00-cb1b-11e8-803c-32b8e939afe8.png)

## Bi-directional Voltage Control
![h_bridge_operating svg_ 2](https://user-images.githubusercontent.com/35666615/46635902-950cce00-cb1b-11e8-9ae1-fda6e98a65f9.png)
The switches usually function in pairs, such that it only allows current to flow in one or the other direction. It is important not to turn on two switches at the same side at the same time as it will short circuit and destroy the device and the power source. It is usually taken care off by the electronic design.

# L298N Motor Driver
![l298n-pinout](https://user-images.githubusercontent.com/35666615/46635905-95a56480-cb1b-11e8-84b8-b6c7d1d2a8d6.png)
L298N is an integrated-circuit that consists of a dual-channel H-bridge, such that it can operates two independent motors at the same time and featuring some auxiliary capabilities such as 5-volt regulator.

# Wiring Diagram
![l298n](https://user-images.githubusercontent.com/35666615/46635904-950cce00-cb1b-11e8-9332-350b62fa9cee.png)

Enable A is for PWM/analog input of Motor connected to Terminal A
IN1 and IN2 are for directional control of Motor connected to Terminal A
Likewise, Enable B is for PWM/analog input of Motor connected to Terminal B
IN3 and IN4 are for directional control of Motor connected to Terminal B

**By default, the ENA and ENB have jumper attached so it always in enable mode**

**Check your wiring before powering it up.**

Connect your power source, either from batteries or DC power supply to the L298N motor driver, the positive terminal goes to the left and the negative terminal goes to the middle of the three-pin terminal block respectively. There is an option to get a regulated 5-volt output from the L298N too if needed. For example, to power your Arduino board or Raspberry Pi which requires 5-volt power supply. 

## Note
It is requires to 'gound' your controller (Arduino or Raspberry Pi) to the motor driver, because of the electrical signals need a referencing potential.


# Arduino Program - One Motor Control
In this example, we are using Arduino to control one motor with forward and backward variable speed.
* `pinMode(#PIN, OUTPUT)` set the corresponding pin to a output port
* `digitalWrite( #PIN, HIGH)` set the pin to output logic HIGH or 5-volt in this case
* In contrary, `digitalWrite( #PIN, LOW)` set the pin to output logic LOW or 0-volt
* `analogWrite( #PIN, NUMBER)` set the pin to output an pseudo-analog output, the `NUMBER` can be 0~255 or any uint8 value 
* only the pin with a `~` next to its pin number has the abilities to use `analogWrite`

For more information of analogWrite, look up [analogWrite](https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/) or if you wish to know what is this pseodo-analog output or PWM, look up [PWM](https://www.arduino.cc/en/Tutorial/PWM)

```c
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
```

# Small Execise
Try to made a function that can take into the speed and direction as parameters and use the function to control the motor. Also try to control two motors at the same time, and use it to operate a small rover chassis.
