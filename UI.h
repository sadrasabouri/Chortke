#ifndef UI_H_ 
#define UI_H_

char Choose();
void clear();
void greeting();
void bye();
int input();
void output(char output_str[10000]);
char show_config(float radius, int axis_color, int plot_color);
void get_graph_configs(float *radius, int *axis_color, int *plot_color);
void set_graph_configs(float radius, int axis_color, int plot_color);

#endif
