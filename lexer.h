#ifndef LEXER_H
#define LEXER_H


#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


#define TOK_LPARA          (0)
#define TOK_RPARA          (1)
#define TOK_ELEM           (2)
#define TOK_EXTD_ELEM      (3)
#define TOK_EOF            (4)


typedef struct {
  uint64_t TOK;
  char *ELEMENT;
} token;


static uint64_t extend = 0;


char* get_word(FILE *runner, char *word) {
  uint64_t point = 0;
  uint64_t rcount = 999;
  char c = fgetc(runner);
  uint64_t brak = 0;
  if (c == '[') {
    brak = 1;
    c = fgetc(runner);
  }
  while (rcount > 0) {
    if (c == ')') {
      ungetc((char)c, runner);
      return word;
    }
    if (c == ']' && brak == 1) {
      return word;
    }
    if (isspace(c) && brak == 0) {
      return word;
    }
    word[point] = c;
    point++;
    rcount--;
    c = fgetc(runner);
  }
  extend = 1;
  return word;

}


char* get_sb_word(FILE *runner, char *word) {
  uint64_t point = 0;
  uint64_t rcount = 999;
  char c;
  c = fgetc(runner);
  c = fgetc(runner);
  while (rcount > 0) {
    if (c == ']') {
      extend = 0;
      return word;
    }
    word[point] = c;
    point++;
    rcount--;
    c = fgetc(runner);
  }
  extend = 1;
  return word;
}


char* get_element(FILE* runner) {
  char* element;
  element=(char *)calloc(999, sizeof(char));
  char c = fgetc(runner);
  ungetc(c, runner);
  if (extend == 0 /*&& c != '['*/) {
    return get_word(runner, element);
  } else {
    return get_sb_word(runner, element);
  }
}


void comment(FILE* runner) {
  char c = fgetc(runner);
  if (c == ':') {
    while (true) {
      c = fgetc(runner);
      if (c == ':') {
	c = fgetc(runner);
	if (c == ':') {break;}
      }
    }
  }
}


extern token get_tok(FILE* input) {
  char chr = ' ';
  token new_tok;
  while (true) {
    chr = (char)fgetc(input);
    if (isspace(chr)) {continue;}
    ungetc(chr, input);
    switch (chr) {
      case '(':
        new_tok.TOK = TOK_LPARA;
	chr = (char)fgetc(input);
        return new_tok;
      case ')':
        new_tok.TOK = TOK_RPARA;
	chr = (char)fgetc(input);
	return new_tok;
      case EOF:
        new_tok.TOK = TOK_EOF;
        return new_tok;
      case ':':
	comment(input);
        continue;
      default:
        if (extend == 0){
          new_tok.TOK = TOK_ELEM;
          new_tok.ELEMENT = get_element(input);
          return new_tok;
        } else {
          new_tok.TOK = TOK_EXTD_ELEM;
          new_tok.ELEMENT = get_element(input);
          return new_tok;
        }
      }
    }
}


#endif
