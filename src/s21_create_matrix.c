#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = 0;

  if (rows <= 0 || columns <= 0 || result == NULL ||
      (size_t)rows > INT_MAX / sizeof(double *) ||
      (size_t)columns > INT_MAX / sizeof(double) ||
      (size_t)rows * (size_t)columns > INT_MAX / sizeof(double)) {
    status = 1;
  }
  if (status == 1) {
    if (result != NULL) {
      result->rows = 0;
      result->columns = 0;
      result->matrix = NULL;
    }
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix == NULL) {
      status = 1;
    } else {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          // status = 1;
          // for (int j = 0; j < i; j++) {
          //   free(result->matrix[j]);
          // }
          // free(result->matrix);
          // break;
        }
      }
    }
  }

  return status;
}