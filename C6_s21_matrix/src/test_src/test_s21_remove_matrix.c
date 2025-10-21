#include "test_s21_matrix.h"

START_TEST(test_remove_matrix1) {
  matrix_t matrix;
  s21_create_matrix(3, 3, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_int_eq(matrix.rows, 0);
  ck_assert_int_eq(matrix.columns, 0);
  ck_assert_ptr_eq(matrix.matrix, NULL);
}
END_TEST

START_TEST(test_remove_matrix2) {
  matrix_t matrix;
  s21_create_matrix(3, 3, &matrix);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&matrix);  // one more time
  ck_assert_int_eq(matrix.rows, 0);
  ck_assert_int_eq(matrix.columns, 0);
  ck_assert_ptr_eq(matrix.matrix, NULL);
}
END_TEST

START_TEST(test_remove_matrix3) {
  matrix_t matrix;
  matrix.rows = 0;
  matrix.columns = 0;
  matrix.matrix = NULL;

  s21_remove_matrix(&matrix);
  ck_assert_int_eq(matrix.rows, 0);
  ck_assert_int_eq(matrix.columns, 0);
  ck_assert_ptr_eq(matrix.matrix, NULL);
}
END_TEST

START_TEST(test_remove_matrix4) {
  s21_remove_matrix(NULL);
}  // не крашится (так и должно быть)
END_TEST

Suite *s21_remove_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("REMOVE");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_remove_matrix1);
  tcase_add_test(tc_core, test_remove_matrix2);
  tcase_add_test(tc_core, test_remove_matrix3);
  tcase_add_test(tc_core, test_remove_matrix4);
  suite_add_tcase(s, tc_core);

  return s;
}
