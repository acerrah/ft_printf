
#include "ft_printf_bonus.h"

int ft_check(char c, const char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_arg(const char *str, va_list arg, t_printfb *print)
{
	size_t i;
	size_t j;
	char *flag;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == '%')
		{
			i++;
			j = i;
			while (ft_check(*(str + j), "cspdiuxX%") == 1)
				j++;
			flag = ft_substr((str + i), 0, j - i + 1);
			flag_check(print, flag);
			ft_print(arg, print);
			free(flag);
			ft_reset(print);
			i = j;
		}
		else
		{
			ft_putchar_fd(*(str + i),1);
			print -> rtn++;
		}
		i++;
	}	
}