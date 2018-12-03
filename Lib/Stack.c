/*
Stack code
Last update by Sadra Sabouri @ 1:00 PM | 3 December 2018.
*/
#include <stdio.h>

#define SIZE 50

int I_n = -1, I_c = -1;
int pop_n(int arr[]);//arr : the stack that we want to pop.
void push_n(int arr[], int x);//arr : the stack that we want to push in | x : the number wanted to be pushed.

char pop_c(char arr[]);//arr : the stack that we want to pop.
void push_c(char arr[], char x);//arr : the stack that we want to push in | x : the number wanted to be pushed.


int main(){
  int stack[SIZE], n;
  char c;
  do{
    printf("What do you want?('p' for pop | 'P' for Push and | 'q' for quit)\n:");
    scanf(" %c", &c);
	switch (c){
	  case 'p':
	    printf("-----> %d\n", pop(stack));
	  break;
	  case 'P':
		printf("Enter your number you want to push: ");
		scanf("%d", &n);
		push(stack, n);
		printf("Done!\n");
	  break;
	}
  }while(c != 'q');
  return 0;
}

int pop(int arr[]){
  if (I_n >= 0) // Stack isn't empty!
    return arr[I_n--];//pop the late added number to stack and move pointer one block back.
  else
	  printf("Stack is Empty:)\n");
}
void push(int arr[], int x){
  arr[++I_n] = x;//set the (i+1)th block to x and then move pointer one block forward.
}
