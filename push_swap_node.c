/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyril <cyril@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:51:28 by cyril             #+#    #+#             */
/*   Updated: 2024/03/23 13:19:39 by cyril            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

node_t	*create_node(int data) 
{
    node_t* new_node;
	new_node = (node_t*)malloc(sizeof(node_t));
	if (new_node)
	{
		new_node->data = data;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	return new_node;
}

void	insert_node_tail(node_t **head, node_t *new_node)
{
	node_t	*prev_tail;
	if (head && new_node)
	{
		if (!*head || !(*head)->next)
		{
			*head = new_node;
			new_node->next = new_node;
			new_node->prev = new_node;
		}
		else
		{
			prev_tail =  (*head)->prev;
			(*head)->prev = new_node;
			prev_tail->next = new_node;
			new_node->next = *head;
			new_node->prev = prev_tail;
		}
	}
}

node_t	*remove_node(node_t **head)
{
	node_t	*temp;
	
	if (!*head | (*head)->next == *head)
		head == NULL;
	else
	{
		temp = (*head)->prev;
		(*head)->prev = temp->prev;
		temp->prev->next = *head;
	}
	return (temp);
}

int	ft_list_size(node_t *node)
{
	int	i;
	node_t*	current;

	i = 0;
	current = node;
	while (current && (i==0 | current != node))
	{
		i++;
		current = current->next;
	}
	return (i);
}

void	ft_lstclear(node_t **head)
{
	node_t	*current;
	
	if (*head)
	{
		current = *head;
		current->prev->next = NULL;
		while (current->next)
		{
			current = current->next;
			free(current->prev);
		}
		free(current);
	}
}

