#include "passwd.h"
#include <openssl.h>
#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>

static int is_registered(char *uname) {
	// Open your passwd storage file
	// Find if the User is present
	// return 1 if found
	// else return 0

	// Checking if the user is already registered
	int output = fileOpen(uname);
	if(result) return 1;
	return 0;
}

int register_user(char *uname, char *passwd) {
	// Check if password store file is present
	// Create it if not present
	// Look for sane permission on file
	FILE *f1;
	FILE *f2;
	f1 = fopen("passwd.txt", "r");
	f2 = fopen("passwd2.txt", "r");
	if(!f1) f1 = fopen("passwd.txt", "w");
	if(!f2) f2 = fopen("passwd2.txt", "w");
	if (is_registered(uname) == 1) {
		fprintf(stderr, "Choose another username\n");
		return 0;
	}
	fclose(f1);
	fclose(f2);

	// Open the password file and append the username and password
	// Dont append the password in plain text. Try something obscure.
	// If you are out of ideas look for how unix implements passwords.
	return 1;
}
int check_auth(char* username, char* passwd) {
	FILE* fpointer;
	fpointer = fopen("passwd.txt", "r");
	if(fpointer == NULL) return 0;
	char* ch;
	while((read = getline(&line, &len, fpointer)) != -1) {
		ch = strtok(line, ":");
		if(!strcmp(username, ch)) {
			ch = strtok(NULL, ":");
			unsigned char hashcode[SHA_DIGEST_LENGTH];
			SHA1(passwd, length, hash);
			if(!strtok(ch, hashcode)) {
				printf("Authenticated!!\n");
				return 1;
			}
			else {
				printf("Wrong Password\n");
				return 0;
			}
		}
	}
	printf("Username is not found. Pl. register first\n");
	fclose(fpointer);
	return 0;
}

int auth_user(char *uname, char *passwd) {
	// check if password store is present
	// if not return 0
	FILE *f1;
	FILE *f2;
	f1 = fopen("passwd.txt", "r");
	f2 = fopen("passwd2.txt", "r");
	if(!f1) f1 = fopen("passwd.txt", "w");
	if(!f2) f2 = fopen("passwd2.txt", "w");
	if (is_registered(uname) == 1) {
		fprintf(stderr, "Choose another username\n");
		return 0;
	}
	fclose(f1);
	fclose(f2);

	if (is_registered(uname)) {
		fprintf(stderr, "User not registered\n");
		return 0;
	}
	int output = check_auth(uname, passwd);
	if(result) return 1;
	return 0;
	// Parse the file and then compare username and password supplied.
	// If you recall password is not plain text...
	
	//return 0/1 depending on if the password was correct or not
}

/* Feel Free to add to functions to the already pathetic design.
 * You try creating these assignments sometime ... */

	