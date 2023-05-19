#ifndef LISP_H
#define LISP_H

typedef struct Node {
  char *val;
  struct Node *next;
} Node;

Node *read_expr(char *input);
void eval_expr(Node *n);

#endif /* LISP_H */
