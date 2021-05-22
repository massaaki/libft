#include "libft.h"
#include <stdio.h>
int ft_isalnum(int c)
{
	if(((unsigned char)c >= 'a' && (unsigned char)c <= 'z') || ((unsigned char)c >= 'A' && (unsigned char)c <= 'Z')
		|| ((unsigned char)c >= '0' && (unsigned char)c <= '9'))
		return (1);
	return (0);
}
