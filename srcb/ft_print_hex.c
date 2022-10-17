
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
	while (i < (print -> fdot) - print -> hexlen)
	{
		ft_putchar_fd('0', 1);
		i++;
		print -> rtn++;
	}
	if(print -> unsvalue != 0 || print -> fdot != 0 || !print -> fdotdot)
		decimal_to_hexa(print, print -> unsvalue, print -> fdot);
	else if (!(print -> fdot == 0 && print -> dvalue == 0 && print -> fnum == 0 && print -> fzero == 0))
	{
		ft_putchar_fd(' ', 1);
		print -> rtn++;
	}
	while (i + (print -> hexlen) < (print -> int_tmp) - (print -> fconvert ? 2:0))
	{
		ft_putchar_fd(' ', 1);
		i++;
		print -> rtn++;
	}
}

void ft_print_hexa2(t_printfb *print)
{
	int i;

	i = 0;
	if (print -> fzero)
		print -> int_tmp = print -> fzero;
	else if (print -> fnum)
		print -> int_tmp = print -> fnum;
	else 
		print -> int_tmp = 0;
	if((print -> fdot) > (print -> hexlen))
	{
		while (print -> int_tmp > (print -> fdot) + (print -> fconvert ? 2:0))
		{
			ft_putchar_fd(' ', 1);
			print -> rtn++;
			print -> int_tmp--;
		}
		ft_print2(print);
		while (i < (print -> fdot) - (print -> hexlen) - (print -> fconvert ? 2:0))
		{
			ft_putchar_fd('0', 1);
			i++;
			print -> rtn++;
		}
		if(print -> unsvalue != 0 || print -> fdot != 0 || !print -> fdotdot)
			decimal_to_hexa(print, print -> unsvalue, print -> fdot);
	}
	else
	{	
		while (i++ < (print -> int_tmp) - (print -> hexlen) - (print -> fconvert ? 2:0))
		{
			if (print -> fzero && !print -> fdotdot)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			print -> rtn++;
		}
		ft_print2(print);
		if(print -> unsvalue != 0 || print -> fdot != 0 || !print -> fdotdot)
			decimal_to_hexa(print, print -> unsvalue, print -> fdot);
		else if (!(print -> fdot == 0 && print -> dvalue == 0 && print -> fnum == 0 && print -> fzero == 0))
		{
			ft_putchar_fd(' ', 1);
			print -> rtn++;
		}
	}
}
