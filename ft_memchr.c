#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*s_temp;

	s_temp = (unsigned char *)s;
	i = 0;
	while (*(s_temp + i) && i < (int)n)
	{
		if (*(s_temp + i) == (char)c)
		{
			return (s_temp + i);
		}
		i++;
	}
	return (NULL);
}
