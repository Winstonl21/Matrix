#include "tests_suite.h"

START_TEST(mult_number1) {
  matrix_t m1 = {NULL, 0, 0};
  double number = 3.14;
  matrix_t m3 = {NULL, 0, 0};
  int result = 0;
  s21_create_matrix(3, 3, &m1);

  m1.matrix[0][0] = 2.9339;
  m1.matrix[0][1] = 28.648;
  m1.matrix[0][2] = 34.964;
  m1.matrix[1][0] = 854.702683;
  m1.matrix[1][1] = -249136.0;
  m1.matrix[1][2] = -177.0;
  m1.matrix[2][0] = 2.0;
  m1.matrix[2][1] = 10.0;
  m1.matrix[2][2] = 0.0;

  result = s21_mult_number(&m1, number, &m3);
  ck_assert_int_eq(result, OK);

  ck_assert_double_eq_tol(m3.matrix[0][0], 9.212446, EPS);
  ck_assert_double_eq_tol(m3.matrix[0][1], 89.95472, EPS);
  ck_assert_double_eq_tol(m3.matrix[0][2], 109.78696, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][0], 2683.76642462, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][1], -782287.04, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][2], -555.78, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][0], 6.28, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][1], 31.4, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][2], 0.0, EPS);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m3);
}
END_TEST

START_TEST(mult_number2) {
  matrix_t m1 = {NULL, 0, 0};
  double number = -289.9;
  matrix_t m3 = {NULL, 0, 0};
  int result = 0;
  s21_create_matrix(3, 3, &m1);

  m1.matrix[0][0] = 1.0;
  m1.matrix[0][1] = -2.0;
  m1.matrix[0][2] = 3.0;
  m1.matrix[1][0] = -1.0;
  m1.matrix[1][1] = 14.0;
  m1.matrix[1][2] = 0.0;
  m1.matrix[2][0] = 5.555555;
  m1.matrix[2][1] = 0.0123456789;
  m1.matrix[2][2] = 0.111111;

  double a = m1.matrix[2][0] * -289.9;
  double b = m1.matrix[2][1] * -289.9;
  double c = m1.matrix[2][2] * -289.9;

  result = s21_mult_number(&m1, number, &m3);
  ck_assert_int_eq(result, OK);

  ck_assert_double_eq_tol(m3.matrix[0][0], -289.9, EPS);
  ck_assert_double_eq_tol(m3.matrix[0][1], 579.8, EPS);
  ck_assert_double_eq_tol(m3.matrix[0][2], -869.7, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][0], 289.9, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][1], -4058.6, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][2], 0.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][0], a, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][1], b, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][2], c, EPS);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m3);
}
END_TEST

START_TEST(mult_number3) {
  matrix_t m1 = {NULL, 0, 0};
  double number = 0;
  matrix_t m3 = {NULL, 0, 0};
  int result = 0;
  s21_create_matrix(3, 3, &m1);

  m1.matrix[0][0] = 1.0;
  m1.matrix[0][1] = -2.0;
  m1.matrix[0][2] = 3.0;
  m1.matrix[1][0] = -1.0;
  m1.matrix[1][1] = 14.0;
  m1.matrix[1][2] = 0.0;
  m1.matrix[2][0] = 5.55555;
  m1.matrix[2][1] = 0.012345;
  m1.matrix[2][2] = 0.111111;

  result = s21_mult_number(&m1, number, &m3);
  ck_assert_int_eq(result, OK);

  ck_assert_double_eq_tol(m3.matrix[0][0], 0.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[0][1], 0.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[0][2], 0.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][0], 0.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][1], 0.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][2], 0.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][0], 0.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][1], 0.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][2], 0.0, EPS);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m3);
}
END_TEST

START_TEST(mult_number4) {
  matrix_t m1 = {NULL, 0, 0};
  double number = 5.5;
  matrix_t *m3 = NULL;
  int result = 0;
  s21_create_matrix(3, 3, &m1);

  result = s21_mult_number(&m1, number, m3);
  ck_assert_int_eq(result, ERROR);

  s21_remove_matrix(&m1);
}
END_TEST

Suite *suite_mult_number(void) {
  Suite *s5;
  TCase *tc5;
  s5 = suite_create("s21_MULT_NUMBER");
  tc5 = tcase_create("case_mult_number");
  tcase_add_test(tc5, mult_number1);
  tcase_add_test(tc5, mult_number2);
  tcase_add_test(tc5, mult_number3);
  tcase_add_test(tc5, mult_number4);
  // tcase_add_test(tc3, sum5);

  suite_add_tcase(s5, tc5);
  return s5;
}