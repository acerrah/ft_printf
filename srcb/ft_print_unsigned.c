
#include "ft_printf_bonus.h"

void    ft_putunsigned(unsigned int n, int fd)
{
    if (n >= 10)
        ft_putunsigned(n / 10, fd);
    ft_putchar_fd(n % 10 + '0', fd);
}

void	ft_print_unsigned(t_printfb *print)
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
	}
	if(print -> unsvalue != 0 || print -> fdot != 0)
		ft_putunsigned(print -> unsvalue, 1);
	while (i + print -> hexlen < print -> int_tmp - (int)(print -> fplus))
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	print -> rtn += i + print -> hexlen;
}

void ft_print_unsigned2(t_printfb *print)
{
	int i;

	i = 0;
	if (print -> fzero)
		print -> int_tmp = print -> fzero;
	else if (print -> fnum)
		print -> int_tmp = print -> fnum;
	if(print -> fdot > print -> hexlen)
		ft_print_unsigned3(print, &i);
	else
		ft_print_unsigned4(print, &i);
	print -> rtn += i + print -> hexlen;
}

void ft_print_unsigned3(t_printfb *print, int *i)
{
	while ((*i)++ < (print -> int_tmp) - (print -> fdot) - (int)(print -> fplus))
	{
		if (print -> fdot)
			ft_putchar_fd(' ', 1);
		else
			ft_putchar_fd('0', 1);
	}
	ft_print2(print);
	while (print -> hexlen < print -> fdot--)
		ft_putchar_fd('0', 1);
	if(print -> unsvalue != 0 || print -> fdot != 0)
		ft_putunsigned(print ->unsvalue, 1);
}

void ft_print_unsigned4(t_printfb *print, int *i)
{
	while ((*i)++ < (print -> int_tmp) - (print -> hexlen) - (int)(print -> fplus))
	{
		if (print -> fdot)
			ft_putchar_fd(' ', 1);
		else
			ft_putchar_fd('0', 1);
	}
	ft_print2(print);
	if(print -> unsvalue != 0 || print -> fdot != 0)
		ft_putunsigned(print -> unsvalue,1);
}