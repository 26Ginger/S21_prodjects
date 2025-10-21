#include "test_s21_matrix.h"

START_TEST(test_s21_inverse_matrix1) {
  matrix_t A, result;
  int rows = 5;
  int columns = 0;
  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 1);

  status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_s21_inverse_matrix2) {
  matrix_t A, result;
  int rows = 5;
  int columns = 3;
  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix3) {
  matrix_t *A = NULL;
  matrix_t result;

  int status = s21_inverse_matrix(A, &result);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_s21_inverse_matrix4) {
  matrix_t A;
  int rows = 5, columns = 5;
  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  matrix_t *result = NULL;
  status = s21_inverse_matrix(&A, result);
  ck_assert_int_eq(status, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix5) {
  matrix_t A, result;
  A.rows = -5;
  A.columns = 3;
  A.matrix = NULL;

  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_s21_inverse_matrix6) {
  matrix_t A, result;
  int rows = 1;
  int columns = 1;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix7) {
  matrix_t A, result;
  int rows = 3;
  int columns = 3;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  double values[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = values[i][j];
    }
  }

  status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix8) {
  matrix_t A, result, expected;
  int rows = 2;
  int columns = 2;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  double values[2][2] = {{2, 6}, {7, 3}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = values[i][j];
    }
  }

  status = s21_create_matrix(rows, columns, &expected);
  ck_assert_int_eq(status, 0);

  double values_expected[2][2] = {{-0.08333333, 0.16666667},
                                  {0.19444444, -0.05555556}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      expected.matrix[i][j] = values_expected[i][j];
    }
  }

  status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, 0);
  ck_assert(s21_eq_matrix(&result, &expected) == 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_inverse_matrix9) {
  matrix_t A, result, expected;
  int rows = 3;
  int columns = 3;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  double values[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = values[i][j];
    }
  }

  status = s21_create_matrix(rows, columns, &expected);
  ck_assert_int_eq(status, 0);

  double values_expected[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      expected.matrix[i][j] = values_expected[i][j];
    }
  }

  status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, 0);
  ck_assert(s21_eq_matrix(&result, &expected) == 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_inverse_matrix10) {
  matrix_t A, result, expected;
  int rows = 1;
  int columns = 1;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  double values[1][1] = {{3}};

  A.matrix[0][0] = values[0][0];

  status = s21_create_matrix(rows, columns, &expected);
  ck_assert_int_eq(status, 0);

  double values_expected[1][1] = {{0.3333333333}};

  expected.matrix[0][0] = values_expected[0][0];

  status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, 0);
  ck_assert(s21_eq_matrix(&result, &expected) == 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_inverse_matrix11) {
  matrix_t A, result, expected;
  int rows = 1, columns = 1, status = 0;

  status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  double values[1][1] = {{0}};

  A.matrix[0][0] = values[0][0];

  status = s21_create_matrix(rows, columns, &expected);
  ck_assert_int_eq(status, 0);

  status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
}
END_TEST

Suite *s21_inverse_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("INVERSE");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_inverse_matrix1);
  tcase_add_test(tc_core, test_s21_inverse_matrix2);
  tcase_add_test(tc_core, test_s21_inverse_matrix3);
  tcase_add_test(tc_core, test_s21_inverse_matrix4);
  tcase_add_test(tc_core, test_s21_inverse_matrix5);
  tcase_add_test(tc_core, test_s21_inverse_matrix6);
  tcase_add_test(tc_core, test_s21_inverse_matrix7);
  tcase_add_test(tc_core, test_s21_inverse_matrix8);
  tcase_add_test(tc_core, test_s21_inverse_matrix9);
  tcase_add_test(tc_core, test_s21_inverse_matrix10);
  tcase_add_test(tc_core, test_s21_inverse_matrix11);
  suite_add_tcase(s, tc_core);

  return s;
}
