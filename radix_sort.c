/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoca <akoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:11:07 by akoca             #+#    #+#             */
/*   Updated: 2026/05/07 11:59:14 by akoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//SORTING OPERATIONS ONLY CALLED IN `radix_sort()`
int	fill_arr(int **arr, t_stack *stack)
{
	int	i;
	int	lstsize;
	int	*new_arr;

	i = 0;
	lstsize = ft_lstsize(stack);
	new_arr = malloc(lstsize * sizeof(int));
	if (!new_arr)
		return (-1);
	while (i < lstsize)
	{
		new_arr[i] = *(stack->data);
		stack = stack->next;
		i++;
	}
	*arr = new_arr;
	return (lstsize);
}

int	*sort_array(int *arr, int lstsize)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < lstsize)
	{
		j = 0;
		while (j < lstsize)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	index_stack(t_stack **stack)
{
	t_stack	*head;
	int		*arr;
	int		lstsize;
	int		i;

	lstsize = fill_arr(&arr, *stack);
	if (!arr)
		return (0);
	sort_array(arr, lstsize);
	i = 0;
	head = *stack;
	while (i < lstsize)
	{
		*stack = head;
		while (*stack)
		{
			if (arr[i] == *((*stack)->data))
				*((*stack)->index) = i;
			*stack = (*stack)->next;
		}
		i++;
	}
	*stack = head;
	free(arr);
	return (1);
}

int	count_max_bits(t_stack *stack)
{
	int		i;
	int		bits;
	int		max_index;

	i = 0;
	bits = 0;
	max_index = *stack->index;
	while (stack)
	{
		if (max_index < *stack->index)
			max_index = *stack->index;
		stack = stack->next;
	}
	while (max_index >> i != 0)
	{
		bits++;
		i++;
	}
	return (bits);
}

//the `c` named t_bench variable stands for count btw
void	radix_sort(t_stack **stack_a, t_stack **stack_b, t_bench **c, int print)
{
	int		max_bits;
	int		lstsize;
	int		index;
	int		i;
	int		j;

	i = 0;
	max_bits = count_max_bits(*stack_a);
	lstsize = ft_lstsize(*stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < lstsize)
		{
			index = *((*stack_a)->index);
			if (((index >> i) & 1) == 0)
				(*c)->pb_count += pb(stack_a, stack_b, print);
			else
				(*c)->ra_count += ra(stack_a, print);
			j++;
		}
		while (j-- > 0)
			(*c)->pa_count += pa(stack_a, stack_b, print);
		i++;
	}
}
/*
#include <time.h>
int	main(void)
{
	t_stack	*a = NULL;
	t_stack	*b = NULL;
	int		i;
	int		n;

	t_bench	*c = initialize_count();
	if (!c)
		return (1);

	srand(time(NULL));
	i = 0;
	while (i < 10)
	{
		n = rand() % 100;
		add_front(&a, new_node(n, 1));
		i++;
	}
	index_stack(&a);
	show_list(&a);
	printf("\n");
	printf("--radix sort--\n");
	radix_sort(&a, &b, &c, 0);
	show_list(&a);
	printf("\n");
	printf("--radix sort--\n");
	//printf("%d\n", c->pa_count);
	//printf("%d\n", c->pb_count);
	//printf("%d\n", c->ra_count);
	//printf("%d\n", c->rb_count);
	//printf("%d\n", c->sa_count);
	exit_protocol(&a, &c);
	return (0);
}*/

/*int	main(void)
{
	t_stack	*a;
	
	a = new_node(5, 5);
	printf("%d\n", count_max_bits(a));
}
*/
/*	i = 0;
printf("--array--\n");
while (i < lstsize)
{
	printf("%d, ", arr[i]);
	i++;
	}
	printf("\n");
printf("--array--\n");*/