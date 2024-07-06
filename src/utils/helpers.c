/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:29:46 by cyril             #+#    #+#             */
/*   Updated: 2024/07/06 18:41:53 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_print(const t_node *node, char c)
{
	int				i;
	const t_node	*current;

	current = node;
	i = 0;
	printf("%c: ", c);
	while (current && (i == 0 || current != node))
	{
		printf("%i / ", current->data);
		current = current->next;
		i++;
	}
	printf("\n");
}

int	find_max(t_node *head)
// Return the max index (if multiple max values, returns the min index)
{
	int		i;
	int		max_index;
	int		max;
	t_node	*current;

	i = 0;
	current = head;
	max_index = -1;
	max = INT_MIN;
	while (current && (i == 0 || current != head))
	{
		if (current->data > max)
		{
			max_index = i;
			max = current->data;
		}
		current = current->next;
		i++;
	}
	return (max_index);
}

int	find_min(t_node *head)
{
	int		i;
	int		min_index;
	int		min;
	t_node	*current;

	i = 0;
	current = head;
	min_index = -1;
	min = INT_MAX;
	while (current && (i == 0 || current != head))
	{
		if (current->data < min)
		{
			min_index = i;
			min = current->data;
		}
		current = current->next;
		i++;
	}
	return (min_index);
}
