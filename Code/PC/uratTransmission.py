# The flow of this program
# 0. Read mode
# if (mode == 1):
#   1. Read stage
#   if (stage == 1):
#       1.1 nth to do 
#   if (stage == 2):
#       1.2 nth to do
#   if (stage == 3):
#       1.3.1 read CUBE_STRING
#       1.3.2 perform solving cube algorithm
#       1.3.3 transmite the solution back to the board
#   if (stage == 4):
#       1.4 nth to do
# if (mode == 2):
#   2. Read stage
#   if (stage == 1):
#       2.1 nth to do
#   if (stage == 2):
#       2.2.1 read difficulty
#       2.2.1 perform reshuffle algorithm
#       2.2.2 transmite the list of commands to the board
#   if (stage == 3):
#       2.3 nth to do

import random
import serial
import kociemba

BUFFER_SIZE = 100
NUM_OF_MOVEMENT = 12
EASY_MOVE = 10
NORMAL_MOVE = 20
HARD_MOVE = 30
MOVEMENT = ['F', 'R', 'L', 'B', 'U', 'D'\
    , 'F2', 'R2', 'L2', 'B2', 'U2', 'D2']
COLOR = ['w', 'r', 'y', 'b', 'g', 'o']
CUBE_STRING = ""

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

def Reshuffle(difficulty):  # I think it should be define as the cube is moved from the reset state by how many moves 
    # --> difficult to define difficulty
    list_of_command = ""
    match(difficulty):
        case ("easy"):
            previous_movement = 'A'
            for number_of_moves in range(EASY_MOVE):
                movement = random.choice(MOVEMENT)
                while (movement == previous_movement):
                    movement = random.choice(MOVEMENT)
                previous_movement = movement
                list_of_command.append(movement)
                if (number_of_moves!=EASY_MOVE-1):
                    list_of_command.append(" ")
        case ("normal"):
            previous_movement = 'A'
            for number_of_moves in range(NORMAL_MOVE):
                movement = random.choice(MOVEMENT)
                while (movement == previous_movement):
                    movement = random.choice(MOVEMENT)
                previous_movement = movement
                list_of_command.append(movement)
                if (number_of_moves!=NORMAL_MOVE-1):
                    list_of_command.append(" ")
        case ("hard"):
            previous_movement = 'A'
            for number_of_moves in range(HARD_MOVE):
                movement = random.choice(MOVEMENT)
                while (movement == previous_movement):
                    movement = random.choice(MOVEMENT)
                previous_movement = movement
                list_of_command.append(movement)
                if (number_of_moves!=HARD_MOVE-1):
                    list_of_command.append(" ")
    list_of_command.ljust(BUFFER_SIZE, '#')
    server.write(list_of_command.encode())
    return

server = serial.Serial("COM4", 115200)

mode = -1
while 1:
    mode = input("Please enter the mode: (eg. mode1) ")    # read mode
    if (mode == "mode1" or mode == "mode2"):
        server.write(mode.encode())
        match (mode[4]):
            case "1":
                while 1:
                    # stage = "0"
                    # print(1)
                    stage = server.read().decode("Ascii")
                    # if (stage != "0"):
                    # print(stage)
                    if (stage == "1"):
                        user_ok = input("Please enter ok when you are ready: ")
                        if (user_ok == "ok"):
                            server.write(user_ok.encode()) 
                            # stage = server.read().decode("Ascii")
                        else:
                            print("Wrong input, please enter ok again when you are ready")
                    elif (stage == "2"):
                        count = 0
                        while 1:
                            user_input = input("Please correct the cube if there is anything wrong in scanning: (eg. 4w)")
                            if (user_input == "confirm" or (len(user_input) == 2 and user_input[0] > "0" and user_input[0] <= "9" and COLOR.count(user_input[1]) == 1)):
                                if (user_input == "confirm"):
                                    count += 1
                                    server.write(user_input.encode())        # --> need to deal with terminate in the board code also
                                    if (count == 6):
                                        # print("face = 6, break")
                                        break
                                else:
                                    user_input = user_input.ljust(7, "#")
                                    server.write(user_input.encode())
                            else:
                                print("Wrong input. Please enter again if you see something wrong in the scanning data")
                        temp = server.read(size=55).decode()
                        # print(temp)
                        CUBE_STRING = temp
                    elif (stage == "3"):
                        # print(CUBE_STRING)
                        # if (len(CUBE_STRING) == 55):
                        #     CUBE_STRING = CUBE_STRING[:-1]
                        #     print(CUBE_STRING)
                        CUBESTRING = ''.join(change(CUBE_STRING[:-1]))
                        print(CUBESTRING)
                        solution = kociemba.solve(CUBESTRING)
                        print(solution)
                        solution = solution.ljust(BUFFER_SIZE, '#')
                        server.write(solution.encode())
                    elif (stage == "4"):
                        while 1:
                            user_fin = input("Please enter ok after you remove the cube:")
                            if (user_fin != "ok"):
                                print("Wrong input. Please try again.")
                            else:
                                server.write("ok")
                                break
                        stage = "0"
            case "2":
                stage = "1"
                while 1:
                    stage = server.read().decode()
                    if (stage == 2):
                        difficulty = server.read().decode()      # needs error checking?
                        Reshuffle(difficulty)
                    elif (stage == 3):
                        stage = -1
                        break
    else:
        print("You input is wrong, please enter again")
