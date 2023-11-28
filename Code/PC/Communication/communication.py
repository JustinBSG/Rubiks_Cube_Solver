import serial
import time
import kociemba

serialPort = serial.Serial(
    port="COM4", baudrate=115200 #, bytesize=8, timeout=2, stopbits=serial.STOPBITS_ONE
)
# if (not serialPort.is_open()):
#     serialPort.open()
# print(serialPort.name)
# serialPort.write("abscd".encode())
# serialString = ""  # Used to hold data coming over UART
while 1:
    # Wait until there is data waiting in the serial buffer
    if serialPort.in_waiting > 0:

        # Read data out of the buffer until a carraige return / new line is found
        serialString = serialPort.readline()

        # Print the contents of the serial data
        try:
            # print(serialString.decode("Ascii"))
            # print(kociemba.solve(serialString.decode("Ascii")[:-1]))
            # time.sleep(1)
            solution = kociemba.solve(serialString.decode("Ascii")[:-1])
            # print(solution)
            time.sleep(3)
            # solution = solution + "\n"
            print(len(solution))
            solution = solution.ljust(80, "*")
            print(solution)
            print(len(solution))
            serialPort.write(solution.encode())
            break
            # break
            # serialPort.flush()
            # print("\n")
        except:
            pass

import random
import serial
import kociemba

BUFFER_SIZE = 80
NUM_OF_MOVEMENT = 12
EASY_MOVE = 10
NORMAL_MOVE = 20
HARD_MOVE = 30
MOVEMENT = ['F', 'B', 'R']
COLOR = ['w', 'b', 'r', 'y', 'o', 'g']

def Reshuffle(difficulty):
    list_of_commands = ""
    match(difficulty):
        case("easy"):
            previous_movement = 'A'
            for number_of_moves in range(EASY_MOVE):
                movement = random.choice(MOVEMENT)
                while(movement == previous_movement):
                    movement = random.choice(MOVEMENT)
                previous_movement = movement
                list_of_commands.append(movement)
                if (number_of_moves!=EASY_MOVE-1):
                    list_of_commands.append(" ")
        case("normal"):
            previous_movement = 'A'
            for number_of_moves in range(NORMAL_MOVE):
                movement = random.choice(MOVEMENT)
                while(movement == previous_movement):
                    movement = random.choice(MOVEMENT)
                previous_movement = movement
                list_of_commands.append(movement)
                if (number_of_moves!=NORMAL_MOVE-1):
                    list_of_commands.append(" ")
        case("hard"):
            previous_movement = 'A'
            for number_of_moves in range(HARD_MOVE):
                movement = random.choice(MOVEMENT)
                while(movement == previous_movement):
                    movement = random.choice(MOVEMENT)
                previous_movement = movement
                list_of_commands.append(movement)
                if (number_of_moves!=HARD_MOVE-1):
                    list_of_commands.append(" ")
    list_of_commands.ljust(BUFFER_SIZE, '#')
    server.write(list_of_commands.encode())
    return

server = serial.Serial("COM4", 115200)

mode = -1
while 1:
    mode = server.readline().decode("Ascii")
    match (mode[5]):
        case 1:
            stage = -1
            while 1:
                stage = server.readline().decode("Ascii")
                if (stage == 2):
                    while 1:
                        user_input = input("Please correct the cube if there is anything wrong in scanning: (eg. 4w)")
                        if (user_input == "terminate"):
                            server.write("terminate".encode())   # --> need handler in board side
                            break
                        if ((user_input[0]<1 and user_input[0]>9) or (COLOR.count(user_input[1])==0)):
                            print("Wrong input, Please enter again in correct formate: (eg. 4w)")
                            continue
                        server.write(user_input.encode())
                elif (stage == 3):
                    CUBE_STRING = server.readline().decode("Ascii")
                    solution = kociemba.solve(CUBE_STRING)
                    solution = solution.ljust(BUFFER_SIZE, '#')
                    server.write(solution.encode())
                elif (stage == 4):
                    stage = -1
                    break
        case 2:
            stage = -1
            while 1:
                stage = server.readline().decode("Ascii")
                if (stage == 2):
                    difficulty = server.readline().decode("Ascii")
                    Reshuffle(difficulty)
                elif (stage == 3):
                    stage = -1
                    break