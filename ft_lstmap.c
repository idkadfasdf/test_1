/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:41:07 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/23 10:10:43 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static char	*addone(void *str)
{
	return (&((char *)str)[0]);
}*/

t_list	*less_lines(t_list *new)
{
	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new -> next = NULL;
	return (new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		i;
	t_list	*temp;
	t_list	*new;
	t_list	*first;

	(void)del;
	i = 0;
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		new = less_lines(new);
		new -> content = f(lst -> content);
		lst = lst -> next;
		if (i != 0)
		{
			temp -> next = new;
			temp = new;
		}
		else
		{
			first = new;
			temp = new;
			i++;
		}
	}
	return (first);
}

/*#include <stdio.h>
int main()
{

	t_list *four = malloc(sizeof(t_list));
	four -> content = "4";
	four -> next = NULL;
	t_list *one = malloc(sizeof(t_list));
	t_list *two = malloc(sizeof(t_list));
	t_list *three = malloc(sizeof(t_list));
	one -> next = two;
	two -> next = three;
	three -> next = NULL;
	two -> content = "2";
	one -> content = "1";
	three -> content = "3";
	three -> next = four;
	t_list *idk = ft_lstmap(one, addone);
	while (idk -> next != NULL)
	{
		printf("%s\n", (char *)idk -> content);
		idk = idk -> next;
	}
}*/
