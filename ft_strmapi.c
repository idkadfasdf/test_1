/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:17:59 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/22 11:34:12 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static char	ft_toupper(unsigned int i, char c)
{
	if (i >= 0)
		return (c - 32);
	return (0);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new;

	i = 0;
	while (s[i])
		i++;
	new = malloc(i + 1);
	if (new == NULL)
		return (NULL);
	new[i] = '\0';
	i = 0;
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	return (new);
}

/*#include <stdio.h>
int main()
{
	printf("%s\n", ft_strmapi("asdfasdf", ft_toupper));
}*/
