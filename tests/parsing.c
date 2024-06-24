#include "ps_tests.h"


// Test case for parse_list function
static void test_parse_list(void)
{
	char *argv1[] = {"", "10", "20", "30"};
	node_t *head1 = parse_list(4, argv1);
	CU_ASSERT_PTR_NOT_NULL(head1);
	CU_ASSERT_EQUAL(ft_list_size(head1), 3);
	ft_lstclear_circular(&head1);

	char *argv2[] = {"", "10", "20", "20"};
	node_t *head2 = parse_list(4, argv2);
	CU_ASSERT_PTR_NULL(head2);

	char *argv3[] = {"", "10", "12", ""};
	node_t *head3 = parse_list(4, argv3);
	CU_ASSERT_PTR_NULL(head3);

	char *argv4[] = {"", "10", "abc", "30"};
	node_t *head4 = parse_list(4, argv4);
	CU_ASSERT_PTR_NULL(head4);

	char *argv5[] = {"", "2147483647", "-2147483648", "0"};
	node_t *head5 = parse_list(4, argv5);
	CU_ASSERT_PTR_NOT_NULL(head5);
	CU_ASSERT_EQUAL(ft_list_size(head5), 3);
	ft_lstclear_circular(&head5);
}

int add_parsing_tests(void) 
{
	CU_pSuite pSuite = NULL;

	pSuite = CU_add_suite("Parsing", init_suite, clean_suite);
	if (NULL == pSuite)
		return CU_get_error();

	CU_add_test(pSuite, "test of parse_list()", test_parse_list);

	return CU_get_error();
}
