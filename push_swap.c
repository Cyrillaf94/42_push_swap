/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:41:44 by cyril             #+#    #+#             */
/*   Updated: 2024/03/23 11:25:47 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(node_t **head)
// For sa sb
{
	int	temp;
	
	temp = (*head)->prev->data;
	(*head)->prev->data = (*head)->prev->prev->data;
	(*head)->prev->prev->data = temp;	
}

void	ft_push(node_t **list_from, node_t **list_to)
// For pa pb
{
	node_t	*node;

	node = remove_node(list_from);
	insert_node_tail(list_to, node);
}

node_t	**ft_rotate(node_t **head)
// For ra rb
{
	return (&(*head)->next);
}

node_t	**ft_reverse_rotate(node_t **head)
// For rra rrb
{
	return (&(*head)->prev);
}
