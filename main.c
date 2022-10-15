#include "srcb/ft_printf_bonus.h"
#include <stdio.h>
int main()
{
    char *s = 0;
//ft_printf("b%06u\n", 1234);
ft_printf("b%05.4c\n", 'a');
printf("r%05.4c", 'a');
/*
ft_printf("%-010.5d\n", 123);
printf("%-010.5d\n", 123);
ft_printf("%+010.5d\n", 123);
printf("%+010.5d\n", 123);*/
}
//cspdiuxX%