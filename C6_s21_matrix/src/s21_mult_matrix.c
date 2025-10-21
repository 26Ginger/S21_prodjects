#include "s21_matrix.h"

/* Если количество столбцов в первой матрице (A->columns)
не совпадает с количеством строк во второй матрице (B->rows),
то операция умножения не может быть выполнена. */

/* Произведением матрицы A = m × k на матрицу B = k × n называется
матрица C = m × n = A × B размера m × n, элементы которой определяются
равенством C(i,j) = A(i,1) × B(1,j) + A(i,2) × B(2,j) + … + A(i,k) × B(k,j). */

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = 0;
  if (s21_is_invalid_matrix(A) || s21_is_invalid_matrix(B) || result == NULL) {
    status = 1;
  } else if (A->columns != B->rows) {
    status = 2;
  }

  if (status == 0) status = s21_create_matrix(A->rows, B->columns, result);
  if (status == 0) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = 0;  // Инициализация pupupu
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }

  return status;
}