/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoca <akoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 11:43:17 by akoca             #+#    #+#             */
/*   Updated: 2026/05/07 12:00:30 by akoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_s(char c)
{
	int	count;

	count = 0;
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putstr_s(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		count += 6;
		return (count);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	count = i;
	return (count);
}

int	ft_putnbr_s(int nbr, char *base)
{
	int			baselen;
	int			count;
	long int	nb;

	count = 0;
	nb = (long int) nbr;
	baselen = ft_strlen(base);
	if (nb < 0)
	{
		ft_putchar_s('-');
		count++;
		nb *= -1;
	}
	if (nb >= baselen)
		count += ft_putnbr_s(nb / baselen, base);
	ft_putchar_s(base[nb % baselen]);
	count++;
	return (count);
}

//Takes care of both hexadecimals and unsigned decimals.
//The %x and %X options are treated as uints.
int	ft_puthexa_uint(unsigned int nbr, char *base)
{
	unsigned int	baselen;
	int				count;

	count = 0;
	baselen = ft_strlen(base);
	if (nbr >= baselen)
		count += ft_puthexa_uint(nbr / baselen, base);
	ft_putchar_s(base[nbr % baselen]);
	count++;
	return (count);
}

int	ft_put_addr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count += ft_putstr_s("(nil)");
		return (count);
	}
	count += ft_putstr_s("0x");
	count += ft_putaddr_long((unsigned long)ptr, LOW_HEXA);
	return (count);
}
