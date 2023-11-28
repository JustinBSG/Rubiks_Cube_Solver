import serial
import kociemba

# white -> U
# red -> R
# green -> F
# orange -> L
# blue -> b
# Yellow -> D
# serial.Serial("COM4", 115200)
def change(Ori):
    CUBESTRING = []
    for index in range(54):
        match(Ori[index]):
            case ('W'):
                CUBESTRING.append('U')
            case ('R'):
                CUBESTRING.append('R')
            case ('G'):
                CUBESTRING.append('F')
            case ('O'):
                CUBESTRING.append('L')
            case ('B'):
                CUBESTRING.append('B')
            case ('Y'):
                CUBESTRING.append('D')
    return CUBESTRING

CUBE_STRING = 'WWBWWBWWBRRRRRRRRRGGWGGWGGWYYGYYGYYGOOOOOOOOOYBBYBBYBB'
CUBESTRING = ''.join(change(CUBE_STRING))
CUBE_STRING2 = 'DRLUUBFBRBLURRLRUBLRDDFDLFUFUFFDBRDUBRUFLLFDDBFLUBLRBD'
print(CUBESTRING)
print(kociemba.solve(CUBESTRING))