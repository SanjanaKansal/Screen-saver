 
%-----------------------------------------------------------------------------------------------------------------------------------------------
SCREENSAVER- THE FUNCTIONALITY:-

This is a screensaver application, which basically have one cuboid box containing some balls, which are moving with random velocities as well as rotating also and following laws of physics,while assuming zero gravity and friction. The colour of the ball also changes according the position of the balls. With some keyboard buttons you can contron various properties of balls,like speed of ball or size of ball. The number of balls will be taken at the time of compilation. 
%-----------------------------------------------------------------------------------------------------------------------------------------------

SUB-COMPONENTS AND THEIR WORKING:-
BALL HEADER FILE:-
Ball header file have a class name "ball" which have two functions named as "position" and "rand" and one constructor. The function "position" is randering the balls on the screen and managing the collision of balls with the walls and the function "rand" is use to generate random numbers.
MAIN FILE:- 
Main file have four functions name as "main", "display", "reshape" and "physics". The function "physics" is controlilng the collision between the balls and the function "display" is rendering cuboid box and the function "reshape is controlling the view of screensaver" and main is calling the other functions.
%-----------------------------------------------------------------------------------------------------------------------------------------------

HOW TO USE:-

"make num_threads=N" -For running the screensacer you just need to type this in command line, where N is the number of balls you need in the cuboid.
"make doc" -For generating documents you need to type this in command line.
"make clean" -For cleaning the created file you need to type this in command line. 
"P-keypress" -To pause the motion of balls.
"R-keypress" -To resume the motion of balls.
"S-keypress" -To reduce the size of balls.
"M-keypress" -To resize the balls to medium.
"L-keypress" -To increase the size of balls.
"+-keypress" -To increase the speed of balls.
"*-keypress" -To randomize the speed of ball.

%-----------------------------------------------------------------------------------------------------------------------------------------------



