/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_movement_ali.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoca <akoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:34:40 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/05/06 11:45:21 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(t_stack **stack)
{
	int	*a;
	int	*b;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	a = (*stack)->data;
	b = (*stack)->index;
	(*stack)->data = (*stack)->next->data;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->data = a;
	(*stack)->next->index = b;
}

void	swap_both_tops(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	swap_top(stack_a);
	swap_top(stack_b);
}

void	push_top(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*head_from;

	if (!stack_from || !(*stack_from))
		return ;
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
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_b))
		return ;
	push_top(stack_a, stack_b);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a))
		return ;
	push_top(stack_b, stack_a);
}
