#include "libft.h"

/*
 * Function: ft_find_char_in_set
 * Description: 
 */
static int	ft_find_char_in_set(char char_to_find, const char *set)
{
	int	i;

	i = 0;
	while (*(set + i))
	{
		if (char_to_find == *(set + i))
			return (1);
		i++;
	}
	return (0);
}

/*
 * Function: ft_get_size_trimmed_str
 * Description: Find length of chars to remove
 * Return: string length without chars to remove ('\0' included)
 */
static int	ft_get_size_trimmed_str(const char *s1, const char *set)
{
	int	i;
	int	chars_to_remove;
	int	last_position_to_remove_from_left;

	i = 0;
	chars_to_remove = 0;
	last_position_to_remove_from_left = 0;
	while (*(s1 + i) && (ft_find_char_in_set(*(s1 + i), set)))
	{
		(chars_to_remove)++;
		last_position_to_remove_from_left = i;
		i++;
	}
	i = ft_strlen(s1) - 1;
	while (i > last_position_to_remove_from_left)
	{
		if (ft_find_char_in_set(*(s1 + i), set))
			chars_to_remove++;
		else
			break ;
		i--;
	}
	return (ft_strlen(s1) - chars_to_remove);
}

/*
 * Function: ft_get_trimmed_str_left
 * Description: Set the FIRST char *dest from left *s1 and update 
 * last_left_position
 * Return: void
 */
static void	ft_get_trimmed_str_left(char *dest, const char *s1, const char *set,
		int *last_left_position)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	*last_left_position = 0;
	while (*(s1 + i))
	{
		if (!ft_find_char_in_set(*(s1 + i), set))
		{
			*(dest + j) = *(s1 + i);
			j++;
			*last_left_position = i;
			break ;
		}
		i++;
	}
}

/*
 * Function: ft_get_trimmed_str
 * Description: Set dest without *set in left and right *s1
 * return void
 */
static void	ft_get_trimmed_str(char *dest, const char *s1,
		const char *set, int size)
{
	int	i;
	int	j;
	int	copy_from_right;
	int	last_left_position;

	ft_get_trimmed_str_left(dest, s1, set, &last_left_position);
	copy_from_right = 0;
	i = ft_strlen(s1) - 1;
	j = size - 1;
	while (i > last_left_position)
	{
		if (!ft_find_char_in_set(*(s1 + i), set))
			copy_from_right = 1;
		if (copy_from_right)
		{
			*(dest + j) = *(s1 + i);
			j--;
		}
		i--;
	}
	*(dest + size) = '\0';
}

/*
 * Function: ft_strtrim
 */
char	*ft_strtrim(const char *s1, const char *set)
{
	int		size;
	char	*dest;

	size = ft_get_size_trimmed_str(s1, set);
	dest = (char *)malloc (size * sizeof(char));
	ft_get_trimmed_str(dest, s1, set, size);
	return (dest);
}
