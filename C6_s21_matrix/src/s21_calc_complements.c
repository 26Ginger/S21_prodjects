#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = 0;

  if (result == NULL || s21_is_invalid_matrix(A)) {
    status = 1;
  } else if (A->rows != A->columns) {
    status = 2;
  }

  if (status == 0) status = s21_create_matrix(A->columns, A->rows, result);
  if (status == 0) {
    int size = A->rows;
    if (size == 1) {
      result->matrix[0][0] = 1.0;
    } else {
      double minor = 0;

      for (int i = 0; !status && i < size; i++) {
        for (int j = 0; j < size; j++) {
          if (s21_calc_minor(A, &minor, i, j) != 0) {
            s21_remove_matrix(result);
            status = 1;
            break;
          }
          if (status == 0) {
            double complement = minor;
            if ((i + j) % 2 != 0) complement = -complement;
            result->matrix[i][j] = complement;
          }
        }
      }
    }
  }
  return status;
}
