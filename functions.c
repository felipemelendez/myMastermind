#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hfile.h"
#define NUMBER_OF_INPUTS 4

/* Random Number Generator */
int* random_number_generator () {
    int i, j, n, temp;
    time_t second; //The time_t function takes a single argument. This is a pointer to an object of type time_t. The value of seconds is stored in this object.
    n = 7;
    int* seven_digit_random_number = (int*)malloc(sizeof(int) * n);
    /* Intializes random number generator */
    srand((unsigned) time(&second)); 
    /* creates an array of 7 numbers */
    for (i = 0; i <= n; i++) {
        seven_digit_random_number[i] = i;
    }
    /* randomly shuffles the array of numbers */
    for (i = 0; i <= n; i++) {
        j = rand() % (n + 1);
        temp = seven_digit_random_number[i];
        seven_digit_random_number[i] = seven_digit_random_number[j];
        seven_digit_random_number[j] = temp;
    } 
    /* returns 4 random numbers */
    int* four_digit_random_number = (int*)malloc(sizeof(int) * NUMBER_OF_INPUTS);
    for (i = 0; i < NUMBER_OF_INPUTS; i++) {
        four_digit_random_number[i] = seven_digit_random_number[i];
    }
    return four_digit_random_number; // an array
}

/* Request Guess */
char* request_for_guess () {
char* players_guess = (char*)malloc(NUMBER_OF_INPUTS);
    printf("Enter 4 numbers:");
    scanf("%s", players_guess);
    return players_guess;
}

/* String Length */
size_t my_strlen(char *param_1) {
    size_t length = 0;
    if(param_1 != NULL) {
        while(*param_1 != '\0') {
            length++;
            param_1++; //this is the pointer
        }
    }
    return length;
}

/* String Comparisor */
int my_strcmp(char *s1, char *s2) {
	if (s1 == NULL || s2 == NULL) {
		return 0;
	}		
	int i, diff;
	for(i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
		diff = s1[i] - s2[i];
		if (diff != 0) {
			return diff;
		}	
	}
	if (s1[i] == '\0' && s2[i] == '\0') {
		return 0;
	}
	if (s1[i] == '\0') {
		return -1;
	} else {
		return 1;
	}	
}

/* String Copier */
char* my_strcpy(char* param_1, char* param_2) {
    int i = 0;
    while (param_2[i] != '\0') {
        param_1[i] = param_2[i];
        i++;
    }
    return param_1;
}

/* Direct Match Finder */
int direct_match_finder(char* input_code, char* players_guess) {
	int direct_match_counter = 0;
	for (int i = 0; i < NUMBER_OF_INPUTS; i++) {
		if (input_code[i] == players_guess[i]) {
			direct_match_counter++;
		}	
	}
	return direct_match_counter;
}

/* Indirect Match Finder */
int not_direct_match_finder(char* input_code, char* players_guess) {
	int indirect_match_counter = 0;
	for (int i = 0; i < NUMBER_OF_INPUTS; i++) {
		for (int j = 0; j < NUMBER_OF_INPUTS; j++) {
			if (players_guess[i] == input_code[j]) {
				if (i != j) {
					indirect_match_counter++;
				}
			}
		}	
	}
	return indirect_match_counter;
}

/* Check for proper input */
int* check_for_proper_input(char* players_guess) {
	int correct_input = 1; // 1 = TRUE;
	int* players_input = &correct_input;
	/* Check for proper length */
	int count_of_numbers_entered = my_strlen(players_guess);
	if (count_of_numbers_entered > NUMBER_OF_INPUTS) {
		correct_input = 0;
	}
	/* Check for proper input (numbers from 1 to 7) */
	for (int t = 0; t < NUMBER_OF_INPUTS; t++) {
		if ((players_guess[t] < 48) || (players_guess[t] > 55)){ 
			correct_input = 0; 
			break; 
		}	
		/* Check for repeated numbers */
		for (int u = 0; u < t; u++){ 
			if (players_guess[t] == players_guess[u]){ 
				correct_input = 0;
				break;
			}
		}
	}	
	return players_input;
}
