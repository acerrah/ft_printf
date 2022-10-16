
#include "ft_printf_bonus.h"

int ft_decimal_len(long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	if(nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while(nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int ft_unsigned_len(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if(nb < 0)
	{
		nb *= -1;
		i++;
	}
	while(nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int ft_hexa_x_len(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if(nb < 0)
	{
		nb *= -1;
		i++;
	}
	while(nb > 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}