#include "ps_tests.h"


static void test_is_sorted(void)
{
	node_t *head_sorted;
	node_t *head_unsorted;
	char *test_values_true[3][4] = {{"", "0", "1", "2"}, {"", "0", "0", "0"}, {"", "-10", "0", "2"}};
	char *test_values_false[3][4] = {{"", "0", "2", "1"}, {"", "0", "1", "0"}, {"", "2", "0", "-10"}};
	
	for (int i = 0; i < 3; i++)
	{
		head_sorted = parse_list(4, test_values_true[i]);	
		CU_ASSERT_EQUAL(is_sorted(head_sorted), true);
		head_unsorted = parse_list(4, test_values_false[i]);	
		CU_ASSERT_EQUAL(is_sorted(head_unsorted), false);
		ft_lstclear(&head_sorted);
		ft_lstclear(&head_unsorted);
	}
}

static void test_sort_three(void)
{
	node_t *head;
	char *test_values[8][4] = {{"", "0", "1", "2"}, {"", "0", "2", "1"}, {"", "1", "0", "2"},
							{"", "1", "2", "0"}, {"", "2", "1", "0"}, {"", "2", "0", "1"},
							{"", "0", "0", "1"}, {"", "1", "0", "0"}};
	for (int i = 0; i < 8; i++)
	{
		head = parse_list(4, test_values[i]);
		sort_three(&head);
		CU_ASSERT_EQUAL(is_sorted(head), true);
		ft_lstclear(&head);
	}
}

int add_sort_tests(void) 
{
	CU_pSuite pSuite = NULL;

	pSuite = CU_add_suite("Sorting", init_suite, clean_suite);
	if (NULL == pSuite)
		return CU_get_error();

	CU_add_test(pSuite, "is_sorted", test_is_sorted);
	CU_add_test(pSuite, "Sort THREE", test_sort_three);

	return CU_get_error();
}