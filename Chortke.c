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
					push_c(next_token[0]);//s for sin, c for cos
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
	return 0;
}
void error(char* buffer){
	puts("Wrong input!");
	int i = 0;
	while(*(buffer + i) != '\n')
		putchar(*(buffer + i++));
	printf(" khodeti :D.");
	exit(0);
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
			if(op1 <= 0)
			{
				puts("Out of Ln's domain.");
				return 0;
			}
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
		case '(':
			return -2;
		break;
		default ://sin cos tan exp ln abs
			return -1;
		break;
	}
}
