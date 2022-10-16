
#include "ft_printf_bonus.h"

void    ft_putunsigned(unsigned int n, int fd, t_printfb *print)
{
	if (n >= 10)
	{
		ft_putunsigned(n / 10, fd, print);
		ft_putunsigned(n % 10, fd, print);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
		print -> rtn++;
	}
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
	while (i < (print -> fdot) - print -> ulen)
	{
		ft_putchar_fd('0', 1);
		i++;
		print -> rtn++;
	}
	if(print -> unsvalue != 0 || print -> fdot != 0 || !print -> fdotdot)
		ft_putunsigned(print -> unsvalue, 1, print);
	while (i + print -> ulen < print -> int_tmp - (int)(print -> fplus))
	{
		ft_putchar_fd(' ', 1);
		i++;
		print -> rtn++;
	}
}

void ft_print_unsigned2(t_printfb *print)
{
	int i;

	i = 0;
	if (print -> fzero)
		print -> int_tmp = print -> fzero;
	else if (print -> fnum)
		print -> int_tmp = print -> fnum;
	if(print -> fdot > print -> ulen)
		ft_print_unsigned3(print, &i);
	else
		ft_print_unsigned4(print, &i);
}

void ft_print_unsigned3(t_printfb *print, int *i)
{	
	if (print -> fdot)
		ft_print2(print);
	while ((*i)++ < (print -> fdot) - (int)(print -> fplus) - print -> ulen)
	{
			ft_putchar_fd('0', 1);
			print -> rtn++;
	}
	if(print -> unsvalue != 0 || print -> fdot != 0 || !print -> fdotdot)
		ft_putunsigned(print ->unsvalue, 1, print);
}

void ft_print_unsigned4(t_printfb *print, int *i)
{
	if (!print -> fdot)
		ft_print2(print);
	while ((*i)++ < (print -> int_tmp) - (print -> ulen) - (int)(print -> fplus))
	{
		ft_putchar_fd(' ', 1);
		print -> rtn++;
	}
	if (print -> fdot)
		ft_print2(print);
	if(print -> unsvalue != 0 || print -> fdot != 0 || !print -> fdotdot)
		ft_putunsigned(print -> unsvalue, 1, print);
}