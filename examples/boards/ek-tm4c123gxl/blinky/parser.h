#ifndef __PARSER_H__
#define __PARSER_H__

#include <stdint.h>
#include <limits.h>

int get_number(void);
void set_number(int value) ;
void parse(char c);
void clear_parser(void);
unsigned char* number_to_char(int input);
int get_number_char(void);
unsigned char* ParseRTC(int input);

#endif // __PARSER_H__