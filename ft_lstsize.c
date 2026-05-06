/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoca <akoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:27:47 by akoca             #+#    #+#             */
/*   Updated: 2026/05/05 11:28:51 by akoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
