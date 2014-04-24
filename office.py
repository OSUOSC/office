from time import sleep
import serial

ser = serial.Serial('/dev/ttyACM0', 9600)
sleep(5)

while True:
	log = open("/home/bsilvereagle/public_html/.office","w")
	ser.write('O')
	value = ser.read()
	print value
	log.write(value)
	log.close()
	sleep(10)
