/*
Our library for interacting with user:
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "UI.h"
#include "Processing.h"

#define CONFIG_DIR "Chortke.config" 

#ifdef _WIN32
	#define CLEAR_SCREEN "cls"
#endif

#ifdef linux
	#define CLEAR_SCREEN "clear"
#endif
//Prototypes :
char Choose();
void clear();
void greeting();
void bye();
int input();
void output(char output_str[10000]);
char show_config(float start,float end, float step);
void get_graph_configs(float *first, float *end, float *step);
void set_graph_configs(float first, float end, float step);
//Bugy

void clear(){
#ifdef _WIN32
	system(CLEAR_SCREEN);
#endif

#ifdef linux
	system(CLEAR_SCREEN);
#endif
	
}

void greeting()
{
 puts("Welcome to \"Chortke\"! :D");
}

char Choose()
{
	char str[10];
	puts("Choose a character to surf into different parts of Chortke:");
	puts("e : for entering numerical equation");
	puts("g : for showing graph of your function");
	puts("c : for see/change configure your plot");
	puts("q : for quiting from Chortke :(");
	fgets(str, 10, stdin);
	return str[0];
}
int input()
{
}

void output(char output_str[10000])
{
 puts(output_str);
}

void bye()
{
 char str[] = "Bye!\nCome back Soon ;)"; // Add description!
 puts(str);
}
void get_graph_configs(float *first, float *end, float *step){
	FILE *file_pointer;
	file_pointer = fopen(CONFIG_DIR, "r");
	fread(first, sizeof(float), 1, file_pointer);
	fread(end, sizeof(float), 1, file_pointer);
	fread(step, sizeof(float), 1, file_pointer);
	fclose(file_pointer);
}
void set_graph_configs(float first, float end, float step){
	FILE *file_pointer;
	file_pointer = fopen(CONFIG_DIR, "w");
	fwrite(&first, sizeof(float), 1, file_pointer);
	fwrite(&end, sizeof(float), 1, file_pointer);
	fwrite(&step, sizeof(float), 1, file_pointer);	
	fclose(file_pointer);
}

char show_config(float start,float end, float step){
	char choice;
	puts("---------------------Configuration---------------------");
	printf("Start point : %.2f\nEnd point : %.2f\nStep size: %.2f\n", start, end, step);
	puts("-------------------------------------------------------");
	printf("Do you want to change it?(y/n):");
	scanf(" %c", &choice);
	return choice;
}
/*
Sharif university of technology
Fall 2018
Bubble Team!
*/
