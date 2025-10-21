#include "test_s21_matrix.h"

START_TEST(test_create_matrix_valid1) {
  matrix_t matrix;
  int status = s21_create_matrix(1, 1, &matrix);
  ck_assert_int_eq(status, 0);
  ck_assert_ptr_nonnull(matrix.matrix); /* pointer not null */
  ck_assert_int_eq(matrix.rows, 1);
  ck_assert_int_eq(matrix.columns, 1);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_create_matrix_valid2) {
  matrix_t matrix;
  int status = s21_create_matrix(3, 3, &matrix);
  ck_assert_int_eq(status, 0);
  ck_assert_ptr_nonnull(matrix.matrix);
  ck_assert_int_eq(matrix.rows, 3);
  ck_assert_int_eq(matrix.columns, 3);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_create_matrix_valid3) {
  matrix_t matrix;
  int status = s21_create_matrix(1, 5, &matrix);
  ck_assert_int_eq(status, 0);
  ck_assert_ptr_nonnull(matrix.matrix);
  ck_assert_int_eq(matrix.rows, 1);
  ck_assert_int_eq(matrix.columns, 5);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_create_matrix_valid4) {
  matrix_t matrix;
  int status = s21_create_matrix(5, 1, &matrix);
  ck_assert_int_eq(status, 0);
  ck_assert_ptr_nonnull(matrix.matrix);
  ck_assert_int_eq(matrix.rows, 5);
  ck_assert_int_eq(matrix.columns, 1);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_create_matrix_valid5) {
  matrix_t matrix;
  int rows = 1000;
  int columns = 1000;
  int status = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(status, 0);
  ck_assert_ptr_nonnull(matrix.matrix);
  ck_assert_int_eq(matrix.rows, rows);
  ck_assert_int_eq(matrix.columns, columns);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_create_matrix_valid6) {
  matrix_t matrix;
  int rows = 5;
  int columns = 8;
  int status = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(status, 0);
  ck_assert_ptr_nonnull(matrix.matrix);
  ck_assert_int_eq(matrix.rows, rows);
  ck_assert_int_eq(matrix.columns, columns);

  rows = 10;
  columns = 20;
  status = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(status, 0);
  ck_assert_ptr_nonnull(matrix.matrix);
  ck_assert_int_eq(matrix.rows, rows);
  ck_assert_int_eq(matrix.columns, columns);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_create_matrix_invalid1) {
  matrix_t matrix;
  matrix.matrix = NULL;
  int status = s21_create_matrix(-1, 3, &matrix);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_create_matrix_invalid2) {
  matrix_t matrix;
  matrix.matrix = NULL;
  int status = s21_create_matrix(3, 0, &matrix);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_create_matrix_invalid3) {
  int status = s21_create_matrix(3, 8, NULL);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_create_matrix_invalid4) {
  matrix_t matrix;
  int rows = INT_MAX;
  int columns = INT_MAX;
  matrix.matrix = NULL;
  int status = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(status, 1);
  ck_assert_int_eq(matrix.rows, 0);
  ck_assert_int_eq(matrix.columns, 0);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_create_matrix_invalid5) {
  matrix_t matrix;
  int rows = 100000;
  int columns = 500000;

  int status = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(status, 1);
  ck_assert_int_eq(matrix.rows, 0);
  ck_assert_int_eq(matrix.columns, 0);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_create_matrix_invalid6) {
  matrix_t matrix = {0};
  int rows = 5;
  int columns = 0;
  matrix.columns = columns;
  matrix.rows = rows;
  int status = s21_is_invalid_matrix(&matrix);
  ck_assert_int_eq(status, 1);
}
END_TEST

Suite *s21_create_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("CREATE");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_create_matrix_valid1);
  tcase_add_test(tc_core, test_create_matrix_valid2);
  tcase_add_test(tc_core, test_create_matrix_valid3);
  tcase_add_test(tc_core, test_create_matrix_valid4);
  tcase_add_test(tc_core, test_create_matrix_valid5);
  tcase_add_test(tc_core, test_create_matrix_valid6);

  /* ------ */
  tcase_add_test(tc_core, test_create_matrix_invalid1);
  tcase_add_test(tc_core, test_create_matrix_invalid2);
  tcase_add_test(tc_core, test_create_matrix_invalid3);
  tcase_add_test(tc_core, test_create_matrix_invalid4);
  tcase_add_test(tc_core, test_create_matrix_invalid5);
  tcase_add_test(tc_core, test_create_matrix_invalid6);
  suite_add_tcase(s, tc_core);

  return s;
}
