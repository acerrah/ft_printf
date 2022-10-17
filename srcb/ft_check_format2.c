
#include "ft_printf_bonus.h"

void	ft_check_c(va_list arg,t_printfb *print)
{
	print -> dvalue = va_arg(arg, int);
	if (print -> fnegative)
		ft_print_char(print);
	else
		ft_print_char2(print);
}

void	ft_check_s(va_list arg,t_printfb *print)
{
	print -> string = va_arg(arg, char *);
	if (print -> string == NULL)
		print -> string = "(null)";
	print -> slen = ft_strlen(print -> string);
	if (print -> fdotdot && print -> fdot < print -> slen)
		print -> slen = print -> fdot;
	if (print -> fnegative)
		ft_print_string(print);
	else
		ft_print_string2(print);
}

void	ft_check_percent(t_printfb *print)
{
	ft_putchar_fd('%', 1);
	print -> rtn++;
}