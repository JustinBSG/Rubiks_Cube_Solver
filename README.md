# Rubik's Cube Solver

# Table of Content
- [Rubik's Cube Solver](#rubiks-cube-solver)
    - [Installation and Setup](#steps-of-setting-up)
    - [Components that We Used](#components-that-we-used)
    - [Steps of Mode 1 (Solving Mode)](#steps-of-mode-1-solving-mode)
    - [Steps of Mode 2 (Shuffling Mode)](#steps-of-mode-2-shuffling-mode)
    - [Authors](#authors)

## Installation and Setup
1. Connecting all wires and components that shown on [here](Image/).
2. Downloading [Code](Code/PC/) on your PC, recommending Windows OS.
3. Flashing [Code for Camera Board](Code/Camera/) and [Code for Control Board](Code/Control/).

## Components that We Used
1.  
2.  
3.  
4.  

## Steps of Mode 1 (Solving Mode)
1. Turning on two boards and executing [terminal.py](Code/PC/terminal.py).
1. Typing `mode1` on the terminal of your PC.
2. Two arms will be pulled and create some spaces and allow you to put the shuffled Rubik's Cube inside.
2. After typing `ok`, it starts scanning each face of the Rubik's Cube.
3. After finishing scanning each face, it stops and waits. It shows the result of the scanning on monitor on Camera Board. If the result is correct, go to step 6. Otherwise, go to step 7.
4. Typing `confirm` on terminal.
5. Typing `<number> <short form of correct colour>` on termianl.
    - `<numbers>` represents the panel of incorrect colour.
        - We use keypad keyboard as the format of the panel of each face
    - `<short form of correct colour>`
        - w for white
        - y for yellow
        - g for green
        - b for blue
        - r for red
        - o for orange
6. After checking all faces of Rubik's Cube, you should see `Complate Scanning` on the terminal of your PC.
7. Your PC starts performing calculation and sending the solution result to Control board for performing solving.
8. After completing solving, it stops and allows you to get back your Rubik's Cube.
9. Typing `ok` on terminal for restarting the program again.

## Steps of Mode 2 (Shuffling Mode)
1. Turning on two boards and executing [terminal.py](Code/PC/terminal.py).
1. Typing `mode2` on the terminal of your PC.
2. Two arms will be pulled and create some spaces and allow you to put the unshuffled Rubik's Cube inside.
3. Typing `ok` on terminal to close the arms.
2. There are 3 difficulties that you can choose. You can choose one of them by typing `easy` or `normal` or `hard`.
    - Easy: you can solve it in xx steps.
    - Normal: you can solve it in xx steps.
    - Hard: you can solve it in xx steps.
3. It starts scrambling the Rubik's Cube and you can wait until it stops.
4. After completing scrambling, it stops and allows you to get back your Rubik's Cube.
9. Typing `ok` on terminal for restarting the program again.

## Authors
- Lau Chun Ting, Justin @JustinBSG
- Yuen Man Him @bosco713