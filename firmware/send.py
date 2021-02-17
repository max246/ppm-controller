import serial
import time
ser = serial.Serial('/dev/ttyACM0', 9600, serial.EIGHTBITS, serial.PARITY_NONE, serial.STOPBITS_ONE)

time.sleep(3)
values = bytearray([0,1,1,1, 0x0c])
while True:
        print("write")
        values = bytearray([1,0,1,1, 0x0c])
        ser.write(values)
        time.sleep(1)
        print("write")
        values = bytearray([1,1,1,1, 0x0c])
        ser.write(values)
        time.sleep(1)
