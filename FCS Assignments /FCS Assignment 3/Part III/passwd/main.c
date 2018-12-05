#include <stdio.h>
#include "passwd.h"
#include <string.h>
#include <unistd.h>
#include <getopt.h>


int main(int argc, char *argv[])
{
	// Handle options using getopt
	//
	// Process aut/reg
	// exit cleanly if all was well
	// else exit with a non-0 return val

	const int MAX_SIZE = 256;
	int _register;
	int option = 0;
	// Taking the arguments from the terminal in the form of -r and -a. All others are invalid
	while((option == getopt(argc, argv, "ra")) != -1) {
		if(option == 'r')
			_register = 1;
		else if(option == 'a')
			_register = 0;
		else 
			printf("Wrong Arguments. Pl. Enter again...\n");_
	}
	char username[MAX_SIZE];
	char* password;
	if(_register == 1) {
		// Registering the user
		scanf("%s", username);
		password = getpass("Enter Password");
		int output = register_user(username, password);
		if(result == 0) return 0;
		else {
			printf("User registered");
		}
	}
	else if(!_register) {
		// Logging in the user
		scanf("%s", username);
		password = getpass("Enter Password");
		auth_user(username, password);
	}
	return 0;
}
