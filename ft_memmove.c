#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*dst_ptr;
	char	*src_ptr;

	if (!dst && !src)
		return (NULL);
	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	if (dst_ptr > src_ptr)
	{
		i = (int)(len - 1);
		while (i >= 0)
		{
			*(dst_ptr + i) = *(src_ptr + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*(dst_ptr + i) = *(src_ptr + i);
			i++;
		}
	}
	return (dst);
}
