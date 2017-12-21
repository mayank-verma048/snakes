# Snakes
A C++ command line interface game inspired from original game of the same name. Uses <conio.h> functions to manipulate the Command Prompt screen. Compatible with Windows only. Tested with Borland C++ compiler.

Welcome Screen
```
                              1010101  10    10    10    10  10  101010  1010101
                              10       1010  10  10  10  10 10   10      10 
                              1010101  10 10 10  101010  1010    10101   1010101
                                   10  10  1010  10  10  10 10   10           10
                              1010101  10   110  10  10  10  10  101010  1010101
```

Key Bindings:
```
Key    Action
 A  ->  Left
 W  ->   Up
 S  ->  Back
 D  ->  Right
 ```
 
Objective: To keep the snake alive as long as possible. Score is determined by the length of the snake. The snake "dies" if it either touches itself or the wall.

The default *Wall* covers the perimeter of the Command Prompt screen. If there is no *Wall* the *Snake* will warp around. The warping logic is well implemented so, the *Wall* can be customized to your heart's content. Just pass your own array of *Point* object and the size of array to the *Wall* constructor. The rest is handled for you.
