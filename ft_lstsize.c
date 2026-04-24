/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:08:51 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/22 14:31:19 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (lst == NULL)
		return (0);
	i = 1;
	while (lst -> next != NULL)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

/*#include <stdio.h>
int main()
{
	t_list *one = malloc(sizeof(t_list));
	t_list *two = malloc(sizeof(t_list));
	t_list *three = malloc(sizeof(t_list));
	one -> next = two;
	two -> next = three;
	three -> next = NULL;
	printf("%d\n", ft_lstsize(one));
}*/
