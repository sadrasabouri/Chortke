/*
Our library for string processing :
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Processing.h"

int put_in();
void Calculate();

char c;

int put_in()
{
 char c, tmp[50], statement[10000], last_operator;
 int is_on_num = 0, i = 0, k = 0;
 while(1)
 {
  c = getchar();
  /* --- Process of casting number to its stack --- */  
  if(( '0' <= c && c <= '9' )|| c == '.')//if character is number of dots.
   tmp[i++] = c;
  else
  {
   if(i != 0)
   {
    tmp[i] = 0;
    push_n(strtod(tmp, NULL));
   }
   i = 0;
   /* --- End of Process --- */

   switch (c)
   {
	case '-':
		push_n(0);//It should push a ( and ) before pushing 0 then.
	case '+':
	case '*':
	case '/':
	case '(':
	case ')':
		push_c(c);
	break;
   }//ignoring spaces!
   if(c == '\n')
    break;
  }
  statement[k++] = c; 
 }
 statement[k] = 0;
 return strcmp(statement, "quit");
}

void Calculate(){
float a, b;//Two number we want to calculate them in each section.
 
 c = pop_c();
 switch (c) // Switch on poped character.
 {
  case ')':
   Calculate();  
  break;
  case '(':
   return;
  break;  
  case '+':
   a = pop_n();
   Calculate();
   b = pop_n();
   push_n(a + b);  
  break;
  case '-':
   a = pop_n();
   Calculate();
   b = pop_n();
   push_n(b - a);  
  break;  
  case '*':
   a = pop_n();
   b = pop_n();
   push_n(a * b);
   Calculate();  
  break;
  case '/':
   a = pop_n();
   b = pop_n();
   if (a != 0)
   	push_n(b / a);
   else
	{
	puts("Divided by 0! :D\n");
	return;	
	}
   Calculate();  
  break;
 }
}


