// добавить строчку выделения матрицы под result OK == s21_create_matrix(A->rows, A->columns, result)

#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = OK;
  if (result == NULL || rows < 1 || columns < 1) {
    status = ERROR;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix == NULL) { // подумать об этом тесте, чтобы колок не выделил память
      status = ERROR;
    } else {
        for (int i = 0; i < rows && status == OK; i++) {
          result->matrix[i] = (double *)calloc(columns, sizeof(double));
          if (result->matrix[i] == NULL) { // Подумать над тестом
            status = ERROR;
          }
        }
    }

  }
  return status;
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    if (A->matrix) {
      for(int i = 0; i < A->rows; i++) {
        free(A->matrix[i]);
      }
      free(A->matrix);
    }
  }
}

void s21_printf_matrix (const matrix_t *m) {
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->columns; j++) {
      printf ("%.2f\t", m->matrix[i][j]); 
    }
    printf("\n");
  }
}

int check_matrix (matrix_t *m) {
  int status = FAILURE;
  if (m != NULL) {
    if (m->rows > 0 && m->columns > 0 && m->matrix != NULL) {
      status = SUCCESS;
    }
  }  
  return status;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = SUCCESS;
  if (check_matrix(A) == SUCCESS && check_matrix(B) == SUCCESS) {
    if ((A->rows == B->rows) && (A->columns == B->columns)) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 0.000001) { // разность сделать меньше 6 знаков после запятой, нужно использовать модуль для учета знака fabs(). done
            status = FAILURE;
          } 
        }
      }    
    } else {
      status = FAILURE;
    }
  } else {
      status = FAILURE;
  }
  return status;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK; // окей постаить. done
  if (result) {
    if (check_matrix(A) == SUCCESS && check_matrix(B) == SUCCESS) {
      if ((A->rows == B->rows) && (A->columns == B->columns)) { 
        if (OK == (status = s21_create_matrix(A->rows, A->columns, result))) {
          for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < B->columns; j++) {
              result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
            }
          }
        }
      } else {
        status = ERROR_IN_CALC;
      }
    } else {
      status = ERROR;
    }
  } else {
    status = ERROR;
    }
  return status;   
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;
  if (result) {
    if (check_matrix(A) == SUCCESS && check_matrix(B) == SUCCESS) {
      if ((A->rows == B->rows) && (A->columns == B->columns)) {
        if (OK == s21_create_matrix(A->rows, A->columns, result)) {
          for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
              result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
            }
          }
        }
      } else {
        status = ERROR_IN_CALC;
      }
    } else {
      status = ERROR;
    }
  } else {
    status = ERROR;
    }
  return status;     
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = OK;
  if (result) {
    if (check_matrix(A) == SUCCESS) {
      if (OK == s21_create_matrix(A->rows, A->columns, result)) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = number * A->matrix[i][j];
          }
        }
      }
    } else {
      status = ERROR;
    }
  } else {
    status = ERROR;
    }
  return status;     
}


int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;
  if (result) {
    if (check_matrix(A) == SUCCESS && check_matrix(B) == SUCCESS) {
      if (A->columns == B->rows) {
        if (OK == (status = s21_create_matrix(A->rows, B->columns, result))) {
          double temp = 0;
          for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < B->columns; j++) {
              for (int k = 0; k < B->rows; k++) {

              temp += A->matrix[i][k] * B->matrix[k][j];
              }
              result->matrix[i][j] = temp;
              temp = 0;
            }
          }
        }
      } else {
        status = ERROR_IN_CALC;
      }
    } else {
      status = ERROR;
    }
  } else {
    status = ERROR;
    }
  return status;     
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = OK;
  if (result) {
    if (check_matrix(A) == SUCCESS) {
      if (OK == (status = s21_create_matrix(A->columns, A->rows, result))) {
        for (int i = 0; i < result->rows; i++) {
          for (int j = 0; j < result->columns; j++) {
            result->matrix[i][j] = A->matrix[j][i];
          }
        }
      }
    } else {
      status = ERROR;
    }
  } else {
    status = ERROR;
    }
  return status;     
}


int s21_determinant(matrix_t *A, double *result) {
  int status = OK;
  if (result) {
    if (check_matrix(A) == SUCCESS) {
      if (A->rows == A->columns) {
        *result = s21_calc_determinant(A);
      } else {
        status = ERROR_IN_CALC;
      }
    } else {
      status = ERROR;
    }
  } else {
    status = ERROR;
    }
  return status;     
}

double s21_calc_determinant(matrix_t *A) {
  double calc = 0.0;
  if (A->rows == 1) {
    calc = A->matrix[0][0]; 
  } else if (A->rows == 2) {
    calc = (A->matrix[0][0] * A->matrix[1][1]) - (A->matrix[0][1] * A->matrix[1][0]);
  } else {
    for (int j = 0; j < A->rows; ++j) {
      matrix_t minor = {NULL, 0, 0};
      if (OK == s21_create_matrix (A->rows - 1, A->columns - 1, &minor)) {
        for (int i = 0; i < minor.rows; i++) {
          for (int k = 0; k < minor.columns; k++) { 
            if (j <= k) {
            minor.matrix [i][k] = A->matrix [i+1][k+1];
            } else {
              minor.matrix [i][k] = A->matrix [i+1][k];
            }
          }
        }
      }
      int sign = 0;
      if ((0+j) % 2) {
        sign = -1;
      } else {
        sign = 1;
      }  
    calc += sign * A->matrix[0][j] * s21_calc_determinant(&minor);
    s21_remove_matrix(&minor);
    }
  }
  return calc; 
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
int status = OK;
  if (result) {
    if (check_matrix(A) == SUCCESS) {
      if (A->columns == A->rows) {
        if (OK == (status = s21_create_matrix(A->rows, A->columns, result))) {
          for (int i = 0; i < A->rows; ++i) {
              for (int j = 0; j < A->columns; ++j) {
                result->matrix[i][j] = s21_calc_one_complement(A, i, j);
              }
          }
        }
      } else {
        status = ERROR_IN_CALC;
      }
    } else {
    status = ERROR;
    }
  } else {
  status = ERROR;
  }
  return status;
}
  
double s21_calc_one_complement(matrix_t *A, int row_skip, int col_skip) {
  int sign = 0;
    if ((row_skip+col_skip) % 2) {
      sign = -1;
    } else {
      sign = 1;
    } 
  double minor = s21_calc_minor(A, row_skip, col_skip);
return sign * minor;
}

double s21_calc_minor(matrix_t *A, int row_skip, int col_skip) { // дублирование кода
    
  double result = 0.0;

  matrix_t minor = {NULL, 0, 0};
    if (OK == s21_create_matrix (A->rows - 1, A->columns - 1, &minor)) {
      fill_minor (A, minor, row_skip, col_skip);
      result = s21_calc_determinant(&minor);
      s21_remove_matrix(&minor);
    }
  return result;
}

void fill_minor (matrix_t *A, matrix_t minor, int row_skip, int col_skip) {
  
  for (int i = 0; i < minor.rows; i++) {
    for (int k = 0; k < minor.columns; k++) { 
      if (col_skip <= k) {
        if (row_skip <= i) {
          minor.matrix [i][k] = A->matrix [i+1][k+1];
        } else {
          minor.matrix [i][k] = A->matrix [i][k+1];
        }
      } else {
        if (row_skip <= i) {
          minor.matrix [i][k] = A->matrix [i+1][k];
        } else {
          minor.matrix [i][k] = A->matrix [i][k];
        }
      }
    }
  }
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = ERROR;
  if (result) {
    double tmp = 0.0;
    status = s21_determinant(A, &tmp);
    if (status == OK && tmp != 0.0) {
        matrix_t m1 = {NULL, 0, 0};
        matrix_t m2 = {NULL, 0, 0};

        s21_calc_complements(A, &m1); // тесты на статус
        s21_transpose(&m1, &m2); // тесты на статус
        s21_mult_number(&m2, 1.0 / tmp, result); // тесты на статус

        s21_remove_matrix(&m1);
        s21_remove_matrix(&m2);
    }
  }
  return status;
}






// тесты на сложение, вычитаение, mult number
// проверки на размерность матрицы.
// функция check_matrix, там row и colums могут быть меньше 1 - done

// int main () {
//   matrix_t A = {NULL, 0, 0};
//   s21_create_matrix (3, 3, &A);
//   A.matrix[0][0] = 1.255;
//   A.matrix[0][1] = 25.758;
//   A.matrix[0][2] = 3.739;
//   A.matrix[1][0] = 85.3567889;
//   A.matrix[1][1] = 124;
//   A.matrix[1][2] = 178.0;
//   A.matrix[2][0] = 1.0;
//   A.matrix[2][1] = 5.0;
//   A.matrix[2][2] = 0.0;
//   matrix_t minor = {NULL, 0, 0};
//     if (OK == s21_create_matrix (A.rows - 1, A.columns - 1, &minor)) {
//       int j = 2;
//       for (int i = 0; i < minor.rows; i++) {
//         for (int k = 0; k < minor.columns; k++) {
//           if (j <= k) {
//           minor.matrix [i][k] = A.matrix [i+1][k+1];
//           } else {
//             minor.matrix [i][k] = A.matrix [i+1][k];
//           }
//         }
//       }
//     }
//     s21_printf_matrix (&A);
//     printf ("\n");
//     s21_printf_matrix (&minor);
//     return 0;
// }