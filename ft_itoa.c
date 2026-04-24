/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:30:14 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/22 17:12:46 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	int	i;
	int	temp;

	i = 0;
	temp = n;
	if (n == 0)
		return (1);
	while (temp != 0)
	{
		temp = temp / 10;
		i++;
	}
	return (i);
}

static char	*alloc(int sign, int i)
{
	char	*str;

	str = malloc(i + 1);
	if (str == NULL)
		return (NULL);
	if (sign == 1)
		str[0] = '-';
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int			sign;
	int			temp;
	char		*str;
	int			i;
	long int	nb;

	nb = (long int)n;
	sign = 0;
	if (nb < 0)
	{
		nb = -nb;
		sign++;
	}
	i = len(nb) + sign;
	str = alloc(sign, i);
	i -= 1;
	while (i != -1 + sign)
	{
		temp = 0;
		while ((nb - temp) % 10 != 0)
			temp++;
		str[i--] = temp + 48;
		nb = nb / 10;
	}
	return (str);
}

/*#include <stdio.h>
int main()
{
	printf("%s\n", ft_itoa(100));
	printf("%s\n", ft_itoa(-100));
	printf("%s\n", ft_itoa(0));
}*/
