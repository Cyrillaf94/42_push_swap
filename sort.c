/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:18:46 by cyril             #+#    #+#             */
/*   Updated: 2024/04/28 21:38:01 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_break()
{
	printf("BREAK\n");
}


bool	is_sorted(node_t *head)
{
	node_t	*current;
	int		i;
	
	i = 0;
	current = head;
	while(current && current->next != head)
	{
		if (current->data > current->next->data)
			return (false);
		current = current->next;
		i++;
	}
	return (true);
}

node_t	*sort_three(node_t *head)
{
	int	index;

	if (!is_sorted(head))
	{
		index = find_min(head);
		if (index == 2)
			head = ft_reverse_rotate(&head);
		else if (index == 1)
			head = ft_rotate(&head);
		index = find_min(head);
		index = find_antepenultimate_min(head, index);
		if (index == 2)
			ft_swap(head);
	}
	return (head);
}

// Algo: think of two rolls, for each element in list a, calculate the number of moves required to (1) shift list b so that it would be ordered once popped and (2) shuft list a so that the element is poppable
// Bonus: you can shift two moves into one if both rolls shift the same way
// --> The index is enough
// Distance to index 0 is min(index, len(list) - index + 1)

int	find_index(node_t *head, int value)
// Find the corrrect position in an ordered circular list (decreasing order)
// (N.B. Head is not necessarily at min value)
// Return the index of the item you will precede (e.g. at the start of the list returns 0)
{
	node_t	*current;
	node_t	*temp;
	int	index;
	int max_index;


	// Protection for empty list
	if (!head || head->next == head)
		return (0);
	index = 0;
	current = head;
	// move cursor to max
	max_index = find_max(head);
	while (max_index--)
	{
		current = current->next;
		index++;
	}
	// If multiple items with same value, go to the earliest
	while (current->data == current->prev->data && index--)
		current = current->prev;
	// Once you are at the 'top' value of the list, if you are outside the bounds of the list,
	// you are in the right place 
	// Otherwise, loop through the list to find the best position
	if (!(current->data <= value || current->prev->data >= value))
	{
		while(!(value >= current->data))
		{
			index++;
			current = current->next;
		}
	}
	index = index % ft_list_size(current);
	return (index);
}

// Both list can shift in the same direction at the same time to avoid costing an extra move
// Returns a negative number if the rotation is in reverse
int	get_number_of_moves(int index_a, int index_b, int size_a, int size_b)
{
	int direction_1;
	int	direction_2;

	direction_1 = ft_max(index_a, index_b);
	direction_2 = ft_min(size_a - index_a, size_b - index_b);
	if (direction_1 < -direction_2)
		return (direction_1);
	return (direction_2);
}

move_t init_moves(int mov_ra, int mov_rb, int mov_rra, int mov_rrb)
{
	move_t move; 
	
	move.ra = mov_ra;
    move.rb = mov_rb;
	move.rra = mov_rra;
	move.rrb = mov_rrb;
	
	return (move);
}

int count_moves(move_t moves)
{
	return(ft_max(moves.ra, moves.rb) + ft_max(moves.rra, moves.rrb));
}

move_t get_moves(int index_a, int index_b, int size_a, int size_b)
{
	move_t moves[4];
	int i;
	int min_i;
	int min_moves;
	int count_mov;

	i = 4;
	min_moves = INT_MAX;
	min_i = -1;
	moves[0] = init_moves(0, 0, index_a, index_b);
	moves[1] = init_moves(size_a - index_a, size_b - index_b - 1, 0 , 0);
	moves[2] = init_moves(0, size_b - index_b, index_a, 0);
	moves[3] = init_moves(size_a - index_a  - 1, 0, 0, index_b);
	while (i--)
	{
		count_mov = count_moves(moves[i]);
		if (count_mov < min_moves)
		{
			min_moves = count_mov;
			min_i = i;
		}
	}
	return (moves[min_i]);
}

// Return the least moves to pop one element of a to b
// REMINDER: you can only pop the the tail of the list
move_t	iterate_a(node_t *head_a, int size_a, node_t *head_b, int size_b)
{
	int index_a;
	int index_b;
	int index_min;
	move_t moves;
	move_t min_moves;
	node_t *current;
	
	index_a = 0;
	index_min = 0;
	current = head_a;
	if (!current)
		return (init_moves(0, 0, 0, 0));
	while (index_a == 0 || current != head_a)
	{
		index_b = find_index(head_b, current->data);
		moves = get_moves(index_a, index_b, size_a, size_b);
		if (index_a > 0  && count_moves(moves) < count_moves(min_moves))
			min_moves = moves;
		index_a++;
		current = current->next;
	}
	return (moves);
}

node_t	*shift_list(move_t moves, node_t **head_a, node_t **head_b)
{
	while (moves.ra && moves.rb)
	{
		ft_rotate(head_a);
		ft_rotate(head_b);
		moves.ra--;
		moves.rb--;
		printf("rr\n");
	}
	while (moves.ra-- && printf("ra\n"))
		ft_rotate(head_a);
	while (moves.rb-- && printf("rb\n"))
		ft_rotate(head_b);	
	while (moves.rra && moves.rrb)
	{
		ft_reverse_rotate(head_a);
		ft_reverse_rotate(head_b);
		moves.rra--;
		moves.rrb--;
		printf("rrr\n");
	}
	while (moves.rra-- && printf("rra\n"))
		ft_reverse_rotate(head_a);
	while (moves.rrb-- && printf("rrb\n"))
		ft_reverse_rotate(head_b);
}

void	sort_list(node_t *head)
{
	int len_a;
	int index_a;
	int	len_b;
	int index_b;
	node_t *head_b;
	move_t moves;
	
	len_a = ft_list_size(head);
	len_b = 0;
	head_b = NULL;
	while (!is_sorted(head) && len_a > 3)
	{
		if (len_b < 2)
			ft_push(&head, &head_b);
		else
		{
			moves = iterate_a(head->prev, len_a, head_b->prev, len_b);
			shift_list(moves, &head, &head_b);
			ft_push(&head, &head_b);
		}
		ft_list_print(head, 'a');
		ft_list_print(head_b, 'b');
		len_a--;
		len_b++;
	}
}













