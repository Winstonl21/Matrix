#ifndef S21_MATRIX_TESTS_SUITE_H
#define S21_MATRIX_TESTS_SUITE_H

#include <check.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#include "../s21_matrix.h"

Suite *suite_create_matrix(void);
Suite *suite_eq(void);
Suite *suite_sum(void);
Suite *suite_sub(void);
Suite *suite_mult_number(void);
Suite *suite_mult_matrix(void);
Suite *suite_transpose(void);
Suite *suite_determinant(void);
Suite *suite_calc(void);
Suite *suite_inverse(void);





void run_tests(void);
void run_testcases(Suite *testcase);

#endif // S21_MATRIX_TESTS_SUITE_H