#include <stdio.h>
#include <string.h>

#include ".\Lib\UI.h"

int main()
{
	char statement[10000];
	greeting();
	do
	{
		
		input(&statement[0]);
		output(statement);
		
	}
	while(strcmp(statement, "quit"));
	bye();
	return 0;
}
