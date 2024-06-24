/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:41:44 by cyril             #+#    #+#             */
/*   Updated: 2024/06/24 21:03:11 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// Push the last_element of list_from to be the last element of list_to
void	ft_push(node_t **list_from, node_t **list_to, char c)
{
	node_t	*node;
	char	str[3];
	
	if (*list_from)
	{
		node = remove_node(&(*list_from)->prev);
		if (node == *list_from)
			*list_from = NULL;
		insert_node_tail(list_to, node);
	}
	str[0] = 'p';
	str[2] = c;
	str[3] = '\n';
	write(1, str, 2);
}


// Swap the top two elements of a list
node_t	*ft_swap(node_t **head)
{
	int	temp;
	
	if (!head || !*head)
		return (NULL);
	temp = (*head)->prev->data;
	(*head)->prev->data = (*head)->prev->prev->data;
	(*head)->prev->data = temp;
	return (*head);	
}

node_t	*ft_rotate(node_t **head)
// For ra rb
{
	if (!head || !*head)
		return (NULL);
	*head = (*head)->next;
	return (*head);
}

node_t	*ft_reverse_rotate(node_t **head)
// For rra rrb
{
	if (!head || !*head)
		return (NULL);
	*head = (*head)->prev;
	return (*head);
}

// In case an instruction can be applied to both lists at the same time
void ft_dispatch_instruct(node_t **head_a, node_t **head_b, node_t * (instruction)(node_t **))
{
	if ((!head_a && !head_b) || !instruction)
		return ;
	if (head_a)
		instruction(head_a);
	if (head_b)
		instruction(head_b);
	if (instruction == &ft_swap)
		write(1, "s", 1);
	else if (instruction == &ft_rotate)
		write(1, "r", 1);
	else if (instruction == &ft_reverse_rotate)
		write(1, "rr", 2);
	if (!head_b)
		write(1, "a", 1);
	else if (!head_a)
		write(1, "b", 1);
	else if (instruction == &ft_swap)
		write(1, "s", 1);
	else
		write(1, "r", 1);
	write(1, "\n", 1);
}
