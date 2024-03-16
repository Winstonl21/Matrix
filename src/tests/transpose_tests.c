#include "tests_suite.h"

START_TEST(transpose1) {
  matrix_t m1 = {NULL, 0, 0};
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

  result = s21_transpose(&m1, &m3);
  ck_assert_int_eq(result, OK);

  ck_assert_double_eq_tol(m3.matrix[0][0], 2.9339, EPS);
  ck_assert_double_eq_tol(m3.matrix[0][1], 854.702683, EPS);
  ck_assert_double_eq_tol(m3.matrix[0][2], 2.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][0], 28.648, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][1], -249136.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][2], 10.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][0], 34.964, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][1], -177.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][2], 0.0, EPS);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m3);
}
END_TEST

START_TEST(transpose2) {
  matrix_t m1 = {NULL, 0, 0};
  matrix_t m3 = {NULL, 0, 0};
  int result = 0;
  s21_create_matrix(2, 5, &m1);

  m1.matrix[0][0] = 1.0;
  m1.matrix[0][1] = 2.0;
  m1.matrix[0][2] = 3.0;
  m1.matrix[0][3] = 1.0;
  m1.matrix[0][4] = 1.0;
  m1.matrix[1][0] = 1.0;
  m1.matrix[1][1] = 1.0;
  m1.matrix[1][2] = 5.0;
  m1.matrix[1][3] = 4.0;
  m1.matrix[1][4] = 4.0;

  result = s21_transpose(&m1, &m3);
  ck_assert_int_eq(result, OK);

  ck_assert_double_eq_tol(m3.matrix[0][0], 1.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[0][1], 1.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][0], 2.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][1], 1.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][0], 3.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][1], 5.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[3][0], 1.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[3][1], 4.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[4][0], 1.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[4][1], 4.0, EPS);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m3);
}
END_TEST

START_TEST(transpose3) {
  matrix_t m1 = {NULL, 0, 0};
  matrix_t *m3 = NULL;
  int result = 0;
  s21_create_matrix(3, 3, &m1);

  result = s21_transpose(&m1, m3);
  ck_assert_int_eq(result, ERROR);

  s21_remove_matrix(&m1);
  s21_remove_matrix(m3);
}
END_TEST

Suite *suite_transpose(void) {
  Suite *s7;
  TCase *tc7;
  s7 = suite_create("S21_TRANSPOSE");
  tc7 = tcase_create("case_transpose");
  tcase_add_test(tc7, transpose1);
  tcase_add_test(tc7, transpose2);
  tcase_add_test(tc7, transpose3);

  suite_add_tcase(s7, tc7);
  return s7;
}