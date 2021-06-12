#include "libft.h"

static char	*ft_substr_allocate(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*dest;

	s_len = ft_strlen(s);
	if (start + len > s_len)
		dest = (char *)malloc(sizeof(char) * (s_len - (size_t)start + 1));
	else
		dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	return (dest);
}

static void	ft_substrcpy(char const *s, unsigned int start,
		size_t len, char *dest)
{
	size_t	i;
	size_t	j;
	char	*str_temp;

	i = (size_t)start;
	j = 0;
	str_temp = (char *)s;
	str_temp += i;
	while (*(str_temp) && (j < len))
	{
		*(dest + j) = *str_temp;
		str_temp++;
		i++;
		j++;
	}
	*(dest + j) = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < (size_t)start)
	{
		dest = (char *)malloc(sizeof(char));
		*dest = '\0';
		return (dest);
	}
	dest = ft_substr_allocate(s, start, len);
	if (dest == NULL)
		return (NULL);
	ft_substrcpy(s, start, len, dest);
	return (dest);
}
