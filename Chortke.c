/*
Main source code of "Chortke"
*/
#include <stdio.h>
#include <string.h>
#include "Stack.h"

#define MAX_CHAR_SIZE 100
#define MAX_TOKEN 20
#define MAX_NUBER_SIZE 10

int anti_space(char *spaced_one,char *none_spaced_one);
int check(char *str);
int is_ok(int x);
int is_operator(char c);
int is_num(char c);
char to_forward(char* str, int i);
char to_downward(char* str, int i);
void error(char* buffer);

int main()
{
	char buffer[MAX_CHAR_SIZE], main_stream[MAX_CHAR_SIZE];
	do{
	printf(" = ");
	fgets(buffer, MAX_CHAR_SIZE, stdin);
	if(anti_space(buffer, main_stream)){
		if( is_ok(check(main_stream)) ){
			char tokens[MAX_TOKEN][MAX_NUBER_SIZE], num_tmp[MAX_TOKEN];
			char c;
			int i = 0, k = 0, n = 0;
			while( (c = main_stream[k]) != 0){
				if(is_num(c) || c == '.')//if character is number of dots.
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
							else if (!strncmp(main_stream + k, "log", 3))
							{
								strcpy(tokens[n++], "log");
								k = k + 2;
							}
							else
								error(buffer);
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

			*/
						for(int i = 0; i < n; i++)
				printf("%s\n", tokens[i]);
			
			
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
						if(is_num(to_forward(spaced_one, i)) && is_num(to_downward(spaced_one, i))){
								//Just for 5 6 2 mode
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
	while(c != 0){
		if(c == '('){
			if (i != 0 && is_num(*(str + i - 1)))
				return 4;
			paran++;
		}
		else if(c == ')'){
			if (*(str + i + 1) != 0 && is_num(*(str + i + 1)))
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
	}
}
int is_operator(char c){
if(c == '+' ||c == '-' ||c == '*' ||c == '/' ||c == '^'||c == '!')
		return 1;
	return 0;
}
int is_num(char c){
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
}
