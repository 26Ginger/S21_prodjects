#include "test_s21_matrix.h"

START_TEST(test_s21_mult_matrix1) {
  int rows = 3;
  int columns = 3;

  matrix_t A;
  A.rows = rows;
  A.columns = columns;

  matrix_t result;

  int status_A = s21_create_matrix(rows, columns, &A);

  ck_assert_int_eq(status_A, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 0.123456 * i + j;
    }
  }

  double number = 123.456;

  int status_mult = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(status_mult, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], A.matrix[i][j] * number);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

END_TEST

START_TEST(test_s21_mult_matrix2) {
  int rows = 3;
  int columns = 3;

  matrix_t A;
  A.rows = rows;
  A.columns = columns;

  matrix_t result;

  int status_A = s21_create_matrix(rows, columns, &A);

  ck_assert_int_eq(status_A, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 0.123456 * i + j;
    }
  }

  double number = 0;

  int status_mult = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(status_mult, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], A.matrix[i][j] * number);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix3) {
  int rows = 3;
  int columns = 3;

  matrix_t A;
  A.rows = rows;
  A.columns = columns;

  matrix_t result;

  int status_A = s21_create_matrix(rows, columns, &A);

  ck_assert_int_eq(status_A, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 0.123456 * i + j;
    }
  }

  double number = 0.0000000000001;

  int status_mult = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(status_mult, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], A.matrix[i][j] * number);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix4) {
  int rows = 3;
  int columns = 3;

  matrix_t A;
  A.rows = rows;
  A.columns = columns;

  matrix_t result;

  int status_A = s21_create_matrix(rows, columns, &A);

  ck_assert_int_eq(status_A, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 0.123456 * i + j;
    }
  }

  double number = 100000000000;

  int status_mult = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(status_mult, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], A.matrix[i][j] * number);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix5) {
  int rows = 3;
  int columns = 7;

  matrix_t A;

  int status_A = s21_create_matrix(rows, columns, &A);

  ck_assert_int_eq(status_A, 0);

  double number = 123.456;

  int status_mult = s21_mult_number(&A, number, NULL);

  ck_assert_int_eq(status_mult, 1);

  s21_remove_matrix(&A);
}

END_TEST

START_TEST(test_s21_mult_matrix6) {
  int rows = 5;
  int columns = -1;

  matrix_t A;
  matrix_t result;

  int status_A = s21_create_matrix(rows, columns, &A);

  ck_assert_int_eq(status_A, 1);

  double number = 123.456;

  int status_mult = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(status_mult, 1);
}

END_TEST

Suite *s21_mult_number_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("MULT NUMBER");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_mult_matrix1);
  tcase_add_test(tc_core, test_s21_mult_matrix2);
  tcase_add_test(tc_core, test_s21_mult_matrix3);
  tcase_add_test(tc_core, test_s21_mult_matrix4);
  tcase_add_test(tc_core, test_s21_mult_matrix5);
  tcase_add_test(tc_core, test_s21_mult_matrix6);

  suite_add_tcase(s, tc_core);

  return s;
}
