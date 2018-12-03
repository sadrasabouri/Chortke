/*
Our library for string processing :
*/
#include <string.h>
#include <stdio.h>

#include "Processing.h"

void put_in(char *input_str);

void put_in(char *input_str)
{
	char tmp[10000];
	gets(tmp);
	int i, n = strlen(tmp), j = 0;

	for (i = 0; i < n; ++i)
		if(tmp[i] != ' ')
			*( input_str + j++ ) = tmp[i];
	*( input_str + j ) = 0;
	
	/* This code doesn't erase spaces
	for (i = 0; i < n; ++i)
		*( input_str + i ) = tmp[i];
	*( input_str + i ) = 0;
	*/
}