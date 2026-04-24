/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:35:56 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/20 15:39:33 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

// #include <stdio.h>
// int main()
// {
//     printf("a: %d\n", ft_isalpha('a'));
//     printf("A: %d\n", ft_isalpha('A'));
//     printf("g: %d\n", ft_isalpha('g'));
//     printf(":: %d\n", ft_isalpha(':'));
//     printf("7: %d\n", ft_isalpha('7'));
// }
