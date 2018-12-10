#include <stdio.h>

#include "./Lib/UI.h"
#include "./Lib/Stack.h"
#include "./Lib/Processing.h"

int main()
{
 int is_continue;
 greeting();
 do
 {
  is_continue = input();
  if(is_continue)
  {
	Calculate();
  	printf("Result is : %f\n", pop_n());
  }
 }
 while (is_continue);
 bye();
 return 0;
}

