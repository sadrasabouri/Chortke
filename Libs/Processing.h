#ifndef CHORTKE_H_ 
#define CHORTKE_H_

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
int factorial(int num);
int check_function(char *checking_pointer, const char * funtion_to_be_checked, char *tokens, int *pt_n, int *pt_k,char* buffer);
int to_token(char* buffer);
float calculate_equation(float x,float y, int *is_con);

#endif
