#include "lisp.h"

#include <stdio.h>
#include <stdlib.h>

Node *read_expr(char *input) {
  int i = 0;
  char c = input[i++];

  if (c == '(') {
    Node *head = NULL;
    Node *tail = NULL;

    while (1) {
      Node *n = read_expr(input + i);
      if (tail == NULL) {
        head = n;
        tail = n;
      } else {
        tail->next = n;
        tail = n;
      }

      c = input[i++];
      if (c == ')') break;
    }

    return head;
  } else {
    char str[100];
    strncpy(str, input + i, 99);
    i += strlen(str);

    Node *n = malloc(sizeof(Node));
    n->val = strdup(str);
    n->next = NULL;
    return n;
  }
}

void eval_expr(Node *n) {
  if (n->next == NULL) {  // atom
    printf("%s ", n->val);
  } else {
    printf("(");
    Node *curr = n;
    while (curr != NULL) {
      eval_expr(curr);
      curr = curr->next;
    }
    printf(") ");
  }
}
