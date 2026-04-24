/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:43:51 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/23 10:30:20 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main() {

//     int array [] = { 54, 85, 20, 63, 21 };
//     size_t size = sizeof( int ) * 5;
//     int length;

//     /* Display the initial values */
//     for( length=0; length<5; length++) {
//         printf( "%d ", array[ length ] );
//     }
//     printf( "\n" );

//     /* Reset the memory bloc */
//     ft_memset( array, 0, size );

//     /* Display the new values */
//     for( length=0; length<5; length++) {
//         printf( "%d ", array[ length ] );
//     }
//     printf( "\n" ); 
//     return 0;
// }
