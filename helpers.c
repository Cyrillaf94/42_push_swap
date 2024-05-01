#include "push_swap.h"

void	ft_list_print(node_t *node, char c)
{
	int	i;
	node_t*	current;

	current = node;
	i = 0;
	printf("%c: ", c);
	while (current && (i == 0 | current != node))
	{
		printf("%i / ", current->data);
		current = current->next;
		i++;
	}
	printf("\n");
}

int	find_max(node_t *head)
// Return the max index (if multiple max values, returns the greatest index)
{
	int i;
	int max_index;
	int max;
	node_t*	current;

	i = 0;
	current = head;
	max_index = -1;
	max = INT_MIN;
	while (current && (i == 0 || current != head))
	{
		if (current->data >= max)
		{
			max_index = i;
			max = current->data;
		} 
		current = current->next;
		i++;
	}
	return (max_index);
}


int	find_antepenultimate_max(node_t *head, int max_index)
{
	int i;
	int antepenultimate_index;
	int max;
	node_t*	current;

	i = 0;
	current = head;
	antepenultimate_index = -1;
	max = INT_MIN;
	while (current && (i == 0 || current != head))
	{
		if (current->data >= max && i != max_index)
		{
			antepenultimate_index = i;
			max = current->data;
		} 
		current = current->next;
		i++;
	}
	return (antepenultimate_index);
}

int	find_min(node_t *head)
{
	int i;
	int min_index;
	int min;
	node_t*	current;

	i = 0;
	current = head;
	min_index = -1;
	min = INT_MAX;
	while (current && (i == 0 || current != head))
	{
		if (current->data <= min)
		{
			min_index = i;
			min = current->data;
		} 
		current = current->next;
		i++;
	}
	return (min_index);
}

int	find_antepenultimate_min(node_t *head, int min_index)
{
	int i;
	int antepenultimate_index;
	int min;
	node_t*	current;

	i = 0;
	current = head;
	antepenultimate_index = -1;
	min = INT_MAX;
	while (current && (i == 0 || current != head))
	{
		if (current->data <= min && i != min_index)
		{
			antepenultimate_index = i;
			min = current->data;
		} 
		current = current->next;
		i++;
	}
	return (antepenultimate_index);
}

int	get_value_index(node_t *head, int index)
{
	while (head && index--)
	{
		head = head->next;
	}
	return (head->data);
}
