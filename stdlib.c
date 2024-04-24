#include "push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char		*ptr;
	size_t				n_bytes;

	if (size && count > (size_t) - 1 / size)
		return (NULL);
	n_bytes = count * size;
	ptr = malloc(n_bytes);
	if (!ptr)
		return (NULL);
	while (n_bytes--)
		*ptr++ = 0;
	ptr -= count * size;
	return (ptr);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}