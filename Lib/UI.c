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
int input();
void output(char output_str[10000]);

void greeting()
{
 char str[] = "Welcome to \"Chortke\"!"; // Add description!
 puts(str);
}

int input()
{
 char str[] = "Please input your algebraic equation (Or \"quit\" for exit from program): "; // Add description!
 puts(str);
 return put_in();
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
