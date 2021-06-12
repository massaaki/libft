#include "libft.h"

static int	ft_get_decimal(int n)
{
	unsigned int	num;
	unsigned int	ref;
	int				count;

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

static char	*ft_alloc_mem(unsigned int *num, int n, int *len)
{
	char	*result;

	if (n < 0)
	{
		*len += 1;
		*num = (n * -1);
		result = (char *)malloc((*len + 1) * sizeof(char));
		if (!result)
			return (NULL);
		result[0] = '-';
	}
	else
	{
		*num = n;
		result = (char *)malloc((*len + 1) * sizeof(char));
		if (!result)
			return (NULL);
	}
	result[*len] = '\0';
	return (result);
}

static char	*ft_alloc_zero(void)
{
	char	*result;

	result = (char *)malloc(2 * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	num;
	int				len;

	len = ft_get_decimal(n);
	if (n == 0)
	{
		result = ft_alloc_zero();
		if (!result)
			return (NULL);
		return (result);
	}
	else
	{
		result = ft_alloc_mem(&num, n, &len);
		if (!result)
			return (NULL);
	}
	while (num > 0)
	{
		result[len - 1 ] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (result);
}
