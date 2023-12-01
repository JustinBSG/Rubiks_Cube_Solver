# Rubik's Cube Solver
- ELEC3300 Final Project

## Table of Content
- [Rubik's Cube Solver](#rubiks-cube-solver)
    - [Installation and Setup](#steps-of-setting-up)
    - [Components that We Used](#components-that-we-used)
    - [Steps of Mode 1 (Solving Mode)](#steps-of-mode-1-solving-mode)
    - [Steps of Mode 2 (Shuffling Mode)](#steps-of-mode-2-shuffling-mode)
    - [Authors](#authors)

## Installation and Setup
1. Connecting all wires and components that shown on [HERE](Material/Image/).
2. Downloading [Code for PC](Code/PC/) on your PC, recommending Windows OS.
3. Freshing [Code for Camera Board](Code/Camera/) and [Code for Control Board](Code/Control/).

## Components that We Used
1. PC, running Windows OS *1
2. STM32F105 Board *2
3. MG996R *8
4. 4DLCD32Q with FSMC control *2
5. HC-05 *1
6. Breadboard *2
7. Bench Power Supply *1
8. Plastic Strip Connection Rod with Fixed Round Hole *4
9. Strews with different size
10. Jumper wires

## Steps of Mode 1 (Solving Mode)
1. Execute [Code for PC](Code/PC/uratTransmission.py) on your PC for connecting to HC-05 on Camera board.
2. Type `mode1` on terminal for choosing this mode.
3. Type `ok` on terminal after inserting the Rubik's Cube.
4. It starts scanning the face of Rubiks's Cube and displaying the result on LCD monitor that connecting to Camera board. If the result is correct, go to step 5. If the result is wrong, go to step 6.
5. Type `confirm` for confirming the result is correct.
6. Type `<number><correct color>` for telling PC the correct color on specific position.
    - `<number>`: following the format on your phone keypad
    - `<correct color>`: 
        - `w` for white
        - `r` for red
        - `y` for yellow
        - `b` for blue
        - `g` for green
        - `o` for orange
7. Go to step 4 for repeating the scanning procedure until all 6 faces are scanned and corrected.
8. It starts solving the Rubik's Cube.
9. You can get back the Rubik's Cube after it stops.
10. Type `ok` after getting back your Cube.

## Steps of Mode 2 (Shuffling Mode)
1. Execute [Code for PC](Code/PC/uratTransmission.py) on your PC for connecting to HC-05 on Camera board.
2. Type `mode1` on terminal for choosing this mode.
3. Type `ok` on terminal after inserting the Rubik's Cube.
4. Type `<difficult>` for choosing the difficulty.
    - `easy` for easy mode.
    - `normal` for normal mode.
    - `hard` for hard mode.
5. It starts reshuffling the Rubik's Cube.
9. You can get back the Rubik's Cube after it stops.
10. Type `ok` after getting back your Cube.

## Authors
- Lau Chun Ting, Justin @JustinBSG
- Yuen Man Him @bosco713