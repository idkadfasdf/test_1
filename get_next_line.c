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

t_list	*new_node(void *content, int i)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	((char *)content)[i] = '\0';
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
	u = 0;
	node = *lst;
	while (node)
	{
		u += ft_strlen(node->content);
		node = node -> next;
	}
	str = malloc(u + 1);
	if (!str)
		return (clear_list(lst), NULL);
	i = 0;
	node = *lst;
	while (node -> next)
		node = node -> next;
	while (node)
	{
		u = 0;
		while (((char *)(node->content))[u])
			str[i++] = ((char *)(node->content))[u++];
		node = node->previous;
	}
	return (str[i] = '\0', clear_list(lst), str);
}

char	*new_line(char *str, static char *buf, static int i)
{
	int	u;

	str = malloc(ft_strlen(buf) + 1);
	u = 0;
	while (buf[i])
	{
		str[u++] = buf[i];
		if (buf[i++] == '\n')
		{
			add_front(&lst, new_node(str, u));
			if (!buf[i])
				i = 0;
			return (return_lst(&lst));
		}
	}
	i = 0;
	add_front(&lst, new_node(str, u));
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char	*str;
	static int		i = 0;
	t_list	*lst;
	int		u;

	lst = NULL;
	while (1)
	{
		if (i == 0)
		{
			u = read(fd, buf, BUFFER_SIZE);
			if (u == 0 && lst)
				return (return_lst(&lst));
			if (u <= 0)
				return (clear_list(&lst), NULL);
			buf[u] = '\0';
		}
		str = malloc(ft_strlen(buf) + 1);
		u = 0;
		while (buf[i])
		{
			str[u++] = buf[i];
			if (buf[i++] == '\n')
			{
				add_front(&lst, new_node(str, u));
				if (!buf[i])
					i = 0;
				return (return_lst(&lst));
			}
		}
		i = 0;
		add_front(&lst, new_node(str, u));
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
