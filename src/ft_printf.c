#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list pars;
	t_printf specter;
	va_start(pars,str);
	specter.rtn = 0;
	check_arg(str, pars,&specter);
	va_end(pars);
	return (specter.rtn);
}