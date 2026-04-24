/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 09:55:10 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/24 14:32:50 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

static int	len(char *str, char sep)
{
	int	i;
	int	total;

	total = 0;
	if (!str)
		return (0);
	if (is_sep(str[0], sep) == 0)
		total++;
	i = 1;
	while (str[i])
	{
		if (is_sep(str[i], sep) == 0 && is_sep(str[i - 1], sep) == 1)
			total++;
		i++;
	}
	return (total);
}

static char	*new_str(char *s, char c, int *u)
{
	char	*str;
	int		i;

	i = 0;
	while (is_sep(s[i + *u], c) == 0)
		i++;
	str = malloc(i + 1);
	str[i] = '\0';
	i = 0;
	while (is_sep(s[i + *u], c) == 0)
	{
		str[i] = s[i + *u];
		i++;
	}
	*u += i;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		u;
	int		j;

	j = len((char *)s, c);
	tab = malloc((j + 1) * sizeof(char *));
	tab[j] = NULL;
	i = 0;
	u = 0;
	while (i < j)
	{
		while (is_sep(((char *)s)[u], c) == 1)
			u++;
		tab[i] = new_str((char *)s, c, &u);
		i++;
	}
	return (tab);
}

/*#include <stdio.h>
int main()
{
	char **tab = ft_split("asdf asdf asdf  asdf", ' ');
	int i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
}*/
