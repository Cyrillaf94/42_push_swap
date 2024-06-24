#include "push_swap.h"

static int	*ft_get_int(const char *str)
{
	int		*value;
	bool	is_neg;

	is_neg = false;
	if (*str == '-' && *str++)
		is_neg = true;
	if (!*str)
		return (NULL);
	value = ft_calloc(1, sizeof(long long));
	if(!value)
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

static bool	is_valid(int *value, node_t *head)
{
	node_t *current;

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


node_t	*parse_list(int argc, char	**argv)
{
	int		*value;
	int 	argn;
	node_t	*node;
	node_t	*head;

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
