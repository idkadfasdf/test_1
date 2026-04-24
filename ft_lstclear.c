/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:45:49 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/23 10:44:59 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*test;
	t_list	**end;
	t_list	*temp;

	(void)end;
	end = lst;
	test = *lst;
	if (test == NULL)
		return ;
	while (test -> next != NULL)
	{
		del(test -> content);
		temp = test;
		test = test -> next;
		free(temp);
	}
	end = NULL;
}
