#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	if (dstsize > 0)
	{
		i = 0;
		while ((src + i) && (i < dstsize - 1))
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(char *)(dst + i) = '\0'; 
	}

	return ft_strlen(src);
}
