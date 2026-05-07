/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoca <akoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 11:24:51 by akoca             #+#    #+#             */
/*   Updated: 2026/05/07 16:47:46 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bench	*initialize_count(void)
{
	t_bench	*count;

	count = malloc(sizeof(t_bench));
	if (!count)
		return (NULL);
	count->pa_count = 0;
	count->pb_count = 0;
	count->ra_count = 0;
	count->rb_count = 0;
	count->sa_count = 0;
	count->rrb_count = 0;
	count->print = 1;
	return (count);
}
