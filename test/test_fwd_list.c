#include "macro_containers/fwd_list.h"
#include "test_utils.h"
#include "unity.h"
#include "unity_fixture.h"

INCLUDE_FWD_LIST(int)
INCLUDE_FWD_LIST(simple)
INCLUDE_FWD_LIST(complex)

// Define test group and setup / teardown

TEST_GROUP(FWD_LIST_TEST_GROUP);

TEST_SETUP(FWD_LIST_TEST_GROUP) {}

TEST_TEAR_DOWN(FWD_LIST_TEST_GROUP) {}

// Start tests here

TEST(FWD_LIST_TEST_GROUP, TEST_FWD_LIST_INIT) {
  struct fwd_list_int list_int;
  fwd_list_int_init(&list_int, compare_int);
  TEST_ASSERT_EQUAL(list_int.size, 0);
  fwd_list_int_free(&list_int);

  struct fwd_list_simple list_simple;
  fwd_list_simple_init(&list_simple, compare_simple);
  TEST_ASSERT_EQUAL(list_simple.size, 0);
  fwd_list_simple_free(&list_simple);

  struct fwd_list_complex list_complex;
  fwd_list_complex_init(&list_complex, compare_complex);
  TEST_ASSERT_EQUAL(list_complex.size, 0);
  fwd_list_complex_free(&list_complex);
}

// Register runner here

TEST_GROUP_RUNNER(FWD_LIST_TEST_GROUP) {
  RUN_TEST_CASE(FWD_LIST_TEST_GROUP, TEST_FWD_LIST_INIT);
}
