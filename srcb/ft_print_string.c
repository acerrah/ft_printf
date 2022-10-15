#include "ft_printf_bonus.h"

void    ft_print_string(t_printfb *print)
{
    int i;

    i = 0;
    while (i < ((print -> fdot < print -> slen) ? (print -> fdot):(print -> slen)))
    {
        ft_putchar_fd(print -> string[i], 1);
        i++;
        print -> rtn++;
    }
    i = 0;
    if (print -> fzero)
        print -> int_tmp = print -> fzero;
    else if (print -> fnum)
        print -> int_tmp = print -> fnum;
    while (i++ < (print -> int_tmp) - ((print -> fdot < print -> slen) ? (print -> fdot):(print -> slen)))
    {
        if (print -> fnum)
            ft_putchar_fd(' ', 1);
        else
            ft_putchar_fd('0', 1);
    }
    print -> rtn += i - 1;
}

void    ft_print_string2(t_printfb *print)
{
    int i;

    i = 0;
    if (print -> fzero)
        print -> int_tmp = print -> fzero;
    else if (print -> fnum)
        print -> int_tmp = print -> fnum;
    while (i++ < (print -> int_tmp) - ((print -> fdot < print -> slen) ? (print -> fdot):(print -> slen)))
    {
        if (print -> fzero)
            ft_putchar_fd('0', 1);
        else
            ft_putchar_fd(' ', 1);
    }
    print -> rtn += i - 1;
    i = 0;
    while (i < ((print -> fdot < print -> slen) ? (print -> fdot):(print -> slen)))
    {
        ft_putchar_fd(print -> string[i], 1);
        i++;
        print -> rtn++;
    }
}
