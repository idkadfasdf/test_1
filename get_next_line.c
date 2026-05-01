/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 10:05:55 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/30 15:23:48 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	clear_list(t_list **lst)
{
	t_list	*temp;

	if (!*lst)
		return ;
	while (*lst)
	{
		free((*lst)->content);
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

t_list	*new_node(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	new -> previous = NULL;
	return (new);
}

void	add_front(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	(*lst) -> previous = new;
	new -> next = *lst;
	*lst = new;
}

char	*return_lst(t_list **lst)
{
	char	*str;
	int		i;
	int		u;
	t_list	*node;

	if (!lst)
		return (NULL);
	i = 0;
	u = 0;
	node = *lst;
	while (node)
	{
		u += ft_strlen(node->content);
		node = node -> next;
		i++;
	}
	str = malloc(u + 1);
	if (!str)
	{
		clear_list(lst);
		return (NULL);
	}
	i = 0;
	node = *lst;
	while (node)
		node = node -> next;
	while (node)
	{
		u = 0;
		while (((char *)(node->content))[u])
		{
			str[i] = ((char *)(node->content))[u];
			i++;
			u++;
		}
		node = node->previous;
	}
	clear_list(lst);
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char	*str;
	int		nb_read;
	static int		i = 0;
	t_list	*lst;
	int		u;

	lst = NULL;
	u = 0;
	while (1)
	{
		if (i == 0)
		{
			nb_read = read(fd, buf, BUFFER_SIZE);
			if (nb_read <= 0)
			{
				if (lst && nb_read != -1)
					return (return_lst(&lst));
				clear_list(&lst);
				return (NULL);
			}
			buf[nb_read] = '\0';
		}
		str = malloc(ft_strlen(buf) + 1);
		while (buf[i])
		{
			str[u] = buf[i];
			if (buf[i] == '\n')
			{
				str[u + 1] = '\0';
				add_front(&lst, new_node(str));
				if (buf[i + 1])
					i++;
				else
					i = 0;
				return (return_lst(&lst));
			}
			i++;
		}
		str[u] = '\0';
		i = 0;
		add_front(&lst, new_node(str));
	}
}

/*int main()
{
	int fd = open("idk", O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s", str);
	while (str)
	{
		printf("%s", str);
		str = get_next_line(fd);
	}
}*/
