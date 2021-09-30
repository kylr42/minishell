#include "libft.h"

size_t	max(size_t a, size_t b)
{
	if (a < b)
		return (b);
	return (a);
}

size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}