/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 12:44:20 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/23 14:43:56 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] !=
			((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] -
				((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

/*#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
int main() {

    int array1 [] = { 54, 85, 20, 63, 21 };
    int array2 [] = { 54, 85, 19, 63, 21 };
    size_t size = sizeof( int ) * 5;

    assert( memcmp( array1, array2, size) ==
    	ft_memcmp( array1, array2, size) );       
    assert( memcmp( array1, array1, size) ==
    	ft_memcmp( array1, array1, size) );       
    assert( memcmp( array2, array1, size) ==
    	ft_memcmp( array2, array1, size) );       
    
    printf( "Test is ok\n" );
    
    return 0;
}*/
