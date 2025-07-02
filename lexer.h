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

char tok_buff[999];
static extern uint64_t extend = 0;

token get_tok(FILE* input) {
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
          new_tok->ELEMENT = get_element(input);
          return new_tok;
        } else {
          new_tok->TOK = TOK_EXTD_ELEM;
          new_tok->ELEMENT = get_element(input);
          return new_tok;
        }
      }
    }
}
#endif LEXER_H
