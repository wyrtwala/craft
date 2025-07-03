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
};


typedef struct {
  node* left;
  node* right;
  node* mother;
  uint64_t node_type;
  char* content; //??maybe
} node;


enum token_side {
  LEFT
  RIGHT
};


node* create_node(node_type tok_type, char* cont) { 
  node* newnode;
  newnode=(node *)calloc(1, sizeof(node);
  newnode->node_type = tok_type;
  newnode->content = &cont;
  return newnode;
}
node* link_node(token tok_m, token_side side, token tok_d) {
  //TODO
}
node* mother_node(node* this_node) {
  return this_node->mother;
}
node* left_node(node* this_node) {
  return this_node->left;
}
node* left_node(node* this_node) {  
  return this_node->right;
}


extern node* parse_ast() {
  node* current_node = create_node(ROOT, "\0");
  node* next_node;
  //TODO
  //TODO
}


#endif AST_H
