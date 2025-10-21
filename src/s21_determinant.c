#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) { /* Метод Гаусса */
  int status = 0;

  if (result == NULL || s21_is_invalid_matrix(A)) {
    status = 1;
  }

  if (status == 0) {
    if (A->rows != A->columns) {
      status = 2;
    }
  }

  if (status == 0) {
    matrix_t copy;
    status = s21_create_matrix(A->rows, A->columns, &copy);
    if (status == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          copy.matrix[i][j] = A->matrix[i][j];
        }
      }

      double determinant = 1;
      int swaps = 0;
      int size = copy.rows;
      for (int i = 0; i < size; i++) {
        int max_row = i;
        for (int k = i + 1; k < size; k++) {
          if (fabs(copy.matrix[k][i]) > fabs(copy.matrix[max_row][i])) {
            max_row = k;
          }
        }

        if (copy.matrix[max_row][i] == 0) {
          determinant = 0;
          break;
        }

        if (max_row != i) {
          for (int j = 0; j < size; j++) {
            double temp = copy.matrix[i][j];
            copy.matrix[i][j] = copy.matrix[max_row][j];
            copy.matrix[max_row][j] = temp;
          }
          swaps++;
        }

        for (int k = i + 1; k < size; k++) {
          double factor = copy.matrix[k][i] / copy.matrix[i][i];
          for (int j = i; j < size; j++) {
            copy.matrix[k][j] -= factor * copy.matrix[i][j];
          }
        }
      }

      for (int i = 0; i < size; i++) {
        determinant *= copy.matrix[i][i];
      }

      if (swaps % 2 != 0) {
        determinant = -determinant;
      }

      *result = determinant;
      s21_remove_matrix(&copy);
    }
  }

  return status;
}