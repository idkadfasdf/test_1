/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:46:22 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/22 14:01:10 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}

/*#include <stdio.h>
int main()
{
	char *test = "asdf";
	t_list *stru = ft_lstnew(test);
	printf("%s\n", (char *)(stru -> content));
	printf("%p\n", (void *)stru -> next);
}*/
