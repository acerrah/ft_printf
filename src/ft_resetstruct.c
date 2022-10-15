#include "ft_printf.h"

void reset_struck(t_printf *p)
{
	p -> flagstart = 0;
	p -> dec = 0;
	p -> cvalue = 0;
	p -> string = 0;
	p -> unsval = 0;
	p -> xval = 0;
	p -> pval = 0;
}