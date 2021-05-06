#include "common.h"

void	f_sa(int size, int ***st)
{
	int	tmp;
	int	i;
	int	**stacks;

	stacks = *st;
	if (stacks[A][0] == 0 || stacks[A][0] == 1)
		return ;
	i = size - stacks[A][0];
	tmp = stacks[A][i + 1];
	stacks[A][i + 1] = stacks[A][i + 2];
	stacks[A][i + 2] = tmp;
	*st = stacks;
}

void	f_sb(int size, int ***st)
{
	int	tmp;
	int	i;
	int	**stacks;

	stacks = *st;
	if (stacks[B][0] == 0 || stacks[B][0] == 1)
		return ;
	i = size - stacks[B][0];
	tmp = stacks[B][i + 1];
	stacks[B][i + 1] = stacks[B][i + 2];
	stacks[B][i + 2] = tmp;
	*st = stacks;
}

void	f_ss(int size, int ***st)
{
	f_sa(size, st);
	f_sb(size, st);
}
