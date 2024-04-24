/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:18:46 by cyril             #+#    #+#             */
/*   Updated: 2024/04/24 10:14:07 by cyril            ###   ########.fr       */
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

// Find the corrrect position in an ordered circular list (decreasing order)
// (N.B. Head is not necessarily at min value)
int	find_index(node_t *head, int value)
{
	node_t	*current;
	int	index;
	int max_index;
	

	if (!head || head->next == head)
		return (0);
	index = 0;
	current = head;
	max_index = find_max(head);
	while (max_index--)
	{
		current = current->next;
		index++;
	}
	while(!(value > current->data || current->data > current->prev->data))
	{
		if (current == head)
			index = 0;
		else
			index++;
		current = current->next;
	}
	return (index);
}

// Both list can shift in the same direction at the same time to avoid costing an extra move
// Returns a negative number if the rotation is in reverse
int	get_number_of_moves(int index_a, int index_b, int size_a, int size_b)
{
	int direction_1;
	int	direction_2;

	direction_1 = ft_max(index_a, index_b);
	direction_2 = ft_min(index_a - size_a, index_b - size_b);
	if (direction_1 < -direction_2)
		return (direction_1);
	return (direction_2);
}

// Return the index in list a with the least number of moves required
int	iterate_a(node_t *head_a, int size_a, node_t *head_b, int size_b)
{
	int index_a;
	int index_b;
	int index_min;
	int min_moves;
	int moves;
	node_t	*current;
	
	index_a = 0;
	index_min = 0;
	min_moves = INT_MAX;
	current = head_a;
	if (!current)
		return (index_min);
	while (index_a == 0 || current != head_a)
	{
		index_b = find_index(head_b, current->data);
		moves = ft_abs(get_number_of_moves(index_a, index_b, size_a, size_b));
		if (moves < min_moves)
		{
			min_moves = moves;
			index_min = index_a;
		}
		index_a++;
		current = current->next;
	}
	return (index_min);
}

move_t get_moves(int index_a, int index_b, int size_a, int size_b)
{
	move_t moves;
	int direction_1;
	int	direction_2;

	direction_1 = ft_max(index_a, index_b);
	direction_2 = ft_min(index_a - size_a, index_b - size_b);
	if (direction_1 < -direction_2)
	{
		moves.rra = index_a;
		moves.rrb = index_b;
		moves.ra = 0;
		moves.rb = 0;
	}
	else
	{
		moves.ra = size_a - index_a;
		moves.rb = size_b - index_b;
		moves.rra = 0;
		moves.rrb = 0;
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
	while (!is_sorted(head) && len_a - 3)
	{
		index_a = iterate_a(head, len_a, head_b, len_b);
		index_b = find_index(head_b, get_value_index(head, index_a));
		printf("Index A: %i, Index B: %i\n", index_a, index_b);
		moves = get_moves(index_a, index_b, len_a--, len_b++);
		shift_list(moves, &head, &head_b);
		ft_push(&head, &head_b);
		ft_list_print(head, 'a');
		ft_list_print(head_b, 'b');
	}
}













