/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:41:44 by cyril             #+#    #+#             */
/*   Updated: 2024/07/06 19:36:41 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Push the last_element of list_from to be the last element of list_to
void	ft_push(t_node **list_from, t_node **list_to, char c)
{
	t_node	*node;
	char	str[3];

	if (*list_from)
	{
		node = remove_node(&(*list_from)->prev);
		if (node == *list_from)
			*list_from = NULL;
		insert_node_tail(list_to, node);
	}
	str[0] = 'p';
	str[1] = c;
	str[2] = '\n';
	write(1, str, 3);
}

// Swap the top two elements of a list
t_node	*ft_swap(t_node **head)
{
	int	temp;

	if (!head || !*head)
		return (NULL);
	temp = (*head)->prev->data;
	(*head)->prev->data = (*head)->prev->prev->data;
	(*head)->prev->data = temp;
	return (*head);
}

t_node	*ft_rotate(t_node **head)
// For ra rb
{
	if (!head || !*head)
		return (NULL);
	*head = (*head)->next;
	return (*head);
}

t_node	*ft_reverse_rotate(t_node **head)
// For rra rrb
{
	if (!head || !*head)
		return (NULL);
	*head = (*head)->prev;
	return (*head);
}

// In case an instruction can be applied to both lists at the same time
void	ft_instruct(t_node **head_a, t_node **head_b,
							t_node *(instruction)(t_node**))
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
