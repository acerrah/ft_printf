#include "ft_printf_bonus.h"

int	check(char a, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (a == set[i])
			return (1);
		i++;
	}
	return (0);
}

void flag_check(t_printfb *print, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		f_conv_neg(print, str, &i);
		f_plus_zero(print, str, &i);
		f_dot_space(print, str, &i);
		f_num(print, str, &i);
		if (check(*(str + i), "cspdiuxX%"))
			print -> format = *(str + i);
		i += check(*(str + i), "cspdiuxX%");
	}
}
