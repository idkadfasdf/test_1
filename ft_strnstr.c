/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:24:54 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/24 11:20:45 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	u;
	size_t	i;

	if (!little)
		return ((char *)big);
	u = 0;
	while (big[u])
	{
		i = 0;
		while (1)
		{
			if (little[i] == '\0' && little[i - 1] == big[u + i - 1] && i + u - 1 < len)
				return (&((char *)big)[u]);
			if (big[u + i] != little[i] || u + i > len)
			{
				u++;
				break ;
			}
			i++;
		}
	}
	if (ft_strlen(big) == 0 && ft_strlen(little) == 0)
		return ((char *)big);
	return (NULL);
}
