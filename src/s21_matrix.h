#ifndef H21_MATRIX_H
#define H21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EPS 0.0000001

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum error_code {
  OK,
  ERROR,        /*- Ошибка, некорректная матрица*/
  ERROR_IN_CALC /*Ошибка вычисления*/
};

enum compare_codes { FAILURE, SUCCESS };

int s21_create_matrix(int rows, int columns, matrix_t *result);

void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// Вспомогательные функции
// void s21_printf_matrix(const matrix_t *m);
int s21_check_matrix(matrix_t *m);
double s21_calc_determinant(matrix_t *A);
double s21_calc_one_complement(matrix_t *A, int row_skip, int col_skip);
double s21_calc_minor(matrix_t *A, int row_skip, int col_skip);
void s21_fill_minor(matrix_t *A, matrix_t minor, int row_skip, int col_skip);

#endif  // H21_MATRIX_H