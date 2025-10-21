#include "test_s21_matrix.h"

START_TEST(test_s21_determinant1) {
  matrix_t matrix;
  int rows = 0;
  int columns = 4;

  int status = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(status, 1);
  double determinant = 0;
  status = s21_determinant(&matrix, &determinant);

  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_s21_determinant2) {
  matrix_t matrix;
  int rows = 4;
  int columns = 4;

  int status = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(status, 0);
  double *determinant = NULL;
  status = s21_determinant(&matrix, determinant);
  s21_remove_matrix(&matrix);

  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_s21_determinant3) {
  matrix_t matrix;
  int rows = 5;
  int columns = 4;

  int status = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(status, 0);
  double determinant = 0;
  status = s21_determinant(&matrix, &determinant);

  ck_assert_int_eq(status, 2);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_s21_determinant4) {
  matrix_t A;
  int rows = 3;
  int columns = 3;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 1;
    }
  }

  double determinant = 123;
  double determinant_res = 0;
  status = s21_determinant(&A, &determinant);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq_tol(determinant, determinant_res, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant5) {
  matrix_t A;
  int rows = 1;
  int columns = 1;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  A.matrix[0][0] = 5;

  double determinant = 123;
  double determinant_res = 5;
  status = s21_determinant(&A, &determinant);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq_tol(determinant, determinant_res, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant6) {
  matrix_t A;
  int rows = 2;
  int columns = 2;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 0.123456 * i + j;
    }
  }

  double determinant = 123;
  double determinant_res =
      A.matrix[0][0] * A.matrix[1][1] - A.matrix[0][1] * A.matrix[1][0];
  status = s21_determinant(&A, &determinant);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq_tol(determinant, determinant_res, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant7) {
  matrix_t A;
  int rows = 4;
  int columns = 4;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (i == j) {
        A.matrix[i][j] = 1;
      } else {
        A.matrix[i][j] = 0;
      }
    }
  }

  double determinant = 123;
  double determinant_res = 1;
  status = s21_determinant(&A, &determinant);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq_tol(determinant, determinant_res, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant8) {
  matrix_t A;
  int rows = 3;
  int columns = 3;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 3;
  A.matrix[2][0] = 4;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;

  double determinant = 123;
  double determinant_res = 0;
  status = s21_determinant(&A, &determinant);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq_tol(determinant, determinant_res, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant9) {
  matrix_t A;
  int rows = 3;
  int columns = 3;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  A.matrix[0][0] = 10;
  A.matrix[0][1] = 20;
  A.matrix[0][2] = 30;
  A.matrix[1][0] = 40;
  A.matrix[1][1] = 50;
  A.matrix[1][2] = 60;
  A.matrix[2][0] = 70;
  A.matrix[2][1] = 80;
  A.matrix[2][2] = 90;

  double determinant = 123;
  double determinant_res = -3.197442310920452e-12;
  status = s21_determinant(&A, &determinant);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq_tol(determinant, determinant_res, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant10) {
  matrix_t A;
  int rows = 5;
  int columns = 5;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  double values[5][5] = {{0, 2, 3, 12, 11},
                         {1, 0, 0, 10, 3},
                         {0, 1, 0, 12, 35},
                         {0, 0, 1, 15, 9},
                         {1, 2, 3, 4, 5}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = values[i][j];
    }
  }

  double determinant = 123;
  double determinant_res = 1034.9999999999989;
  status = s21_determinant(&A, &determinant);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq_tol(determinant, determinant_res, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant11) {
  matrix_t A;
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

  double determinant = 123;
  double determinant_res = -1;
  status = s21_determinant(&A, &determinant);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq_tol(determinant, determinant_res, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant12) {
  matrix_t A;
  int rows = 3;
  int columns = 3;

  int status = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status, 0);

  double values[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = values[i][j];
    }
  }

  double determinant = 123;
  double determinant_res = 0;
  status = s21_determinant(&A, &determinant);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq_tol(determinant, determinant_res, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant13) {
  matrix_t matrix1;
  double determinant = 0;
  int status, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  s21_remove_matrix(&matrix1);
  status = s21_determinant(&matrix1, &determinant);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_s21_determinant14) {
  matrix_t A;
  double determinant = 0;
  double det_true = 17187;
  double const A_nums[4] = {9, 2, 96, 1931};
  s21_create_matrix(2, 2, &A);
  int count = 0;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A_nums[count];
      count++;
    }
  }
  int res = s21_determinant(&A, &determinant);
  ck_assert_double_eq_tol(determinant, det_true, 1e+08);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_determinant_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("DETERMINANT");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_determinant1);
  tcase_add_test(tc_core, test_s21_determinant2);
  tcase_add_test(tc_core, test_s21_determinant3);
  tcase_add_test(tc_core, test_s21_determinant4);
  tcase_add_test(tc_core, test_s21_determinant5);
  tcase_add_test(tc_core, test_s21_determinant6);
  tcase_add_test(tc_core, test_s21_determinant7);
  tcase_add_test(tc_core, test_s21_determinant8);
  tcase_add_test(tc_core, test_s21_determinant9);
  tcase_add_test(tc_core, test_s21_determinant10);
  tcase_add_test(tc_core, test_s21_determinant11);
  tcase_add_test(tc_core, test_s21_determinant12);
  tcase_add_test(tc_core, test_s21_determinant13);
  tcase_add_test(tc_core, test_s21_determinant14);

  suite_add_tcase(s, tc_core);

  return s;
}
