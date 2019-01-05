#include "Processing.h"
#include "UI.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR_SIZE 10000

int main(){
	char option, buffer[MAX_CHAR_SIZE];
	int is_continue = 1, is_quit = 0;// a flag showing if wrong input is inputed or not.
	float result;
	(system("cls")||system("clear")); 
	greeting();
	
	option = Choose();//A UI.c function to let user choose the type he wants to work with. 
	switch(option){
		case 'e':
			do{
				printf("= ");
				fgets(buffer, MAX_CHAR_SIZE, stdin);
				is_quit = to_token(buffer);
				if(is_continue && !is_quit)
					result = calculate_equation(0, &is_continue);//No need for x.
				if(is_continue && is_quit == 0)
					printf("%f\n", result);
				}while(is_quit != 1);
			
		break;
		case 'g':
			do{
				printf("= ");
				fgets(buffer, MAX_CHAR_SIZE, stdin);
				to_token(buffer);
				
				result = calculate_equation(0, &is_continue);
				if(is_continue == 1)
					printf("%f\n", result);
			}while(is_continue != -1);
		break;
	}
	return 0;
}
