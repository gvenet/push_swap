#include "push_swap.h"

static void	create_new_stack(int ac, int **n_st, int **stacks)
{
	int	i;
	int	*new_stack;

	new_stack = *n_st;
	new_stack = NULL;
	new_stack = (int *)malloc(sizeof(int) * ac);
	if (!new_stack)
		exit_clear(stacks, "Error: malloc failed\n", 1, NULL);
	i = 0;
	while (i < ac)
		new_stack[i++] = -1;
	*n_st = new_stack;
}

static void	get_first_tmp(int *new_stack, int *stack, int *k, int *tmp)
{
	int	i;

	i = 0;
	while (++i <= stack[0])
	{
		if (new_stack[i] == -1)
		{
			*tmp = stack[i];
			*k = i;
			break ;
		}
	}
}

static void	data_cmp_fill_nst(int **n_st, int **stacks)
{
	int	i;
	int	j;
	int	k;
	int	tmp;
	int	*new_stack;

	new_stack = *n_st;
	new_stack[0] = stacks[A][0];
	i = 0;
	while (++i <= stacks[A][0])
	{
		get_first_tmp(new_stack, stacks[A], &k, &tmp);
		j = 0;
		while (++j <= stacks[A][0])
		{
			if (tmp > stacks[A][j] && new_stack[j] == -1)
			{
				tmp = stacks[A][j];
				k = j;
			}
		}
		new_stack[k] = i;
	}
	*n_st = new_stack;
}

void	simplify_data(int ac, int ***st)
{
	int	*new_stack;
	int	**stacks;

	stacks = *st;
	new_stack = NULL;
	create_new_stack(ac, &new_stack, stacks);
	data_cmp_fill_nst(&new_stack, stacks);
	free(stacks[A]);
	stacks[A] = new_stack;
	*st = stacks;
}
