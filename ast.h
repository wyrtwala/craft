#ifndef AST_H
#define AST_H
#include "lexer.h"



typedef struct {
  node* left;
  node* right;
  node* mother;
  token* TOK;
} node;


enum token_side {
  LEFT
  RIGHT
};


node* create_node(token* tok) { 
  node* newnode;
  newnode=(node *)calloc(1, sizeof(node);
  newnode.TOK = &tok;
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
  node* current_node = create_node(//TODO);
  node* next_node;
  //TODO
  //TODO
}


#endif AST_H
