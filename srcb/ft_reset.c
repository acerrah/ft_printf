
#include "ft_printf_bonus.h"

void ft_reset(t_printfb *print)
{
	print -> int_tmp = 0;
	print -> flag = 0;
	print -> dvalue = 0;
	print -> string = 0;
	print -> unsvalue = 0;
	print -> fconvert = 0;
	print -> fnegative = 0;
	print -> fplus = 0;
	print -> fzero = 0;
	print -> fdot = 0;
	print -> fspace = 0;
	print -> format = 0;
	print -> fnum = 0;
	print -> fdotdot = 0;
	print -> neg = 0;
	print -> hexlen = 0;
	print -> dlen = 0;
	print -> ulen = 0;
	print -> slen = 0;
}	