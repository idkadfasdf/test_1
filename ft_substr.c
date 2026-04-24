/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:07:57 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/24 13:38:18 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (ft_strlen(s) < start)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	i = 0;
	while (s[i + start] && i < len)
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
