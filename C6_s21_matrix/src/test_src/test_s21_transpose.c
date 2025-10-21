#include "test_s21_matrix.h"

START_TEST(test_s21_transpose1) {
  matrix_t A;
  int rows = 3;
  int columns = 2;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  double value = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      value = rand() % 10;
      A.matrix[i][j] = value;
    }
  }
  matrix_t result;
  status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq(result.matrix[j][i], A.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose2) {
  matrix_t A;
  int rows = 5;
  int columns = 5;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  double value = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      value = rand() % 10;
      A.matrix[i][j] = value;
    }
  }
  matrix_t result;
  status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq(result.matrix[j][i], A.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose3) {
  matrix_t A;
  int rows = 1;
  int columns = 7;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  double value = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      value = rand() % 10;
      A.matrix[i][j] = value;
    }
  }
  matrix_t result;
  status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq(result.matrix[j][i], A.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose4) {
  matrix_t A;
  int rows = 0;
  int columns = 2;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 1);

  matrix_t result;
  status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_s21_transpose5) {
  matrix_t A;
  int rows = 3;
  int columns = 5;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 1;
    }
  }

  status = s21_transpose(&A, NULL);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_transpose6) {
  matrix_t A;
  int rows = 1;
  int columns = 1;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  double value = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      value = -rand() % 10;
      A.matrix[i][j] = value;
    }
  }
  matrix_t result;
  status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq(result.matrix[j][i], A.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose7) {
  matrix_t A, result, expected;
  int rows = 3;
  int columns = 2;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  status = s21_create_matrix(columns, rows, &expected);
  ck_assert_int_eq(status, 0);

  double values[3][2] = {{1, 4}, {2, 5}, {3, 6}};
  double expected_values[2][3] = {{1, 2, 3}, {4, 5, 6}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = values[i][j];
    }
  }

  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      expected.matrix[i][j] = expected_values[i][j];
    }
  }

  status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, 0);

  ck_assert(s21_eq_matrix(&result, &expected) == 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_transpose8) {
  matrix_t A, result, expected;
  int rows = 2;
  int columns = 2;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  status = s21_create_matrix(columns, rows, &expected);
  ck_assert_int_eq(status, 0);

  double values[2][2] = {{1, 2}, {3, 4}};
  double expected_values[2][2] = {{1, 3}, {2, 4}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = values[i][j];
    }
  }

  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      expected.matrix[i][j] = expected_values[i][j];
    }
  }

  status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, 0);

  ck_assert(s21_eq_matrix(&result, &expected) == 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

Suite *s21_transpose_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("TRANSPOSE");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_transpose1);
  tcase_add_test(tc_core, test_s21_transpose2);
  tcase_add_test(tc_core, test_s21_transpose3);
  tcase_add_test(tc_core, test_s21_transpose4);
  tcase_add_test(tc_core, test_s21_transpose5);
  tcase_add_test(tc_core, test_s21_transpose6);
  tcase_add_test(tc_core, test_s21_transpose7);
  tcase_add_test(tc_core, test_s21_transpose8);

  suite_add_tcase(s, tc_core);

  return s;
}