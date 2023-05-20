#include "lisp.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *read_expr(char *input) {
  int i = 0;
  char c = input[i++];
  if (c == '(') {
    if (input[i] == '\0') return NULL;
    Node *head = NULL;
    Node *tail = NULL;
    while (c != '\0' && c == '(') {
      Node *n = read_expr(input + i);
      if (n == NULL) return NULL;
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
    free(head);
    return head;
  } else {
    char *str_end = strchr(input + i, '(');
    int str_len = str_end - input - i;
    char *str = strndup(input + i, str_len);
    if (str == NULL) return NULL;
    Node *n = malloc(sizeof(Node));
    if (n == NULL) {
      free(str);
      return NULL;
    }
    n->val = strdup(str);
    free(str);
    n->next = NULL;
    i += str_len;
    return n;
  }
}

void free_nodes(Node *n) {
  if (n == NULL) return;
  free_nodes(n->next);
  free(n);
}

void eval_expr(Node *n) {
  if (n == NULL) return;

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

void print_result(Node *expr) {
  if (expr == NULL) return;

  if (expr->val[0] != '(') {
    printf("%s", expr->val);
    return;
  }

  putchar('(');
  Node *head = expr;
  while (head != NULL) {
    print_result(head);
    head = head->next;
    if (head != NULL) putchar(' ');
  }
  putchar(')');
}
