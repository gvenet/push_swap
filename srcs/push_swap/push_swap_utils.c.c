#include "push_swap.h"
int	is_sort(int *stack, t_ps *ps)
{
	int	i;

	i = ps->st_size - stack[0] + 1;
	while (i < ps->st_size)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	smaller_fct(t_ps *ps, int *stack)
{
	int	tmp;
	int	i;

	tmp = ps->st_size;
	i = ps->st_size - stack[0] + 1;
	if (stack[0] == 0)
		tmp = 0;
	while (i <= ps->st_size)
	{
		if (tmp > stack[i])
			tmp = stack[i];
		i++;
	}
	return (tmp);
}

int	bigger_fct(t_ps *ps, int *stack)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = ps->st_size - stack[0] + 1;
	while (i <= ps->st_size)
	{
		if (tmp < stack[i])
			tmp = stack[i];
		i++;
	}
	return (tmp);
}

int	smaller_index(t_ps *ps, int *stack)
{
	int	index;
	int	tmp;
	int	i;

	tmp = ps->st_size;
	i = ps->st_size - stack[0] + 1;
	while (i <= ps->st_size)
	{
		if (tmp > stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	range_selector(int *bloc_data, int current_nb)
{
	int	bloc_range;

	bloc_range = 1;
	while (current_nb > bloc_data[bloc_range])
		bloc_range++;
	return (bloc_range);
}
