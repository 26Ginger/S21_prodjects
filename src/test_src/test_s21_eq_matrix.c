#include "test_s21_matrix.h"

/*
#define SUCCESS 1
#define FAILURE 0

*/

START_TEST(test_eq_matrix1) {
  matrix_t A;
  matrix_t B;
  int rows = 3;
  int columns = 3;
  int status_A = s21_create_matrix(rows, columns, &A);
  int status_B = s21_create_matrix(rows, columns, &B);

  ck_assert_int_eq(status_A, 0);
  ck_assert_int_eq(status_B, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 0.0;
      B.matrix[i][j] = 0.0;
    }
  }

  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix2) {
  matrix_t A;
  matrix_t B;
  int rows = 3;
  int columns = 3;
  int status_A = s21_create_matrix(rows, columns, &A);
  int status_B = s21_create_matrix(rows, columns, &B);

  ck_assert_int_eq(status_A, 0);
  ck_assert_int_eq(status_B, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 0.0;
      B.matrix[i][j] = 1.1;
    }
  }

  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix3) {
  matrix_t A;
  matrix_t B;
  int rows = 3;
  int columns_A = 3;
  int columns_B = 5;
  int status_A = s21_create_matrix(rows, columns_A, &A);
  int status_B = s21_create_matrix(rows, columns_B, &B);

  ck_assert_int_eq(status_A, 0);
  ck_assert_int_eq(status_B, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns_A; j++) {
      A.matrix[i][j] = 1.1;
    }
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns_B; j++) {
      B.matrix[i][j] = 1.1;
    }
  }

  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix4) {
  matrix_t A;
  matrix_t B;
  int rows_A = 3;
  int rows_B = 8;
  int columns = 3;
  int status_A = s21_create_matrix(rows_A, columns, &A);
  int status_B = s21_create_matrix(rows_B, columns, &B);

  ck_assert_int_eq(status_A, 0);
  ck_assert_int_eq(status_B, 0);

  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 2.2222222;
    }
  }

  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns; j++) {
      B.matrix[i][j] = 2.2222222;
    }
  }

  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix5) {
  matrix_t A;
  matrix_t B;
  int rows = 3;
  int columns = 7;
  int status_A = s21_create_matrix(rows, columns, &A);
  int status_B = s21_create_matrix(rows, columns, &B);

  ck_assert_int_eq(status_A, 0);
  ck_assert_int_eq(status_B, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i * j * 2.2222222;
      B.matrix[i][j] = i * j * 2.2222222;
    }
  }

  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix6) {
  matrix_t A;
  matrix_t B;
  int rows = 3;
  int columns = 7;
  int status_A = s21_create_matrix(rows, columns, &A);
  int status_B = s21_create_matrix(rows, columns, &B);

  ck_assert_int_eq(status_A, 0);
  ck_assert_int_eq(status_B, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 2.0000001;
      B.matrix[i][j] = 2.0000000;
    }
  }

  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix7) {
  matrix_t A;
  matrix_t B;
  int rows = 3;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 1.0;
    }
  }
  B.rows = 0;
  B.columns = 0;
  B.matrix = NULL;

  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_eq_matrix8) {
  matrix_t A;
  matrix_t B;
  int rows = 1000;
  int columns = 1000;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 123.456;
      B.matrix[i][j] = 123.456;
    }
  }

  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix9) {
  matrix_t A;
  matrix_t B;
  int rows = 5;
  int columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  double value = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      value = rand();
      A.matrix[i][j] = value;
      B.matrix[i][j] = value;
    }
  }

  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix10) {
  matrix_t matrix1;
  matrix_t matrix2;
  int result, rows = 2, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  result = s21_eq_matrix(&matrix1, &matrix2);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(test_eq_matrix11) {
  matrix_t A = {0};
  matrix_t B = {0};
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(FAILURE, result);
}
END_TEST

Suite *s21_eq_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("EQ");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_eq_matrix1);
  tcase_add_test(tc_core, test_eq_matrix2);
  tcase_add_test(tc_core, test_eq_matrix3);
  tcase_add_test(tc_core, test_eq_matrix4);
  tcase_add_test(tc_core, test_eq_matrix5);
  tcase_add_test(tc_core, test_eq_matrix6);
  tcase_add_test(tc_core, test_eq_matrix7);
  tcase_add_test(tc_core, test_eq_matrix8);
  tcase_add_test(tc_core, test_eq_matrix9);
  tcase_add_test(tc_core, test_eq_matrix10);
  tcase_add_test(tc_core, test_eq_matrix11);

  suite_add_tcase(s, tc_core);

  return s;
}
