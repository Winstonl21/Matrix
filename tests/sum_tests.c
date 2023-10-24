#include "tests_suite.h"

// какие тесты будут для суммирования:
// где все хорошо. done
// чтобы обрезалась после 6 знака. done
// где 0 матрицы. done
// где не совпадают поля матрицы
// где одна матрица NULL 
START_TEST(sum1) {
  matrix_t m1 = {NULL, 0, 0};
  matrix_t m2 = {NULL, 0, 0};
  matrix_t m3 = {NULL, 0, 0};
  int result = 0;
  s21_create_matrix(3, 3, &m1);
  s21_create_matrix(3, 3, &m2);

  m1.matrix[0][0] = 1.255;
  m1.matrix[0][1] = 25.758;
  m1.matrix[0][2] = 3.739;
  m1.matrix[1][0] = 85.3567889;
  m1.matrix[1][1] = -124568;
  m1.matrix[1][2] = 1788.0;
  m1.matrix[2][0] = 1.0;
  m1.matrix[2][1] = 5.0;
  m1.matrix[2][2] = 0.0;

  m2.matrix[0][0] = 1.6789;
  m2.matrix[0][1] = 2.89;
  m2.matrix[0][2] = 31.225;
  m2.matrix[1][0] = 769.34589435;
  m2.matrix[1][1] = -124568;
  m2.matrix[1][2] = -1965;
  m2.matrix[2][0] = 1.0;
  m2.matrix[2][1] = 5.0;
  m2.matrix[2][2] = 0.0;

  double a = m1.matrix[1][0] + m2.matrix[1][0];

  result = s21_sum_matrix(&m1, &m2, &m3);
  ck_assert_int_eq(result, OK);

  ck_assert_double_eq_tol(m3.matrix[0][0], 2.9339, EPS);
  ck_assert_double_eq_tol(m3.matrix[0][1], 28.648, EPS);
  ck_assert_double_eq_tol(m3.matrix[0][2], 34.964, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][0], a, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][1], -249136.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][2], -177.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][0], 2.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][1], 10.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][2], 0.0, EPS);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);

} END_TEST

START_TEST(sum2) {
  matrix_t m1 = {NULL, 0, 0};
  matrix_t m2 = {NULL, 0, 0};
  matrix_t m3 = {NULL, 0, 0};
  int result = 0;
  s21_create_matrix(3, 3, &m1);
  s21_create_matrix(3, 3, &m2);

  m1.matrix[0][0] = 1;
  m1.matrix[0][1] = 2;
  m1.matrix[0][2] = 3;
  m1.matrix[1][0] = 1;
  m1.matrix[1][1] = 1;
  m1.matrix[1][2] = 1;
  m1.matrix[2][0] = 1;
  m1.matrix[2][1] = 5;
  m1.matrix[2][2] = 4;

  m2.matrix[0][0] = 0;
  m2.matrix[0][1] = 0;
  m2.matrix[0][2] = 0;
  m2.matrix[1][0] = 0;
  m2.matrix[1][1] = 0;
  m2.matrix[1][2] = 0;
  m2.matrix[2][0] = 0;
  m2.matrix[2][1] = 0;
  m2.matrix[2][2] = 0;

  result = s21_sum_matrix(&m1, &m2, &m3);
  ck_assert_int_eq(result, OK);
  
  ck_assert_double_eq_tol(m3.matrix[0][0], 1.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[0][1], 2.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[0][2], 3.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][0], 1.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][1], 1.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][2], 1.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][0], 1.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][1], 5.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][2], 4.0, EPS);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);

} END_TEST

START_TEST(sum3) {
  matrix_t m1 = {NULL, 0, 0};
  matrix_t m2 = {NULL, 0, 0};
  matrix_t m3 = {NULL, 0, 0};
  int result = 0;
  s21_create_matrix(3, 3, &m1);
  s21_create_matrix(3, 2, &m2);

  result = s21_sum_matrix(&m1, &m2, &m3);
  ck_assert_int_eq(result, ERROR_IN_CALC);
  
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);

} END_TEST

START_TEST(sum4) {
  matrix_t m1 = {NULL, 0, 0};
  matrix_t m2 = {NULL, 0, 0};
  matrix_t *m3 = NULL;
  int result = 0;
  s21_create_matrix(3, 3, &m1);
  s21_create_matrix(3, 3, &m2);

  result = s21_sum_matrix(&m1, &m2, m3);
  ck_assert_int_eq(result, ERROR);
  
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);

} END_TEST


Suite *suite_sum(void) {
  Suite *s3;
  TCase *tc3;
  s3 = suite_create("s21_SUM");
  // s4 = suite_create("s21_FLOOR");
  // s3 = suite_create("s21_ROUND");
  tc3 = tcase_create("case_sum");
  tcase_add_test(tc3, sum1);
  tcase_add_test(tc3, sum2);
  tcase_add_test(tc3, sum3);
  tcase_add_test(tc3, sum4);
  // tcase_add_test(tc3, sum5);

  suite_add_tcase(s3, tc3);
  return s3;
}