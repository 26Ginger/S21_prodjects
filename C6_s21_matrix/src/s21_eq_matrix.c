#include "s21_matrix.h"

/*
#define SUCCESS 1
#define FAILURE 0

*/

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL ||
      A->columns != B->columns || A->rows != B->rows) {
    return FAILURE;
  }

  int status = SUCCESS;
  double precision = 1e-8;  // 7 + 1
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > precision) {
        status = FAILURE;
        i = A->rows;
        j = A->columns;
      }
    }
  }

  return status;
}
