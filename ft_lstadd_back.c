/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:36:57 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/22 15:23:31 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	last -> next = new;
}

/*#include <stdio.h>
int main()
{

	t_list *four = malloc(sizeof(t_list));
	four -> content = "4";
	four -> next = NULL;
	t_list *one = malloc(sizeof(t_list));
	t_list *two = malloc(sizeof(t_list));
	t_list *three = malloc(sizeof(t_list));
	one -> next = two;
	two -> next = three;
	three -> next = NULL;
	two -> content = "2";
	one -> content = "1";
	three -> content = "3";
	ft_lstadd_back(&one, four);
	printf("%s\n", (char *)ft_lstlast(one) -> content);
}*/
