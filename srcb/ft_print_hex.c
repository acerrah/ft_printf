
#include "ft_printf_bonus.h"

void	ft_print_hexa(t_printfb *print)
{
	int i;

	i = 0;
	if (print -> fzero)
		print -> int_tmp = print -> fzero;
	else if (print -> fnum)
		print -> int_tmp = print -> fnum;
	ft_print2(print);
	while (i < (print -> fdot) - (print -> hexlen))
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	if(print -> unsvalue != 0 || print -> fdot != 0)
		decimal_to_hexa(print, print -> unsvalue);
	while (i + (print -> hexlen) < (print -> int_tmp) - (print -> fconvert ? 2:0))
	{
		if (print -> fdot)
			ft_putchar_fd(' ', 1);
		else
			ft_putchar_fd('0', 1);
		i++;
	}
	print -> rtn += i + print -> hexlen;
}

void ft_print_hexa2(t_printfb *print)
{
	int i;

	i = 0;
	if (print -> fzero)
		print -> int_tmp = print -> fzero;
	else if (print -> fnum)
		print -> int_tmp = print -> fnum;
	if((print -> fdot) > (print -> hexlen))
	{
		if (!print -> fdot)
			ft_print2(print);
		while (i++ < (print -> int_tmp) - (print -> fdot) - (print -> fconvert ? 2:0))
		{
			if (print -> fdot)
				ft_putchar_fd(' ', 1);
			else
				ft_putchar_fd('0', 1);
		}
		if (print -> fdot)
			ft_print2(print);
		while (print -> hexlen < print -> fdot--)
			ft_putchar_fd('0', 1);
		if(print -> unsvalue != 0 || print -> fdot != 0)
			decimal_to_hexa(print, print -> unsvalue);
	}
	else
	{
		if (!print -> fdot)
			ft_print2(print);
		while (i++ < (print -> int_tmp) - (print -> hexlen) - (print -> fconvert ? 2:0))
		{
			if (print -> fdot)
				ft_putchar_fd(' ', 1);
			else
				ft_putchar_fd('0', 1);
		}
		if (print -> fdot)
			ft_print2(print);
		if(print -> unsvalue != 0 || print -> fdot != 0)
			decimal_to_hexa(print, print -> unsvalue);
	}
	print -> rtn += i + print -> hexlen;
}
