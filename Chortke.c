/*
Main source code of "Chortke"
*/
#include <stdio.h>
#include <string.h>
#include "Stack.h"
#include "Processing.h"

#define MAX_CHAR_SIZE 100
#define MAX_TOKEN 20
#define MAX_NUBER_SIZE 10

void anti_space(char *spaced_one,char *none_spaced_one);
int check(char *str);
int is_ok(int x);
int is_operator(char c);
int is_num(char c);

int main()
{
	char buffer[MAX_CHAR_SIZE], main_stream[MAX_CHAR_SIZE];
	
	fgets(buffer, MAX_CHAR_SIZE, stdin);
	anti_space(buffer, main_stream);
	
	if( is_ok(check(main_stream)) ){
		char tokens[MAX_TOKEN][MAX_NUBER_SIZE], tmp[MAX_TOKEN];
		char c;
		int i = 0, k = 0, n = 0;
		while( (c = main_stream[k]) != 0){
			if(( '0' <= c && c <= '9' )|| c == '.')//if character is number of dots.
				tmp[i++] = c;
			else{
			if(i != 0){
				tmp[i] = 0;
				strcpy(tokens[n++], tmp);
			}
			tokens[n][0]= c;
			tokens[n++][1] = 0; // To make it string.
			i = 0;
			}
		k++;
		}	
		if(i != 0){
			tmp[i] = 0;
			strcpy(tokens[n++], tmp);
		}
		for(int i = 0; i < n; i++)
			printf("%s\n", tokens[i]);
	}
	return 0;
}

void anti_space(char *spaced_one,char *none_spaced_one){
	int i = 0, j = 0;
	while(*(spaced_one + i) != '\n'){
		if(*(spaced_one + i) != ' '){
			*(none_spaced_one + j) = *(spaced_one + i);
			j++;
		}
		i++;
	}
	*(none_spaced_one + j) = 0;
}
int check(char *str){
	int i = 0, paran = 0, op_collision = 0;
	char c = *str;
	if(is_operator(c))
		return 3;
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
		if(is_operator(c) && is_operator(*(str + i + 1)))
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
			printf("Parentheses not match!");
			return 0;
		break;
		case 2:
			printf("Operator collision!");
			return 0;
		break;
		case 3:
			printf("Starts or ends with operator!");
			return 0;
		break;
		case 4:
			printf("multiply operator (*) missed!");
			return 0;
		break;
	}
}
int is_operator(char c){
	if(c == '+' ||c == '-' ||c == '*' ||c == '/' ||c == '^')
		return 1;
	return 0;
}
int is_num(char c){
	if(c >= '0' && c <= '9')
		return 1;
	return 0;
}


