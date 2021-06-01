#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst_ptr;
	char	*src_ptr;

	if (!dst && !src)
		return (NULL);
	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	if (dst_ptr > src_ptr)
	{
		while (len-- > 0)
			*(dst_ptr + len) = *(src_ptr + len);
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*(dst_ptr + i) = *(src_ptr + i);
			i++;
		}
	}
	return (dst);
}
