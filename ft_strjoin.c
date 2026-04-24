/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:22:38 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/23 14:59:45 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		u;

	i = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = malloc(i + 1);
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	i = 0;
	while (((char *)s1)[i])
	{
		str[i] = ((char *)s1)[i];
		i++;
	}
	u = 0;
	while (((char *)s2)[u])
	{
		str[i + u] = ((char *)s2)[u];
		u++;
	}
	return (str);
}

/*#include <stdio.h>
int main()
{
	char *str = ft_strjoin("asdf", "2345");
	int i = 0;
	while (str[i])
	{
		printf("%c", str[i]);
		i++;
	}
	free(str);
}*/
