# myMastermind

Mastermind is a code-breaking game. 
It is a game composed of 8 different pieces. In this case, we are playing with numbers from 0 to 7.

Gameplay and rules:
The object of the game is to guess a secret code. 
Each guess results in feedback that helps the codebreaker narrow down the possibilities of the code. 
The point of the game is to crack the code in the least amount of attempts possible. 
This game can is played by either one or two people. 
If a single person is playing, the program will generate a random code for you. 
If two people are playing, the code maker can create a secret code for the codebreaker to find. 

By default, the player has 10 attempts to find the secret code.
If the player(s) want more or fewer attempts, a different number can be used (see instructions below). 
After each input, the game indicates the number of well-placed pieces and the number of misplaced pieces.
A misplaced piece is a number that is present in the secret code, but it is not in a good position. 
If the player finds the code, he wins, and the game stops.

For this program, the code maker’s input is given through the command line. 
If no code is entered, the program will generate a random code. 
If the player(s) opt to enter a number of attemps or a secret code, the program requires the following parameters:
-c [CODE]: specifies the secret code. 
-t [ATTEMPTS]: specifies the number of attempts.

Let's Play!
If the game is played by a single player, he or she can enter:

gcc my_mastermind.c functions.c -o out && ./out
OR
make play
OR
gcc my_mastermind.c functions.c -o out && ./out -t 5 (5 is just an example, enter whatever number of attempts you want)


If the game is played by two people:

gcc my_mastermind.c functions.c -o out && ./out -c 1234  (the 1234 is just an example, enter whatever code you want)
OR
make play 
Note: if "make play" is selected, the code maker will not know the code in advance; therefore no teasing, and what sort of fun is that?)
OR
gcc my_mastermind.c functions.c -o out && ./out -t 5 -c 1234 (number of attempts and code are supplied by code maker)

HAVE FUN!!!
