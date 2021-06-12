#include "libft.h"

static void	ft_atoi_initialize(int *i, int *signal)
{
	*i = 0;
	*signal = 1;
}

static void	ft_process_spaces(const char *str, int *i)
{
	while (*(str + *i) == ' ' || *(str + *i) == '\t' || *(str + *i) == '\n'
		|| *(str + *i) == '\v' || *(str + *i) == '\f' || *(str + *i) == '\r')
		(*i)++;
}

static void	ft_process_signal(const char *str, int *i,
		int *signal)
{	
	if (*(str + *i) == '-')
	{
		*signal = -1;
		(*i)++;
	}
	else if (*(str + *i) == '+')
		(*i)++;
}

static int	ft_process_result(const char *str, int i, int signal)
{
	int	result;

	result = 0;
	if (*(str + i) == '-' || *(str + i) == '+')
		return (0);
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		result = (result * 10) + *(str + i) - '0';
		i++;
	}
	return (result * signal);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	signal;

	ft_atoi_initialize(&i, &signal);
	ft_process_spaces(str, &i);
	ft_process_signal(str, &i, &signal);
	return (ft_process_result(str, i, signal));
}
