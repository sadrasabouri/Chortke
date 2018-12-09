#include <stdio.h>

#include "./Lib/UI.h"
#include "./Lib/Stack.h"

int main()
{
	int is_continue;
	greeting();
	do
	{
		is_continue = input();
	}
	while(is_continue);
	bye();
	return 0;
}
