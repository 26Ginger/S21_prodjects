#include "test_s21_matrix.h"

int main(void) {
  int number_failed = 0;
  Suite *s1, *s2, *s3, *s4, *s5, *s6, *s7, *s8, *s9, *s10, *s11;
  SRunner *sr;

  s1 = s21_create_matrix_suite();
  s2 = s21_remove_matrix_suite();
  s3 = s21_eq_matrix_suite();
  s4 = s21_sum_matrix_suite();
  s5 = s21_sub_matrix_suite();
  s6 = s21_mult_number_suite();
  s7 = s21_mult_matrix_suite();
  s8 = s21_transpose_suite();
  s9 = s21_calc_complements_suite();
  s10 = s21_determinant_suite();
  s11 = s21_inverse_matrix_suite();

  printf(
      "\033[38;5;82m\nWake up, Neo...\nThe Matrix has you...\nFollow the white "
      "rabbit...\n\n\033[0m");

  sr = srunner_create(s1);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  sr = srunner_create(s2);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  sr = srunner_create(s3);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  sr = srunner_create(s4);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  sr = srunner_create(s5);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  sr = srunner_create(s6);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  sr = srunner_create(s7);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  sr = srunner_create(s8);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  sr = srunner_create(s9);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  sr = srunner_create(s10);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  sr = srunner_create(s11);
  srunner_run_all(sr, CK_NORMAL);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}