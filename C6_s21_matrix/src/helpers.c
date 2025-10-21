#include "s21_matrix.h"

int s21_is_invalid_matrix(matrix_t *matrix) {
  if (matrix == NULL || matrix->matrix == NULL || matrix->rows <= 0 ||
      matrix->columns <= 0) {
    return 1;
  }

  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      if (isinf(matrix->matrix[i][j]) || isnan(matrix->matrix[i][j])) {
        return 1;
      }
    }
  }

  return 0;
}

int s21_calc_minor(matrix_t *A, double *minor, int row,
                   int column) {  // i j
  int size = A->rows;
  if (size < 2) return 1;

  matrix_t sub_matrix;
  if (s21_create_matrix(size - 1, size - 1, &sub_matrix) != 0) return 1;

  int sub_i = 0;
  for (int i = 0; i < size; i++) {
    if (i == row) continue;
    int sub_j = 0;
    for (int j = 0; j < size; j++) {
      if (j == column) continue;
      sub_matrix.matrix[sub_i][sub_j] = A->matrix[i][j];
      sub_j++;
    }
    sub_i++;
  }

  double minor_determinant;
  int status = s21_determinant(&sub_matrix, &minor_determinant);
  s21_remove_matrix(&sub_matrix);

  if (status != 0) return 1;

  *minor = minor_determinant;
  return 0;
}

// void s21_print_matrix(matrix_t *matrix) {
//   if (matrix == NULL || matrix->matrix == NULL ||
//   s21_is_invalid_matrix(matrix))
//     return;
//   int rows = matrix->rows;
//   int columns = matrix->columns;

//   for (int i = 0; i < rows; i++) {
//     for (int j = 0; j < columns; j++) {
//       printf("\033[38;5;82m%.2lf\t\033[0m", matrix->matrix[i][j]);
//     }
//     printf("\n");
//   }
//   printf("\n");
// }