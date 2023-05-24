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
      if (n == NULL) {
        if (head != NULL) free_list(head);
        return NULL;
      }
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
    if (tail != NULL) tail->next = NULL;
    return head;
  } else {
    char *str_end = strchr(input + i, '(');
    if (str_end == NULL) {
      str_end = input + strlen(input) - 1;
    } else {
      str_end--;
    }
    int str_len = str_end - (input + i) + 1;
    char *str_start = input + i - 1;
    char *str = malloc(str_len + 1);
    if (str == NULL) return NULL;
    memcpy(str, str_start, str_len);
    str[str_len] = '\0';
    Node *n = malloc(sizeof(Node));
    if (n == NULL) {
      free(str);
      return NULL;
    }
    n->val = malloc(str_len + 1);
    if (n->val == NULL) {
      free(str);
      free(n);
      return NULL;
    }
    memcpy(n->val, str, str_len + 1);
    free(str);
    n->next = NULL;
    i += str_len + 1;
    return n;
  }
}

void free_list(Node *head) {
  while (head != NULL) {
    Node *next = head->next;
    free(head->val);
    free(head);
    head = next;
  }
}

void free_nodes(Node *n) {
  if (n == NULL) return;
  free_nodes(n->next);
  free(n);
}

void eval_atom(Node *n) {
  if (n == NULL) return;
  if (strcmp(n->val, "true") == 0 || strcmp(n->val, "false") == 0) {
    printf("bool: %s ", n->val);
  } else if (n->val[0] == '\"' && n->val[strlen(n->val) - 1] == '\"') {
    printf("string: %s ", n->val);
  } else if (n->val[0] == '\'') {
    printf("char: %s ", n->val);
  } else if (n->val[0] == '-' || (n->val[0] >= '0' && n->val[0] <= '9')) {
    printf("number: %s ", n->val);
  } else {
    printf("symbol: %s ", n->val);
  }
}

void eval_expr(Node *n) {
  if (n == NULL) return;

  if (n->next == NULL) {  // atom
    eval_atom(n);
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
