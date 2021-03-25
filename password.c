/*

   Simple Password Encrytper/decrypter
   -----------------------------------

   This is a very basic password encryption/
   decryption program which utilises an XOR
   cipher.

   All code is ANSI C90 compliant.

*/


#include "password.h"



int main (int argc, char** argv)
{
   start_password();

   return 0;
}

/*
   Starts the password function.
*/
void start_password(void)
{
   save_password();

   delete_pass();
}

/*
   A random string is generated using the key generator. The
   key is passed to 'encrypt_decrypt' and the resulting string is
   written to the password store.
*/
void save_password(void)
{
   char password[100], ref[100], encrypt[100], key[100], decrypt[100];

   printf("\nEnter your name: ");
   scanf("%s", ref);
   printf("Enter your password: ");
   scanf("%s", password);

   key_generator(key,strlen(password));
   encrypt_decrypt(password, encrypt, key);
   return_password(password, ref, encrypt, key, decrypt);
}

/*
   Random character from array is taken. This is repeated n
   times to create a random string of length n.
*/
extern void key_generator(char *key, int n)
{
   int index = 0;
   char strings[100] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

   srand((unsigned int)(time(NULL)));

   for(index = 0; index < n; index++){
      key[index] = strings[rand() % (sizeof strings - 1)];
   }

   key[index]='\0';
}

/*
   Encrypt_decrypt implements the XOR cipher. The result is stored
   into output.
*/
void encrypt_decrypt(char *input, char *output, char *key)
{
   int i;
   int len;

   len = strlen(input);

   for(i = 0; i < len; i++){
      output[i] = input[i] ^ key[i];
   }

   output[i]='\0';
}

/*
   Prints output including name, key and encrypted password.
*/
void return_password(char password[100], char ref[100], char encrypt[100],
                   char key[100], char decrypt[100])
{
   FILE *fp;

   printf("\nName: %s", ref);
   printf("\nKey: %s", key);
   printf("\nEncrypted: %s", encrypt);

   fp=fopen("oldPass.txt","a");

   if(fp == NULL){
      printf("Searching...can't find anything.\n");
   }
   else{
      fprintf(fp,"%s %s %s", ref, encrypt, key);
   }

   fclose(fp);
   printf("\n\nYour password has been encrypted and saved.\n");

   open_password(password, ref, encrypt, key, decrypt);
}

/*
   After checking ref, password store is opened and refs are
   compared. When found, the encrypt string and the key are
   decrypted.
*/
void open_password(char password[100], char ref[100], char encrypt[100],
                   char key[100], char decrypt[100])
{
   int i;
   char name[40];
   FILE *fp;

   printf("\nEnter your name: ");
   scanf("%s", name);

   fp=fopen("oldPass.txt","r");

   if(fp == NULL){
      printf("File failed to open");
   }
   else{
      for(i=0;i<40;i++){
          fscanf(fp,"%s %s %s \n", ref, encrypt, key);
          if(strcmp(ref, name)==0){
             encrypt_decrypt(encrypt, decrypt, key);
          }
      }
   }

   printf("Your decrypt password is: %s", decrypt);

   display_names(password, ref, encrypt, key, decrypt);
}

/*
   The password store is read and the references are printed
   unil the end of file.
*/
void display_names(char password[100], char ref[100], char encrypt[100],
                   char key[100], char decrypt[100])
{
   FILE *file;

   printf("\nThe name associated is: ");

   file=fopen("oldPass.txt","r");

   if(file == NULL){
      printf("File failed to open");
   }
   else{
      while(!feof(file)){
         fscanf(file, "%s %s %s \n", ref, encrypt, key);
         printf("%s", ref);
      }
   }

   start_program(password, ref, encrypt, key, decrypt);
}

/*
  This function comes before whatever program you require
  this password manager for.
*/
void start_program(char password[100], char ref[100], char encrypt[100],
                  char key[100], char decrypt[100])
{
   char name[40];
   FILE *fp;
   int i;

   printf("\nTo start the program, enter your name: ");
   scanf("%s", name);
   printf("Enter your password: ");
   scanf("%s", password);

   fp=fopen("oldPass.txt","r");

   if(fp == NULL){
      printf("\nFile failed to open");
   }
   else{
      for(i=0;i<40;i++){
         fscanf(fp,"%s %s %s \n", ref, encrypt, key);
         if(strcmp(ref, name)==0){
            break;
         }
      }
   }

   encrypt_decrypt(encrypt, decrypt, key);

   while(strcmp(password, decrypt)!=0){
      printf("Incorrect entry. Please try again: ");
      scanf("%s", password);
   }

   printf("Decrypted password %s matches password %s. \n",
          decrypt, password);
}

/*
   Deletes the password store.
*/
void delete_pass()
{
   if(remove("oldPass.txt") == 0){
      printf("Password deleted successfully.\n");
   }
   else{
    	printf("Unable to delete the vault");
   }
}
