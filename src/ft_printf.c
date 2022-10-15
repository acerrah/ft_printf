#include "ft_printf.h"
void	del(void *content)
{
	free(content);
}

int ft_printf(const char *str, ...)
{
	va_list pars;
	t_printf specter;
	va_start(pars,str);
	specter.rtn = 0;
	check_arg(str, pars,&specter);
	va_end(pars);
	ft_lstclear(&specter);
	return (specter.rtn);
}