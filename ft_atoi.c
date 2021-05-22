#include "libft.h"

static void	ft_atoi_initialize(int *i, int *signal, int *has_signal)
{
	*i = 0;
	*signal = 1;
	*has_signal = 0;
}

static void	ft_process_spaces(const char *str, int *i)
{
	while (*(str + *i) == ' ' || *(str + *i) == '\t' || *(str + *i) == '\n'
		|| *(str + *i) == '\v' || *(str + *i) == '\f' || *(str + *i) == '\r')
		(*i)++;
}

static void	ft_process_signal(const char *str, int *i,
		int *signal, int *has_signal)
{	
	if (*(str + *i) == '-')
	{
		*has_signal = 1;
		*signal = -1;
		(*i)++;
	}
	else if (*(str + *i) == '+')
	{
		*has_signal = 1;
		(*i)++;
	}
}

static int	ft_process_result(const char *str, int i,
		int signal, int has_signal)
{
	int	result;

	result = 0;
	if ((has_signal) && (*(str + i) == '-' || *(str + i) == '+'))
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
	int	has_signal;

	ft_atoi_initialize(&i, &signal, &has_signal);
	ft_process_spaces(str, &i);
	ft_process_signal(str, &i, &signal, &has_signal);
	return (ft_process_result(str, i, signal, has_signal));
}
