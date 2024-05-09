#include "ps_tests.h"

// Test case for create_node function
static void test_create_node(void)
{
	node_t *node = create_node(10);
	CU_ASSERT_PTR_NOT_NULL(node);
	CU_ASSERT_EQUAL(node->data, 10);
	CU_ASSERT_PTR_NULL(node->next);
	CU_ASSERT_PTR_NULL(node->prev);
	free(node);
}

// Test case for insert_node_tail function
static void test_insert_node_tail(void)
{
	node_t *head = NULL;
	node_t *node1 = create_node(10);
	node_t *node2 = create_node(20);
	insert_node_tail(&head, node1);
	CU_ASSERT_PTR_EQUAL(head, node1);
	CU_ASSERT_PTR_EQUAL(head->next, head);
	CU_ASSERT_PTR_EQUAL(head->prev, head);
	insert_node_tail(&head, node2);
	CU_ASSERT_PTR_EQUAL(head->next, node2);
	CU_ASSERT_PTR_EQUAL(head->prev, node2);
	CU_ASSERT_PTR_EQUAL(node1->prev, node2);
	CU_ASSERT_PTR_EQUAL(node2->next, head);
	ft_lstclear(&head);
}


// Test case for remove_node function
static void test_remove_node(void)
{
	node_t *head = NULL;
	node_t *node1 = create_node(10);
	insert_node_tail(&head, node1);
	CU_ASSERT_PTR_EQUAL(remove_node(&head), node1);
	CU_ASSERT_PTR_NULL(head);
	free(node1);
}

// Test case for ft_list_size function
static void test_ft_list_size(void)
{
	node_t *head = NULL;
	node_t *node1 = create_node(10);
	insert_node_tail(&head, node1);
	CU_ASSERT_EQUAL(ft_list_size(head), 1);
	free(node1);
}

// Test case for ft_lstclear function
static void test_ft_lstclear(void)
{
	node_t *head = NULL;
	node_t *node1 = create_node(10);
	insert_node_tail(&head, node1);
	ft_lstclear(&head);
	CU_ASSERT_PTR_NULL(head);
}

int add_lists_tests(void) 
{
	CU_pSuite pSuite = NULL;

	pSuite = CU_add_suite("Lists", init_suite, clean_suite);
	if (NULL == pSuite)
		return CU_get_error();

	CU_add_test(pSuite, "test of create_node()", test_create_node);
	CU_add_test(pSuite, "test of insert_node_tail()", test_insert_node_tail);
	CU_add_test(pSuite, "test of remove_node()", test_remove_node);
	CU_add_test(pSuite, "test of ft_list_size()", test_ft_list_size);
	CU_add_test(pSuite, "test of ft_lstclear()", test_ft_lstclear);

	return CU_get_error();
}
