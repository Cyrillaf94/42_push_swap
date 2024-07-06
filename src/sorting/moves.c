/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:18:46 by cyril             #+#    #+#             */
/*   Updated: 2024/07/06 20:37:40 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_move	init_moves(int mov_ra, int mov_rb, int mov_rra, int mov_rrb)
{
	t_move	move;

	move.ra = mov_ra;
	move.rb = mov_rb;
	move.rra = mov_rra;
	move.rrb = mov_rrb;
	return (move);
}

static int	count_moves(t_move moves)
{
	return (ft_max(moves.ra, moves.rb) + ft_max(moves.rra, moves.rrb));
}

/*
	Get number of moves to push - REMINDER: you need to be at max index (size - 1)
	There are two ways to get the element at the end: forward or backwards - i.e.
*/
static t_move	get_moves(int index_a, int index_b, int size_a, int size_b)
{
	t_move	moves[4];
	int		i;
	int		min_i;
	int		min_moves;
	int		count_mov;

	i = 0;
	min_moves = INT_MAX;
	min_i = -1;
	moves[0] = init_moves(index_a + 1, index_b + 1, 0, 0);
	moves[1] = init_moves(0, 0, (size_a - index_a - 1), (size_b - index_b - 1));
	moves[2] = init_moves(index_a + 1, 0, 0, (size_b - index_b - 1));
	moves[3] = init_moves(0, index_b + 1, (size_a - index_a - 1), 0);
	while (i <= 3)
	{
		count_mov = count_moves(moves[i]);
		if (count_mov < min_moves)
		{
			min_moves = count_mov;
			min_i = i;
		}
		i++;
	}
	return (moves[min_i]);
}

/*
	Return the least moves to pop one element of a to b
	REMINDER: you can only pop the the END of the list (last index)
*/
t_move	iter_list(t_node *head_a, t_node *head_b,
					int (*find_index)(t_node *, int))
{
	int		index[2];
	int		list_sizes[2];
	t_move	moves;
	t_move	min_move;
	t_node	*current;

	index[0] = 0;
	list_sizes[0] = ft_list_size(head_a);
	list_sizes[1] = ft_list_size(head_b);
	current = head_a;
	if (!current)
		return (init_moves(0, 0, 0, 0));
	min_move = init_moves(INT_MAX, 0, 0, 0);
	while (index[0] == 0 || current != head_a)
	{
		index[1] = find_index(head_b, current->data);
		moves = get_moves(index[0], index[1], list_sizes[0], list_sizes[1]);
		if (count_moves(moves) < count_moves(min_move))
			min_move = moves;
		index[0]++;
		current = current->next;
	}
	return (min_move);
}
