/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:18:46 by cyril             #+#    #+#             */
/*   Updated: 2024/05/11 11:57:30 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_three(node_t **head)
{
	int	index;

	if (!is_sorted(*head))
	{
		index = find_max(*head);
		if (index == 0)
			ft_rotate(head);
		else if (index == 1)
			ft_reverse_rotate(head);
		if ((*head)->data > (*head)->next->data)
			ft_swap(*head);
	}
}

// Algo: think of two rolls, for each element in list a, calculate the number of moves required to (1) shift list b so that it would be ordered once popped and (2) shuft list a so that the element is poppable
// Bonus: you can shift two moves into one if both rolls shift the same way
// --> The index is enough
// Distance to index 0 is min(index, len(list) - index + 1)


/* 
	Find the corrrect position in an ordered circular list (decreasing order)
	(N.B. Head is not necessarily at min value)
	Return the index of the item the value should precede (e.g. at the start of the list returns 0)
*/
int	find_index_bis(node_t *head, int value)
{
	node_t	*current;
	int	index;
	int max_index;

	if (!head || head->next == head)
		return (0);
	index = 0;
	current = head;
	max_index = find_max(head);
	while (max_index-- && ++index)
		current = current->next;
	if (!(current->data <= value || current->prev->data >= value))
	{
		while(!(value >= current->data) && ++index)
			current = current->next;
	}
	index = index % ft_list_size(current);
	return (index);
}
/* 
	Find the corrrect position in an ordered circular list (decreasing order)
	(N.B. Head is not necessarily at min value)
	Return the index of the item the value should precede (e.g. at the start of the list returns 0)
*/
int	find_index(node_t *head, int value)
{
	node_t	*node;
	int	index;

	if (!head)
		return (0);
	index = 0;
	node = head;
	while (true) // in bounds
	{
		if (value <= node->prev->data && value >= node->data)
			return (index);
		if (value == node->data)
			return (index);
		if (node->prev->data < node->data && (value < node->prev->data || value > node->data))
			return (index);
		if (node == head && index > 0)
			return (0);
		node = node->next;
		index++;
	}
	return (index);
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
	moves[0] = init_moves(index_a, index_b, 0 , 0);
	moves[1] = init_moves(0, 0, (size_a - index_a) % size_a,
							(size_b - index_b) % size_b);
	moves[2] = init_moves(index_a, 0, (size_b - index_b) % size_b, 0);
	moves[3] = init_moves(0, index_b, (size_a - index_a) % size_a, 0);
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
// REMINDER: you can only pop the the HEAD of the list (index 0)
move_t	iterate_a(node_t *head_a, int size_a, node_t *head_b, int size_b)
{
	int index_a;
	int index_b;
	move_t moves;
	move_t min_moves;
	node_t *current;
	
	index_a = 0;
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

void	shift_list(move_t moves, node_t **head_a, node_t **head_b)
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

void	sort_list(node_t *head_a)
{
	int len_a;
	int	len_b;
	node_t *head_b;
	move_t moves;
	
	len_a = ft_list_size(head_a);
	len_b = 0;
	head_b = NULL;
	while (!is_sorted(head_a) && len_a > 3)
	{
		if (len_b < 2 && printf("pa\n"))
			ft_push(&head_a, &head_b);
		else
		{
			moves = iterate_a(head_a, len_a, head_b, len_b);
			shift_list(moves, &head_a, &head_b);
			ft_push(&head_a, &head_b);
			printf("pa\n");
		}
		len_a--;
		len_b++;
	}
	sort_three(&head_a);
	ft_list_print(head_a, 'a');
	ft_list_print(head_b, 'b');
}













