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

void	bucket_sort(t_stack **a_stack, t_stack **b_stack)
{
	int		len;
	int		range[5];
	t_stack	*sorted;
	t_stack	*a_top;
	t_stack	*b_top;

	if (!*a_stack)
		return ;
	a_top = *a_stack;
	len = ft_lstsize(*a_stack);
	range[0] = *a_top->data;
	range[1] = *a_top->data;
	range[2] = 0;
	while (range[2]++ != len)
	{
		if (*a_top->data > range[1])
			range[1] = *a_top->data;
		if (*a_top->data < range[0])
			range[0] = *a_top->data;
		rotate(&a_top);
	}
	if (ft_lstsize(*a_stack) == 1 || range[0] == range[1])
		return ;
	a_top = *a_stack;
	while (*a_stack)
	{
		b_top = *b_stack;
		range[2] = *(*a_stack)->data;
		//b_top = *b_stack;
		if (!*b_stack)
		{
			push_top(b_stack, a_stack);
			continue ;
		}
		range[3] = ft_lstsize(*b_stack);
		range[4] = 0;
		while (range[3] != range[4]++ && *b_top->index < ((range[2] - range[0]) / (range[1] - range[0])) * (len - 1))
			rotate(&b_top);
		//printf("data: %d, min: %d, max: %d, len: %d\n", range[2], range[0], range[1], len);
		//printf("%d : %d : %d\n", *(*b_stack)->index, (((range[2] - range[0]) / (range[1] - range[0])) * (len - 1)), *(*a_stack)->data);
		push_top(&b_top, a_stack);
		show_list(&b_top);
	}
	//show_list(b_stack);
	range[0] = 0;
	while (range[0]++ != len)
	{
		sorted = NULL;
		bucket_sort(&(*b_stack)->lst, &sorted);
		while ((*b_stack)->lst)
		{
			reverse_rotate(&(*b_stack)->lst);
			push_top(a_stack, &(*b_stack)->lst);
		}
		reverse_rotate(b_stack);
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
