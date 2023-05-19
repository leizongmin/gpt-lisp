#include <stdio.h>

#include "lisp.h"

int main() {
  while (1) {
    char input[100];
    fgets(input, 100, stdin);

    if (strcmp(input, "\n") == 0 || strcmp(input, " \n") == 0) continue;

    Node *expr = read_expr(input);
    eval_expr(expr);
    printf("\n");
  }
}
