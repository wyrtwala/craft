#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "lexer.h"



char** get_cast(FILE* input) {
  //setup
  uint64_t mask        = 1;         //bitwise map of cast
  uint64_t ast_runner  = 1;         //current ast depth :: for cutoff at d64
  uint64_t cast_runner = 1;         //current cast depth
  uint64_t tok_count   = 1;
  uint64_t par_count   = 0;
  char** cast          = (char**)malloc(64 * sizeof(char*));
  token cur_tok        = get_tok(input); 
  if (cur_tok.TOK == TOK_LPARA || cur_tok.TOK == TOK_RPARA) {
    log_error("top level logic cannot start with ()");
    ablinnan();
  }
  cast[0] = cur_tok.ELEMENT;

  //pop loop
  while (cur_tok.TOK != TOK_EOF) {
    /*
                                    1
                    2                                 3
            4                5                6                7
        8       9      10        11      12        13      14      15
    */

    // n*2+1
    if (cur_tok.TOK != TOK_LPARA && cur_tok.TOK != TOKLPARA) {
      




      
    } else {

      
    }
  if (cur_tok.TOK != TOK_EOF) {
    log_error("")
    ablinnan();
  }
  return cast;
  }
}
