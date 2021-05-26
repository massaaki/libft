#include "libft.h"
#include <stddef.h>
#include <stdio.h>

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

void	ft_append_str(char **array, char *initial, char* final, int len)
{
	char *current;

	current = initial;

	printf("len..: %d\n", len);
	printf("word to split..: \"");
	while (current < final)
	{
		printf("%c", *current);
		current++;
	}
	printf("\"\n");
	array = NULL;
}

char	**ft_split(const char *s, char c)
{
	char **array = (char **) malloc (sizeof(char *));
	//char **array;
	char *initial_pos;
	char *current_pos;
	char *str;
	int len;
	char *set;
	
	set = (char *)malloc(sizeof(char) * 1 + 1);
	*set = c;
	*(set + 1) = '\0';

	str = ft_strtrim((char *)s, set);
	initial_pos = str;
	current_pos = initial_pos;
	
	printf("split_count..: %d\n", ft_count_char(str, *(set)));

	printf("trimmed str..: \"%s\"\n", str);

	printf("initial_pos..: %p %c\n", initial_pos, *initial_pos);
	printf("current_pos..: %p %c\n", current_pos, *current_pos);
	while (*str)
	{
		if (*str == c)
		{
			current_pos = str;
			len = current_pos - initial_pos;
			//ft_append_str(array, initial_pos, current_pos, len);
			ft_append_str(array, initial_pos, current_pos, len);
			current_pos++;
			initial_pos = current_pos;
		}

		current_pos++;
		str++;
	}
	if (initial_pos != current_pos)
	{
		len = current_pos - initial_pos - 1;
		//ft_append_str(array, initial_pos, current_pos, len);
		ft_append_str(array, initial_pos, current_pos, len);
	}
	printf("initial char..: %c\n", *initial_pos);
	printf("last char..: %c\n", *current_pos);
	printf("\n");
	free(set);
	return (array);
}
