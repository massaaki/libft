#include "libft.h"

void	ft_remove_duplicated(char *treated_str, char *s, char c)
{
	char	*current;
	int		found;
	char	*treated_str_ptr;

	current = (char *)s;
	treated_str_ptr = treated_str;
	found = 0;
	while (*current)
	{
		while (*current == c)
		{
			found = 1;
			current++;
		}
		if (found)
		{
			*treated_str_ptr = c;
			treated_str_ptr++;
		}
		*treated_str_ptr = *current;
		treated_str_ptr++;
		current ++;
		found = 0;
	}
	*treated_str_ptr = '\0';
}

char	*ft_trimmed_split_str(const char *s, char c)
{
	char	*set;
	char	*result;

	set = (char *)malloc(sizeof(char) * 1);
	set[0] = c;
	set[1] = '\0';
	result = ft_strtrim(s, set);
	free(set);
	return (result);
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
	if (*(treated_str_ptr - 1) != c)
		count++;
	return (count);
}

void	*ft_get_splited_str(char **array, char *treated_str, char c)
{
	char	*initial;
	size_t	pos;
	size_t	len;

	initial = treated_str;
	pos = 0;
	len = ft_strlen(treated_str) + 1;
	while (len--)
	{
		if (*treated_str == c || *treated_str == '\0')
		{
			array[pos] = (char *)malloc((treated_str - initial + 1));
			if (!array[pos])
				return (NULL);
			array[pos][0] = '\0';
			ft_strlcat(array[pos], initial, (treated_str - initial + 1));
			pos++;
			initial = treated_str + 1;
		}
		treated_str++;
	}
	array[pos] = NULL;
	return (array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	char	*str_treated;
	size_t	qty_str;
	void	*result;

	if (!s)
		return (NULL);
	qty_str = 0;
	str_treated = (char *)malloc(ft_strlen(s) * sizeof(char));
	if (!str_treated)
		return (NULL);
	str_treated[0] = '\0';
	ft_remove_duplicated(str_treated, ft_trimmed_split_str(s, c), c);
	qty_str = ft_count_str(str_treated, c);
	array = (char **)malloc(qty_str * sizeof(char *) + 1);
	result = ft_get_splited_str(array, str_treated, c);
	if (result == NULL)
		return (NULL);
	free(str_treated);
	free(result);
	return (array);
}
