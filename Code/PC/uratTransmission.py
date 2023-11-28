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

BUFFER_SIZE = 80
NUM_OF_MOVEMENT = 12
EASY_MOVE = 10
NORMAL_MOVE = 20
HARD_MOVE = 30
MOVEMENT = ['F', 'R', 'L', 'B', 'U', 'D'\
    , 'F2', 'R2', 'L2', 'B2', 'U2', 'D2']

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
    server.write(list_of_command)
    return

server = serial.Serial("COM4", 115200)

mode = -1
while 1:
    mode = server.readline()    # read mode
    match (mode[5]):
        case 1:
            stage = -1
            while 1:
                stage = server.readline()
                if (stage == 2):
                    while 1:
                        user_input = input("Please correct the cube if there is anything wrong in scanning: (eg. 4w)")
                        server.write(user_input)        # --> need to deal with terminate in the board code also
                        if (user_input == "terminate"):
                            break
                elif (stage == 3):
                    CUBE_STRING = server.readline()
                    solution = kociemba.solve(CUBE_STRING)
                    solution = solution.ljust(BUFFER_SIZE, '#')
                    server.write(solution)
                elif (stage == 4):
                    stage = -1
                    break
        case 2:
            stage = -1
            while 1:
                stage = server.readline()
                if (stage == 2):
                    difficulty = server.readline()      # needs error checking?
                    Reshuffle(difficulty)
                elif (stage == 3):
                    stage = -1
                    break
