/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:09:06 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/05/07 17:00:15 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	mk_stack(t_stack **b_stack, long int len)
{
	long int	i;

	i = 0;
	while (i < len)
	{
		add_front(b_stack, new_node(i, i));
		i++;
	}
}

void	get_range(long int *min, long int *max, t_stack *stack)
{
	if (!stack)
	{
		*min = 0;
		*max = 0;
		return ;
	}
	*min = *stack->data;
	*max = *stack->data;
	while (stack)
	{
		if (*stack->data < *min)
			*min = *stack->data;
		if (*stack->data > *max)
			*max = *stack->data;
		stack = stack->next;
	}
}

void	final_list(t_stack **a_stack, t_stack **b_stack,
	long int len, t_bench **b)
{
	long int	i;
	long int	min;
	long int	max;

	i = 0;
	while (i++ != len)
	{
		get_range(&min, &max, (*b_stack)->lst);
		if (ft_lstsize((*b_stack)->lst) > 1 && min != max)
			bucket_sort(&(*b_stack)->lst, b);
		while ((*b_stack)->lst)
		{
			(*b)->rrb_count += rrb(&(*b_stack)->lst);
			(*b)->pa_count += pa(a_stack, &(*b_stack)->lst, (*b)->print);
		}
		(*b)->rb_count += rb(b_stack, (*b)->print);
	}
	exit_protocol(b_stack, b);
}

void	bucket_sort(t_stack **a_stack, t_bench **b)
{
	long int	len;
	long int	range[3];
	t_stack		*b_stack;

	if (!*a_stack)
		return ;
	len = ft_lstsize(*a_stack);
	get_range(&range[0], &range[1], *a_stack);
	if (ft_lstsize(*a_stack) == 1 || range[0] == range[1])
		return ;
	b_stack = NULL;
	mk_stack(&b_stack, len);
	while (*a_stack)
	{
		while ((long int)*b_stack->index != ((*(*a_stack)->data - range[0])
				* (len - 1)) / (range[1] - range[0]))
			(*b)->rb_count += rb(&b_stack, (*b)->print);
		(*b)->pb_count += pb(&b_stack->lst, a_stack, (*b)->print);
	}
	while (*b_stack->index != ft_lstsize(b_stack) - 1)
		(*b)->rb_count += rb(&b_stack, (*b)->print);
	final_list(a_stack, &b_stack, len, b);
}

/*#include <time.h>
int main()
{
        t_stack	*a;
	int		i;
	t_bench *bench;

	a = NULL;
	srand(time(NULL));
        i = 0;
        while (i != 100000)
        {
		if (i % 2 == 0)
                	add_front(&a, new_node(rand(), i));
		else
                	add_front(&a, new_node(-rand(), i));
                i++;
        }
        show_list(&a);
        bucket_sort(&a, &bench);

        show_list(&a);
	exit_protocol(&a, &bench);
}*/
