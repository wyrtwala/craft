#include "lexer.h"

enum node_type {
  PASTE,
  MARK,
  STACK,
  HEAP,
  FOLLOW,
  CRAFT,
  MOVE,
  IF,
  JUMP,
  ADD,
  SUB,
  MUL,
  DIV,
  NE,
  EQ,
  GT,
  GE,
  LT,
  LE,
  BIT_AND,
  BIT_OR,
  BIT_XOR,
  BIT_NOT,
  BIT_SLEFT,
  BIT_SRIGHT,
  FREE,
  POINT,
  ADDRESS,
  RESIZE,
  REGEX,
  SYS_CALL,
  READ,
  WRITE,
  RETURN,
  ERROR,
  FUNCTION,
  VARIABLE,
  ELEMENT
}


typedef struct {
  node* left;
  node* right;
  uint64_t node_type;
} node;

node* create_node() {
  
}

void link_node() {
  
  
}

node* parse_ast() {
  node root = 
  
  
}
