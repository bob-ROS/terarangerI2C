from periphery import I2C
import time

i2c = I2C("/dev/i2c-0")

msgs = [I2C.Message([0x62,0x01]), I2C.Message([0x00], read = False)]
i2c.transfer(0x31,msgs)
time.sleep(0.005)
for i in range(10):
	msgs = [I2C.Message([0x63,0x00]), I2C.Message([0x00], read = True)]
	print("0x31: 0x%02x" % msgs[1].data[0])

i2c.close

