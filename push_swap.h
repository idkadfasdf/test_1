/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:27:55 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/05/06 13:10:57 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_stack
{
	struct s_stack	*previous;
	struct s_stack	*next;
	struct s_stack	*lst;
	int	*data;
	int	*index;
}	t_stack;

void	push_top(t_stack **stack_to, t_stack **stack_from);
void    show_lst(t_stack **stack);
int	ft_lstsize(t_stack *lst);
void	add_front(t_stack **lst, t_stack *new);
t_stack	*new_node(int content, int i);
void    show_list(t_stack **stack);
void	rotate(t_stack **s);
void	swap_top(t_stack **stack);
void	reverse_rotate(t_stack **s);
void	bubble_sort(t_stack **stack);
