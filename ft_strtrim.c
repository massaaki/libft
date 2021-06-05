#include "libft.h"
#include <stdio.h>
/*
 * Function: ft_strtrim
 */


int		ft_char_is_in_set(char c, const char *set)
{
	char *set_ptr;

	set_ptr = (char *)set;
	while(*set_ptr)
	{
		if (c == *set_ptr)
			return (1);
		set_ptr++;
	}
	return (0);
}


void	*ft_get_initial(const char *s1, const char *set)
{
	char *s1_ptr;

	//printf("finding initial...\n");
	s1_ptr = (char *)s1;
	while(*s1_ptr && ft_char_is_in_set(*s1_ptr, set))
	{
		//printf("%c", *s1_ptr);
		s1_ptr++;
	}
	//printf("=>%c\n", *s1_ptr);
	return s1_ptr;
}


void	*ft_get_final(const char *s1, const char *set)
{
	size_t len;
	char	*s1_ptr;

	s1_ptr = (char *)s1;
	len = ft_strlen(s1) -1;
	s1_ptr += len;
	//printf("finding final...\n");
	while(len-- &&  ft_char_is_in_set(*s1_ptr, set))
	{
	//	printf("%c", *s1_ptr);
		s1_ptr--;
	}
	//printf("=>%c\n", *s1_ptr);
	return (s1_ptr);
}


char	*ft_strtrim(const char *s1, const char *set)
{
	char	*dest;
	void	*initial_str;
	void	*final_str;
	size_t	len_to_cpy;

	if(!s1 || !set)
		return (NULL);
	initial_str = ft_get_initial(s1, set);
	final_str = ft_get_final(s1, set);
	//printf("inicial..: %p = %c\n", initial_str, *(char *)(initial_str));
	//printf("final..: %p = %c\n", final_str, *(char *)(final_str));
	
	len_to_cpy = final_str - initial_str + 1;
	if((final_str == s1 && *(char *)initial_str == '\0') || len_to_cpy == 0)
	{
		dest = (char *)malloc(sizeof(char));
		//printf("len to copy..: 2\n");
		if (!dest)
			return (NULL);
		dest[0] = '\0';
	}
	else
	{
		dest = (char *)malloc(len_to_cpy * sizeof(char) + 1);
		if (!dest)
			return (NULL);
		printf("len to copy..:%lu\n", len_to_cpy);
		ft_strlcat(dest, initial_str,  len_to_cpy + 1);
		printf("imprimir aqui..: \"%s\"\n", dest);
	}
	return (dest);
}
