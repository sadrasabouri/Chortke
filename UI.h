#ifndef UI_H_ 
#define UI_H_


char Choose();
void clear();
void greeting();
void bye();
int input();
char show_config(float start,float end, float step);
void output(char output_str[10000]);
void get_graph_configs(float *first, float *end, float *step);
void set_graph_configs(float first, float end, float step);


#endif
