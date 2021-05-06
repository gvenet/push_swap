#include "push_swap.h"

static void	norm(int ***st, t_ps *ps, int p)
{
	int	**stacks;

	stacks = *st;
	if (stacks[A][ps->st_size - 1] == 1 + p)
		add_mvs_to_list(ps, &stacks, ra);
	else if (stacks[A][ps->st_size - 1] == 2 + p)
	{
		add_mvs_to_list(ps, &stacks, sa);
		add_mvs_to_list(ps, &stacks, rra);
	}
	*st = stacks;
}

void	sort_that_little_shit(int ***st, t_ps *ps, int p)
{
	int	**stacks;
	int	n1;
	int	n2;

	stacks = *st;
	n1 = ps->st_size - 2;
	n2 = ps->st_size - 1;
	if (stacks[A][n1] == 1 + p && stacks[A][n2] == 3 + p)
	{
		add_mvs_to_list(ps, &stacks, sa);
		add_mvs_to_list(ps, &stacks, ra);
	}
	else if (stacks[A][n1] == 2 + p)
	{
		if (stacks[A][n2] == 1 + p)
			add_mvs_to_list(ps, &stacks, sa);
		else if (stacks[A][n2] == 3 + p)
			add_mvs_to_list(ps, &stacks, rra);
	}
	else if (stacks[A][n1] == 3 + p)
		norm(&stacks, ps, p);
	*st = stacks;
}
