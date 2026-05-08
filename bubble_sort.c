/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 09:31:43 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/05/07 16:13:34 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	one_sort(t_stack **stack, t_bench **b)
{
	t_stack			*top;
	long int		len;
	long int		nb_op;
	long int		i;

	nb_op = 0;
	top = *stack;
	len = ft_lstsize(top) - 1;
	i = 0;
	while (i != len)
	{
		while (*top->data > *(top->next->data) && i != len)
		{
			(*b)->sa_count += sa(&top, (*b)->print);
			(*b)->ra_count += ra(&top, (*b)->print);
			nb_op++;
			i++;
		}
		if (i != len)
		{
			(*b)->ra_count += ra(&top, (*b)->print);
			i++;
		}
	}
	return ((*b)->ra_count += ra(&top, (*b)->print), *stack = top, nb_op);
}

void	bubble_sort(t_stack **stack, t_bench **b)
{
	long int	nb_op;

	nb_op = -1;
	while (nb_op != 0)
		nb_op = one_sort(stack, b);
}

/*#include <time.h>
int main()
{
        t_stack *s;
        int     i;
	
	srand(time(NULL));
        i = 0;
        while (i != 10)
        {
                add_front(&s, new_node(rand()%101, i));
                i++;
        }
        show_list(&s);
        printf("\n\n");
        bubble_sort(&s);

        show_list(&s);
	printf("\n");
}*/
