#include "s21_matrix.h"

/*
    0 - OK
    1 - Error, incorrect matrix
    2 - Calculation error
    (mismatched matrix sizes; matrix for which calculations cannot be performed,
   etc.)
*/

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = 0;
  /* isfinite проверяет, является ли число конечным, исключая бесконечности и
   * NaN (Not a Number) */
  if (s21_is_invalid_matrix(A) || result == NULL || !isfinite(number)) {
    status = 1;
  }

  if (status == 0) {
    status = s21_create_matrix(A->rows, A->columns, result);

    if (status == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  }
  return status;
}
