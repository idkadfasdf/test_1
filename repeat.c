#include "push_swap.h"

int	is_repeat(t_stack *s)
{
	int		nb;
	t_stack	*head;
	t_stack	*current;

	head = s;
	while (s)
	{
		nb = *s->data;
		current = head;
		while (current)
		{
			if (*current->data == nb && *s->index != *current->index)
				return (1);
			current = current->next;
		}
		s = s->next;
	}
	return (0);
}
