
#include "ft_printf_bonus.h"

void	ft_print_dec(t_printfb *print)
{
	int i;

	i = 0;
	if (print -> fzero)
		print -> int_tmp = print -> fzero;
	else if (print -> fnum)
		print -> int_tmp = print -> fnum;
	ft_print2(print);
	if (print -> neg == TRUE)
	{
		ft_putchar_fd('-', 1);
		print -> rtn++;
	}
	while (i < (print -> fdot) - print -> dlen - (int)(print -> neg))
	{
		ft_putchar_fd('0', 1);
		i++;
		print -> rtn++;
	}
	if(print -> dvalue != 0 || print -> fdot != 0 || !print -> fdotdot)
	{
		ft_putnbr_fd(print -> dvalue, 1);
		print -> rtn += print -> dlen;
	}
	while (i + print -> dlen < print -> int_tmp - (int)(print -> fplus) - (int)(print -> neg))
	{
		ft_putchar_fd(' ', 1);
		i++;
		print -> rtn++;
	}
}

void ft_print_dec2(t_printfb *print)
{
	int i;

	i = 0;
	if (print -> fzero)
		print -> int_tmp = print -> fzero;
	else if (print -> fnum)
		print -> int_tmp = print -> fnum;
	if(print -> fdot > print -> dlen)
	{
		if (print -> neg)
		{
			ft_putchar_fd('-', 1);
			print -> rtn++;
		}
		while (i++ < (print -> fdot) - (int)(print -> fplus) - print -> dlen)
		{
				ft_putchar_fd('0', 1);
				print -> rtn++;
		}
		ft_print2(print);
		if(print -> dvalue != 0 || print -> fdot != 0 || !print -> fdotdot)
		{
			ft_putnbr_fd(print -> dvalue, 1);
			print -> rtn += print -> dlen;
		}
	}
	else
	{
		while (i++ < (print -> int_tmp) - (print -> dlen) - (int)(print -> fplus) - (int)(print -> neg))
		{
			ft_putchar_fd(' ', 1);
			print -> rtn++;
		}
		if (print -> neg)
		{
			ft_putchar_fd('-', 1);
			print -> rtn++;
		}
		ft_print2(print);
		if(print -> dvalue != 0 || print -> fdot != 0 || !print -> fdotdot)
		{
			ft_putnbr_fd(print -> dvalue, 1);
			print -> rtn += print -> dlen;
		}
	}
}
