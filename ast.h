#ifndef AST_H
#define AST_H
#include "lexer.h"

enum node_type {
  ROOT,
  MARK,
  STACK,
  HEAP,
  DATA,
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
  DEC_FUNCTION,
  ELEMENT
}

typedef struct {
  node* left;
  node* right;
  node* mother;
  uint64_t node_type;
  char* content; //??maybe
} node;

node* create_node() {
  
}

uint64_t link_node() {
    
}
uint64_t find_node() {
  
}

node* parse_ast() {
  node root = 
  
  
}
#endif AST_H
