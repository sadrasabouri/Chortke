/*
Stack code
Last update by Hanieh Tajer && Amirali Ekhteraee && Sadra Sabouri  @ 7:10 PM | 3 December 2018.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#include "Stack.h"

#define SIZE 50

float num_stack[SIZE];//Our Stack for float numbers.
char char_stack[SIZE]; // And for characters.
int I_n = -1, I_c = -1;

void reverse();
float pop_n();
void push_n(float x);// x : the number wanted to be pushed.
int get_i_n();

char pop_c();
void push_c(char x);// x : the number wanted to be pushed.
char show_last_c();
int get_i_c();

int get_i_n(){
  return I_n;
}
int get_i_c(){
  return I_c;
}
float pop_n(){
  if (I_n >= 0) // Stack isn't empty!
    return num_stack[I_n--];//pop the late added number to num_stack and move pointer one block back.
  else
   printf("Stack is Empty:)\n");
}
void push_n(float x){
  num_stack[++I_n] = x;//set the (i+1)th block to x and then move pointer one block forward.
}

char pop_c(){
  if (I_c >= 0) // Stack isn't empty!
    return char_stack[I_c--];//pop the late added number to num_stack and move pointer one block back.
  else
   printf("Stack is Empty:)\n");
}
char show_last_c(){
  if (I_c >= 0) // Stack isn't empty!
    return char_stack[I_c];//get back the last.
  else
   printf("Stack is Empty:)\n");
}
void push_c(char x){
  char_stack[++I_c] = x;//set the (i+1)th block to x and then move pointer one block forward.
}
void reverse(){
	int tmp_num, n1 = I_n + 1, n2 = I_c + 1;
	char tmp_char;
	for(int i = 0; i < n1; ++i){
	tmp_num = num_stack[i];
	num_stack[i] = num_stack[n1 - i - 1];
	num_stack[n1 - i - 1] = tmp_num;	
	}	
	for(int j = 0; j < n2; ++j){
	tmp_char = char_stack[j];
	char_stack[j] = char_stack[n2 - j - 1];
	char_stack[n2 - j - 1] = tmp_char;	
	}
}
/*
  ---- For test Stack.c ---
int main(){
  int t = 0;
  char c, tmp[20];
  do{
    printf("What do you want?('p' for pop | 'P' for Push and | 'q' for quit)\n:");
    scanf(" %c", &c);
 switch (c){
   case 'p':
  if (t % 2 == 0)
   printf("-----> %d\n", pop_n(num_stack));
  else
   printf("-----> %c\n", pop_c(char_stack));
  ++t;
   break;
   case 'P':
  printf("Enter your number you want to push: ");
  scanf("%s", tmp);
  if(strlen(tmp) == 1)
   if (tmp[0] >= '0' && tmp[0] >= '9')
    push_n(num_stack, tmp[0] - '0');
   else
    push_c(char_stack, tmp[0]);
  else
   push_n(num_stack, atoi(tmp));// atoi returns int~
  printf("Done!\n");
   break;
   case 'q':
  break;
   break;
   default :
  printf("Invalid input :P!\n");
   break;
 }
  }while(c != 'q');
  return 0;
}
*/
