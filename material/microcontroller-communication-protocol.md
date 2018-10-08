## Microcontroller communication protocol 

**Goal**: overviewing over I2c, serial, and SPI communication protocol. Impotance of communication protocol 

## Overall idea
- There are multiple microcontroller, and programming language like C, Java, C++,...
- Each has it own strength and weaknesses.
- Question arrive: `How can all programming language and microcontroller be unite?` `How can they work together to create one piece of technology?`
- follow up example: If one person is good at C programming languague(Arduino), and one is good at Python(raspberry pi) then how can they work together to create one piece of technology? 
- Through universal communication. 3 main: 
	- I2c
	- Serial
	- SPI


## Inter-intergrated circuit( I2c)
- Allow multiple device communication up to 128 or 127 
- only need 2 wire for configuration
- Slow. Good enough for sensor task.
- Masters and slaves communicate on the same bus(same 2 wire) 
> ![how-i2c-communication-bus-works](https://user-images.githubusercontent.com/35666615/46591097-e9617080-ca7d-11e8-98b1-6ec1d48b58a7.jpg)
- [rasberry pi I2c configure](https://radiostud.io/howto-i2c-communication-rpi/)
- [Arduino I2c Library](https://www.arduino.cc/en/Reference/Wire)
- [Arduino commnicate with Raspbery Pi](https://oscarliang.com/raspberry-pi-arduino-connected-i2c/)

## Serial(UART)
- everyday example: Flash drive, keyboard, mouse,....
- only need 2 wire(Tx, Rx)(transmitter and receiver)
- only allow 2 way communication between 2 microcontroller
> ![usb-pinout](https://user-images.githubusercontent.com/35666615/46590688-d305e580-ca7a-11e8-92e8-64401f731383.jpg)

- Arduino Uno has 1 serial communication port, `Mega` board have 4
- What if you run out of Serial port?? use [software Serial](https://www.arduino.cc/en/Reference/SoftwareSerial)
- Configure serial communication on Arduino
```c
void setup(){
	Serial.begin(9600); // init Serial port 1 with 9600 baud rate
	Serial2.begin(115200); // init Serial port 2 with 115200 baudrate
}
void loop(){
	Serial.println("Hello world"); // print to serial 1 often print out to display
	Serial2.println("go"); // print to Serial 2 to trigger something. 
}
```
- Extra: We used Serial communication to allow raspberry pi talk to Arduino chip on our last year robot competition. Arduino Triggers Rasberry pi to take image and process by `Serial.println("go");`. Pi send coordinate of ping pong balls to Arduino. 

- [Rasperry pi Serial communication](https://oscarliang.com/connect-raspberry-pi-and-arduino-usb-cable/)

## SPI
- Master and slave communicate on different bus(wire)
- Fast.
- 4 bus(wire)
	- `ss` slave select - select slave to talk to 
	- `MOSI` master out slave in - master talk to slave
	- `MISO` master in slave out - slave talk to master
	- `SCK` Serial clock - to keep all clock synchronize
- Improvement of I2c. allow the process of communication faster since communication are split to difference buses.

> ![spi](https://user-images.githubusercontent.com/35666615/46590995-46a8f200-ca7d-11e8-8152-3ac5af27f91a.PNG)
- [more in-depth](https://learn.sparkfun.com/tutorials/serial-peripheral-interface-spi/all)