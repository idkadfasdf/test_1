/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:34:40 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/05/05 15:35:55 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int content, int i)
{
	int	*nb;
	t_stack	*new;
	int	*data;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->lst = NULL;
	nb = malloc(sizeof(int));
	*nb = i;
	new -> index = nb;
	data = malloc(sizeof(int));
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
	new->previous = NULL;
	*lst = new;
}

void	show_list(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
        printf("\n");
        while (temp)
        {
                printf("%d, ", *temp->data);
                temp = temp -> next;
        }
	printf("\n");
}

void    show_lst(t_stack **stack)
{
        t_stack *temp;

	if (!(*stack))
		return ;
	temp = *stack;
	while (temp)
	{
		if (*temp->data != 0)
			printf("%d\n", *temp->data);
		show_lst(&temp->lst);
		temp = temp->next;
	}
}
