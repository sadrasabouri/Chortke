#include "./Libs/Processing.h"
#include "./Libs/UI.h"
#include "./Libs/bitmap_ploter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_SIZE 100000
#define SIZE 1000
#define ACCURACY 0.01
#define STEP_SIZE 0.01
#define INTERVAL_NUMBER 10000

#ifdef _WIN32
	#define SHOW_PLOT "plot.bmp"
#else
	#define SHOW_PLOT "display plot.bmp"
#endif

int main(){
	char option, buffer[MAX_CHAR_SIZE];
	int is_continue = 1, is_quit = 0, is_end = 0;// radius flag showing if wrong input is inputed or not.
	float y, radius, tmp_r;
	int	axis_color, screen_color, plot_color, tmp_axc, tmp_plc, tmp_scrn;
	do{
	//Initial the configs of graph | defined in UI.c
		get_graph_configs(&radius, &axis_color, &screen_color, &plot_color);
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
						y = calculate_equation(0, 0, &is_continue);//No need for x.
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
							y = calculate_equation(x, 0, &is_continue);
							if(is_continue){
								int i = (x + radius) / step;
								if (i > SIZE - 1) i = SIZE - 1;
								if (i < 0) i = 0;
								int j = (y + radius) / step;
								if (j > SIZE - 1 || j < 0) continue;
								plot[i][j] = 1;
							}
						  }
						  
						  write_bitmap((char *)plot, SIZE, SIZE, axis_color, screen_color, plot_color, "plot.bmp");
						  system(SHOW_PLOT);
						}
					}while(is_quit != 1);
				break;
			case 'p':
				do{
					printf("0 = ");
					fgets(buffer, MAX_CHAR_SIZE, stdin);
					is_quit = to_token(buffer);
					/*-- Go for different x --*/
						if(is_continue && !is_quit){
						  char plot[SIZE][SIZE] = {0};
						  float step = 2 * radius / SIZE;
						  for (float x = -radius; x < radius; x += step) {
							  for (float y_r = -radius; y_r < radius; y_r += step) {
								is_continue = 1;
								y = calculate_equation(x, y_r, &is_continue);
								if(is_continue){
									if((y > 0 ? y : (-1) * y) < 0.05){
										int i = (x + radius) / step;
										if (i > SIZE - 1) i = SIZE - 1;
										if (i < 0) i = 0;
										int j = (y_r + radius) / step;
										if (j > SIZE - 1 || j < 0) continue;
										plot[i][j] = 1;
									}
								}
							  }
						  }
						  
						  write_bitmap((char *)plot, SIZE, SIZE, axis_color, screen_color, plot_color, "plot.bmp");
						  system(SHOW_PLOT);
						}
					}while(is_quit != 1);
				break;
			case 's':
				do{
					int nthx = 1;
					printf("0 = ");
					fgets(buffer, MAX_CHAR_SIZE, stdin);
					is_quit = to_token(buffer);
					/*-- Go for different x --*/
						if(is_continue && !is_quit){
						  for (float x = -radius; x < radius; x += STEP_SIZE) {
							is_continue = 1;
							y = calculate_equation(x, 0, &is_continue);
							if(is_continue)
								if( (y > 0 ? y : (-1) * y) < ACCURACY){
									printf("X%d: %0.3f\n", nthx, x);
									nthx++;
								}
						  }
						  if(nthx == 1)
							  printf("No answer for x in the domain with accurecy of %f.\n", ACCURACY);
						}
					}while(is_quit != 1);
			break;
			case 'i':
				do{
					float a, b, integral = 0;
					char main_stream[MAX_CHAR_SIZE];
					printf("y = ");
					fgets(buffer, MAX_CHAR_SIZE, stdin);
					strcpy(main_stream, buffer);
					is_quit = to_token(main_stream);
					/*-- Go for different x --*/
						if(is_continue && !is_quit){
						  printf("a = ");
						  fgets(buffer, MAX_CHAR_SIZE, stdin);
						  to_token(buffer);//Biasing stacks
						  y = calculate_equation(0, 0, &is_continue);
						  if(is_continue)
							  a = y;
					      printf("b = ");
						  fgets(buffer, MAX_CHAR_SIZE, stdin);
						  to_token(buffer);//Biasing stacks
						  y = calculate_equation(0, 0, &is_continue);
						  if(is_continue)
							  b = y;
					      float step = (b - a) / INTERVAL_NUMBER;//(b - a) / n
						  to_token(main_stream);//Biasing stacks
						  for (float x = a; x <=b; x += step) {
							is_continue = 1;
							y = calculate_equation(x, 0, &is_continue);
							if(is_continue)
							  integral += y * step;//sigma of f(x*)dx
						  }
						  if(is_continue){
							  main_stream[strlen(main_stream) - 1] = 0;
							  printf("S(%s)dx = %.4f\n", main_stream, integral);
						  }
						}
					}while(is_quit != 1);
				break;
			case 'c':
				if(show_config(radius, axis_color, screen_color, plot_color) == 'y'){
					printf("Enter radius of your plotting(-r < x < r): ");
					scanf("%f", &tmp_r);
					printf("Enter color of axis(without 0x): ");
					scanf("%x", &tmp_axc);
					printf("Enter color of screen_color(without 0x): ");
					scanf("%x", &tmp_scrn);
					printf("Enter color of plot(without 0x): ");
					scanf("%x", &tmp_plc);
					set_graph_configs(tmp_r, tmp_axc, tmp_scrn, tmp_plc);
				}
			break;
			
			case 'q':
				is_end = 1;
			break;
	
		}
	}while(!is_end);
	return 0;
}
