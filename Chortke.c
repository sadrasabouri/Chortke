#include "Processing.h"
#include "UI.h"
#include "bitmap_ploter.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR_SIZE 10000
#define SIZE 1000

int main(){
	char option, buffer[MAX_CHAR_SIZE];
	int is_continue = 1, is_quit = 0, is_end = 0;// a flag showing if wrong input is inputed or not.
	float result, a, b, step, tmp_f ,tmp_e ,tmp_s;
	do{
	//Initial the configs of graph | defined in UI.c
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
					printf("y = ");
					fgets(buffer, MAX_CHAR_SIZE, stdin);
					is_quit = to_token(buffer);
					/*-- Go for different x --*/
						
						char plot[SIZE][SIZE] = {0};
						float w = 5.0, step = 2 * w / SIZE;
						if(is_continue && !is_quit){
						  for (float x = -w; x < w; x += step) {
							is_continue = 1;
							float y = calculate_equation(x, &is_continue);
							if(is_continue){
								int i = (x + w) / step;
								if (i > SIZE - 1) i = SIZE - 1;
								if (i < 0) i = 0;
								int j = (y + w) / step;
								if (j > SIZE - 1 || j < 0) continue;
								plot[i][j] = 1;
							}
						  }/*
								for(float x = a; x <= b; x += step){
								is_continue = 1;
									result = calculate_equation(x, &is_continue);
									
								if(is_continue)
										printf("( %f , %f )\n", x, result);
								}
							*/
						}
					  write_bitmap((char *)plot, SIZE, SIZE, "plot.bmp");
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
