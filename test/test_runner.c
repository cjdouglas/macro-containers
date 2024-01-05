#include "unity_fixture.h"

static void run_all_tests() { RUN_TEST_GROUP(FWD_LIST_TEST_GROUP); }

int main(int argc, const char* argv[]) {
  return UnityMain(argc, argv, run_all_tests);
}
