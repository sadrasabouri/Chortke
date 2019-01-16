#include "Processing.h"
#include "UI.h"
#include "bitmap_ploter.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR_SIZE 100000
#define SIZE 1000

int main(){
	char option, buffer[MAX_CHAR_SIZE];
	int is_continue = 1, is_quit = 0, is_end = 0;// radius flag showing if wrong input is inputed or not.
	float y, radius, tmp_r;
	int	axis_color, plot_color, tmp_axc, tmp_plc;
	do{
	//Initial the configs of graph | defined in UI.c
		get_graph_configs(&radius, &axis_color, &plot_color);
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
						y = calculate_equation(0, &is_continue);//No need for x.
					if(is_continue && is_quit == 0)
						printf("%f\n", y);
					}while(is_quit != 1);
				
			break;
			case 'g':
				do{
					printf("y = ");
					fgets(buffer, MAX_CHAR_SIZE, stdin);
					is_quit = to_token(buffer);
					/*-- Go for different x --*/
						if(is_continue && !is_quit){
						  char plot[SIZE][SIZE] = {0};
						  float step = 2 * radius / SIZE;
						  for (float x = -radius; x < radius; x += step) {
							is_continue = 1;
							y = calculate_equation(x, &is_continue);
							if(is_continue){
								int i = (x + radius) / step;
								if (i > SIZE - 1) i = SIZE - 1;
								if (i < 0) i = 0;
								int j = (y + radius) / step;
								if (j > SIZE - 1 || j < 0) continue;
								plot[i][j] = 1;
							}
						  }
						  
						  write_bitmap((char *)plot, SIZE, SIZE, axis_color, plot_color, "plot.bmp");
						}
					}while(is_quit != 1);
				break;
			case 'c':
				if(show_config(radius, axis_color, plot_color) == 'y'){
					printf("Enter radius of your plotting(-r < x < r): ");
					scanf("%f", &tmp_r);
					printf("Enter color of axis(without 0x): ");
					scanf("%x", &tmp_axc);
					printf("Enter color of plot(without 0x): ");
					scanf("%x", &tmp_plc);
					set_graph_configs(tmp_r, tmp_axc, tmp_plc);
				}
			break;
			case 'q':
				is_end = 1;
			break;
		}
	}while(!is_end);
	return 0;
}
