/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoca <akoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 11:40:01 by akoca             #+#    #+#             */
/*   Updated: 2026/05/07 12:00:14 by akoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putaddr_long(long unsigned int nbr, char *base)
{
	unsigned int	baselen;
	int				count;

	count = 0;
	baselen = ft_strlen(base);
	if (nbr >= baselen)
		count += ft_putaddr_long(nbr / baselen, base);
	ft_putchar_s(base[nbr % baselen]);
	count++;
	return (count);
}

int	check_option(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar_s(va_arg(args, int));
	if (c == 's')
		count = ft_putstr_s(va_arg(args, char *));
	if (c == 'p')
		count = ft_put_addr(va_arg(args, void *));
	if (c == 'd')
		count = ft_putnbr_s(va_arg(args, int), DECIMAL);
	if (c == 'i')
		count = ft_putnbr_s(va_arg(args, int), DECIMAL);
	if (c == 'u')
		count = ft_puthexa_uint(va_arg(args, unsigned int), DECIMAL);
	if (c == 'x')
		count = ft_puthexa_uint(va_arg(args, int), LOW_HEXA);
	if (c == 'X')
		count = ft_puthexa_uint(va_arg(args, int), UP_HEXA);
	if (c == '%')
		count = ft_putchar_s('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		slen;

	va_start(args, s);
	i = 0;
	count = 0;
	slen = ft_strlen(s);
	while (s[i])
	{
		if (s[slen - 1] == '%' && s[slen - 2] != '%')
			return (-1);
		else if (s[i] == '%' && s[i + 1])
			count += check_option(s[++i], args);
		else
			count += ft_putchar_s(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}
