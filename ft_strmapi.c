#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;
	int				len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		result[i] = f(i, *(s + i));
		i++;
	}
	result[i] = '\0';
	return (result);
}
