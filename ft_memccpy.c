/*
 * memcpy copy a block of data from a source to destination address,
 * stopping when character c is found or length == nb
 * 	- Details:
 * 		- typecast to char* (1 byte)
 *		- copy data from src to dst
 *	- Considerations:
 *		- if overlap result is undefined
 *		- if char is found, return next char position + 1
 *		
 */

#include "libft.h"
void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dest_temp;
	char	*src_temp;
	char	c_temp;

	dest_temp = (char *)dst;
	src_temp = (char *)src;
	c_temp = (char) c;
	i = 0;
	while (i < n)
	{
		*(dest_temp + i) = *(src_temp + i);
		if (*(src_temp + i) == c_temp)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
