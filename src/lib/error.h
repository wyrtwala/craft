#ifndef ERROR_H
#define ERROR_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *craft_error_log;

void initiate_error_log(){
  craft_error_log = (char *)calloc(20, sizeof(char));
  sprintf(craft_error_log, "[CRAFT ERROR LOG]\n");
}

void log_error(char *input) {
  craft_error_log = (char *)realloc(craft_error_log, (strlen(craft_error_log) + strlen(input) + 1) * sizeof(char));
  sprintf(craft_error_log, "%s%s\n", craft_error_log, input);
}

void print_error_log() {
  printf(craft_error_log);
}

void destroy_craft(){
  printf("%s", craft_error_log);
  printf("[END LOG]");
}

#endif
