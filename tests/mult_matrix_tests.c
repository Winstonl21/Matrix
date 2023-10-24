#include "tests_suite.h"
// усножение неквадратных матриц
// тест на разные карайне ряды и колонки для матрицы

START_TEST(mult_matrix1) {
  matrix_t m1 = {NULL, 0, 0};
  matrix_t m2 = {NULL, 0, 0};
  matrix_t m3 = {NULL, 0, 0};
  int result = 0;
  s21_create_matrix(3, 3, &m1);
  s21_create_matrix(3, 3, &m2);

  m1.matrix[0][0] = 2.9339;
  m1.matrix[0][1] = 28.648;
  m1.matrix[0][2] = -34.964;
  m1.matrix[1][0] = 854.702683;
  m1.matrix[1][1] = -249136.0;
  m1.matrix[1][2] = -177.0;
  m1.matrix[2][0] = 2.0;
  m1.matrix[2][1] = 10.0;
  m1.matrix[2][2] = 0.0;

  m2.matrix[0][0] = 1.6789;
  m2.matrix[0][1] = -2.89;
  m2.matrix[0][2] = -31.225;
  m2.matrix[1][0] = 769.34589435;
  m2.matrix[1][1] = -0.0989887;
  m2.matrix[1][2] = -1965.0;
  m2.matrix[2][0] = 1.0;
  m2.matrix[2][1] = 0.0;
  m2.matrix[2][2] = 0.0;

  result = s21_mult_matrix(&m1, &m2, &m3);
  ck_assert_int_eq(result, OK);

  ck_assert_double_eq_tol(m3.matrix[0][0], 4.925725, EPS);
  ck_assert_double_eq_tol(m3.matrix[0][1], 82.79272, EPS);
  ck_assert_double_eq_tol(m3.matrix[0][2], 1091.7509, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][0], 657562.0000559795, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][1], 24661.6487632, EPS);
  ck_assert_double_eq_tol(m3.matrix[1][2], 347805.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][0], 2.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][1], 0.0, EPS);
  ck_assert_double_eq_tol(m3.matrix[2][2], 0.0, EPS);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&m3);

} END_TEST

// START_TEST(mult_matrix2) {
//   matrix_t m1 = {NULL, 0, 0};
//   double number = -289.9;
//   matrix_t m3 = {NULL, 0, 0};
//   int result = 0;
//   s21_create_matrix(3, 3, &m1);

//   m1.matrix[0][0] = 1.0;
//   m1.matrix[0][1] = -2.0;
//   m1.matrix[0][2] = 3.0;
//   m1.matrix[1][0] = -1.0;
//   m1.matrix[1][1] = 14.0;
//   m1.matrix[1][2] = 0.0;
//   m1.matrix[2][0] = 5.555555;
//   m1.matrix[2][1] = 0.0123456789;
//   m1.matrix[2][2] = 0.111111;

//   result = s21_mult_matrix(&m1, number, &m3);
//   ck_assert_int_eq(result, OK);
  
//   ck_assert_double_eq_tol(m3.matrix[0][0], -289.9 , EPS);
//   ck_assert_double_eq_tol(m3.matrix[0][1], 579.8, EPS);
//   ck_assert_double_eq_tol(m3.matrix[0][2], -869.7, EPS);
//   ck_assert_double_eq_tol(m3.matrix[1][0], 289.9, EPS);
//   ck_assert_double_eq_tol(m3.matrix[1][1], -4058.6, EPS);
//   ck_assert_double_eq_tol(m3.matrix[1][2], 0.0, EPS);
//   ck_assert_double_eq_tol(m3.matrix[2][0], 1610.5553945, EPS);
//   ck_assert_double_eq_tol(m3.matrix[2][1], 3.579012, EPS);
//   ck_assert_double_eq_tol(m3.matrix[2][2], 32.2110789, EPS);

//   s21_remove_matrix(&m1);

// } END_TEST

// START_TEST(mult_matrix3) {
//   matrix_t m1 = {NULL, 0, 0};
//   double number = 0;
//   matrix_t m3 = {NULL, 0, 0};
//   int result = 0;
//   s21_create_matrix(3, 3, &m1);

//   m1.matrix[0][0] = 1.0;
//   m1.matrix[0][1] = -2.0;
//   m1.matrix[0][2] = 3.0;
//   m1.matrix[1][0] = -1.0;
//   m1.matrix[1][1] = 14.0;
//   m1.matrix[1][2] = 0.0;
//   m1.matrix[2][0] = 5.55555;
//   m1.matrix[2][1] = 0.012345;
//   m1.matrix[2][2] = 0.111111;

//   result = s21_mult_matrix(&m1, number, &m3);
//   ck_assert_int_eq(result, OK);
  
//   ck_assert_double_eq_tol(m3.matrix[0][0], 0.0, EPS);
//   ck_assert_double_eq_tol(m3.matrix[0][1], 0.0, EPS);
//   ck_assert_double_eq_tol(m3.matrix[0][2], 0.0, EPS);
//   ck_assert_double_eq_tol(m3.matrix[1][0], 0.0, EPS);
//   ck_assert_double_eq_tol(m3.matrix[1][1], 0.0, EPS);
//   ck_assert_double_eq_tol(m3.matrix[1][2], 0.0, EPS);
//   ck_assert_double_eq_tol(m3.matrix[2][0], 0.0, EPS);
//   ck_assert_double_eq_tol(m3.matrix[2][1], 0.0, EPS);
//   ck_assert_double_eq_tol(m3.matrix[2][2], 0.0, EPS);

//   s21_remove_matrix(&m1);

// } END_TEST

// START_TEST(mult_matrix4) {
//   matrix_t m1 = {NULL, 0, 0};
//   double number = 5.5;
//   matrix_t *m3 = NULL;
//   int result = 0;
//   s21_create_matrix(3, 3, &m1);

//   result = s21_mult_matrix(&m1, number, m3);
//   ck_assert_int_eq(result, ERROR);
  
//   s21_remove_matrix(&m1);

// } END_TEST


Suite *suite_mult_matrix(void) {
  Suite *s6;
  TCase *tc6;
  s6 = suite_create("s21_MULT_MATRIX");
  tc6 = tcase_create("case_mult_matrix");
  tcase_add_test(tc6, mult_matrix1);
//   tcase_add_test(tc6, mult_matrix2);
//   tcase_add_test(tc6, mult_matrix3);
//   tcase_add_test(tc6, mult_matrix4);
  // tcase_add_test(tc3, sum5);

  suite_add_tcase(s6, tc6);
  return s6;
}