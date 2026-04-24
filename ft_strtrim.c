/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 09:40:48 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/24 14:23:49 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}
#include <string.h>
char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		u;

	i = 0;
	while (is_sep(((char *)s1)[i], (char *)set) == 1)
		i++;
	u = 0;
	while (((char *)s1)[u])
		u++;
	u--;
	while (is_sep(((char *)s1)[u], (char *)set) == 1)
		u--;
	return (NULL);
}

/*#include <stdio.h>
int main()
{
	char *str = ft_strtrim("helloaahello", "ab");
	int i = 0;
	while (str[i])
	{
		printf("%c", str[i]);
		i++;
	}
}*/
