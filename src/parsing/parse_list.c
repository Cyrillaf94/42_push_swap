/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:34:16 by cyril             #+#    #+#             */
/*   Updated: 2024/07/06 18:44:53 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_get_int(const char *str)
{
	int		*value;
	t_bool	is_neg;

	is_neg = false;
	if (*str == '-' && *str++)
		is_neg = true;
	if (!*str)
		return (NULL);
	value = ft_calloc(1, sizeof(long long));
	if (!value)
		return (NULL);
	while (ft_isdigit(*str) && *value < INT_MAX)
		*value = *value * 10 + *str++ - '0';
	if (is_neg)
		*value *= -1;
	if (*str)
	{
		free(value);
		return (NULL);
	}
	return (value);
}

static t_bool	is_valid(int *value, t_node *head)
{
	t_node	*current;

	current = head;
	if (value == NULL)
		return (false);
	if (current == NULL)
		return (true);
	while (true)
	{
		if (current->data == *value)
			return (false);
		if (current->next == head)
			return (true);
		current = current->next;
	}
}

t_node	*parse_list(int argc, char	**argv)
{
	int		*value;
	int		argn;
	t_node	*node;
	t_node	*head;

	argn = 1;
	head = NULL;
	while (argn < argc)
	{
		value = ft_get_int(argv[argn]);
		if (is_valid(value, head))
		{
			node = create_node(*value);
			insert_node_tail(&head, node);
			argn++;
		}
		else
		{
			ft_lstclear_circular(&head);
			argn = argc;
		}
		if (value)
			free(value);
	}
	return (head);
}
