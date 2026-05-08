/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:34:40 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/05/07 16:16:19 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int content, int i)
{
	int			*nb;
	t_stack		*new;
	long int	*data;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	nb = malloc(sizeof(int));
	*nb = i;
	new -> index = nb;
	data = malloc(sizeof(long int));
	*data = content;
	new -> data = data;
	new -> next = NULL;
	new -> previous = NULL;
	return (new);
}

void	add_front(t_stack **lst, t_stack *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	(*lst)-> previous = new;
	new -> next = *lst;
	*lst = new;
}

void	add_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last -> next = new;
	new->next = NULL;
	new->previous = last;
}

void	show_list(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp)
	{
		printf("%ld, ", *temp->data);
		temp = temp -> next;
	}
	printf("\n\n");
}
