/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:09:54 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/24 12:30:13 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	size_t	i;
	void	*point;
	char	*cast;

	if (n == 0 || size == 0)
	{
		point = malloc(1);
		if (point == NULL)
			return (NULL);
		return (point);
	}
	if (n >= 2147483647 || size >= 2147483647)
		return (NULL);
	if (n * size >= 2147483647)
		return (NULL);
	point = malloc(n * size);
	if (point == NULL)
		return (NULL);
	cast = (char *)point;
	i = 0;
	while (i < n * size)
	{
		cast[i] = 0;
		i++;
	}
	return (point);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define INT_NUMBER 10

int main() {

    int i;
    int * pointer = (int *) ft_calloc( INT_NUMBER, sizeof(int) );

    assert( pointer != NULL );

    for ( i=0; i<INT_NUMBER-1; i++ ) {
        pointer[i] = i;
    }


    for (i=0; i<INT_NUMBER; i++ ) {
        printf( "%d ", pointer[i] );
    }
    printf( "\n" );
    free( pointer );

    return 0;
}*/
