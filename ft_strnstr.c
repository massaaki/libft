#include "libft.h"

char	*ft_strnstr(const char *haystrack, const char *needle, size_t len)
{
	char	*ptr_haystrack;
	size_t	needle_len;
	size_t	i;
	size_t	j;

	ptr_haystrack = (char *) haystrack;
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return (ptr_haystrack);
	i = 0;
	j = 0;
	while (*(ptr_haystrack + i) && (i < len))
	{
		if (*(ptr_haystrack + i) == *(needle + j))
			j++;
		else
			j = 0;
		if (j == needle_len)
			return (ptr_haystrack + i - (j - 1));
		i++;
	}
	return (NULL);
}
