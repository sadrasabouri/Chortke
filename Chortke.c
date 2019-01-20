<<<<<<< HEAD
/*
Main source code of "Chortke"
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Stack.h"

#define MAX_CHAR_SIZE 100
#define MAX_TOKEN 20
#define MAX_NUBER_SIZE 10

int anti_space(char *spaced_one,char *none_spaced_one);
int check(char *str);
int is_ok(int x);
int is_operator(char c);
int is_digit(char c);
char to_forward(char* str, int i);
char to_downward(char* str, int i);
void error(char* buffer);
int calc();
int is_num(char str[]);
int get_precendence(char op);

int main()
{
	char buffer[MAX_CHAR_SIZE], main_stream[MAX_CHAR_SIZE];
	do{
	printf(" = ");
	initial();
	fgets(buffer, MAX_CHAR_SIZE, stdin);
	if(anti_space(buffer, main_stream)){
		if( is_ok(check(main_stream)) ){
			char tokens[MAX_TOKEN][MAX_NUBER_SIZE], num_tmp[MAX_TOKEN];
			char c;
			int i = 0, k = 0, n = 0;
			while( (c = main_stream[k]) != 0){
				if(is_digit(c) || c == '.')//if character is number of dots.
					num_tmp[i++] = c;
				else{
					switch(c){
						case '-':
							if(k == 0 || main_stream[k - 1] == '(') // negetive numbers.
									num_tmp[i++] = c;	
							else{
								if(i != 0){
								num_tmp[i] = 0;
								strcpy(tokens[n++], num_tmp);
								}
								tokens[n][0]= c;
								tokens[n++][1] = 0; // To make it string.
								i = 0;
								}
						break;
						//All operators:
						case '+':
						case '*':
						case '/':
						case '^':
						case '!':
						case '(':
						case ')':
							if(i != 0){
								num_tmp[i] = 0;
								strcpy(tokens[n++], num_tmp);
							}
							tokens[n][0]= c;
							tokens[n++][1] = 0; // To make it string.
							i = 0;
						break;
						case 's':
							if(!strncmp(main_stream + k, "sin", 3))
							{
								strcpy(tokens[n++], "sin");
								k = k + 2;
							}
							else
								error(buffer);
						break;
						
						case 'c':
							if(!strncmp(main_stream + k, "cos", 3))
							{
								strcpy(tokens[n++], "cos");
								k = k + 2;
							}
							else 
								error(buffer);
						break;
						
						case 't':
							if(!strncmp(main_stream + k, "tan", 3))
							{
								strcpy(tokens[n++], "tan");
								k = k + 2;
							}
							else error(buffer);
						break;
						
						case 'e':
							if(!strncmp(main_stream + k, "exp", 3))
							{
								strcpy(tokens[n++], "exp");
								k = k + 2;
							}
							else
								error(buffer);
						break;
						
						case 'l':
							if(!strncmp(main_stream + k, "ln", 2))
							{
								strcpy(tokens[n++], "ln");
								k = k + 1;
							}
							else
								error(buffer);
						break;
						
						case 'a':
							if(!strncmp(main_stream + k, "abs", 3))
							{
								strcpy(tokens[n++], "abs");
								k = k + 2;
							}
							else
								error(buffer);
						break;
						
						case 'x'://Variable
								tokens[n][0]= c;
								tokens[n++][1] = 0; // To make it string.
						break;
						default :
							if(!strcmp(main_stream, "quit"))
								return 0;
							error(buffer);
							return 0;
						break;
						
					}
				}
			k++;
			}	
			if(i != 0){
				num_tmp[i] = 0;
				strcpy(tokens[n++], num_tmp);
			}
			/* -- Token process has been completed -- */
			
			/* ---- For testing Token part ---
				for(int i = 0; i < n; i++)
				printf("%s\n", tokens[i]);
			*/
			/* ---- For testing stack ---- 
			push_n(3.1415);
			push_c('+');
			push_n(1.2);
			calc();
			printf("%f", pop_n());
			*/
			int index = 0;
			char next_token[MAX_NUBER_SIZE];
			while(index < n)
			{
				strcpy(next_token, tokens[index]);
				if(is_num(next_token))
					push_n(atof(next_token));
				else if(next_token[0] == 'x')// X = 0
					push_n(0);
				else if(next_token[0] == '(')
					push_c('(');
				else if(next_token[0] == ')'){
					while (get_top() != '(')
						if(!calc())
							return 0;
					pop_c();//Discarding Left parentheses
				}
				else{//It should be an operator
					while(get_i_c() != -1 && get_precendence(get_top()) >= get_precendence(next_token[0]))
						if(!calc())
							return 0;
					push_c(next_token[0]);
				}
				index++;
			}
			while(get_i_c() != -1)
			{
				if(!calc()){
				    return 0;
				}
			}
			printf("Result is : %f \n", pop_n());
		}
	}
	}while(1);
	return 0;
}

int anti_space(char *spaced_one,char *none_spaced_one){
	int i = 0, j = 0;
	while(*(spaced_one + i) != '\n'){
		if(*(spaced_one + i) != ' '){
			*(none_spaced_one + j) = *(spaced_one + i);
			j++;
		}
		else
						if(is_digit(to_forward(spaced_one, i)) && is_digit(to_downward(spaced_one, i))){
								//Just for 5 6 2  = 562 mode
								puts("Mistaken numbers!");
								return 0;
						}
		i++;
	}
	*(none_spaced_one + j) = 0;
	return 1;
}
int check(char *str){
	int i = 0, paran = 0, op_collision = 0;
	char c = *str;
	if(is_operator(c) && c != '-')
			return 5;
	while(c != 0){
		if(c == '('){
			if (i != 0 && is_digit(*(str + i - 1)))
				return 4;
			if(is_operator(*(str + i + 1)) && *(str + i + 1) != '-')
				return 5;
			paran++;
		}
		else if(c == ')'){
			if (*(str + i + 1) != 0 && is_digit(*(str + i + 1)))
				return 4;
			paran--;
		}
		if(is_operator(c) && is_operator(*(str + i + 1)) )
			return 2;
		c = *(str + ++i);
	}
	if(is_operator(*(str + i - 1)))
		return 3;
	if(paran != 0)
		return 1;
	return 0;
}
int is_ok(int x){
	switch(x){
		case 0:
			return 1;
		break;
		case 1:
			puts("Parentheses not match!");
			return 0;
		break;
		case 2:
			puts("Operator collision!");
			return 0;
		break;
		case 3:
			puts("Ends with operator!");
			return 0;
		break;
		case 4:
			puts("multiply operator (*) missed!");
			return 0;
		break;
		case 5:
			puts("Starts with operator!");
			return 0;
		break;
	}
}
int is_operator(char c){
if(c == '+' ||c == '-' ||c == '*' ||c == '/' ||c == '^'||c == '!')
		return 1;
	return 0;
}
int is_digit(char c){
	if(c >= '0' && c <= '9')
		return 1;
	return 0;
}
char to_forward(char* str, int i){
	int j = i;
	while(*(str + j) != 0){
		if(*(str + j) != ' ')
			return *(str + j);
		j++;
	}
}
char to_downward(char* str, int i){
	int j = i;
	while(j >= 0)
	{
		if(*(str + j) != ' ')
			return *(str + j);
		j--;
	}
=======
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
>>>>>>> c11d5301fb79bc878f02413e4897454ded32415a
	return 0;
}
void error(char* buffer){
	puts("Wrong input!");
	int i = 0;
	while(*(buffer + i) != '\n')
		putchar(*(buffer + i++));
	printf(" khodeti :D.");
}
int calc(){
	char operator = pop_c();
	float op1, op2;
	switch(operator){
		case '+':
			op1 = pop_n();
			op2 = pop_n();
			push_n(op1 + op2);
		break;
		case '-':
			op1 = pop_n();
			op2 = pop_n();
			push_n(op2 - op1);
		break;
		case '*':
			op1 = pop_n();
			op2 = pop_n();
			push_n(op1 * op2);
		break;
		case '/':
			op1 = pop_n();
			op2 = pop_n();
			if(op1 == 0)
			{
				puts("Divided by 0! :D");
				return 0;
			}
			push_n(op2 / op1);
		break;
		case '^':
			op1 = pop_n();
			op2 = pop_n();
			push_n(pow(op2, op1));
		break;

		case 's': // Sin ()
			op1 = pop_n();
			push_n(sin(op1));
		break;
		case 'c': // Cos ()
			op1 = pop_n();
			push_n(cos(op1));
		break;
		case 't': // Tan ()
			op1 = pop_n();
			push_n(tan(op1));
		break;
		case 'e': // exp ()
			op1 = pop_n();
			push_n(exp(op1));
		break;
		case 'l':// ln()
			op1 = pop_n();
			push_n(log(op1));
		break;
		case 'a':// abs ()
			op1 = pop_n();
			if (op1 >= 0)
				push_n(op1);
			else
				push_n(-op1);
		break;
		return 1;
	}
}
int is_num(char str[]){
	if(is_digit(str[0]))
		return 1;
	else if(str[0] == '-' && is_digit(str[1]))
		return 1;
	else
		return 0;
}
int get_precendence(char op){
	switch(op)
	{
		case '-':
		case '+':
			return 0;
		break;
		case '*':
		case '/':
			return 1;
		break;
		case '^':
			return 2;
		break;
		default ://sin cos tan exp ln abs
			return -1;
		break;
	}
}
