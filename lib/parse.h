#ifndef AST_H
#define AST_H
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "lexer.h"

#define FUNC_DEF (0)
#define FUNC_END (1)
#define FUNC_CAL (2)

#define DEC_STAC (3)
#define DEC_HEAP (4)
#define DEC_DBSS (5)
#define DEC_DATA (6)

#define ASM_CALL (7)
#define SYS_CALL (8)

#define PARS_RUN (9)
#define PARS_EOF (0)

typedef struct Knot {
  token TOKEN;
  uint64_t TYPE;
  struct Knot* ARG1;
  struct Knot* ARG2;
} Knot;

typedef struct Branch{
  Knot* knot;
  uint64_t code; // 1-2-4-8-16-32 = 63
} Branch;

Knot* create_knot(FILE* runner) { 
  Knot* newknot  = (Knot*)calloc(1, sizeof(Knot));
  newknot->TOKEN = get_tok(runner);
  return newknot;
}


Branch* get_tree(FILE* input) {
  Knot* base_knot = create_knot(input);
  Knot* cur_knot  = create_knot(input);
  Branch* branch = (Branch*)malloc(sizeof(Branch));
  branch->knot = base_knot;
  uint64_t stem[64] = { 0 };
  uint64_t mask = 0;
  while (cur_knot->TOKEN.TOK != TOK_EOF) {
    






  }
  return branch;
}
#endif
