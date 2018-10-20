# base on: pinout.xyz/pinout/i2c

import smbus 

DEVICE_BUS = 1
DEVICE_ADD = 0x15
bus = smbus.SMBus(DEVICE_BUS)

#slave_address 1 
address = 0x04

#slave_address 2
address_2 = 0x05 


def writeNumber(value, toAddress):
	bus.write_byte(toAddress, int(ord(value)))
	# bus.write_byte_data(address, 0, value)
	return -1

def readNumber():
	# number = bus.read_byte(address)
	number = bus.read_byte_data(address, 1)
	return number

while True: 
	data = raw_input('Slave 1(Motor) or 2(Light)')
	if( int(data) == 1): 
		value = raw_input('Run Motor - Yes(1) or No(0)')
		writeNumber(value, address)
	elif(int(data) == 2):
		value = raw_input('Light - On(1) or Off(0)')
		writeNumber(value, address)
	

