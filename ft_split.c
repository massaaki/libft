#include "libft.h"

/*
 * remove c duplicated in sequence
 */
char	*ft_treat_str(char *str, char c)
{
	int		found;
	char	*str_temp;
	char	*result;
	char	*result_temp;

	found = 0;
	result = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	result_temp = result;
	str_temp = str;
	while (*str_temp != '\0')
	{
		while (*str_temp == c && *str_temp)
		{
			found++;
			str_temp++;
		}
		if (found > 0)
		{
			*result_temp = c;
			result_temp++;
			found = 0;
		}
		*result_temp = *str_temp;
		result_temp++;
		str_temp++;
	}
	*(result_temp) = '\0';
	return (result);
}

int	ft_count_char(char *str, char c)
{
	char	*str_temp;
	int		count;

	count = 0;
	str_temp = str;
	while (*str_temp)
	{
		if (*str_temp == c)
			count++;
		str_temp++;
	}
	if (*str_temp != '\0')
		count++;
	return (count + 1);
}

void	ft_append_str(char **array, char *initial, char *final, int pos)
{
	char			*current;
	int				i;
	unsigned int	len;

	if (*(final + 1) == '\0')
		len = final - initial - 1;
	else
		len = final - initial;
	current = initial;
	array[pos] = (char *)malloc(len * sizeof(char) + 1);
	i = 0;
	while (current < final)
	{
		array[pos][i] = *current;
		current++;
		i++;
	}
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	char	*initial_pos;
	char	*current_pos;
	char	*str;
	char	*treated_str;
	char	*treated_str_current;
	char	*set;
	int		array_index;

	set = ft_calloc(2, sizeof(char));
	*set = c;
	*(set + 1) = '\0';
	str = ft_strtrim((char *)s, set);
	treated_str = ft_treat_str(str, c);
	treated_str_current = treated_str;
	array = (char **)malloc(ft_count_char(str, *(set)) * sizeof(char *) + 1);
	initial_pos = treated_str_current;
	current_pos = initial_pos;
	array_index = 0;
	while (*treated_str_current)
	{
		if (*treated_str_current == c)
		{
			current_pos = treated_str_current;
			ft_append_str(array, initial_pos, current_pos, array_index);
			current_pos++;
			initial_pos = current_pos;
			array_index++;
		}
		current_pos++;
		treated_str_current++;
	}
	if (initial_pos != current_pos)
	{
		ft_append_str(array, initial_pos, current_pos, array_index);
		array_index++;
	}
	array[array_index] = NULL;
	free(set);
	free(treated_str);
	free(str);
	return (array);
}
