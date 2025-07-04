#ifndef LEXER_H
#define LEXER_H


#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TOK_LPARA          (0)
#define TOK_RPARA          (1)
#define TOK_ELEM           (2)
#define TOK_EXTD_ELEM      (3)
#define TOK_EOF            (4)


typedef struct {
  uint64_t TOK;
  char ELEMENT[999];
} token;


static extern uint64_t extend = 0;


char* get_word(FILE *runner, char *word) {
  uint64_t point = 0;
  uint64_t rcount = 999;
  while (!isspace(c = fgetc(runner)) && rcount > 0) {
    if (c == ')') {
      ungetc((char)c, runner);
      return word;
    }
    word[point] = c;
    point++;
    rcount--;
  }
  return word;
}


char* get_sb_word(FILE *runner, char *word) {
  uint64_t point = 0;
  uint64_t rcount = 999;
  if (char c = fgetc(runner) != '[') {
    //call parsing error
  }
  extend = 1;
  while (!isspace(c = fgetc(runner)) && rcount > 0) {
    if (c == ']') {
      extend = 0;
      return word;
    }
    word[point] = c;
    point++;
    rcount--;
  }
  return word;
}


char* get_element(FILE* runner) {
  char* element;
  element=(char *)calloc(999, sizeof(char));
  extend = fgetc(runner) == '[';
  ungetc((char)c, runner);
  if (extend == 0) {
    element = get_word(runner, element);
  } else {
    element = get_sb_word(runner, element);
  }
  return element;
}


extern token get_tok(FILE* input) {
  char chr = '';
  token new_tok;
  while (true) {
    chr = (char)fgetc(input)
    switch (chr) {
      case '(':
        new_tok->TOK = TOK_LPARA;
        return new_tok;
      case ')':
        new_tok->TOK = TOK_RPARA;
        return new_tok;
      case EOF:
        new_tok->TOK = TOK_EOF;
        return new_tok;
      default:
        if (extend == 0){
          new_tok->TOK = TOK_ELEM;
          new_tok->ELEMENT = &get_element(input);
          return new_tok;
        } else {
          new_tok->TOK = TOK_EXTD_ELEM;
          new_tok->ELEMENT = &get_element(input);
          return new_tok;
        }
      }
    }
}


#endif LEXER_H
