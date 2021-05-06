#include "common.h"

void	f_pa(int size, int ***st)
{
	int	**stacks;

	stacks = *st;
	if (stacks[B][0] == 0)
		return ;
	stacks[B][0]--;
	stacks[A][size - stacks[A][0]] = stacks[B][size - stacks[B][0]];
	stacks[B][size - stacks[B][0]] = 0;
	stacks[A][0]++;
	*st = stacks;
}

void	f_pb(int size, int ***st)
{
	int	**stacks;

	stacks = *st;
	if (stacks[A][0] == 0)
		return ;
	stacks[A][0]--;
	stacks[B][size - stacks[B][0]] = stacks[A][size - stacks[A][0]];
	stacks[A][size - stacks[A][0]] = 0;
	stacks[B][0]++;
	*st = stacks;
}
