#include "tests_suite.h"

START_TEST(calc1) {
  matrix_t m1 = {NULL, 0, 0};
  matrix_t m3 = {NULL, 0, 0};
  int result = 0;
  s21_create_matrix(3, 3, &m1);
  
    m1.matrix[0][0] = 1.0;
    m1.matrix[0][1] = 2.0;
    m1.matrix[0][2] = 3.0;
    m1.matrix[1][0] = 0.0;
    m1.matrix[1][1] = 4.0;
    m1.matrix[1][2] = 2.0;
    m1.matrix[2][0] = 5.0;
    m1.matrix[2][1] = 2.0;
    m1.matrix[2][2] = 1.0;
  

  result = s21_calc_complements(&m1, &m3);
  ck_assert_int_eq(result, OK);
  
    ck_assert_double_eq_tol(m3.matrix[0][0], 0.0, EPS);
    // ck_assert_double_eq_tol(m3.matrix[0][1], 10.0, EPS);
    // ck_assert_double_eq_tol(m3.matrix[0][2], -20.0, EPS);
    ck_assert_double_eq_tol(m3.matrix[1][0], 4.0, EPS);
    ck_assert_double_eq_tol(m3.matrix[1][1], -14.0, EPS);
    ck_assert_double_eq_tol(m3.matrix[1][2], 8.0, EPS);
    ck_assert_double_eq_tol(m3.matrix[2][0], -8.0, EPS);
    ck_assert_double_eq_tol(m3.matrix[2][1], -2.0, EPS);
    ck_assert_double_eq_tol(m3.matrix[2][2], 4.0, EPS);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m3);

} END_TEST


// START_TEST(calc2) {
//   matrix_t m1 = {NULL, 0, 0};
//   matrix_t m3 = {NULL, 0, 0};
//   int result = 0;
//   s21_create_matrix(3, 3, &m1);

//   result = s21_calc_complements(&m1, &m3);
//   ck_assert_int_eq(result, ERROR_IN_CALC);
  
//   s21_remove_matrix(&m1);

// } END_TEST

// START_TEST(calc3) {
//   matrix_t m1 = {NULL, 0, 0};
//   matrix_t *m3 = NULL;
//   int result = 0;
//   s21_create_matrix(3, 3, &m1);

//   result = s21_calc_complements(&m1, m3);
//   ck_assert_int_eq(result, ERROR);
  
//   s21_remove_matrix(&m1);

// } END_TEST


Suite *suite_calc(void) {
  Suite *s9;
  TCase *tc9;
  s9 = suite_create("s21_CALC");
  tc9 = tcase_create("case_calc");
  tcase_add_test(tc9, calc1);
  // tcase_add_test(tc9, calc2);
  // tcase_add_test(tc9, calc3);

  suite_add_tcase(s9, tc9);
  return s9;
}