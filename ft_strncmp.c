/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 12:23:36 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/24 11:39:03 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] < 0 && s2[i] < 0)
				return (s1[i] - s2[i]);
			if (s1[i] < 0 || s2[i] < 0)
				return (s2[i] - s1[i]);
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/*#include <stdio.h>
int main()
{
	printf("%d\n", ft_strncmp("aaab", "aaab", 5));
	printf("%d\n", ft_strncmp("baaa", "aaab", 1));
	printf("%d\n", ft_strncmp("aaa", "aaab", 5));
	printf("%d\n", ft_strncmp("aaxab", "aaab", 5));
}*/
