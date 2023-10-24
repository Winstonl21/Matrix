
#include "tests_suite.h"


START_TEST(create_test1) {
  matrix_t m1 = {NULL, 0, 0};
  int result = 0;
  result = s21_create_matrix(1, 3, &m1);
  ck_assert_int_eq(result, OK);
  s21_remove_matrix(&m1);
} END_TEST


START_TEST(create_test2) {
  matrix_t m1 = {NULL, 0, 0};  
  int result = 0;
  result = s21_create_matrix(2147483647, 1, &m1); // MAX_INT
  ck_assert_int_eq(result, ERROR);
  s21_remove_matrix(&m1);
} END_TEST

START_TEST(create_test3) {
  matrix_t m1 = {NULL, 0, 0};// тут нужно чтобы не выделалась память уже под колонки
  int result = 0;
  result = s21_create_matrix(3, 2147483647, &m1);
  ck_assert_int_eq(result, ERROR);
  s21_remove_matrix(&m1);
} END_TEST

START_TEST(create_test4) {
  matrix_t m1 = {NULL, 0, 0};;
  int result = 0;
  result = s21_create_matrix(0, 2, &m1);
  ck_assert_int_eq(result, ERROR);
  s21_remove_matrix(&m1);
} END_TEST

START_TEST(create_test5) {
  matrix_t m1 = {NULL, 0, 0};
  int result = 0;
  result = s21_create_matrix(-1, -5, &m1);
  ck_assert_int_eq(result, ERROR);
  s21_remove_matrix(&m1);
} END_TEST

START_TEST(create_test6) {
  matrix_t *m1 = NULL; // нужносделать эту матрицу либо слишком маленькой либо слишком большой, либо внутри структуры, какой то неправильный **matrix  
  int result = 0;
  result = s21_create_matrix(3, 1, m1);
  ck_assert_int_eq(result, ERROR);
  s21_remove_matrix(m1);
} END_TEST

Suite *suite_create_matrix(void) {
  Suite *s1;
  TCase *tc1;
  s1 = suite_create("s21_CREATE");
  tc1 = tcase_create("case_create");
  tcase_add_test(tc1, create_test1);
  tcase_add_test(tc1, create_test2);
  tcase_add_test(tc1, create_test3);
  tcase_add_test(tc1, create_test4);
  tcase_add_test(tc1, create_test5);
  tcase_add_test(tc1, create_test6);

  suite_add_tcase(s1, tc1);
  return s1;
}