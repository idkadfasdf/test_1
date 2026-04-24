/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:27:35 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/24 13:53:05 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;

	nb = (long int)n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;	
	}
	if (nb >= 0 && nb <= 9)
	{
		nb = nb + 48;
		write(fd, &(nb), 1);
		return ;
	}
	ft_putnbr_fd(nb / 10, fd);
	ft_putnbr_fd(nb % 10, fd);
}

/*int main()
{
	ft_putnbr_fd(-123123, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(123123, 1);
	
	write(1, "\n", 1);
	ft_putnbr_fd(0, 1);

	write(1, "\n", 1);
}*/
