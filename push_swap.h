/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoca <akoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:24:41 by akoca             #+#    #+#             */
/*   Updated: 2026/05/07 16:57:33 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	struct s_stack	*previous;
	struct s_stack	*next;
	struct s_stack	*lst;
	long int		*data;
	int				*index;
}	t_stack;

typedef struct s_bench
{
	int	pa_count;
	int	pb_count;
	int	ra_count;
	int	rb_count;
	int	sa_count;
	int	rrb_count;
	int	print;
}	t_bench;

//NODE OPERATIONS
void	add_front(t_stack **lst, t_stack *new);
t_stack	*new_node(int content, int i);
void	show_list(t_stack **stack);
int		ft_lstsize(t_stack *lst);
void	add_back(t_stack **lst, t_stack *new);

//SORTING OPERATIONS
int		push_top(t_stack **stack_to, t_stack **stack_from);
int		swap_both_tops(t_stack **stack_a, t_stack **stack_b);
int		swap_top(t_stack **stack);
int		rotate_both(t_stack **a, t_stack **b);
int		rotate(t_stack **s);
int		rrb(t_stack **s);
int		pa(t_stack **stack_a, t_stack **stack_b, int print);
int		pb(t_stack **stack_a, t_stack **stack_b, int print);
int		ra(t_stack **stack_a, int print);
int		rb(t_stack **stack_b, int print);

//RADIX SORT
int		fill_arr(int **arr, t_stack *stack);
int		*sort_array(int *arr, int lstsize);
int		index_stack(t_stack **stack);
int		count_max_bits(t_stack *stack);
void	radix_sort(t_stack **stack_a, t_stack **stack_b,
			t_bench **c, int print);
//BUCKET SORT
void	bucket_sort(t_stack **a_stack, t_bench **bench);

//BUBBLE SORT
void	bubble_sort(t_stack **stack);

//LIBFT
int		strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);

//BENCH OPTION
t_bench	*initialize_count(void);

//MEMORY FREEING
void	exit_protocol(t_stack **stack, t_bench **bench);

#endif
