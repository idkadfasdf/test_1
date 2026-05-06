/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 09:31:43 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/05/05 15:33:48 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	one_sort(t_stack **stack)
{
	t_stack	*top;
	int		len;
	int		nb_op;
	int		i;

	nb_op = 0;
	top = *stack;
	len = ft_lstsize(top) - 1;
	i = 0;
	while (i != len)
	{
		while (*top->data > *(top->next->data) && i != len)
		{
			swap_top(&top);
			rotate(&top);
			nb_op++;
			i++;
		}
		if (i != len)
		{
			rotate(&top);
			i++;
		}
	}
	return (rotate(&top), *stack = top, nb_op);
}

void	bubble_sort(t_stack **stack)
{
	int	nb_op;

	nb_op = -1;
	while (nb_op != 0)
		nb_op = one_sort(stack);
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
