#include "parser.h"

int number = INT_MIN;
unsigned char number_char[16] = {0};
int number_to_char_counter = 0;
unsigned char output[2] = {0};

int get_number(void) {
  return number;
}
void set_number(int value) {
   number= value ;
}
void parse(char c) {
  if(number == INT_MIN) {
    number = 0;
  }
  int digit = c - '0';
  number = (number * 10) + digit;
}

void clear_parser(void) {
  number = INT_MIN;
}

unsigned char* number_to_char(int input) {
  number_to_char_counter = 0;
  uint8_t is_neg = 0;
  if(input < 0) {
    is_neg = 1;
    input *= -1;
  }
  if(input == 0) {
    number_char[0] = '0';
    number_to_char_counter++;
    return number_char;
  }
  while(input != 0) {
    number_char[number_to_char_counter] = (input % 10) + '0';
    input  /= 10;
    number_to_char_counter++;
  }
  if(is_neg == 1) {
    number_char[number_to_char_counter] = '-';
    number_to_char_counter++;
  }

  return number_char;
}

unsigned char* ParseRTC(int input) {
    if(input < 10) {
        output[1] = '0';
        output[0] = input + '0';
    } else {
        output[0] = (input % 10) + '0';
        input  /= 10;
        output[1] = (input % 10) + '0';
    }

    return output;
}

int get_number_char(void) {
  return number_to_char_counter;
}