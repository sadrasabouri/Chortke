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
				is_quit = to_token(buffer);
				
				/*-- Go for different x --*/
				if(is_continue && !is_quit){
						for(float x = -10; x < 10; x += 0.1){
							result = calculate_equation(x, &is_continue);
							printf("( %f , %f )\n", x, result);
						}
				}
				}while(is_quit != 1);
			break;
	}
	return 0;
}
