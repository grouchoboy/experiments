#include <stdlib.h>
#include <check.h>
#include "mergesort.h"

START_TEST(use_mergesort)
{
	array input = {
		.data = (int[]){ 5, 3, 2 },
		.size = 3,
	};
	merge_sort(&input);
	int expected[] = { 2, 3, 5 };

	for (size_t i = 0; i < input.size; ++i) {
		ck_assert_int_eq(expected[i], input.data[i]);
	}

	array input2 = {
		.data = (int[]){ 10, 4, 1, 2, 5, 3 },
		.size = 6,
	};
	merge_sort(&input2);
	int expected2[] = { 1, 2, 3, 4, 5, 10 };
	for (size_t i = 0; i < input2.size; ++i) {
		ck_assert_int_eq(expected2[i], input2.data[i]);
	}
}
END_TEST

Suite *mergesort_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Mergesort");
	tc_core = tcase_create("Core");
	tcase_add_test(tc_core, use_mergesort);
	suite_add_tcase(s, tc_core);

	return s;
}

int main(void)
{
	int number_failed;
	Suite *s;
	SRunner *sr;
	s = mergesort_suite();
	sr = srunner_create(s);
	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
