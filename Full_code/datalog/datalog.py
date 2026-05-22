import serial

filename = "sampel5/sampel5_4.csv"

def readserial(comport, baudrate):

    ser = serial.Serial(comport, baudrate, timeout=0.1)
    i = 0
    while True:
        data = ser.readline().decode().strip()
        if data:
            data = data+"\n"
            print(data," ",i)
            with open(filename, 'a') as file:
                file.write(data)
            if i == 19:
                break
            else :
                i+=1


if __name__ == '__main__':
    with open(filename, "w") as file:
        file.write("nitrogen,phosporous,potassium,ec,ph,temp,hum\n")
    readserial('COM5', 115200)
