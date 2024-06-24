/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:18:46 by cyril             #+#    #+#             */
/*   Updated: 2024/06/24 21:01:27 by cyril            ###   ########.fr       */
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

/* 
	Find the corrrect position in an ordered circular list (decreasing order)
	(N.B. Head is not necessarily at min value)
	Return the index of the item the value should follow
*/
int	find_index_dec(node_t *head, int value)
{
	node_t	*node;
	int	index;

	if (!head)
		return (0);
	index = 0;
	node = head;
	while (true)
	{
		if (value > node->next->data && value < node->data) // normal condition
			return (index);
		if (node->next->data > node->data && (value < node->data || value > node->next->data)) // out of bounds
			return (index);
		if (node->next == head) // end of list
			return (index);
		node = node->next;
		index++;
	}
	return (index);
}

/* 
	Find the corrrect position in an ordered circular list (decreasing order)
	(N.B. Head is not necessarily at min value)
	Return the index of the item the value should precede (e.g. at the start of the list returns 0)
*/
int	find_index_inc(node_t *head, int value)
{
	node_t	*node;
	int	index;

	if (!head)
		return (0);
	index = 0;
	node = head;
	while (true)
	{
		if (node->data < value && value < node->next->data) // normal condition
			return (index);
		if (node->next->data < node->data && (value > node->data || value < node->next->data)) // out of bounds
			return (index);
		if (node->next == head) // end of list
			return (index);
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

// Get number of moves to push - REMINDER: you need to be at max index (size - 1)
// There are two ways to get the element at the end: forward or backwards - i.e. 
move_t get_moves(int index_a, int index_b, int size_a, int size_b)
{
	move_t moves[4];
	int i;
	int min_i;
	int min_moves;
	int count_mov;

	i = 0;
	min_moves = INT_MAX;
	min_i = -1;
	moves[0] = init_moves(index_a + 1, index_b + 1, 0 , 0);
	moves[1] = init_moves(0, 0, (size_a - index_a - 1),
							(size_b - index_b - 1));
	moves[2] = init_moves(index_a + 1, 0, 0, (size_b - index_b - 1));
	moves[3] = init_moves(0, index_b + 1,  (size_a - index_a - 1), 0);
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

// Return the least moves to pop one element of a to b
// REMINDER: you can only pop the the END of the list (last index)
move_t	iter_list(node_t *head_a, int size_a, node_t *head_b, int size_b, 
int (*find_index)(node_t *, int))
{
	int index_a;
	int index_b;
	move_t moves;
	move_t min_move;
	node_t *current;
	
	index_a = 0;
	current = head_a;
	if (!current)
		return (init_moves(0, 0, 0, 0));
	min_move = init_moves(INT_MAX, 0, 0, 0);
	while (index_a == 0 || current != head_a)
	{
		index_b = find_index(head_b, current->data);
		moves = get_moves(index_a, index_b, size_a, size_b);
		if (count_moves(moves) < count_moves(min_move))
			min_move = moves;
		index_a++;
		current = current->next; 
	}
	return (min_move);
}

static void	reverse_rotate_list(move_t moves, node_t **list_from, node_t **list_to, char c)
{
	while (moves.rra && moves.rrb)
	{
		ft_dispatch_instruct(list_from, list_to, &ft_reverse_rotate);
		moves.ra--;
		moves.rb--;
	}
	while (moves.rra-- && c == 'a')
		ft_dispatch_instruct(list_from, NULL, &ft_reverse_rotate);
	while (moves.rrb-- && c == 'a')
		ft_dispatch_instruct(list_to, NULL, &ft_reverse_rotate);
	while (moves.rra-- && c == 'b')
		ft_dispatch_instruct(NULL, list_from, &ft_reverse_rotate);
	while (moves.rrb-- && c == 'b')
		ft_dispatch_instruct(NULL, list_to, &ft_reverse_rotate);
}

static void	rotate_list(move_t moves, node_t **list_from, node_t **list_to, char c)
{
	while (moves.ra && moves.rb)
	{
		ft_dispatch_instruct(list_from, list_to, &ft_rotate);
		moves.ra--;
		moves.rb--;
	}
	while (moves.ra-- && c == 'a')
		ft_dispatch_instruct(list_from, NULL, &ft_rotate);
	while (moves.rb-- && c == 'a')
		ft_dispatch_instruct(list_to, NULL, &ft_rotate);
	while (moves.ra-- && c == 'b')
		ft_dispatch_instruct(NULL, list_from, &ft_rotate);
	while (moves.rb-- && c == 'b')
		ft_dispatch_instruct(NULL, list_to, &ft_rotate);	
}

static void	move_one_elem(node_t **head_from, node_t **head_to, int len_from, int len_to, 
							int (*find_index)(node_t *, int))
{
	move_t	moves;
	char	c;

	if (find_index == &find_index_dec)
		c = 'a';
	else
		c = 'b';

	moves = iter_list(*head_from, len_from, *head_to, len_to, find_index);
	rotate_list(moves, head_from, head_to, c);
	reverse_rotate_list(moves, head_from, head_to, c);
	ft_push(head_from, head_to, c);
}

// Shift ordered circular doubly linked list so that the min value is at index 0 
static void	shift_final_list(node_t **head, int list_len)
{
	int	index_min;

	index_min = find_min(*head);
	if (list_len / 2 > index_min)
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

void	sort_list(node_t *head_a, int len_a)
{
	int	len_b;
	node_t *head_b;
	
	len_a = ft_list_size(head_a);
	len_b = 0;
	head_b = NULL;
	while (!is_sorted(head_a) && len_a > 3)
	{
		if (len_b < 2 && write(1, "pa\n", 3))
			ft_push(&head_a, &head_b, 'a');
		else
			move_one_elem(&head_a, &head_b, len_a, len_b, &find_index_dec);
		len_a--;
		len_b++;
	}
	sort_three(&head_a);
	while (len_b)
	{
		move_one_elem(&head_b, &head_a, len_b, len_a, &find_index_inc);
		len_b--;
		len_a++;
	}
	shift_final_list(&head_a, len_a);
}
