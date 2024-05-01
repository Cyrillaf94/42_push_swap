#include "push_swap.h"

void test_find_index() {
    node_t *head = NULL;
	int test_values[] = {-2, 0, 6, 8, 12};
	int expected_index_2[] = {1, 1, 0, 0, 1};
	int expected_index_3[] = {1, 1, 0, 2, 1};

    // Test empty list
	printf("\nTest Empty List:\n");
    printf("Expected Index = 0, Actual Index = %d\n", find_index(head, test_values[0]));

	// Test list of one
	printf("\nTest List Len == 1:\n");
	insert_node_tail(&head, create_node(2));
	ft_list_print(head, 'T');
	for (int i = 0; i < 5; i++)
		printf("Test Value %d: Expected Index = 0, Actual Index = %d\n",
			test_values[i], find_index(head, test_values[i]));
	
	// Test list of two
	printf("\nTest List Len == 2:\n");
	insert_node_tail(&head, create_node(10));
	ft_list_print(head, 'T');
	for (int i = 0; i < 5; i++)
		printf("Test Value %d: Expected Index = %d, Actual Index = %d\n", test_values[i],
			expected_index_2[i], find_index(head, test_values[i]));

	// Test list of three
	printf("\nTest List Len == 3:\n");
	insert_node_tail(&head, create_node(8));
	ft_list_print(head, 'T');
	for (int i = 0; i < 5; i++)
		printf("Test Value %d: Expected Index = %d, Actual Index = %d\n", test_values[i],
			expected_index_3[i], find_index(head, test_values[i]));
	

	ft_lstclear(head);
	head = NULL;

	// TEST LARGE
	for (int i = 100; i > -100; i--)
		insert_node_tail(&head, create_node(i));

    // Test various scenarios
	printf("\nTest List Len == LARGE:\n");
    printf("Test Value 55: Expected Index = 45, Actual Index = %d\n", find_index(head, 55));
    printf("Test Value 25: Expected Index = 75, Actual Index = %d\n", find_index(head, 25));
    printf("Test Value 70: Expected Index = 30, Actual Index = %d\n", find_index(head, 70));

	// Shift list
	while (head->data > 0)
		head = head->next;

    // Test various scenarios
    printf("Test Value 55: Expected Index = 145, Actual Index = %d\n", find_index(head, 55));
    printf("Test Value 25: Expected Index = 175, Actual Index = %d\n", find_index(head, 25));
    printf("Test Value 70: Expected Index = 130, Actual Index = %d\n", find_index(head, 70));

	ft_lstclear(head);
}

int main()
{
	test_find_index();
	return 1;
}