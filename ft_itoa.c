#include "libft.h"
#include <stdio.h>

static int	ft_get_decimal(int n)
{ 
	unsigned int num;
	unsigned int ref;
	int count;

	ref = 1;
	count = 0;
	if (n < 0)
		num = (n * -1);
	else
		num = n;
	while (num / ref != 0 && ref <= 1000000000)
	{
		count++;
		ref *= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	unsigned int num;
	int len;

	len = ft_get_decimal(n);

	if (n == 0)
	{
		result = (char *)malloc(2 * sizeof(char));
		result[0] = '0';
		result[1] = '\0';
		return result;
	}
	if (n < 0)
	{
		len += 1;
		num = (n * -1);
		result = (char *)malloc((len + 1) * sizeof(char));
		result[0] = '-';
	}
	else 
	{
		num = n;
		result = (char *)malloc((len + 1) * sizeof(char));
	}

	result[len] = '\0';
	
	while(num > 0)
	{
		result[len - 1 ] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	
	return result;
}
