#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;	

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize < 1)
		return (src_len);
	if (dstsize < dst_len)
		return (dstsize + src_len);
	i = dst_len;
	j = 0;
	while (*(src + j) && (i < dstsize - 1))
	{
		*(dst + i) = *(src + j);
		i++;
		j++;
	}
	*(dst + i) = '\0';
	if (dstsize < dst_len)
		return (src_len + dstsize);
	else
		return (src_len + dst_len);
}
