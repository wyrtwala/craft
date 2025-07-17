#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "lexer.h"

typedef struct Branch {
  uint64_t mask;
  char** branch
} Branch;


char** get_cast(FILE* input) {
  //setup
  uint64_t mask        = 1;         //bitwise map of cast
  uint64_t cast_runner = 2;         //current cast position
  uint64_t par_count   = 0;         //current ast depth :: for cutoff at d64 :: checked with '('
  uint64_t tok_count   = 1;
  char** cast          = (char**)malloc(64 * sizeof(char*));
  token cur_tok        = get_tok(input); 
  if (cur_tok.TOK == TOK_LPARA || cur_tok.TOK == TOK_RPARA) {
    log_error("top level logic cannot start with ()");
    ablinnan();
  }
  cast[0] = cur_tok.ELEMENT;

  //pop loop
  while (cur_tok.TOK != TOK_EOF) {
    cur_tok = get_tok(input);

    if (cur_tok.TOK != TOK_LPARA && cur_tok.TOK != TOKLPARA) {
      if (cast_runner % 3 != 0 && cast_runner % 2 != 0) { //primary node
        cast[cast_runner - 1] = cur_tok.ELEMENT;
        cast_runner++;
      }
      if (tok_count % 2 != 0 && 




      
    } else { //parentheses :: reshuffle

      
    }
  if (cur_tok.TOK != TOK_EOF) {
    log_error("")
    ablinnan();
  }
  return cast;
  }
}
