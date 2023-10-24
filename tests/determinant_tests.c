#include "tests_suite.h"

// START_TEST(determinant1) {
//   matrix_t m1 = {NULL, 0, 0};
//   matrix_t m3 = {NULL, 0, 0};
//   int result = 0;
//   s21_create_matrix(1, 1, &m1);
  
//   m1.matrix[0][0] = 1.225;

//   result = s21_determinant(&m1, &m3);
//   ck_assert_int_eq(result, OK);

//   ck_assert_double_eq_tol(m3.matrix[0][0], 1.255, EPS);

//   s21_remove_matrix(&m1);
//   s21_remove_matrix(&m3);

// } END_TEST

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
  
  ck_assert_double_eq_tol(res, -2.570954, EPS);

  s21_remove_matrix(&m1);


} END_TEST

// START_TEST(determinant3) {
//   matrix_t m1 = {NULL, 0, 0};
//   matrix_t m3 = {NULL, 0, 0};
//   int result = 0;
//   s21_create_matrix(3, 3, &m1);
  
//   m1.matrix[0][0] = 1.255;
//   m1.matrix[0][1] = 25.758;
//   m1.matrix[0][2] = 3.739;
//   m1.matrix[1][0] = 85.356;
//   m1.matrix[1][1] = -124568.0;
//   m1.matrix[1][2] = 1788.0;
//   m1.matrix[2][0] = 1.0;
//   m1.matrix[2][1] = 5.0;
//   m1.matrix[2][2] = 0.0;
  

//   result = s21_determinant(&m1, &m3);
//   ck_assert_int_eq(result, OK);
  
//   ck_assert_double_eq_tol(m3.matrix, 507965.468168, EPS);

//   s21_remove_matrix(&m1);
//   s21_remove_matrix(&m3);

// } END_TEST


// START_TEST(determinant4) {
//   matrix_t m1 = {NULL, 0, 0};
//   matrix_t m3 = {NULL, 0, 0};
//   int result = 0;
//   s21_create_matrix(3, 2, &m1);

//   result = s21_determinant(&m1, &m3);
//   ck_assert_int_eq(result, ERROR_IN_CALC);
  
//   s21_remove_matrix(&m1);

// } END_TEST

// START_TEST(determinant5) {
//   matrix_t m1 = {NULL, 0, 0};
//   matrix_t *m3 = NULL;
//   int result = 0;
//   s21_create_matrix(3, 3, &m1);

//   result = s21_determinant(&m1, m3);
//   ck_assert_int_eq(result, ERROR);
  
//   s21_remove_matrix(&m1);

// } END_TEST


Suite *suite_determinant(void) {
  Suite *s8;
  TCase *tc8;
  s8 = suite_create("s21_DETERMINANT");
  tc8 = tcase_create("case_determinant");
  // tcase_add_test(tc8, determinant1);
  tcase_add_test(tc8, determinant2);
  // tcase_add_test(tc8, determinant3);
  // tcase_add_test(tc8, determinant4);

  suite_add_tcase(s8, tc8);
  return s8;
}