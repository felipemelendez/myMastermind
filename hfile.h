#ifndef HFILE_H
#define HFILE_H

int* random_number_generator();
char* request_for_guess(); 
size_t my_strlen(char *param_1);
int my_strcmp(char* param_1, char* param_2);
char* my_strcpy(char* param_1, char* param_2);
int direct_match_finder(char* input_code, char* players_guess); 
int not_direct_match_finder(char* input_code, char* players_guess);
int* check_for_proper_input(char* players_guess);

#endif
