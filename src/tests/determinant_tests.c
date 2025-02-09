#include "tests_suite.h"

START_TEST(determinant1) {
  matrix_t m1 = {NULL, 0, 0};
  double res = 0.0;
  int result = 0;
  s21_create_matrix(1, 1, &m1);

  m1.matrix[0][0] = 1.225;

  result = s21_determinant(&m1, &res);
  ck_assert_int_eq(result, OK);

  ck_assert_double_eq_tol(res, 1.225, EPS);

  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(determinant2) {
  matrix_t m1 = {NULL, 0, 0};
  double res = 0.0;
  int result = 0;
  s21_create_matrix(2, 2, &m1);

  m1.matrix[0][0] = 1.25;
  m1.matrix[0][1] = 2.36;
  m1.matrix[1][0] = 3.6789;
  m1.matrix[1][1] = 4.899;

  result = s21_determinant(&m1, &res);
  ck_assert_int_eq(result, OK);

  ck_assert_double_eq_tol(res, -2.558454, EPS);

  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(determinant3) {
  matrix_t m1 = {NULL, 0, 0};
  int result = 0;
  double res = 0.0;
  s21_create_matrix(3, 3, &m1);

  m1.matrix[0][0] = 1.255;
  m1.matrix[0][1] = 25.758;
  m1.matrix[0][2] = 3.739;
  m1.matrix[1][0] = 85.356;
  m1.matrix[1][1] = -12456.0;
  m1.matrix[1][2] = 1788.0;
  m1.matrix[2][0] = 1.0;
  m1.matrix[2][1] = 5.0;
  m1.matrix[2][2] = 0.0;

  double corret_res = 83004.31842;

  result = s21_determinant(&m1, &res);
  ck_assert_int_eq(result, OK);

  ck_assert_double_eq_tol(res, corret_res, EPS);

  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(determinant4) {
  matrix_t m1 = {NULL, 0, 0};
  double res = 0.0;
  int result = 0;
  s21_create_matrix(3, 2, &m1);

  result = s21_determinant(&m1, &res);
  ck_assert_int_eq(result, ERROR_IN_CALC);

  s21_remove_matrix(&m1);
}
END_TEST

Suite *suite_determinant(void) {
  Suite *s8;
  TCase *tc8;
  s8 = suite_create("s21_DETERMINANT");
  tc8 = tcase_create("case_determinant");
  tcase_add_test(tc8, determinant1);
  tcase_add_test(tc8, determinant2);
  tcase_add_test(tc8, determinant3);
  tcase_add_test(tc8, determinant4);

  suite_add_tcase(s8, tc8);
  return s8;
}