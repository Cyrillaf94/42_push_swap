/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:18:46 by cyril             #+#    #+#             */
/*   Updated: 2024/07/06 19:55:35 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_sorted(t_node *head)
{
	t_node	*current;
	int		i;

	i = 0;
	current = head;
	while (current && current->next != head)
	{
		if (current->data > current->next->data)
			return (false);
		current = current->next;
		i++;
	}
	return (true);
}

/* 
	Find the corrrect position in an ordered circular list (decreasing order)
	(N.B. Head is not necessarily at min value)
	Return the index of the item the value should follow
*/
int	find_index_dec(t_node *head, int value)
{
	t_node	*node;
	int		index;

	if (!head)
		return (0);
	index = 0;
	node = head;
	while (true)
	{
		if (value > node->next->data && value < node->data)
			return (index);
		if (node->next->data > node->data
			&& (value < node->data || value > node->next->data))
			return (index);
		if (node->next == head)
			return (index);
		node = node->next;
		index++;
	}
	return (index);
}

/* 
	Find the corrrect position in an ordered circular list (decreasing order)
	(N.B. Head is not necessarily at min value)
	Return the index of the item the value should precede
	(e.g. at the start of the list returns 0)
*/
int	find_index_inc(t_node *head, int value)
{
	t_node	*node;
	int		index;

	if (!head)
		return (0);
	index = 0;
	node = head;
	while (true)
	{
		if (node->data < value && value < node->next->data)
			return (index);
		if (node->next->data < node->data
			&& (value > node->data || value < node->next->data))
			return (index);
		if (node->next == head)
			return (index);
		node = node->next;
		index++;
	}
	return (index);
}

void	rr_list(t_move moves, t_node **list_from, t_node **list_to, char c)
{
	while (moves.rra && moves.rrb)
	{
		ft_instruct(list_from, list_to, &ft_reverse_rotate);
		moves.ra--;
		moves.rb--;
	}
	while (moves.rra && c == 'a' && moves.rra--)
		ft_instruct(list_from, NULL, &ft_reverse_rotate);
	while (moves.rrb && c == 'a' && moves.rrb--)
		ft_instruct(list_to, NULL, &ft_reverse_rotate);
	while (moves.rra && c == 'b' && moves.rra--)
		ft_instruct(NULL, list_from, &ft_reverse_rotate);
	while (moves.rrb && c == 'b' && moves.rrb--)
		ft_instruct(NULL, list_to, &ft_reverse_rotate);
}

void	r_list(t_move moves, t_node **list_from, t_node **list_to, char c)
{
	while (moves.ra && moves.rb)
	{
		ft_instruct(list_from, list_to, &ft_rotate);
		moves.ra--;
		moves.rb--;
	}
	while (moves.ra && c == 'a' && moves.ra--)
		ft_instruct(list_from, NULL, &ft_rotate);
	while (moves.rb && c == 'a' && moves.rb--)
		ft_instruct(list_to, NULL, &ft_rotate);
	while (moves.ra && c == 'b' && moves.ra--)
		ft_instruct(NULL, list_from, &ft_rotate);
	while (moves.rb && c == 'b' && moves.rb--)
		ft_instruct(NULL, list_to, &ft_rotate);
}
