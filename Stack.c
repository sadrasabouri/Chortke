/*
Stack code
*/

#include "Stack.h"

#define SIZE 50

struct oprand_stacks {
	int i;
	float stack[SIZE];
} numbers;//Stack for float numbers.

struct operator_stacks {
	int i;
	char stack[SIZE];
} chars;//Stack for characters.

void initial(){
	numbers.i = -1;
	chars.i = -1;
}

float pop_n();
void push_n(float x);// x : the number wanted to be pushed.
int get_i_n();

char pop_c();
char get_top();
void push_c(char x);// x : the character wanted to be pushed.
char show_last_c();
int get_i_c();


int get_i_n(){
  return numbers.i;
}
int get_i_c(){
  return chars.i;
}



float pop_n(){
  if (numbers.i >= 0) // Stack isn't empty!
    return numbers.stack[numbers.i--];//pop the late added number to numbers and move pointer one block back.
}
void push_n(float x){
  numbers.stack[++numbers.i] = x;//set the (i+1)th block to x and then move pointer one block forward.
}



char pop_c(){
  if (chars.i >= 0) // Stack isn't empty!
    return chars.stack[chars.i--];//pop the late added number to numbers and move pointer one block back.
}
char get_top(){
	  if (chars.i >= 0) // Stack isn't empty!
			return chars.stack[chars.i];//pop the late added number to numbers.
}
void push_c(char x){
  chars.stack[++chars.i] = x;//set the (i+1)th block to x and then move pointer one block forward.
}

char show_last_c(){
  if (chars.i >= 0) // Stack isn't empty!
    return chars.stack[chars.i];//get back the last one.
  else
	  return -1;
}
/*
--- For testing stack.h ---
int main(){
  push_c('+');
  push_c('-');
  push_c('*');
  push_c('/');
  
  push_n(1.22);
  push_n(1.254);
  push_n(455.1);
  push_n(2.4);
  printf("%f %c\n", pop_n(), pop_c());
  
  printf("%f %c\n", pop_n(), pop_c());
  
  printf("%f %c\n", pop_n(), pop_c());
  
  printf("%f %c\n", pop_n(), pop_c());
  return 0;
}
*/