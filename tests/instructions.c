/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 07:33:18 by cyril             #+#    #+#             */
/*   Updated: 2024/05/11 08:47:40 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ps_tests.h"

static void test_ft_swap(void)
{
	node_t *head = NULL;
    insert_node_tail(&head, create_node(10)); // List: 10 <-> 20
	insert_node_tail(&head, create_node(20));
	insert_node_tail(&head, create_node(30));
    ft_swap(head);  // Should swap 10 and 20
    CU_ASSERT_EQUAL(head->data, 20);
    CU_ASSERT_EQUAL(head->next->data, 10);
	CU_ASSERT_EQUAL(ft_list_size(head), 3);

    ft_lstclear(&head);
}

static void test_ft_push(void)
{
    node_t *list_from = NULL;
    node_t *list_to = NULL;
    insert_node_tail(&list_from, create_node(10));
    insert_node_tail(&list_to, create_node(20)); // list_from: 10 <-> 20

    ft_push(&list_from, &list_to);  // Move '20' to list_to
	CU_ASSERT_PTR_EQUAL(list_from, NULL);
    CU_ASSERT_EQUAL(ft_list_size(list_from), 0);
    CU_ASSERT_EQUAL(ft_list_size(list_to), 2);
    CU_ASSERT_EQUAL(list_to->data, 10);

	insert_node_tail(&list_from, create_node(1));
	insert_node_tail(&list_from, create_node(2));
	insert_node_tail(&list_from, create_node(3));
	insert_node_tail(&list_from, create_node(4));
	
	CU_ASSERT_EQUAL(ft_list_size(list_from), 4);
	ft_push(&list_from, &list_to);
	CU_ASSERT_EQUAL(ft_list_size(list_from), 3);
	CU_ASSERT_EQUAL(list_from->data, 2);
	CU_ASSERT_EQUAL(list_to->data, 1);
	
	

    ft_lstclear(&list_from);
    ft_lstclear(&list_to);
}

static void test_ft_rotate(void)
{
    node_t *head = NULL;
    insert_node_tail(&head, create_node(10));
    insert_node_tail(&head, create_node(20));
	insert_node_tail(&head, create_node(30)); // List: 10 <-> 20

    node_t *new_head = ft_rotate(&head);
	CU_ASSERT_PTR_EQUAL(new_head, head);
    CU_ASSERT_EQUAL(head->data, 20);
    CU_ASSERT_EQUAL(head->prev->data, 10);
    ft_lstclear(&head);
}

static void test_ft_reverse_rotate(void)
{
    node_t *head = NULL;
    insert_node_tail(&head, create_node(10));
    insert_node_tail(&head, create_node(20));
	insert_node_tail(&head, create_node(30));

    node_t *new_head = ft_reverse_rotate(&head);
    CU_ASSERT_PTR_EQUAL(new_head, head);
    CU_ASSERT_EQUAL(head->data, 30);
    CU_ASSERT_EQUAL(head->next->data, 10);

    ft_lstclear(&head);
}

int add_instructions_tests(void)
{
    CU_pSuite pSuite = CU_add_suite("List Operations", init_suite, clean_suite);
    if (NULL == pSuite) return CU_get_error();

    CU_add_test(pSuite, "test of ft_swap()", test_ft_swap);
    CU_add_test(pSuite, "test of ft_push()", test_ft_push);
    CU_add_test(pSuite, "test of ft_rotate()", test_ft_rotate);
    CU_add_test(pSuite, "test of ft_reverse_rotate()", test_ft_reverse_rotate);

    return CU_get_error();
}
