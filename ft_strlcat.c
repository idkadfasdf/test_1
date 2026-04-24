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
	size_t	v;

	i = ft_strlen(dst);
	u = ft_strlen(src);
	if (size == 0 || size <= i)
		return (u + size);
	v = 0;
	while (src[v] && v < size - i - 1)
	{
		dst[i + v] = src[v];
		v++;
	}
	dst[i + v] = '\0';
	return (i + u);
}
