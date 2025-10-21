#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = 0;

  if (result == NULL || s21_is_invalid_matrix(A)) {
    status = 1;
  } else if (A->rows != A->columns) {
    status = 2;
  }

  if (status == 0) {
    double det = 0;
    s21_determinant(A, &det);

    if (det) {
      matrix_t complements = {0}, adjugate = {0};
      s21_calc_complements(A, &complements);
      s21_transpose(&complements, &adjugate); /* присоединённая */
      s21_remove_matrix(&complements);
      det = 1.0 / det;
      status = s21_mult_number(&adjugate, det, result);
      s21_remove_matrix(&adjugate);
    } else
      status = 2;
  }
  return status;
}
