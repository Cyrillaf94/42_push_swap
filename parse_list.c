#include "push_swap.h" 

int	ft_isspace(int c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				atoi;

	atoi = 0;
	i = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			i++;
	}
	while (ft_isdigit(*str))
		atoi = atoi * 10 + *str++ - '0';
	if (i % 2)
		atoi *= -1;
	return (atoi);
}

node_t	*parse_list(int argc, char	**argv)
{
	int	value;
	int argn;
	node_t	*node;
	node_t	*head;

	argn = 1;
	head = NULL;
	while (argn < argc)
	{
		value = ft_atoi(argv[argn]);
		node = create_node(value);
		insert_node_tail(&head, node);
		if (head == NULL)
			head = node;		
		argn++;
	}
	return (head);
}
