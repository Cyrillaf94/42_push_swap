/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:41:44 by cyril             #+#    #+#             */
/*   Updated: 2024/05/11 08:26:21 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(node_t *head)
// For sa sb
{
	int	temp;
	
	temp = head->data;
	head->data = head->next->data;
	head->next->data = temp;	
}

void	ft_push(node_t **list_from, node_t **list_to)
// For pa pb
{
	node_t	*node;
	node_t	*temp;
	
	if (*list_from)
	{
		temp = (*list_from)->next;
		node = remove_node(list_from);
		if (temp != node)
			*list_from = temp;
		else
			*list_from = NULL;
		insert_node_tail(list_to, node);
		*list_to = (*list_to)->prev;
	}
}

node_t	*ft_rotate(node_t **head)
// For ra rb
{
	*head = (*head)->next;
	return (*head);
}

node_t	*ft_reverse_rotate(node_t **head)
// For rra rrb
{
	*head = (*head)->prev;
	return (*head);
}
