/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:02:23 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/23 16:29:30 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	(void)last;	
	last = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			last = &((char *)s)[i];
		i++;
	}
	if (c == 0)
		return (&((char *)s)[i]);
	return (last);
}

/*#include <stdio.h>
int main()
{
	char *point;
	char str[10] = "aBsdfBaB1";
	str[9] = '\0';
	point = ft_strrchr(str, 'B');
	int i = 0;
	while (point[i])
	{
		printf("%c", point[i]);
		i++;
	}
}*/
