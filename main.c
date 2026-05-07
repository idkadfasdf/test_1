/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:52:40 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/05/07 16:39:10 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_params(char **argv, char *params, int i)
{
	int	ripali[4];

	ripali[0] = strcmp(argv[1], "--bench") + strcmp(argv[i], "--bench");
	ripali[1] = strcmp(argv[1], "--simple") + strcmp(argv[i], "--simple");
	ripali[2] = strcmp(argv[1], "--medium") + strcmp(argv[i], "--medium");
	ripali[3] = strcmp(argv[1], "--complex") + strcmp(argv[i], "--complex");
	if (ripali[0] > 1 || ripali[1] + ripali[2] + ripali[3] > 1)
	{
		params[0] = 'e';
		return ;
	}
	if (ripali[1] == 1)
		params[0] = 's';
	else if (ripali[2] == 1)
		params[0] = 'm';
	else if (ripali[3] == 1)
		params[0] = 'c';
	else
		params[0] = 'a';
	if (ripali[0] == 1)
		params[1] = 'b';
	params[2] = ripali[0] + ripali[1] + ripali[2] + ripali[3];
}

static int	mk_stack(t_stack **a_stack, int inc, char **argv, t_bench **bench)
{
	int	i;
	int	u;

	i = 1 + inc;
	while (argv[i] && u != -1)
	{
		u = 0;
		while (argv[i][u])
		{
			if (ft_isdigit(argv[i][u]) == 0)
			{
				printf("error: %c\n", argv[i][u]);
				u = -1;
				exit_protocol(a_stack, bench);
				return (0);
			}
			u++;
		}
		add_back(a_stack, new_node(ft_atoi(argv[i]), i - inc));
		i++;
	}
	return (1);
}

void	call_sort(t_stack **a_stack, t_bench **bench, char *params)
{
	if (params[0] == 's')
		bubble_sort(a_stack);
	else if (params[0] == 'm')
		bucket_sort(a_stack, bench);
	/*else if (params[0] == 'c')
		radix_sort(a_stack);*/
	show_list(a_stack);
}

int	main(int argc, char **argv)
{
	char	params[3];
	t_stack	*a_stack;
	t_bench	*bench;

	if (argc == 1)
		return (0);
	if (!argv[2])
		get_params(argv, params, 0);
	else
		get_params(argv, params, 2);
	if (params[0] == 'e')
	{
		printf("error\n");
		return (0);
	}
	bench = NULL;
	bench = initialize_count();
	if (mk_stack(&a_stack, params[2], argv, &bench) == 0)
		return (0);
	call_sort(&a_stack, &bench, params);
}
