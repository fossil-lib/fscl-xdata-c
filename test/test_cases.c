/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/package.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// TEST DATA
//
XTEST_DATA(ProjectTestData) {
    char *one;
    char *two;
}project_data;

//
// XUNIT FIXTURE
//
XTEST_FIXTURE(project_tests);
XTEST_SETUP(project_tests) {
    project_data.one = "Something";
    project_data.two = "Coffe Cup";
} // end of func

XTEST_TEARDOWN(project_tests) {
    // empty
} // end of func

//
// XUNIT TEST CASES
//
XTEST_CASE_FIXTURE(project_tests, basic_run_of_string) {
    XASSERT_STRING_EQUAL(project_data.one, project_data.one);
    XASSERT_STRING_NOT_EQUAL(project_data.one, project_data.two);
} // end case

XTEST_CASE_FIXTURE(project_tests, basic_run_of_pointer) {
    XASSERT_PTR_NOT_NULL("Coffee Cup");
    XASSERT_PTR_NULL(NULL);
} // end case

XTEST_CASE_FIXTURE(project_tests, basic_run_of_boolean) {
    XASSERT_BOOL_TRUE(true);
    XASSERT_BOOL_FALSE(false);
    XASSERT_BOOL_UNLESS(true);
} // end case

//
// XUNIT-TEST RUNNER
//
int main(int argc, char **argv) {
    XUnitRunner runner = XTEST_RUNNER_START(argc, argv);

    XTEST_RUN_FIXTURE(basic_run_of_string,  project_tests, runner);
    XTEST_RUN_FIXTURE(basic_run_of_pointer, project_tests, runner);
    XTEST_RUN_FIXTURE(basic_run_of_boolean, project_tests, runner);

    return XTEST_RUNNER_END(runner);
} // end of function main
