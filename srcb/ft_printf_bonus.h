#ifndef FT_PRINTFB_H
#define FT_PRINTFB_H

#include <unistd.h>
#include <stdarg.h>

#include "../libft/libft.h"

typedef enum t_boolean
{
	TRUE = 1,
	FALSE = 0
}		t_bool;

typedef struct t_list
{
	int				int_tmp;
	char			*str_tmp;
	char 			flagstart;
	char			*flag;
	long 			dvalue;
	char 			*string;
	unsigned long	unsvalue;
	unsigned long	pvalue;
	int				p_space_len;
	int				rtn;
	t_bool			fconvert;
	t_bool			fnegative;
	t_bool			fplus;
	int				fzero;
	int				fdot;
	t_bool			fspace;
	char			format;
	int				fnum;
	int				hexlen;
	int				dlen;
	int				ulen;
	int				slen;
	t_bool			fdotdot;
	t_bool			neg;
}					t_printfb;

int ft_printf(const char *str, ...);
void flag_check(t_printfb *print, char *str);
void ft_check_arg(const char *str, va_list arg, t_printfb *print);
int ft_check(char c, const char *str);
void f_conv_neg(t_printfb *print, char *str, int *i);
void	f_plus_zero(t_printfb *print, char *str, int *i);
void	f_dot_space(t_printfb *print, char *str, int *i);
void	f_num(t_printfb *print, char *str, int *i);
void	ft_print(va_list arg, t_printfb *print);
void 	ft_reset(t_printfb *print);
int 	ft_hexa_x_len(unsigned long nb);
int 	ft_decimal_len(long nbr);
int		ft_unsigned_len(unsigned int nb);
void	ft_print2(t_printfb *print);
void	ft_print_dec(t_printfb *print);
void	ft_print_dec2(t_printfb *print);
void	ft_print_hexa(t_printfb *print);
void	ft_print_hexa2(t_printfb *print);
void    decimal_to_hexa(t_printfb *print, unsigned long nb, long i);
void	unsigned_convert(t_printfb *print, unsigned int nb);
void	ft_print_unsigned(t_printfb *print);
void	ft_print_unsigned2(t_printfb *print);
void	ft_print_unsigned3(t_printfb *print, int *i);
void	ft_print_unsigned4(t_printfb *print, int *i);
void	ft_print_string(t_printfb *print);
void	ft_print_string2(t_printfb *print);
void	ft_print_char(t_printfb *print);
void	ft_print_char2(t_printfb *print);


#endif