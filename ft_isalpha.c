#include "libft.h"

int ft_isalpha(int c)
{
	if(((char)c > 'a' && (char)c < 'z') || ((char)c > 'A' && (char)c < 'Z'))
		return (1);
	return (0);
}
