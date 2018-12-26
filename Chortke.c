#include "Processing.h"
#include "UI.h"
#include <stdio.h>

#define MAX_CHAR_SIZE 10000

int main(){
	char option, buffer[MAX_CHAR_SIZE];
	int is_continue = 1;// a flag showing if wrong input is inputed or not.
	float result;
	greeting();
	option = Choose();//A UI.c function to let user choose the type he wants to work with. 
	switch(option){
		case 'e':
			do{
			printf("= ");
			fgets(buffer, MAX_CHAR_SIZE, stdin);
			
			result = calculate_equation(buffer, 0, &is_continue);
			if(is_continue == 1)
				printf("%f\n", result);
			}while(is_continue != -1);
			
		break;
	}
	return 0;
}
