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
  push_c('(');
  is_continue = input();
  push_c(')');
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

