#include "tests_suite.h"

int main(void) {
  run_tests();
  return 0;
}
void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;
  if (counter_testcase > 1)
    counter_testcase++;
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}

void run_tests(void) {
  Suite *list_cases[] = {suite_create_matrix(), suite_eq(), suite_sum(), suite_sub(), suite_mult_number(), 
                        suite_mult_matrix(), suite_transpose(), suite_determinant(), suite_calc(), suite_inverse (), NULL};

  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}