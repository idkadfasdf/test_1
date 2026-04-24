/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:59:59 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/23 10:30:49 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char) '\0';
		i++;
	}
}

/*#include <stdio.h>
int main()
{
    int array [] = { 54, 85, 20, 63, 21 };
    for (int i = 0; i < 5; i++)
        printf("%d ", array[i]);
    printf("\n");
    ft_bzero(array, 3 * sizeof(int));
    for (int i = 0; i < 5; i++)
        printf("%d ", array[i]);
}*/
