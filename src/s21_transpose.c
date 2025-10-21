#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = 0;

  if (result == NULL || s21_is_invalid_matrix(A)) {
    status = 1;
  }
  if (status == 0) status = s21_create_matrix(A->columns, A->rows, result);
  if (status == 0) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }

  return status;
}