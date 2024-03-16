#include "tests_suite.h"

START_TEST(inverse1) {
  matrix_t m1 = {NULL, 0, 0};
  matrix_t m3 = {NULL, 0, 0};
  int result = 0;
  s21_create_matrix(3, 3, &m1);

  m1.matrix[0][0] = 2.0;
  m1.matrix[0][1] = 5.0;
  m1.matrix[0][2] = 7.0;
  m1.matrix[1][0] = 6.0;
  m1.matrix[1][1] = 3.0;
  m1.matrix[1][2] = 4.0;
  m1.matrix[2][0] = 5.0;
  m1.matrix[2][1] = -2.0;
  m1.matrix[2][2] = -3.0;

  result = s21_inverse_matrix(&m1, &m3);
  ck_assert_int_eq(result, OK);

  ck_assert_double_eq_tol(m3.matrix[0][0], 1.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[0][1], -1.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[0][2], 1.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][0], -38.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][1], 41.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][2], -34.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][0], 27.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][1], -29.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][2], 24.0, EPS);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m3);
}
END_TEST

START_TEST(inverse2) {
  matrix_t m1 = {NULL, 0, 0};
  matrix_t m3 = {NULL, 0, 0};
  int result = 0;
  s21_create_matrix(3, 2, &m1);

  result = s21_inverse_matrix(&m1, &m3);
  ck_assert_int_eq(result, ERROR_IN_CALC);

  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(inverse3) {
  matrix_t m1 = {NULL, 0, 0};
  matrix_t *m3 = NULL;
  int result = 0;
  s21_create_matrix(3, 3, &m1);

  result = s21_inverse_matrix(&m1, m3);
  ck_assert_int_eq(result, ERROR);

  s21_remove_matrix(&m1);
}
END_TEST

Suite *suite_inverse(void) {
  Suite *s10;
  TCase *tc10;
  s10 = suite_create("s21_INVERSE");
  tc10 = tcase_create("case_inverse");
  tcase_add_test(tc10, inverse1);
  tcase_add_test(tc10, inverse2);
  tcase_add_test(tc10, inverse3);

  suite_add_tcase(s10, tc10);
  return s10;
}