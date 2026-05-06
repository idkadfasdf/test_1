/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:09:06 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/05/06 16:20:11 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mk_stack(t_stack **b_stack, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		add_front(b_stack, new_node(i, i));
		i++;
	}
}

void	get_range(int *min, int *max, t_stack *stack)
{
	int	i;
	int	len;

	if (!stack)
	{
		min = 0;
		max = 0;
		return ;
	}
	*min = *stack->data;
	*max = *stack->data;
	len = ft_lstsize(stack);
	i = 0;
	while (i < len)
        {
                if (*stack->data < *min)
		       *min = *stack->data;
                if (*stack->data > *max)
                        *max = *stack->data;
		i++;
                rotate(&stack);
        }	
}

void	bucket_sort(t_stack **a_stack, t_stack **b_stack)
{
	int		len;
	int		range[2];
	t_stack	*sorted;

	if (!*a_stack)
		return ;
	len = ft_lstsize(*a_stack);
	get_range(&range[0], &range[1], *a_stack);
	if (ft_lstsize(*a_stack) == 1 || range[0] == range[1])
		return ;
	mk_stack(b_stack, len);
	while (*a_stack)
	{
		while (*(*b_stack)->index != ((*(*a_stack)->data - range[0]) * (len - 1)) / (range[1] - range[0]))
			rotate(b_stack);
		push_top(&(*b_stack)->lst, a_stack);
	}
	while (*(*b_stack)->index != ft_lstsize(*b_stack) - 1)
		rotate(b_stack);
	range[0] = 0;
	while (range[0]++ != len)
	{
		sorted = NULL;
		//get_range(&range[0], &range[1], (*b_stack)->lst);
		if (ft_lstsize((*b_stack)->lst) > 1/* && range[0] != range[1]*/)
			bucket_sort(&(*b_stack)->lst, &sorted);
		while ((*b_stack)->lst)
		{
			rotate(&(*b_stack)->lst);
			push_top(a_stack, &(*b_stack)->lst);
		}
		rotate(b_stack);
	}
}

#include <time.h>
	int main()
{
        t_stack *a;
	t_stack	*b;
        int     i;

	a = NULL;
	b = NULL;
	srand(time(NULL));
        i = 0;
        while (i != 10)
        {
                add_front(&a, new_node(rand()%101, i));
                i++;
        }
        show_list(&a);
        printf("\n\n");
        bucket_sort(&a, &b);

        show_list(&a);
	printf("\n");
}
