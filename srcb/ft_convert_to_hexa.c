
#include "ft_printf_bonus.h"

void    decimal_to_hexa(t_printfb *print, unsigned long nb, long i)
{
	char			*base1 = "0123456789abcdef";
	char			*base2 = "0123456789ABCDEF";
	if(print -> format == 'x')
	{
		if(nb >= 16 && (i > 0 || !print -> fdotdot))
		{
			i--;
			decimal_to_hexa(print, nb / 16, i);
		}
		ft_putchar_fd(base1[nb % 16], 1);
		print -> rtn++;
	}
	if(print -> format == 'X')
	{
		if(nb >= 16 && (i > 0 || !print -> fdotdot))
		{
			i--;
			decimal_to_hexa(print, nb / 16, i);
		}
		ft_putchar_fd(base2[nb % 16], 1);
		print -> rtn++;
	}
}

void	unsigned_convert(t_printfb *print, unsigned int nb)
{
	char *base = "0123456789";
	if(print -> format == 'u')
	{
		if(nb >= 10)
		{
			unsigned_convert(print, nb / 10);
		}
		ft_putchar_fd(base[nb % 10], 1);
		print -> rtn++;
	}
}