/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_movement_ali.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoca <akoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:34:40 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/05/07 16:15:56 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_top(t_stack **stack)
{
	long int	*a;
	int			*b;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	a = (*stack)->data;
	b = (*stack)->index;
	(*stack)->data = (*stack)->next->data;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->data = a;
	(*stack)->next->index = b;
	return (1);
}

int	push_top(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*head_from;

	if (!stack_from || !(*stack_from))
		return (0);
	head_from = (*stack_from);
	(*stack_from) = (*stack_from)->next;
	if (!(*stack_to))
	{
		(*stack_to) = head_from;
		(*stack_to)->next = NULL;
	}
	else
	{
		(*stack_to)->previous = head_from;
		head_from->next = (*stack_to);
		(*stack_to) = head_from;
	}
	(*stack_to)->previous = NULL;
	if ((*stack_from))
		(*stack_from)->previous = NULL;
	return (1);
}

int	sa(t_stack **stack_a, int print)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return (0);
	swap_top(stack_a);
	if (print)
		write(1, "sa\n", 3);
	return (1);
}

int	pa(t_stack **stack_a, t_stack **stack_b, int print)
{
	/*if (!(*stack_b))
		return (0);*/
	push_top(stack_a, stack_b);
	if (print)
		write(1, "pa\n", 3);
	return (1);
}

int	pb(t_stack **stack_a, t_stack **stack_b, int print)
{
	/*if (!(*stack_a))
		return (0);*/
	push_top(stack_a, stack_b);
	if (print)
		write(1, "pb\n", 3);
	return (1);
}
/*int	swap_both_tops(t_stack **stack_a, t_stack **stack_b)
{
	int	count;

	count = 0;
	count += swap_top(stack_a);
	count += swap_top(stack_b);
	return (count);
}*/
