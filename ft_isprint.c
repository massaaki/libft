#include "libft.h"

int	ft_isprint(int c)
{
	if (c >=0 && c <=126)
		return (1);
	return (0);
}
