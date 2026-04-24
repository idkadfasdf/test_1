/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:01:38 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/22 14:23:13 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

/*#include <stdio.h>
int main()
{
	t_list *list;
	t_list *new;
	list = malloc(sizeof(t_list));
	new = malloc(sizeof(t_list));
	list -> content = "asdf";
	new -> content = "fdsa";

	printf("%s\n", (char *)list -> content);
	ft_lstadd_front(&list, new);
	printf("%s\n", (char *)list -> content);
}*/
