/*
Our library for string processing :
*/
#include <string.h>
#include <stdio.h>
#include "Stack.h"
#include "Processing.h"

void put_in(char *input_str);

void put_in(char *input_str)
{
	/*
	
	Your Work Here!
	To push in operators : push_c(c);
	which c is character!
	like : push_c('+');
	
	To push in operators : push_n(a);
	which c is character!
	like : push_n(52.1);
	*/
	
	/*
		
	--- This code erase spaces ---
	
	char tmp[10000];
	gets(tmp);
	int i, n = strlen(tmp), j = 0;

	for (i = 0; i < n; ++i)
		if(tmp[i] != ' ')
			*( input_str + j++ ) = tmp[i];
	*( input_str + j ) = 0;
	*/
	
	
	/* 
	--- This code doesn't erase spaces ---
	for (i = 0; i < n; ++i)
		*( input_str + i ) = tmp[i];
	*( input_str + i ) = 0;
	*/
}