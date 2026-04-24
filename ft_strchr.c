/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:12:16 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/23 16:33:24 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] != (char)c)
			i++;
		else
			return (&((char *)s)[i]);
	}
	if (c == 0)
		return (&((char *)s)[i]);
	return (NULL);
}

/*#include <stdio.h>
int main()
{
	char *point;
	char str[10] = "asdfBasdf";
	str[9] = '\0';
	point = ft_strchr(str, 'B');
	int i = 0;
	while (point[i])
	{
		printf("%c", point[i]);
		i++;
	}
}*/
