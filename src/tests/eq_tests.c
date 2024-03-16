#include "tests_suite.h"

START_TEST(eq1) {
  matrix_t m1 = {NULL, 0, 0};
  matrix_t m2 = {NULL, 0, 0};
  int result = 0;
  s21_create_matrix(3, 3, &m1);
  s21_create_matrix(3, 3, &m2);

  m1.matrix[0][0] = 1.0;
  m1.matrix[0][1] = 2.0;
  m1.matrix[0][2] = 3.0;
  m1.matrix[1][0] = 1.0;
  m1.matrix[1][1] = 1.0;
  m1.matrix[1][2] = 1.0;
  m1.matrix[2][0] = 1.0;
  m1.matrix[2][1] = 5.0;
  m1.matrix[2][2] = 4.0;

  m2.matrix[0][0] = 1.0;
  m2.matrix[0][1] = 2.0;
  m2.matrix[0][2] = 3.0;
  m2.matrix[1][0] = 1.0;
  m2.matrix[1][1] = 1.0;
  m2.matrix[1][2] = 1.0;
  m2.matrix[2][0] = 1.0;
  m2.matrix[2][1] = 5.0;
  m2.matrix[2][2] = 4.0;

  result = s21_eq_matrix(&m1, &m2);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
}
END_TEST

START_TEST(eq2) {
  matrix_t m1 = {NULL, 0, 0};
  matrix_t m2 = {NULL, 0, 0};
  int result = 0;

  s21_create_matrix(3, 3, &m1);
  s21_create_matrix(3, 3, &m2);

  m1.matrix[0][0] = 1.32478978;
  m1.matrix[0][1] = 2.78787967;
  m1.matrix[0][2] = 3234.1232345;
  m1.matrix[1][0] = 17.3454359;
  m1.matrix[1][1] = 1.4355464;
  m1.matrix[1][2] = 1.8787974;
  m1.matrix[2][0] = 145.3445645;
  m1.matrix[2][1] = 5.455623423;
  m1.matrix[2][2] = 4.234435234;

  m2.matrix[0][0] = 1.3247897;
  m2.matrix[0][1] = 2.7878797;
  m2.matrix[0][2] = 3234.1232345;
  m2.matrix[1][0] = 17.3454359;
  m2.matrix[1][1] = 1.4355464;
  m2.matrix[1][2] = 1.8787974;
  m2.matrix[2][0] = 145.3445645;
  m2.matrix[2][1] = 5.4556234;
  m2.matrix[2][2] = 4.2344352;

  result = s21_eq_matrix(&m1, &m2);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
}
END_TEST

START_TEST(eq3) {
  matrix_t m1 = {NULL, 0, 0};
  matrix_t m2 = {NULL, 0, 0};

  int result = 0;

  s21_create_matrix(3, 3, &m1);
  s21_create_matrix(3, 3, &m2);

  m1.matrix[0][0] = 1.3257897;
  m1.matrix[0][1] = 2.78787967;
  m1.matrix[0][2] = 3234.1232345;
  m1.matrix[1][0] = 17.3454359;
  m1.matrix[1][1] = 1.4355464;
  m1.matrix[1][2] = 1.8787974;
  m1.matrix[2][0] = 145.3445645;
  m1.matrix[2][1] = 7.455623423;
  m1.matrix[2][2] = 4.234435234;

  m2.matrix[0][0] = 1.324789;
  m2.matrix[0][1] = 2.787879;
  m2.matrix[0][2] = 3234.123234;
  m2.matrix[1][0] = 17.345435;
  m2.matrix[1][1] = 1.435546;
  m2.matrix[1][2] = 1.878797;
  m2.matrix[2][0] = 145.344564;
  m2.matrix[2][1] = 5.455623;
  m2.matrix[2][2] = 4.234435;

  result = s21_eq_matrix(&m1, &m2);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
}
END_TEST

START_TEST(eq4) {
  matrix_t m1 = {NULL, 0, 0};
  int result = 0;
  s21_create_matrix(2, 3, &m1);
  matrix_t *m2 = NULL;
  result = s21_eq_matrix(&m1, m2);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&m1);
}
END_TEST

START_TEST(eq5) {
  matrix_t m1 = {NULL, 0, 0};
  matrix_t m2 = {NULL, 0, 0};
  int result = 0;
  s21_create_matrix(2, 3, &m1);
  s21_create_matrix(3, 3, &m2);
  result = s21_eq_matrix(&m1, &m2);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
}
END_TEST

Suite *suite_eq(void) {
  Suite *s2;
  TCase *tc2;
  s2 = suite_create("S21_EQ");
  tc2 = tcase_create("case_eq");
  tcase_add_test(tc2, eq1);
  tcase_add_test(tc2, eq2);
  tcase_add_test(tc2, eq3);
  tcase_add_test(tc2, eq4);
  tcase_add_test(tc2, eq5);

  suite_add_tcase(s2, tc2);
  return s2;
}