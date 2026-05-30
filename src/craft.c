#include <stdio.h>
#include <string.h>
#include <inttypes.h>




//function declarations
int f_set_output_type(char*, int);
int f_assemble();


int main(int argc, char *argv[]){
  int s_output_type = f_set_output_type(argv[1], argc);
  if (s_output_type < 0){
    printf("argparse failure");
    return -1;
  }
  return 0;
}

 

//function definitions
int assemble(){
  //TODO
  return 0;
}
int f_set_output_type(char* a_instruction, int s_arg_count){
  if (s_arg_count != 4){
    printf("Craft needs two arguments");
    return -1;
  }
  else if (strcmp(a_instruction, "define") == 0){
    printf("Not ready yet");
    return 1;
  }
  else if (strcmp(a_instruction, "compile") == 0){
    printf("Not yet ready");
    return 2;
  }
  else if (strcmp(a_instruction, "library") == 0){
    printf("Not yet ready");
    return 3;
  }
  else if (strcmp(a_instruction, "assembly") == 0){
    assemble();
    return 4;
  }
  else {
    return -1;
  }
