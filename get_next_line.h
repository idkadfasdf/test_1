#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

char	*get_next_line(int fd);
int		ft_strlen(char *s);
void	clear_list(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*new_node(void *content, int i);
void	add_front(t_list **lst, t_list *new);
char	*final_str(t_list *lst);
char	*return_lst(t_list **lst);
char	*new_line(char *buf, t_list **lst, ssize_t *u);
char	*get_next_line(int fd);

#endif
