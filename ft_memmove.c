/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:43:41 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/21 13:51:26 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	void	*adresse;

	adresse = dest;
	i = 0;
	if (dest <= src)
	{
		while ((size_t)i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
		return (adresse);
	}
	dest += n - 1;
	src += n - 1;
	while ((size_t)i < n)
	{
		*((unsigned char *)dest--) = *((unsigned char *)src--);
		i++;
	}
	return (adresse);
}

/*#include <stdio.h>
int main()
{
	int *src = malloc(10 * sizeof(int));
	int *dest = malloc(10 * sizeof(int));

	for (int i = 0; i < 5; i++)
		src[i] = i;
	ft_memmove(dest, src, 3 * sizeof(int));
	int i = 0;
	while (i < 3)
	{
		printf("%d", dest[i]);
		i++;
	}
}*/
