#include "s21_matrix.h"

/*
    0 - OK
    1 - Error, incorrect matrix
    2 - Calculation error
    (mismatched matrix sizes; matrix for which calculations cannot be performed,
   etc.)
*/

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = 0;
  if (s21_is_invalid_matrix(A) || s21_is_invalid_matrix(B) || result == NULL) {
    status = 1;
  }

  if ((status == 0) && (A->rows != B->rows || A->columns != B->columns)) {
    status = 2;
  }

  if (status == 0) {
    status = s21_create_matrix(A->rows, A->columns, result);

    if (status == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    }
  }
  return status;
}
