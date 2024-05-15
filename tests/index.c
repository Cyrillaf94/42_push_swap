#include "ps_tests.h"

static void test_empty_list() 
{
	node_t *head = NULL;
	CU_ASSERT_EQUAL(find_index_dec(head, -2), 0);
}

static void test_list_length_one() 
{
	node_t *head = NULL;
	insert_node_tail(&head, create_node(2));
	int test_values[] = {-2, 0, 6, 8, 12};
	for (int i = 0; i < 5; i++) {
		CU_ASSERT_EQUAL(find_index_dec(head, test_values[i]), 0);
	}
	ft_lstclear(&head);
}

static void test_list_length_two() 
{
	node_t *head = NULL;
	insert_node_tail(&head, create_node(2));
	insert_node_tail(&head, create_node(10));
	int test_values[] = {-2, 0, 6, 8, 12};
	int expected_index_2[] = {1, 1, 0, 0, 1};
	for (int i = 0; i < 5; i++) {
		CU_ASSERT_EQUAL(find_index_dec(head, test_values[i]), expected_index_2[i]);
	}
	ft_lstclear(&head);
}

static void test_list_length_three() 
{
	node_t *head = NULL;
	insert_node_tail(&head, create_node(2));
	insert_node_tail(&head, create_node(10));
	insert_node_tail(&head, create_node(8));
	int test_values[] = {-2, 0, 6, 8, 12};
	int expected_index_3[] = {1, 1, 0, 0, 1};
	for (int i = 0; i < 5; i++) {
		CU_ASSERT_EQUAL(find_index_dec(head, test_values[i]), expected_index_3[i]);
	}
	ft_lstclear(&head);
}

static void test_list_length_four() 
{
	node_t *head = NULL;
	insert_node_tail(&head, create_node(2));
	insert_node_tail(&head, create_node(10));
	insert_node_tail(&head, create_node(8));
	insert_node_tail(&head, create_node(2));
	int test_values[] = {-2, 0, 2, 6, 12};
	int expected_index_3[] = {1, 1, 0, 3, 1};
	for (int i = 0; i < 5; i++) {
		CU_ASSERT_EQUAL(find_index_dec(head, test_values[i]), expected_index_3[i]);
	}
	ft_lstclear(&head);
}

static void tests_list_large()
{
	node_t *head;
	head = NULL;

	// TEST LARGE
	for (int i = 100; i > -100; i--)
		insert_node_tail(&head, create_node(i));
	int test_values_bis[] = {55, 25, 70};
	int expected_index_large_bis[] =  {45, 75, 30};
	for (int i = 0; i < 3; i++)
	{
		CU_ASSERT_EQUAL(find_index_dec(head, test_values_bis[i]), expected_index_large_bis[i]);
	}

	// Shift list to test if head is not at max value
	while (head->data > 0)
		head = head->next;
	int test_values[] = {55, 25, 70};
	int expected_index_large[] =  {145, 175, 130};
	for (int i = 0; i < 3; i++)
	{
		CU_ASSERT_EQUAL(find_index_dec(head, test_values[i]), expected_index_large[i]);
	}
	ft_lstclear(&head);
}

int add_index_tests(void) {
    CU_pSuite pSuite = CU_add_suite("Index Test Suite", init_suite, clean_suite);
    if (NULL == pSuite) {
        return CU_get_error();
    }
    
    CU_add_test(pSuite, "Empty List Test", test_empty_list);
    CU_add_test(pSuite, "List Length 1 Test", test_list_length_one);
    CU_add_test(pSuite, "List Length 2 Test", test_list_length_two);
    CU_add_test(pSuite, "List Length 3 Test", test_list_length_three);
	CU_add_test(pSuite, "List Length 4 Test", test_list_length_four);
	CU_add_test(pSuite, "List Large", tests_list_large);

    return CU_get_error();
}
