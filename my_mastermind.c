#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hfile.h"
#define NUMBER_OF_INPUTS 4

int main (int argc, char **argv) {
	/* call random code generator and typecast to a string so it can be matched to player's input (argv entries are strings) */
	char* random_number_string = malloc(sizeof(char) * NUMBER_OF_INPUTS);
	int* random_number_integer = malloc(sizeof(int) * NUMBER_OF_INPUTS);
	random_number_integer = random_number_generator();
	for (int i = 0; i < NUMBER_OF_INPUTS; i++) {
		random_number_string[i] = random_number_integer[i] + '0';
	}
	char* player_input_code = malloc(sizeof(char) * NUMBER_OF_INPUTS);
	my_strcpy(player_input_code, random_number_string);
	/* search command line for code */
	int index_of_player_input_code;
	for (int i = 1; i < argc; i++){
		if ((my_strcmp(argv[i], "-c") == 0)) {
			index_of_player_input_code = i + 1;
			my_strcpy(player_input_code, argv[index_of_player_input_code]);	
		}	                              
	}
	/* find Player's desired attempts, if no attempts entered the default is 10 */
	char* desired_attempts = malloc(sizeof(char) * 2); // max would be 99 (2 digit number)
	if ((argc == 1)  || (index_of_player_input_code == '0')) {
		desired_attempts = "10";
	} else {
		int index_of_desired_attempts;
		for (int j = 1; j < argc; j++){
			if ((my_strcmp(argv[j], "-t") == 0)) {
				index_of_desired_attempts = j + 1;
				my_strcpy(desired_attempts, argv[index_of_desired_attempts]);	
			}	
		}
	}
	printf("You have %s attempts, use them wisely.\n\n", desired_attempts);
	int number_of_attempts_given = atoi(desired_attempts);	
	/* Check for proper input */ 
	char* input_guess;
    char* players_guess = malloc(sizeof(char) * NUMBER_OF_INPUTS);
	int number_of_direct_matches, number_of_indirect_matches;
	printf("Please enter 4 numbers between 0 and 7, and do not repeat the numbers you enter\n\n");
	int number_of_attempts = 0; 
	while (number_of_direct_matches != 4 && number_of_attempts < number_of_attempts_given) {
		if (number_of_attempts > 0) {
			printf("This is your %i attempt, choose wisely.\n\n", number_of_attempts + 1);
		}
		number_of_attempts++;
		input_guess = request_for_guess(); 
  	    players_guess = malloc(sizeof(char) * NUMBER_OF_INPUTS);
		my_strcpy(players_guess, input_guess);
		/* Check for proper input */ 
		int* input_check = check_for_proper_input(players_guess);
		int proper_input = *input_check; 
		if (proper_input != 1) {
			printf("-----------------------------------------------------------------------------\n");
			printf("You have chosen poorly.\n");
			printf("Please enter 4 numbers between 0 and 7, and do not repeat the number you enter\n");
			printf("______________________________________________________________________________\n");
			input_check = check_for_proper_input(players_guess);
			proper_input = *input_check; 
		}
		if (proper_input == 1) {
			number_of_direct_matches = direct_match_finder(player_input_code, players_guess);
			printf("\n--------------------------------------\n");
			printf("$       Well placed pieces: %d        $\n", number_of_direct_matches);
			printf("--------------------------------------\n\n");
			number_of_indirect_matches = not_direct_match_finder(player_input_code, players_guess);
			printf("--------------------------------------\n");
			printf("$         Misplaced pieces: %d        $\n", number_of_indirect_matches);
			printf("--------------------------------------\n\n");
		}	
	} 
	if (number_of_direct_matches == NUMBER_OF_INPUTS) {
		printf(">----------------------------------------------------------------------------<\n");
		printf(">***************************     Great Success!    **************************<\n");
		printf(">*********************  You have chosen wisely; You Win!  ********************<\n");
		printf(">----------------------------------------------------------------------------<\n\n");
	}
	if (number_of_attempts == number_of_attempts_given) {
		printf(">----------------------------------------------------------------------------<\n");
		printf(">******************************     You Lose!    ****************************<\n");
		printf(">----------------------------------------------------------------------------<\n\n");
	}
  return 0;
}
