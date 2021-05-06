#include "common.h"

void	f_ra(int size, int ***st)
{
	int	tmp;
	int	i;
	int	**stacks;

	stacks = *st;
	if (stacks[A][0] == 0 || stacks[A][0] == 1)
		return ;
	i = size - stacks[A][0] + 1;
	tmp = stacks[A][i];
	i--;
	while (++i < size)
		stacks[A][i] = stacks[A][i + 1];
	stacks[A][i] = tmp;
	*st = stacks;
}

void	f_rb(int size, int ***st)
{
	int	tmp;
	int	i;
	int	**stacks;

	stacks = *st;
	if (stacks[B][0] == 0 || stacks[B][0] == 1)
		return ;
	i = size - stacks[B][0] + 1;
	tmp = stacks[B][i];
	i--;
	while (++i < size)
		stacks[B][i] = stacks[B][i + 1];
	stacks[B][i] = tmp;
	*st = stacks;
}

void	f_rr(int size, int ***st)
{
	f_ra(size, st);
	f_rb(size, st);
}
