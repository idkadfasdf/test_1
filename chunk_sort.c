#include "push_swap.h"

void	sort(t_stack **a_stack, t_stack **b_stack, t_bench **b)
{
	int	i;
	int	max;

	i = ft_lstsize(*b_stack) - 1;
        max = i;
        while (*(*b_stack)->index != i)
                (*b)->rb_count += rb(b_stack, (*b)->print);
        while (*b_stack)
        {
                if (*(*b_stack)->index == i)
                {
                        (*b)->pa_count += pa(a_stack, b_stack, (*b)->print);
                        i--;
                }
                else if (i >= max / 2)
                        (*b)->rrb_count += rrb(b_stack, (*b)->print);
                else
                        (*b)->rb_count += rb(b_stack, (*b)->print);
        }
}

void	chunk_sort(t_stack **a_stack, t_bench **b)
{
	int		i;
	int		range;
	t_stack	*b_stack;

	b_stack = NULL;
	index_stack(a_stack);
	range = 10;
	i = 0;
	while (*a_stack)
	{
		if (*(*a_stack)->index <= i)
		{
			(*b)->pb_count += pb(&b_stack, a_stack, (*b)->print);
			(*b)->rb_count += rb(&b_stack, (*b)->print);
			i++;
		}
		else if (*(*a_stack)->index <= i + range)
		{	
			(*b)->pb_count += pb(&b_stack, a_stack, (*b)->print);
			i++;
		}
		else
			(*b)->ra_count += ra(a_stack, (*b)->print);
	}
	sort(a_stack, &b_stack, b);
}

/*#include <time.h>
int main()
{
        t_stack *a;
	t_stack	*b;
        int             i;
        t_bench *bench;

        a = NULL;
	b = NULL;
        srand(time(NULL));
        i = 0;
        while (i != 100)
        {
            	add_front(&a, new_node(rand()%101, i));
                i++;
        }
        bench = NULL;
        bench = initialize_count();
        show_list(&a);
        chunk_sort(&a, &b, &bench);

        show_list(&a);
        exit_protocol(&a, &bench);
}*/
