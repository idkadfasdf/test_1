/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoca <akoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:31:38 by akoca             #+#    #+#             */
/*   Updated: 2026/05/07 16:56:27 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack **s)
{
	t_stack	*first;
	t_stack	*temp;

	if (!s || !(*s) || !((*s)->next))
		return (0);
	first = *s;
	temp = *s;
	*s = (*s)->next;
	if (*s)
		(*s)->previous = NULL;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	first->previous = temp;
	first->next = NULL;
	return (1);
}

int	ra(t_stack **stack_a, int print)
{
	if (!stack_a || !(*stack_a))
		return (0);
	rotate(stack_a);
	if (print)
		write(1, "ra\n", 3);
	return (1);
}

int	rb(t_stack **stack_b, int print)
{
	if (!stack_b || !(*stack_b))
		return (0);
	rotate(stack_b);
	if (print)
		write(1, "rb\n", 3);
	return (1);
}
/*int	rotate_both(t_stack **a, t_stack **b)
{
	if (!*a && !*b)
	return (0);
	if (!*a)
	return (rotate(b));
	if (!*b)
	return (rotate(a));
	rotate(a);
	rotate(b);
	return (2);
}

int	reverse_rotate_both(t_stack **a, t_stack **b)
{
	if (!*a && !*b)
	return (0);
	if (!*a)
	return (reverse_rotate(b));
	if (!*b)
	return (reverse_rotate(a));
	reverse_rotate(a);
	reverse_rotate(b);
	return (2);
}
*/

int	rrb(t_stack **s, int idk)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*s)
		return (0);
	temp = *s;
	last = *s;
	while (last->next)
		last = last->next;
	temp->previous = last;
	last->next = temp;
	last = last->previous;
	last->next = NULL;
	temp = temp->previous;
	temp->previous = NULL;
	*s = temp;
	if (idk)
		write(1, "rrb\n", 4);
	return (1);
}
/*
int main()
{
	t_stack	*a;
	t_stack	*b = NULL;
	int	i;
	
	i = 0;
	while (i < 10)
	{
		add_front(&a, new_node(NULL, i));
		i++;
	}
	show_list(&a);
	printf("\n");
	//rotate(&s);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	show_list(&a);
	printf("\n");
	show_list(&b);
}*/
