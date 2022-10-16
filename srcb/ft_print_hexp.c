
#include "ft_printf_bonus.h"

void	ft_print_hexap(t_printfb *print)
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
		print -> rtn++;
	}
	if(print -> pvalue != 0 || print -> fdot != 0 || print -> fdotdot == FALSE)
		decimal_to_hexa(print, print -> pvalue);
	print -> rtn += print -> hexlen;
	while (i + (print -> hexlen) < (print -> int_tmp) - (print -> fconvert ? 2:0))
	{
		ft_putchar_fd(' ', 1);
		i++;
		print -> rtn++;
	}
}

void ft_print_hexap2(t_printfb *print)
{
	int i;

	i = 0;
	if (print -> fzero)
		print -> int_tmp = print -> fzero;
	else if (print -> fnum)
		print -> int_tmp = print -> fnum;
	if((print -> fdot) > (print -> hexlen))
	{
		while (i < (print -> int_tmp) - (print -> fdot) - (print -> fconvert ? 2:0))
		{
			ft_putchar_fd(' ', 1);
			i++;
			print -> rtn++;
		}
		ft_print2(print);
		while (print -> hexlen < print -> fdot--)
			{
				ft_putchar_fd('0', 1);
				print -> rtn++;
			}
		if(print -> pvalue != 0 || print -> fdot != 0 || print -> fdotdot == FALSE)
			decimal_to_hexap(print, print -> pvalue);
		
	}
	else
	{		
		while (i < (print -> int_tmp) - (print -> hexlen) - (print -> fconvert ? 2:0))
		{
			ft_putchar_fd(' ', 1);
			i++;
			print -> rtn++;
		}
		ft_print2(print);
		if(print -> pvalue != 0 || print -> fdot != 0 || print -> fdotdot == FALSE)
			decimal_to_hexap(print, print -> pvalue);
	}
}
