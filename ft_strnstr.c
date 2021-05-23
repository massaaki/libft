#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr_haystack;
	size_t	needle_len;
	size_t	j;

	ptr_haystack = (char *) haystack;
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return (ptr_haystack);
	j = 0;
	while (*(ptr_haystack) && (len >= needle_len))
	{
		if (ft_strncmp(needle, ptr_haystack, needle_len) == 0)
			return (ptr_haystack);
		ptr_haystack++;
		len--;
	}
	return (NULL);
}
