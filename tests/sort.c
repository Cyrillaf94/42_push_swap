#include "ps_tests.h"

static void test_sort_three(void)
{
	node_t *head;
	char *test_values[6][4] = {{"", "0", "1", "2"}, {"", "0", "2", "1"}, {"", "1", "0", "2"},
							{"", "1", "2", "0"}, {"", "2", "1", "0"}, {"", "2", "0", "1"}};
	for (int i = 0; i < 2; i++)
	{
		head = parse_list(4, test_values[i]);
		sort_three(head);
		ft_list_print(head, 't');
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

	CU_add_test(pSuite, "Sort THREE", test_sort_three);

	return CU_get_error();
}