#include "ft_printf.h"

void	check_arg(const char *str, va_list pars,t_printf *prnt)
{
	size_t i;

	i = 0;
	while(*(str + i))
	{
		if(*(str + i) == '%')
		{
			i++;
			prnt -> flagstart = *(str + i);
			check_one(pars, prnt);
			reset_struck(prnt);
		}
		else
		{
			ft_putchar_fd(*(str + i),1);
			prnt -> rtn++;
		}
		i++;
	}
}