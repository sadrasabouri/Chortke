#include "Processing.h"
#include "UI.h"
#include <stdio.h>

#define MAX_CHAR_SIZE 10000

int main(){
	char option, buffer[MAX_CHAR_SIZE];
	int is_continue = 1;
	float result;
	greeting();
	option = Choose();
	switch(option){
		case 'e':
			do{
			printf("= ");
			fgets(buffer, MAX_CHAR_SIZE, stdin);
			result = calculate_equation(buffer, 0, &is_continue);
			if(is_continue != 0)
				printf("%f\n", result);//Buggy is_continue for diffrent sit
			
			}while(is_continue != 0);
		break;
	}
	return 0;
}
