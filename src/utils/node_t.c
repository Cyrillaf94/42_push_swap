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
	node_t *tail;

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

node_t	*remove_node(node_t **head)
{
	node_t	*temp;
	
	if (!head || !*head)
		return (NULL);
	if ((*head)->next == *head)
	{
		temp = *head;
		*head = NULL;
	}	
	else
	{
		temp = (*head)->prev;
		(*head)->prev = temp->prev;
		temp->prev->next = *head;
	}
	temp->next = temp->prev = NULL;
	return (temp);
}

int	ft_list_size(node_t *node)
{
	int	i;
	node_t*	current;

	i = 0;
	current = node;
	while (current && (i==0 || current != node))
	{
		i++;
		current = current->next;
	}
	return (i);
}

void	ft_lstclear(node_t **head)
{
	node_t	*current;
	
	if (head)
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

