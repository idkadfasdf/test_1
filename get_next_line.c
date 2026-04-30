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

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	get_previous(char *str)
{
	int		i;
	static char	store[BUFFER_SIZE + 1] = {0};

	if (!str[0])
	{
		i = 0;
		while (store[i])
		{
			str[i] = store[i];
			i++;
		}
		str[i] = 0;
		store[0] = 0;
		return ;
	}
	i = 0;
	while (str[i])
	{
		store[i] = str[i];
		i++;
	}
	store[i] = '\0';
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
	return (new);
}

/*void    show_list(t_list **lst)
{
        t_list *idk;
        idk = *lst;
        while (idk)
        {
                printf("%s", ((char *)idk->content));
                idk = idk->next;
        }
}*/

void	add_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last -> next = new;
}

char	*return_lst(t_list **lst)
{
	char	*str;
	t_list	*first;
	int		i;
	int		u;

	if (!lst)
		return (NULL);
	first = *lst;
	i = 0;
	while (first)
	{
		first = first -> next;
		i++;
	}
	str = malloc(i * BUFFER_SIZE + 1);
	if (!str)
	{
		clear_list(lst);
		return (NULL);
	}
	i = 0;
	first = *lst;
	while (first)	
	{
		u = 0;
		while (((char *)(first->content))[u])
		{
			str[i] = ((char *)(first->content))[u];
			i++;
			u++;
		}
		first = first -> next;
	}
	clear_list(lst);
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*str;
	int		nb_read;
	char	previous[BUFFER_SIZE + 1];
	int		i;
	t_list	*lst;

	lst = NULL;
	previous[0] = '\0';
	get_previous(previous);
	if (previous[0] != '\0')
	{
		str = malloc(BUFFER_SIZE + 1);
		i = 0;
		while (previous[i])
		{
			str[i] = previous[i];
			i++;
		}
		str[i] = '\0';
		add_back(&lst, new_node(str));
	}
	while (1)
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
		str = malloc(nb_read + 1);
		i = 0;
		while (buf[i])
		{
			str[i] = buf[i];
			if (buf[i] == '\n')
			{
				str[i + 1] = '\0';
				add_back(&lst, new_node(str));
				if (buf[i + 1])
					get_previous(&buf[i + 1]);
				return (return_lst(&lst));
			}
			i++;
		}
		str[i] = '\0';
		add_back(&lst, new_node(str));
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
