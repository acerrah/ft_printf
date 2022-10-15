
#include "ft_printf_bonus.h"

void    ft_print_char(t_printfb *print)
{
    int i;

	i = 0;
    ft_putchar_fd(print -> dvalue, 1);
	print -> rtn++;
	while (i++ < ((print -> fzero > print ->fnum) ? print -> fzero : print -> fnum) - 1)
	{
		ft_putchar_fd(' ', 1);
		print -> rtn++;
	}
}

void    ft_print_char2(t_printfb *print)
{
    int i;

	i = 0;
	while (i++ < ((print -> fzero > print ->fnum) ? print -> fzero : print -> fnum) - 1)
	{
		if (print -> fzero > print -> fnum)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		print -> rtn++;
	}
	ft_putchar_fd(print -> dvalue, 1);
	print -> rtn++;
}