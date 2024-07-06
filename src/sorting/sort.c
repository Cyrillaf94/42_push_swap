/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:18:46 by cyril             #+#    #+#             */
/*   Updated: 2024/07/06 20:48:49 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_node **head)
{
	int	index;

	if (head && !is_sorted(*head))
	{
		index = find_max(*head);
		if (index == 0)
			ft_rotate(head);
		else if (index == 1)
			ft_reverse_rotate(head);
		if ((*head)->data > (*head)->next->data)
			ft_swap(head);
	}
}

static void	move_one_elem(t_node **head_from, t_node **head_to,
							int (*find_index)(t_node *, int))
{
	t_move	moves;
	char	c;

	if (find_index == &find_index_dec)
		c = 'a';
	else
		c = 'b';
	moves = iter_list(*head_from, *head_to, find_index);
	r_list(moves, head_from, head_to, c);
	rr_list(moves, head_from, head_to, c);
	ft_push(head_from, head_to, c);
}

/*
	Shift ordered circular doubly linked list 
	so that the min value is at index 0
*/
static void	shift_final_list(t_node **head, int list_len)
{
	int	index_min;

	index_min = find_min(*head);
	if (list_len / 2 < index_min)
	{
		while (index_min < list_len)
		{
			ft_reverse_rotate(head);
			write(1, "rra\n", 4);
			index_min++;
		}
	}
	else
	{
		while (index_min > 0)
		{
			ft_rotate(head);
			write(1, "ra\n", 3);
			index_min--;
		}
	}
}

void	sort_list(t_node *head_a, int len_a)
{
	int		len_b;
	t_node	*head_b;

	head_b = NULL;
	len_b = 0;
	while (!is_sorted(head_a) && len_a > 3)
	{
		if (len_b < 2)
			ft_push(&head_a, &head_b, 'a');
		else
			move_one_elem(&head_a, &head_b, &find_index_dec);
		len_a--;
		len_b++;
	}
	if (len_a <= 3)
		sort_three(&head_a);
	while (len_b)
	{
		move_one_elem(&head_b, &head_a, &find_index_inc);
		len_a++;
		len_b--;
	}
	shift_final_list(&head_a, len_a);
}
