/*
 *	-- nebula --
 *	stong but yet typing friendly-password generator
 *
 *	by batzilo
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#define N_ARG 2

// used after malloc
void oom() {
    fprintf(stderr, "Out of memory!\n");
    exit(1);
}

// return true if char array num represent a number
int is_number( char *num )
{
	int i=0;
	while ( num[i] != '\0' )
	{
		if isdigit(num[i]) i++;
		else return 0;
	}
	return 1;
}

// argument check
void arg_check( int argc, char *argv[] )
{
	if ( argc != N_ARG )
	{
		fprintf(stderr, "Usage Error! ");
		if ( argc>N_ARG ) fprintf(stderr, "Too many arguments\n");
		else fprintf(stderr, "Not enough arguments\n");
		fprintf(stderr, "\tUsage :\t%s <passoword-length>\n", argv[0]);
		fprintf(stderr, "\te.g :\t%s 8\n", argv[0]);
		exit(1);
	}
	if ( !is_number(argv[1]) ) 
	{
		fprintf(stderr, "Arguments Error!\n");
		fprintf(stderr, "\tArgument \"%s\" is not a valid password length\n", argv[1]);
		exit(1);
	}
	return;
}

int main( int argc, char *argv[] )
{
	arg_check(argc, argv);
	srand(time(NULL));
	int N = atoi(argv[1]);

	char left[] = { '`', '~', '1', '!', '2', '@', '3', '#', '4', '$', '5', '%',
			'q', 'Q', 'w', 'W', 'e', 'E', 'r', 'R', 't', 'T',
			'a', 'A', 's', 'S', 'd', 'D', 'f', 'F', 'g', 'G',
			'z', 'Z', 'x', 'X', 'c', 'C', 'v', 'V', 'b', 'B' };

	char right[]= { '6', '^', '7', '&', '8', '*', '9', '(', '0', ')', '-', '_', '=', '+', '\\', '|',
			'y', 'Y', 'u', 'U', 'i', 'I', 'o', 'O', 'p', 'P', '[', '{', ']', '}',
			'h', 'H', 'j', 'J', 'k', 'K', 'l', 'L', ';', ':', '\'', '\"',
			'n', 'N', 'm', 'M', ',', '<', '.', '>', '/', '?' };

	int left_length = 42;
	int right_length = 52;

	int i;
	char c, *password;
	password = malloc(sizeof(char)*N);
    if (!password) oom();

    // make the password
	for (i=0;i<N;i++)
	{
		if ( i%2==0 ) c = right[ rand() % right_length ];
		else c = left[ rand() % left_length ];
		password[i] = c;
	}
	password[i]='\0';

	printf("%s\n", password);
	return 0;
}
