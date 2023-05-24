#ifndef LISP_H
#define LISP_H

typedef struct Node {
  char *val;
  struct Node *next;
} Node;

void free_list(Node *head);
void free_nodes(Node *n);
Node *read_expr(char *input);
void eval_expr(Node *n);
void print_result(Node *expr);

#endif /* LISP_H */
