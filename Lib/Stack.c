/*
Stack code
Last update by Hanieh Tajer && Amirali Ekhteraee && Sadra Sabouri  @ 7:10 PM | 3 December 2018.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>	

#define SIZE 50

int num_stack[SIZE];
char char_stack[SIZE]; 
int I_n = -1, I_c = -1;
int pop_n(int arr[]);//arr : the num_stack that we want to pop.
void push_n(int arr[], int x);//arr : the num_stack that we want to push in | x : the number wanted to be pushed.

char pop_c(char arr[]);//arr : the num_stack that we want to pop.
void push_c(char arr[], char x);//arr : the num_stack that we want to push in | x : the number wanted to be pushed.


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

int pop_n(int arr[]){
  if (I_n >= 0) // Stack isn't empty!
    return arr[I_n--];//pop the late added number to num_stack and move pointer one block back.
  else
	  printf("Stack is Empty:)\n");
}
void push_n(int arr[], int x){
  arr[++I_n] = x;//set the (i+1)th block to x and then move pointer one block forward.
}

char pop_c(char arr[]){
  if (I_c >= 0) // Stack isn't empty!
    return arr[I_c--];//pop the late added number to num_stack and move pointer one block back.
  else
	  printf("Stack is Empty:)\n");
}
void push_c(char arr[], char x){
  arr[++I_c] = x;//set the (i+1)th block to x and then move pointer one block forward.
}
