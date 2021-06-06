#include "libft.h"
#include <stdio.h>

void	*ft_remove_duplicated(char *treated_str, char *s, char c)
{
	int		found;
	char	*treated_str_ptr;

	if (!s)
		return (NULL);
	treated_str_ptr = treated_str;
	found = 0;
	while (*s)
	{
		while (*s == c)
		{
			found = 1;
			s++;
		}
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
	return (treated_str);
}

char	*ft_trimmed_split_str(const char *s, char c)
{
	char	*set;
	char	*result;

	set = ft_calloc(2, sizeof(char));
	if (!set)
		return (NULL);
	set[0] = c;
	result = ft_strtrim(s, set);
	if (!result)
		return (NULL);
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
	if (treated_str[0] != '\0' && *(treated_str_ptr - 1) != c)
		count++;
	return (count);
}

void	*ft_get_splited_str(char **array, char *treated_str, char c)
{
	char	*initial;
	size_t	pos;
	size_t	len;

	pos = 0;
	len = ft_strlen(treated_str) + 1;
	if (treated_str[0] == '\0')
		return (array);
	initial = treated_str--;
	while (len--)
	{
		if (*++treated_str == c || *treated_str == '\0')
		{
			array[pos] = ft_calloc((treated_str - initial + 1), sizeof(char));
			if (!array[pos])
			{
				pos = 0;
				while (array[pos])
					free(array[pos++]);
				free(array);
				return (NULL);
			}
			ft_strlcat(array[pos++], initial, (treated_str - initial + 1));
			initial = treated_str + 1;
		}
	}
	return (array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	char	*str_treated;
	size_t	qty_str;
	void	*check;
	char	set[2];

	set[0] = c;
	set[1] = '\0';
	if (!s)
		return (NULL);
	qty_str = 0;
	str_treated = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str_treated)
		return (NULL);
	//check = ft_remove_duplicated(str_treated, ft_trimmed_split_str(s, c), c);
	check = ft_remove_duplicated(str_treated, ft_strtrim(s, set), c);
	
	if (check == NULL)
	{
		free(str_treated);
		return (NULL);
	}
	qty_str = ft_count_str(str_treated, c);
	array = ft_calloc(qty_str + 1, sizeof(char *));
	if (!array)
	{
		free(str_treated);
		return (NULL);
	}
	check = ft_get_splited_str(array, str_treated, c);
	if (check == NULL)
	{
		free(str_treated);
		return (NULL);
	}
	free(str_treated);
	return (array);
}
