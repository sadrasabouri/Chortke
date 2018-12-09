/*
Our library for string processing :
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Processing.h"

int put_in();

int put_in()
{
	char c, tmp[50], statement[10000];
	int is_on_num = 0, i = 0, k = 0;
	while(1)
	{
		c = getchar();
		if(( '0' <= c && c <= '9' )|| c == '.')//if character is number of dots.
			tmp[i++] = c;
		else
		{
			if(i != 0)
			{
				tmp[i] = 0;
				push_n(atof(tmp));
			}
			i = 0;
			if(c == '+' || c == '-' || c == '/' || c == '*' || c == ')' || c == '(')
				push_c(c);
			if(c == '\n')
				break;
		}
		statement[k++] = c; 
	}
	statement[k] = 0;
	return strcmp(statement, "quit");
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
