/*
Our library for interacting with user:
*/
#include <stdio.h>
#include <string.h>

#include "UI.h"
#include "Processing.h"

//Prototypes :
char Choose();
void greeting();
void bye();
int input();
void output(char output_str[10000]);

void greeting()
{
 puts("Welcome to \"Chortke\"! :D");
}

char Choose()
{
	char str[10];
	puts("Choose a character to surf into different parts of Chortke:");
	puts("e : for entering numerical equation");
	puts("g : for showing graph of your function");
	puts("q : for quiting from Chortke :(");
	fgets(str, 10, stdin);
	return str[0];
}
int input()
{
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
