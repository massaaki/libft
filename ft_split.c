#include "libft.h"
#include <stddef.h>
#include <stdio.h>


/*
 * remove c duplicated in sequence
 */
char	*ft_treat_str(char *str, char c)
{
	int found = 0;
	char *str_temp;
	char *result;
	char *result_temp;

	//result = (char *) malloc(ft_strlen(str) * sizeof(char) + 1);
	result = ft_calloc(ft_strlen(str) + 1, sizeof(char) );
	result_temp = result;
	str_temp = str;
	while(*str_temp != '\0')
	{
		
		while(*str_temp == c && *str_temp)
		{
			found++;
			str_temp++;
		}
	//	printf("%c", *(str_temp));


		if(found > 0)
		{
			printf("%c", c);
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

int		ft_count_char(char *str, char c)
{
	char *str_temp;
	int count;

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

void	ft_append_str(char **array, char *initial, char* final, int len, int pos)
{
	char *current;
	int i;
	current = initial;

	//printf("----------\n");
	//printf("len..: %d\n", len);
	array[pos] = (char *)malloc(len * sizeof(char) + 1);
	//printf("str..: \"");
	i = 0;
	while (current < final)
	{
	//	printf("%c", *current);
		array[pos][i] = *current;
		current++;
		i++;
	}
	//array[pos][i] = '\0';
	//printf("----------\n");
}

char	**ft_split(const char *s, char c)
{
	char **array;
	char *initial_pos;
	char *current_pos;
	char *str;
	char *treated_str;
	char *treated_str_current;
	int len;
	char *set;
	int array_index;
	//printf("%s\n", s);	
	//set = (char *)malloc(sizeof(char) * 1);
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

	//printf("\nTREATED_STR..: %s\n\n", treated_str);
	
	//printf("split_count..: %d\n", ft_count_char(str, *(set)));
	//printf("treated string..: \"%s\"\n", treated_str);
	//printf("initial_pos..: %p %c\n", initial_pos, *initial_pos);
	//printf("current_pos..: %p %c\n", current_pos, *current_pos);
	

		
	while (*treated_str_current)
	{
		if (*treated_str_current == c)
		{
			current_pos = treated_str_current;
			len = current_pos - initial_pos;

			ft_append_str(array, initial_pos, current_pos, len, array_index);
			current_pos++;
			initial_pos = current_pos;
			array_index++;
		}

		current_pos++;
		treated_str_current++;
	}
	if (initial_pos != current_pos)
	{
		len = current_pos - initial_pos -1;
		ft_append_str(array, initial_pos, current_pos, len, array_index);
		array_index++;
	}
	array[array_index] = NULL;
	//printf("initial char..: %c\n", *initial_pos);
	//printf("last char..: %c\n", *current_pos);
	//printf("\n");
	free(set);
	free(treated_str); 

	free(str);
	return (array);
	return NULL;
}
