/*
Our library for interacting with user:
*/
#include <stdio.h>
#include <string.h>

#include "UI.h"
#include "Processing.h"

//Prototypes :
void greeting();
void bye();
void input(char *input_str);
void output(char output_str[10000]);

void greeting()
{
	char str[] = "Welcome to \"Chortke\"!"; // Add description!
	puts(str);
}

void input(char *input_str)
{
	char str[] = "Please input your algebraic equation : ";	// Add description!
	puts(str);
	put_in(input_str);
}

void output(char output_str[10000])
{
	puts(output_str);
}

void bye()
{
	char str[] = "Bye!\nCome back Soon ;)"; // Add description!
	puts(str);
}


/*
Sharif university of technology
Fall 2018
Bubble Team!
*/
