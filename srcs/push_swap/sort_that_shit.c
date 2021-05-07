#include "push_swap.h"

void	init_sort(int *current_nb, int *bloc_range, int *last_bloc_range)
{
	*current_nb = 1;
	*bloc_range = 1;
	*last_bloc_range = 0;
}

static int	moves_cnt(t_ps *ps, int *stack, int nb)
{
	int	i;

	i = ps->st_size - stack[0] + 1;
	while (stack[i] != nb)
		i++;
	i += -(ps->st_size - stack[0]);
	return (i);
}

static void	extrem_moves(int ***st, t_ps *ps, int nb)
{
	int	i;
	int	**stacks;

	stacks = *st;
	i = moves_cnt(ps, stacks[A], nb);
	if (i <= stacks[A][0] / 2)
	{
		i++;
		while (--i > 1)
			add_mvs_to_list(ps, &stacks, ra);
	}
	else
	{
		i = stacks[A][0] - i + 3;
		while (--i > 1)
			add_mvs_to_list(ps, &stacks, rra);
	}
	add_mvs_to_list(ps, &stacks, pb);
	*st = stacks;
}

void	sort_that_shit(int ***st, t_ps *ps)
{
	int	**stacks;

	stacks = *st;
	extrem_moves(&stacks, ps, 1);
	extrem_moves(&stacks, ps, 5);
	sort_that_little_shit(&stacks, ps, 1);
	add_mvs_to_list(ps, &stacks, pa);
	add_mvs_to_list(ps, &stacks, ra);
	add_mvs_to_list(ps, &stacks, pa);
	*st = stacks;
}
