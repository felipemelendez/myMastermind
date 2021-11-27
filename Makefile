play:
	gcc -Wall -Wextra -Werror my_mastermind.c functions.c -o out && ./out

coded:
	gcc -Wall -Wextra -Werror my_mastermind.c functions.c -o out && ./out -c 1234 -t 8

play2:
	gcc -Wall -Wextra -Werror my_mastermind.c functions.c -o out && ./out -t 3
