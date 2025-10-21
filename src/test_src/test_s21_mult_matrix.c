#include "test_s21_matrix.h"

// int s21_mult_matrix_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

START_TEST(test_s21_mult_matrix_matrix1) {
  int rows = 3;
  int columns = 3;

  matrix_t A;
  A.rows = rows;
  A.columns = columns;

  matrix_t B;
  B.rows = rows;
  B.columns = columns;

  matrix_t result;

  int status_A = s21_create_matrix(rows, columns, &A);
  int status_B = s21_create_matrix(rows, columns, &B);

  ck_assert_int_eq(status_A, 0);
  ck_assert_int_eq(status_B, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 0.123456 * i + j;
      B.matrix[i][j] = i * j + 0.123456;
    }
  }

  int status_mult_matrix = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(status_mult_matrix, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double expected_value = 0.0;
      for (int k = 0; k < columns; k++) {
        expected_value += A.matrix[i][k] * B.matrix[k][j];
      }
      ck_assert_double_eq(result.matrix[i][j], expected_value);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

END_TEST

START_TEST(test_s21_mult_matrix_matrix2) {
  int rows_A = 4;
  int rows_B = 5;
  int columns = 3;

  matrix_t A;
  matrix_t B;
  matrix_t result;

  int status_A = s21_create_matrix(rows_A, columns, &A);
  int status_B = s21_create_matrix(rows_B, columns, &B);

  ck_assert_int_eq(status_A, 0);
  ck_assert_int_eq(status_B, 0);

  int status_mult_matrix = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(status_mult_matrix, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_mult_matrix_matrix3) {
  int rows = 3;
  int columns_A = 7;
  int columns_B = 7;

  matrix_t A;
  matrix_t B;
  matrix_t result;

  int status_A = s21_create_matrix(rows, columns_A, &A);
  int status_B = s21_create_matrix(rows, columns_B, &B);

  ck_assert_int_eq(status_A, 0);
  ck_assert_int_eq(status_B, 0);

  int status_mult_matrix = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(status_mult_matrix, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

END_TEST

START_TEST(test_s21_mult_matrix_matrix4) {
  int rows = 3;
  int columns = 7;

  matrix_t A;
  matrix_t B;

  int status_A = s21_create_matrix(rows, columns, &A);
  int status_B = s21_create_matrix(rows, columns, &B);

  ck_assert_int_eq(status_A, 0);
  ck_assert_int_eq(status_B, 0);

  int status_mult_matrix = s21_mult_matrix(&A, &B, NULL);

  ck_assert_int_eq(status_mult_matrix, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

END_TEST

START_TEST(test_s21_mult_matrix_matrix5) {
  int rows = 0;
  int columns = 7;

  matrix_t A;
  matrix_t B;
  matrix_t result;

  int status_A = s21_create_matrix(rows, columns, &A);
  int status_B = s21_create_matrix(rows, columns, &B);

  ck_assert_int_eq(status_A, 1);
  ck_assert_int_eq(status_B, 1);

  int status_mult_matrix = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(status_mult_matrix, 1);
}

END_TEST

Suite *s21_mult_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("MULT MATRIX");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_mult_matrix_matrix1);
  tcase_add_test(tc_core, test_s21_mult_matrix_matrix2);
  tcase_add_test(tc_core, test_s21_mult_matrix_matrix3);
  tcase_add_test(tc_core, test_s21_mult_matrix_matrix4);
  tcase_add_test(tc_core, test_s21_mult_matrix_matrix5);

  suite_add_tcase(s, tc_core);

  return s;
}
