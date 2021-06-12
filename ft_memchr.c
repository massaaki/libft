#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*s_temp;

	s_temp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(s_temp + i) == (unsigned char)c)
			return (s_temp + i);
		i++;
	}
	return (NULL);
}
