/* ************************************************************************** */
/*																			*/
/*		                                                :::      ::::::::   */
/*   push_swap_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:51:28 by cyril             #+#    #+#             */
/*   Updated: 2024/04/01 18:05:06 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (new_node)
	{
		new_node->data = data;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	return (new_node);
}

void	insert_node_tail(t_node **head, t_node *new_node)
{
	t_node	*tail;

	if (!(*head))
	{
		*head = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		tail = (*head)->prev;
		tail->next = new_node;
		new_node->prev = tail;
		new_node->next = *head;
		(*head)->prev = new_node;
	}
}

// Remove a node from the list, return the pointer to that node, 
// nullify the pointer of pointer if list is empty
t_node	*remove_node(t_node **node)
{
	t_node	*temp;

	if (!node || !*node)
		return (NULL);
	temp = *node;
	if ((*node)->next == *node)
	{
		temp = *node;
		*node = NULL;
		return (temp);
	}
	else
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}

int	ft_list_size(t_node *node)
{
	int		i;
	t_node	*current;

	i = 0;
	current = node;
	while (current && (i == 0 || current != node))
	{
		i++;
		current = current->next;
	}
	return (i);
}

void	ft_lstclear_circular(t_node **head)
{
	t_node	*current;

	if (head && *head)
	{
		current = *head;
		current->prev->next = NULL;
		while (current->next)
		{
			current = current->next;
			free(current->prev);
		}
		free(current);
		*head = NULL;
	}
}
