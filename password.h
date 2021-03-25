/*

   File Contains all functions for the password
   encrypter/decrypter.

   I could have used global variables but I resisted the
   temptation because I have been taught to not use them
   in C.
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>



void start_password(void);

void return_password(char password[100], char ref[100],
                     char encrypt[100], char key[100], char decrypt[100]);

void start_program(char password[100], char ref[100],
                   char encrypt[100], char key[100], char decrypt[100]);

void save_password(void);

extern void key_generator(char *key, int n);

void encrypt_decrypt(char *input, char *output, char *key);

void open_password(char password[100], char ref[100],
                   char encrypt[100], char key[100], char decrypt[100]);

void display_names(char password[100], char ref[100], char encrypt[100],
                   char key[100], char decrypt[100]);

void delete_pass(void);
