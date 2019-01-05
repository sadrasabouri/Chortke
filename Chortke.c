#include "Processing.h"
#include "UI.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR_SIZE 10000

int main(){
	char option, buffer[MAX_CHAR_SIZE];
	int is_continue = 1, is_quit = 0, is_end = 0;// a flag showing if wrong input is inputed or not.
	float result, a, b, step, tmp_f ,tmp_e ,tmp_s;
	
	get_graph_configs(&a, &b, &step);
	do{
		get_graph_configs(&a, &b, &step);
		clear();
		greeting();
		option = Choose();//A UI.c function to let user choose the type he wants to work with. 
		switch(option){
			case 'e':
				do{
					is_continue = 1, is_quit = 0;
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
							for(float x = a; x <= b; x += step){
							is_continue = 1;
								result = calculate_equation(x, &is_continue);
								if(is_continue)
									printf("( %f , %f )\n", x, result);
							}
					}
					}while(is_quit != 1);
				break;
			case 'c':
				if(show_config(a, b, step) == 'y'){
					printf("Enter first point of plotting: ");
					scanf("%f", &tmp_f);
					printf("Enter end point of plotting: ");
					scanf("%f", &tmp_e);
					printf("Enter step of plotting: ");
					scanf("%f", &tmp_s);
					set_graph_configs(tmp_f, tmp_e, tmp_s);
				}
			break;
			case 'q':
				is_end = 1;
			break;
		}
	}while(!is_end);
	return 0;
}
