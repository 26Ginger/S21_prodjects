#include "test_s21_matrix.h"

START_TEST(test_s21_calc_complements1) {
  matrix_t A, result;
  int rows = 5;
  int columns = 0;
  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 1);

  status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_s21_calc_complements2) {
  matrix_t A, result;
  int rows = 5;
  int columns = 3;
  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_calc_complements3) {
  matrix_t *A = NULL;
  matrix_t result;

  int status = s21_calc_complements(A, &result);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_s21_calc_complements4) {
  matrix_t A;
  int rows = 5, columns = 5;
  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  matrix_t *result = NULL;
  status = s21_calc_complements(&A, result);
  ck_assert_int_eq(status, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_calc_complements5) {
  matrix_t A, result;
  A.rows = -5;
  A.columns = 3;
  A.matrix = NULL;

  int status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_s21_calc_complements6) {
  matrix_t A, result;
  int rows = 1;
  int columns = 1;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, 0);

  ck_assert_double_eq_tol(result.matrix[0][0], 1, 1e-7);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements7) {
  matrix_t A, result, expected;
  int rows = 5;
  int columns = 5;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  double values[5][5] = {{0, 2, 3, 12, 11},
                         {1, 4, 11, 10, 3},
                         {7, 1, 9, 12, 35},
                         {78, 0, 1, 15, 9},
                         {1, 2, 3, 4, 5}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = values[i][j];
    }
  }

  status = s21_create_matrix(rows, columns, &expected);
  ck_assert_int_eq(status, 0);

  double expected_values[5][5] = {
      {5550.0, 21664.0, 20256.0, -32794.0, 4306.0},
      {670.0, 38380.0, -32229.0, -7012.0, 9461.0},
      {-44.0, 22770.0, -10890.0, 4796.0, -6402.0},
      {-3020.0, 424.0, 754.0, -910.0, 710.0},
      {-6868.0, -230842.0, 49647.0, 44420.0, -20027.0}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      expected.matrix[i][j] = expected_values[i][j];
    }
  }

  status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, 0);

  ck_assert(s21_eq_matrix(&result, &expected) == 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_calc_complements8) {
  matrix_t A, result, expected;
  int rows = 3;
  int columns = 3;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  double values[3][3] = {{1, 10, 3}, {9, 12, 35}, {45, 15, 9}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = values[i][j];
    }
  }

  status = s21_create_matrix(rows, columns, &expected);
  ck_assert_int_eq(status, 0);

  double expected_values[3][3] = {
      {-417.0, 1494, -405.0}, {-45.0, -126.0, 435.0}, {314.0, -8.0, -78.0}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      expected.matrix[i][j] = expected_values[i][j];
    }
  }

  status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, 0);

  ck_assert(s21_eq_matrix(&result, &expected) == 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_calc_complements9) {
  matrix_t A, result, expected;
  int rows = 3;
  int columns = 3;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  double values[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

  double expected_values[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = values[i][j];
    }
  }

  status = s21_create_matrix(rows, columns, &expected);
  ck_assert_int_eq(status, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      expected.matrix[i][j] = expected_values[i][j];
    }
  }

  status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, 0);

  ck_assert(s21_eq_matrix(&result, &expected) == 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_calc_complements10) {
  matrix_t A, result, expected;
  int rows = 2;
  int columns = 2;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  double values[2][2] = {{2, 6}, {7, 3}};

  double expected_values[2][2] = {{3, -7}, {-6, 2}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = values[i][j];
    }
  }

  status = s21_create_matrix(rows, columns, &expected);
  ck_assert_int_eq(status, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      expected.matrix[i][j] = expected_values[i][j];
    }
  }

  status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, 0);

  ck_assert(s21_eq_matrix(&result, &expected) == 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_calc_complements11) {
  matrix_t A, result, expected;
  int rows = 3;
  int columns = 3;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  double values[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};

  double expected_values[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = values[i][j];
    }
  }

  status = s21_create_matrix(rows, columns, &expected);
  ck_assert_int_eq(status, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      expected.matrix[i][j] = expected_values[i][j];
    }
  }

  status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, 0);

  ck_assert(s21_eq_matrix(&result, &expected) == 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_calc_complements12) {
  matrix_t A, result, expected;
  int rows = 3;
  int columns = 3;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  double values[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};

  double expected_values[3][3] = {{-1, 38, -27}, {1, -41, 29}, {-1, 34, -24}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = values[i][j];
    }
  }

  status = s21_create_matrix(rows, columns, &expected);
  ck_assert_int_eq(status, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      expected.matrix[i][j] = expected_values[i][j];
    }
  }

  status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, 0);

  ck_assert(s21_eq_matrix(&result, &expected) == 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_calc_complements13) {
  matrix_t A, result, expected;
  int rows = 1;
  int columns = 1;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  double values[1][1] = {{3}};

  A.matrix[0][0] = values[0][0];

  status = s21_create_matrix(rows, columns, &expected);
  ck_assert_int_eq(status, 0);

  double values_expected[1][1] = {{1}};

  expected.matrix[0][0] = values_expected[0][0];

  status = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status, 0);
  ck_assert(s21_eq_matrix(&result, &expected) == 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements14) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int status = 0, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);

  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;
  matrix1.matrix[1][0] = 0;
  matrix1.matrix[1][1] = 4;
  matrix1.matrix[1][2] = 2;
  matrix1.matrix[2][0] = 5;
  matrix1.matrix[2][1] = 2;
  matrix1.matrix[2][2] = 1;

  matrix2.matrix[0][0] = 0;
  matrix2.matrix[0][1] = 10;
  matrix2.matrix[0][2] = -20;
  matrix2.matrix[1][0] = 4;
  matrix2.matrix[1][1] = -14;
  matrix2.matrix[1][2] = 8;
  matrix2.matrix[2][0] = -8;
  matrix2.matrix[2][1] = -2;
  matrix2.matrix[2][2] = 4;
  status = s21_calc_complements(&matrix1, &matrix_result);
  ck_assert_int_eq(status, 0);
  status = s21_eq_matrix(&matrix2, &matrix_result);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(test_s21_calc_complements15) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &C);
  A.matrix[0][0] = 984.1238;
  C.matrix[0][0] = 1;
  int res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(s21_eq_matrix(&B, &C), SUCCESS);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

Suite *s21_calc_complements_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("COMPLEMENTS");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_calc_complements1);
  tcase_add_test(tc_core, test_s21_calc_complements2);
  tcase_add_test(tc_core, test_s21_calc_complements3);
  tcase_add_test(tc_core, test_s21_calc_complements4);
  tcase_add_test(tc_core, test_s21_calc_complements5);
  tcase_add_test(tc_core, test_s21_calc_complements6);
  tcase_add_test(tc_core, test_s21_calc_complements7);
  tcase_add_test(tc_core, test_s21_calc_complements8);
  tcase_add_test(tc_core, test_s21_calc_complements9);
  tcase_add_test(tc_core, test_s21_calc_complements10);
  tcase_add_test(tc_core, test_s21_calc_complements11);
  tcase_add_test(tc_core, test_s21_calc_complements12);
  tcase_add_test(tc_core, test_s21_calc_complements13);
  tcase_add_test(tc_core, test_s21_calc_complements14);
  tcase_add_test(tc_core, test_s21_calc_complements15);

  suite_add_tcase(s, tc_core);

  return s;
}
