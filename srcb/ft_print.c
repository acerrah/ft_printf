
#include "ft_printf_bonus.h"

void	ft_print(va_list arg,t_printfb *print)
{
	if(print -> format == 'd' || print -> format == 'i')
		ft_check_d(arg, print);
	else if(print -> format == 'c')
		ft_check_c(arg, print);
	else if(print -> format == 's')
		ft_check_s(arg, print);
	else if(print -> format == 'p')
		ft_check_p(arg, print);
	else if(print -> format == 'u')
		ft_check_u(arg, print);
	else if(print -> format == 'x' || print -> format == 'X')
		ft_check_x(arg, print);
	else if(print -> format == '%')
		ft_check_percent(print);
}

void ft_print2( t_printfb *print)
{

	if (print -> fconvert == TRUE)
	{
		if (print -> format == 'x')
			ft_putstr_fd("0x", 1);
		else
			ft_putstr_fd("0X", 1);
		print -> rtn += 2;
	}
	else if ((print -> fplus == TRUE || print -> fspace == TRUE) && (print -> format == 'd' || print -> format == 'i'))
	{
		if (print -> dvalue >= 0)
		{
			if (print -> fplus == TRUE)
				ft_putstr_fd("+", 1);
			else
				ft_putstr_fd(" ", 1);
			print -> rtn++;
		}
	}
}