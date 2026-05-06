#include "push_swap.h"

void	reverse_rotate(t_stack **s)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*s)
		return ;
	temp = *s;
	last = *s;
	while (last->next)
		last = last->next;
	temp->previous = last;
	last->next = temp;
	last = last->previous;
	last->next = NULL;
	temp = temp->previous;
	temp->previous = NULL;
	*s = temp;
	
}

void	rotate(t_stack **s)
{
	t_stack	*first;
	t_stack	*temp;

	if (!s || !(*s) || !((*s)->next))
		return ;
	first = *s;
	temp = *s;
	*s = (*s)->next;
	if (*s)
		(*s)->previous = NULL;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	first->previous = temp;
	first->next = NULL;
}

void	rotate_both(t_stack **a, t_stack **b)
{
	if (!*a && !*b)
		return ;
	if (!*a)
		return (rotate(b));
	if (!*b)
		return (rotate(a));
	rotate(a);
	rotate(b);
}

void	reverse_rotate_both(t_stack **a, t_stack **b)
{
	if (!*a && !*b)
		return ;
	if (!*a)
		return (reverse_rotate(b));
	if (!*b)
		return (reverse_rotate(a));
	reverse_rotate(a);
	reverse_rotate(b);
}
/*
int main()
{
	t_stack	*a;
	t_stack	*b = NULL;
	int	i;

	i = 0;
	while (i < 10)
	{
		add_front(&a, new_node(NULL, i));
		i++;
	}
	show_list(&a);
	printf("\n");
	//rotate(&s);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	show_list(&a);
	printf("\n");
	show_list(&b);
}*/
