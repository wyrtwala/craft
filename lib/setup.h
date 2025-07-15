#ifndef SETUP_H
#define SETUP_H
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include "lexer.h"
#include "error.h"

FILE* workspace_setup(FILE *input, FILE *output) {
  token cur_setup_tok = get_tok(input);
  char paste[] = "paste";
  char local[] = "local";
  char craft[] = "craft";
  char web[] = "web";
  while (cur_setup_tok.TOK != EOF) {
    if (strcmp(cur_setup_tok.ELEMENT, paste) == 0) {
      cur_setup_tok = get_tok(input);
      if (strcmp(cur_setup_tok.ELEMENT, local)== 0){
        FILE* flp;
        flp = fopen(cur_setup_tok.ELEMENT, "r+");
        if (flp == NULL){
          char *error = (char*)calloc(99, sizeof(char));
          sprintf(error, "[SETUP] could not open: %s", cur_setup_tok.ELEMENT);
          log_error(error);
        }
        char c;
        while ((c = fgetc(flp)) != EOF){
          fputc(c, output);
        }
      } else if (strcmp(cur_setup_tok.ELEMENT, craft) == 0) {
        //FILE* fcp;
        //fcp = fopen(cur_setup_tok.ELEMENT, "r+");
        //if (fcp == NULL){
        //  error_log(sprinf("could not open %s", cur_setup_tok.ELEMENT));
        //}
        //TODO
      } else if (strcmp(cur_setup_tok.ELEMENT, web) == 0){
        cur_setup_tok = get_tok(input);
        CURL* curl;
        CURLcode response;
        curl = curl_easy_init();
        if (curl) {
          curl_easy_setopt(curl, CURLOPT_URL, cur_setup_tok.ELEMENT);
          curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&output);
          response = curl_easy_perform(curl);
          if (response != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(response));
          }
        }
        curl_easy_cleanup(curl);
      }
    } else {
      char *error = (char*)calloc(99, sizeof(char));
      sprintf(error, "[SETUP] unknown format: %s", cur_setup_tok.ELEMENT);
      log_error(error);
    }
  }
}
#endif
