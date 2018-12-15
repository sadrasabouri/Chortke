/*
Main source code of "Chortke"
*/
#include <stdio.h>

#include "./Lib/UI.h"
#include "./Lib/Stack.h"
#include "./Lib/Processing.h"

int main()
{
 int is_continue, is_true = 0;
 greeting();
 do
 {
  reset();
  push_c('(');
  is_continue = input();
  push_c(')');
  if(is_continue)
  {
	while(get_i_n()!=0)
		is_true = Calculate();
	if(is_true)
  		printf("Result is : %f\n", pop_n());
  }
 }
 while (is_continue);
 bye();
 return 0;
}

