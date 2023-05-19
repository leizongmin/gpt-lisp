#include <check.h>

#include "lisp.h"

START_TEST(test_atom) {
  char *input = "a";
  Node *expr = read_expr(input);
  ck_assert(expr != NULL);
  ck_assert_str_eq(expr->val, "a");
}
END_TEST

START_TEST(test_list) {
  char *input = "(a b c)";
  Node *expr = read_expr(input);
  ck_assert(expr != NULL);
  Node *curr = expr;
  ck_assert_str_eq(curr->val, "a");
  curr = curr->next;
  ck_assert_str_eq(curr->val, "b");
  curr = curr->next;
  ck_assert_str_eq(curr->val, "c");
}
END_TEST

START_TEST(test_nested_list) {
  char *input = "(a (b c) d)";
  Node *expr = read_expr(input);
  ck_assert(expr != NULL);
  Node *curr = expr;
  ck_assert_str_eq(curr->val, "a");
  curr = curr->next;

  ck_assert(curr != NULL);
  ck_assert_str_eq(curr->val, "(");
  curr = curr->next;
  ck_assert_str_eq(curr->val, "b");
  curr = curr->next;
  ck_assert_str_eq(curr->val, "c");
  curr = curr->next;
  ck_assert_str_eq(curr->val, ")");

  curr = curr->next;
  ck_assert_str_eq(curr->val, "d");
}
END_TEST

// 更多测试......

int main() {
  Suite *s = suite_create("Lisp Interpreter");
  TCase *tc_atom = tcase_create("Atom");
  tcase_add_test(tc_atom, test_atom);
  suite_add_tcase(s, tc_atom);

  TCase *tc_list = tcase_create("List");
  tcase_add_test(tc_list, test_list);
  suite_add_tcase(s, tc_list);

  TCase *tc_nested_list = tcase_create("Nested List");
  tcase_add_test(tc_nested_list, test_nested_list);
  suite_add_tcase(s, tc_nested_list);

  // 更多测试用例......

  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
}