import serial

arduino = serial.Serial("/dev/cu.usbmodem14201", timeout=1)

while True:
    X=''
    Y=''
    rawdata = arduino.readline()[:-2].decode("utf-8") 
    for i in range(len(rawdata)):
        if rawdata[i] != ';':
            X += rawdata[i]
        else:
            Y = rawdata[i+1:][:-2]
            break

    if int(X) <= 400:
        print('DOWN')
    if int(X) >= 600:
        print('UP')
    if int(Y) <= 400:
        print('LEFT')
    if int(Y) >= 600:
        print('RIGHT')

   