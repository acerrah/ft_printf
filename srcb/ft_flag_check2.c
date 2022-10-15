
#include "ft_printf_bonus.h"

void f_conv_neg(t_printfb *print, char *str, int *i)
{
	if (str[*i] == '#')
	{
			print -> fconvert = TRUE;
			if(str[ft_strlen(str) - 1] != 'x' && str[ft_strlen(str) - 1] != 'X' )
				print -> fconvert = FALSE;
			(*i)++;
	}

	if (str[*i] == '-')
		{
			(*i)++;
			print -> fnegative = TRUE;
		}
}

void	f_plus_zero(t_printfb *print, char *str, int *i)
{
	if (str[*i] == '+')
	{
		print -> fplus = TRUE;
		(*i)++;
	}

	if (str[*i] == '0')
	{
		(*i)++;
		print -> int_tmp = *i;
		while (str[*i] <= '9' && str[*i] >= '0')
			(*i)++;
		print -> str_tmp = ft_substr(str, print -> int_tmp, *i - print -> int_tmp);
		print -> fzero = ft_atoi(print -> str_tmp);
		free(print -> str_tmp);
	}
}

void f_dot_space(t_printfb *print, char *str, int *i)
{
	if (str[*i] == '.')
	{		
		(*i)++;
		print -> int_tmp = *i;
		while (str[*i] <= '9' && str[*i] >= '0')
			(*i)++;
		print -> str_tmp = ft_substr(str, print -> int_tmp, *i - print -> int_tmp);
		print -> fdot = ft_atoi(print -> str_tmp);
		free(print -> str_tmp);
	}

	if(str[*i] == ' ')
	{
		print -> fspace = TRUE;
		(*i)++;
	}
}

void f_num(t_printfb *print, char *str, int *i)
{
	if (str[*i] <= '9' && str[*i] >= '0')
	{
		print -> int_tmp = *i;
		while (str[*i] <= '9' && str[*i] >= '0')
			(*i)++;
		print -> str_tmp = ft_substr(str, print -> int_tmp, *i - print -> int_tmp);
		print -> fnum = ft_atoi(print -> str_tmp);
		free(print -> str_tmp);
	}
}