#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "lisp.h"

#define INPUT_BUFFER_SIZE 100
#define GET_INPUT(a, b) (a > 1 ? b[1] : get_input_stdin())

char *get_input_stdin() {
  char *input = malloc(INPUT_BUFFER_SIZE);
  while (1) {
    fgets(input, INPUT_BUFFER_SIZE, stdin);
    if (strcmp(input, "\n") == 0 || strcmp(input, " \n") == 0) continue;
    return input;
  }
}

int main(int argc, char *argv[]) {
  char *input = GET_INPUT(argc, argv);
  Node *expr = read_expr(input);
  eval_expr(expr);
  print_result(expr);

  if (argc == 1) free(input);
}
