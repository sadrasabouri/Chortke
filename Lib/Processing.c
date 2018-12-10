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
float a, b;//Two number we want to calculate them in each section.

int put_in()
{
 char c, tmp[50], statement[10000];
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
    push_n(atof(tmp));
   }
   i = 0;
   /* --- End of Process --- */

   if(c == '+' || c == '-' || c == '/' || c == '*' || c == ')' || c == '(') // operator poping
    {
	push_c(c);
    }
   if(c == '\n')
    break;
  }
  statement[k++] = c; 
 }
 statement[k] = 0;
 return strcmp(statement, "quit");
}

void Calculate(){
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
   b = pop_n();
   Calculate();
   push_n(a + b);  
  break;
  case '-':
   a = pop_n();
   b = pop_n();
   Calculate();
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
   push_n(b / a);
   Calculate();  
  break;
 }
}


