
#include "ft_printf_bonus.h"

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

void	ft_print(va_list arg,t_printfb *print)
{
	if(print -> format == 'd' || print -> format == 'i')
	{
		print -> dvalue = va_arg(arg, int);
		print -> dlen = ft_decimal_len(print -> dvalue);
		if (print -> fnegative)
			ft_print_dec(print);
		else
			ft_print_dec2(print);
	}
	else if(print -> format == 'x' || print -> format == 'X')
	{
		print -> unsvalue = va_arg(arg, unsigned int);
		print -> hexlen = ft_hexa_x_len(print -> unsvalue);
		if (print -> fnegative)
			ft_print_hexa(print);
		else
			ft_print_hexa2(print);
	}
	else if(print -> format == 'p')
	{
		print -> fconvert = TRUE;
		print -> format = 'x';
		print -> pvalue = va_arg(arg, unsigned long);
		print -> hexlen = ft_hexa_x_len(print -> unsvalue);
		if (print -> fnegative)
			ft_print_hexap(print);
		else
			ft_print_hexap2(print);
	}
	else if(print -> format == 'u')
	{
		print -> fplus = FALSE;
		print -> fspace = FALSE;
		print -> unsvalue = va_arg(arg, unsigned int);
		print -> hexlen = ft_unsigned_len(print -> unsvalue);
		if (print -> fnegative)
			ft_print_unsigned(print);
		else
			ft_print_unsigned2(print);		
	}
	else if(print -> format == 's')
	{
		if (print -> fnum > 0)
			print -> int_tmp = print -> fnum;
		else if (print -> fzero > 0)
			print -> int_tmp = print -> fzero;
		print -> str_tmp = va_arg(arg, char *);
		if (print -> str_tmp == NULL)
			print -> str_tmp = "(null)";
		if (print -> int_tmp < (int)ft_strlen(print -> str_tmp))
			print -> str_tmp = ft_substr(print -> str_tmp, 0, print -> int_tmp);
		else
		{
			print -> int_tmp = print -> int_tmp - ft_strlen(print -> str_tmp);
			print -> rtn += print -> int_tmp;
			while (print -> int_tmp--)
				ft_putchar_fd(' ', 1);
		}
		print -> rtn += ft_strlen(print -> str_tmp);
		ft_putstr_fd(print -> str_tmp, 1);
	}
	else if(print -> format == 'c')
	{
		print -> int_tmp = va_arg(arg, int);
		ft_putchar_fd(print -> int_tmp, 1);
		print -> rtn++;
	}
}