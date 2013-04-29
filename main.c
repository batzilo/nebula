/*
 *	-- nebula --
 *	stong but yet typing friendly-password generator
 *
 *	by batzilo
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N_ARG 2

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
	printf("Arguments ok!\n");
	return 0;
}
