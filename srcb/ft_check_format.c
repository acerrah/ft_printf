
#include "ft_printf_bonus.h"

void	ft_check_d(va_list arg,t_printfb *print)
{
	print -> dvalue = va_arg(arg, int);
	if (print -> dvalue < 0)
	{	
		print -> dvalue *= -1;
		print -> neg = TRUE;
		print -> fplus = FALSE;
		print -> fspace = FALSE;
	}
	print -> dlen = ft_decimal_len(print -> dvalue);
	if (print -> fnegative)
		ft_print_dec(print);
	else
		ft_print_dec2(print);
}

void	ft_check_x(va_list arg,t_printfb *print)
{
	print -> unsvalue = va_arg(arg, unsigned int);
	if (print -> unsvalue == 0)
		print -> fconvert = FALSE;
	print -> hexlen = ft_hex_x_len(print -> unsvalue);
	if (print -> fdot == 0 && print -> unsvalue == 0)
		print -> fdot = 0;
	else if (print -> fdot < print -> hexlen)
		print -> fdot = print -> hexlen;
	if (print -> fnegative)
		ft_print_hexa(print);
	else
		ft_print_hexa2(print);
}

void	ft_check_p(va_list arg,t_printfb *print)
{
	print -> fconvert = TRUE;
	print -> format += 8;
	print -> unsvalue = va_arg(arg, unsigned long);
	print -> hexlen = ft_hex_x_len(print -> unsvalue);
	if (print -> fnegative)
		ft_print_hexa(print);
	else
		ft_print_hexa2(print);
}

void	ft_check_u(va_list arg,t_printfb *print)
{
	print -> unsvalue = va_arg(arg, unsigned int);
	if (print -> unsvalue == 0)
		print -> fconvert = FALSE;
	print -> ulen = ft_unsigned_len(print -> unsvalue);
	if (print -> fdot == 0 && print -> unsvalue == 0)
		print -> fdot = 0;
	else if (print -> fdot < print -> ulen)
		print -> fdot = print -> ulen;
	if (print -> fnegative)
		ft_print_unsigned(print);
	else
		ft_print_unsigned2(print);
}