#include "libft.h"

static void	*ft_remove_duplicated(char *treated_str, char *s, char c)
{
	int		found;
	char	*treated_str_ptr;
	char	*initial;

	if (!s)
		return (NULL);
	initial = s;
	treated_str_ptr = treated_str;
	found = 0;
	while (*s)
	{
		while (*s == c && s++)
			found = 1;
		if (found)
		{
			*treated_str_ptr = c;
			treated_str_ptr++;
		}
		*treated_str_ptr = *s;
		treated_str_ptr++;
		s++;
		found = 0;
	}
	return (free(initial), treated_str);
}

static void	*ft_free_all(char **array)
{
	size_t	pos;

	pos = 0;
	while (array[pos])
		free(array[pos++]);
	free(array);
	return (NULL);
}

size_t	ft_count_str(char *treated_str, char c)
{
	char	*treated_str_ptr;
	size_t	count;

	treated_str_ptr = treated_str;
	count = 0;
	while (*treated_str_ptr)
	{
		if (*treated_str_ptr == c)
			count++;
		treated_str_ptr++;
	}
	if (treated_str[0] != '\0' && *(treated_str_ptr - 1) != c)
		count++;
	return (count);
}

static void	*ft_get_splited_str(char **array, char *treated_str, char c)
{
	char	*initial;
	size_t	pos;
	size_t	len;

	pos = 0;
	len = ft_strlen(treated_str) + 1;
	if (treated_str[0] == '\0')
		return (array);
	initial = treated_str;
	while (len--)
	{
		if (*treated_str == c || *treated_str == '\0')
		{
			array[pos] = ft_calloc((treated_str - initial + 1), sizeof(char));
			if (!array[pos])
				return (ft_free_all(array));
			ft_strlcat(array[pos++], initial, (treated_str - initial + 1));
			initial = treated_str + 1;
		}
		treated_str++;
	}
	return (array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	char	*str_treated;
	size_t	qty_str;
	char	set[2];

	set[0] = c;
	set[1] = '\0';
	if (!s)
		return (NULL);
	qty_str = 0;
	str_treated = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str_treated)
		return (NULL);
	if (!ft_remove_duplicated(str_treated, ft_strtrim(s, set), c))
		return (free(str_treated), NULL);
	qty_str = ft_count_str(str_treated, c);
	array = ft_calloc(qty_str + 1, sizeof(char *));
	if (!array)
		return (free(str_treated), NULL);
	if (!ft_get_splited_str(array, str_treated, c))
		return (free(str_treated), NULL);
	free(str_treated);
	return (array);
}
