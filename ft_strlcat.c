/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:31:51 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/24 12:20:00 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	u;

	printf("\n");
	if (size <= 0)
		return (ft_strlen(src));
	u = 0;
	i = 0;
	while (dst[i])
		i++;
	while (src[u] && u < size)
	{
		dst[i] = src[u];
		i++;
		u++;
	}
	dst[i] = '\0';
	//printf("%s, %d", src, (int)ft_strlen(src));
	//printf("%d, ", (int)(ft_strlen(src) + u));
	//printf("%d, ", (int)u);
	//printf("%d", (int)ft_strlen(src));
	printf("%c", dst[0]);
	printf("%d", ft_strncmp(dst, "B", 123));
	return (ft_strlen(src) + u);
}
