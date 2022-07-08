# Rubiks_cube_C


## Compilation
### Linux :
make

Or you can use this command :
```
gcc -Wall rubiks.c IA.c functions.c getch.c functions.h getch.h -o rubiks -lm
```
### Windows :
```
gcc -Wall rubiks.c IA.c functions.c functions.h -o rubiks -lm
```
## How to play

### Select a mode
You can choose :
- 2x2
- 3x3  

It's really intuitive.

### Keyboard
Check the move notation : https://en.wikipedia.org/wiki/Rubik%27s_Cube#Move_notation

### To move the rubik's cube :
```
U (Up)
D (Down)
R (Right)
L (Left)
F (Front)
B (Back)
E (Equator)
M (Middle)
To use : U', R', L'... You can activate **Maj lock**
```
### To scramble the cube :
```
S (scramble the cube)
```
### AI (only for 2x2)
I developped an AI to solve the rubiks cube 2x2. But it only works for rubik's cube 2x2 at this moment. If you launch the AI on a 3x3, it will only solve the corners.  
Steps :
- Solve white face
- OLL
- PLL
Finally, it shows the sequence of movements to solve it. In the future, I may add a mode to add a scramble. Because, right now you can just solve a random scramble.  
Well, to solve a scramble, you just have to press :  
```
I (Solve a 2x2 or 3x3 corners)
```
