/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:42:48 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/21 13:51:03 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	while ((size_t)i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
int main()
{
    char *src;
    char *dest;

    src = malloc(10);
    dest = malloc (10);
    for (int i = 0; i < 5; i++)
        src[i] = i;
    ft_memcpy(dest, src, 3 * sizeof(int));
    for (int i = 0; i < 3; i++)
        printf("%d", dest[i]);
}*/