#ifndef LEXER_H
#define LEXER_H


#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


#define TOK_LPARA          (0)
#define TOK_ELEM           (1)
#define TOK_EXTD_ELEM      (2)
#define TOK_EOF            (3)


typedef struct {
  uint64_t TOK;
  char *ELEMENT;
} token;


static uint64_t extend = 0;


char* get_word(FILE *runner, char *word) {
  uint64_t point = 0;
  uint64_t rcount = 999;
  char c = fgetc(runner);
  while (!isspace(c) && rcount > 0) {
    if (c == ')') {
      ungetc((char)c, runner);
      return word;
    }
    word[point] = c;
    point++;
    rcount--;
    c = fgetc(runner);
  }
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
  return word;
}


char* get_element(FILE* runner) {
  char* element;
  element=(char *)calloc(999, sizeof(char));
  char c = fgetc(runner);
  ungetc(c, runner);
  if (extend == 0) {
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


token get_tok(FILE* input) {
  char chr = ' ';
  token new_tok;
  while (true) {
    chr = (char)fgetc(input);
    if (isspace(chr)) {continue;}
    ungetc(chr, input);
    switch (chr) {
      case '(':
        new_tok.TOK = TOK_LPARA;
	new_tok.ELEMENT[0] = '(';
	new_tok.ELEMENT[1] = '\0';
	chr = (char)fgetc(input);
        return new_tok;
      case ')':
	chr = (char)fgetc(input);
	continue;
      case EOF:
        new_tok.TOK = TOK_EOF;
	new_tok.ELEMENT[0] = '\0';
        return new_tok;
      case ':':
	comment(input);
      case '[':
	new_tok.TOK = TOK_EXTD_ELEM;
	extend = 1;
	new_tok.ELEMENT = get_element(input);
	return new_tok;
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
