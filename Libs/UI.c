/*
Our library for interacting with user:
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "UI.h"
#include "Processing.h"

#define CONFIG_DIR "./configs/Chortke.config" 

#ifdef _WIN32
	#define CLEAR_SCREEN "cls"
#else
	#define CLEAR_SCREEN "clear"
#endif
//Prototypes :
char Choose();
void clear();
void greeting();
void bye();
int input();
void output(char output_str[10000]);
char show_config(float radius, int axis_color,int screen_color, int plot_color);
void get_graph_configs(float *radius, int *axis_color, int *screen_color, int *plot_color);
void set_graph_configs(float radius, int axis_color, int screen_color, int plot_color);

void clear(){
	system(CLEAR_SCREEN);	
}

void greeting()
{
	
#ifdef _WIN32
	system("title Chortke");
#endif
//For linux.
 puts("\x1b[31m""Welcome to \"Chortke\"! :D""\x1b[0m");
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
void get_graph_configs(float *radius, int *axis_color, int *screen_color, int *plot_color){
	FILE *file_pointer;
	file_pointer = fopen(CONFIG_DIR, "r");
	if(file_pointer != NULL){
		fread(radius, sizeof(float), 1, file_pointer);
		fread(axis_color, sizeof(float), 1, file_pointer);
		fread(plot_color, sizeof(float), 1, file_pointer);	
		fread(screen_color, sizeof(float), 1, file_pointer);		
		fclose(file_pointer);
	}
}
void set_graph_configs(float radius, int axis_color,int screen_color, int plot_color){
	FILE *file_pointer;
	file_pointer = fopen(CONFIG_DIR, "w");
	fwrite(&radius, sizeof(float), 1, file_pointer);
	fwrite(&axis_color, sizeof(float), 1, file_pointer);
	fwrite(&plot_color, sizeof(float), 1, file_pointer);	
	fwrite(&screen_color, sizeof(float), 1, file_pointer);	
	fclose(file_pointer);
}

char show_config(float radius, int axis_color,int screen_color, int plot_color){
	char choice;
	puts("---------------------Configuration---------------------");
	printf("x Domain : -%.2f < x < %.2f\naxis color: 0x%x\nscreen color:0x%x\nplot color: 0x%x\n", radius, radius, axis_color, screen_color, plot_color);
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
