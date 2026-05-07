/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoca <akoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:12:31 by akoca             #+#    #+#             */
/*   Updated: 2026/05/07 14:48:21 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	disorder_metric(t_stack *stack)
{
	float	mistakes;
	float	total_pairs;
	int		lstsize;

	lstsize = ft_lstsize(stack);
	if (lstsize <= 1)
		return (0);
	total_pairs = lstsize - 1;
	mistakes = 0;
	printf("Mistakes: ");
	while (stack->next)
	{
		if (*(stack->data) > *(stack->next->data))
		{
			mistakes++;
		}
		stack = stack->next;
	}
	return (mistakes / total_pairs);
}
/*
int main()
{
	t_stack	*a;
	int	i;

	i = 10;
	while (i > 0)
	{
		add_front(&a, new_node(i, i));
		i--;
	}
	add_front(&a, new_node(10, 11));
	add_front(&a, new_node(17, 12));
	add_front(&a, new_node(80, 13));
	add_front(&a, new_node(0, 14));
	show_list(&a);
	printf("\n");
	printf("%d\n", ft_lstsize(a));
	printf("%f\n", disorder_metric(a));
	//rotate(&s);
}*/
