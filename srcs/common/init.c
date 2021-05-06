#include "checker.h"

static void	check_recurrence(int ac, int **stacks)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (stacks[A][i] == stacks[A][j])
				exit_clear(stacks, "Error: reccurence checked\n", 1, NULL);
			j++;
		}
		i++;
	}
}

static int	check_limits(char *nb)
{
	long long int	n;

	n = ft_atoi(nb);
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	return (1);
}

static void	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][0] == '-' && j == 0)
			{
				j++;
				if (!av[i][j])
					exit_clear(NULL, "Error\n", 1, NULL);
			}
			if (!ft_isdigit(av[i][j]))
				exit_clear(NULL, "Error\n", 1, NULL);
			if (!check_limits(av[i]))
				exit_clear(NULL, "Error\n", 1, NULL);
			j++;
		}
		i++;
	}
}

static void	create_stacks(int ac, char **av, int ***st)
{
	int	i;
	int	**stacks;

	stacks = *st;
	stacks = (int **)malloc(sizeof(int *) * 2);
	if (!stacks)
		exit_clear(NULL, "Error: malloc failed\n", 1, NULL);
	i = -1;
	while (++i < 2)
	{
		stacks[i] = NULL;
		stacks[i] = (int *)malloc(sizeof(int) * ac);
	}
	if (!stacks[A] || !stacks[B])
		exit_clear(stacks, "Error: malloc failed\n", 1, NULL);
	i = 0;
	stacks[A][0] = ac - 1;
	stacks[B][0] = 0;
	while (++i < ac)
	{
		stacks[A][i] = ft_atoi(av[i]);
		stacks[B][i] = 0;
	}
	*st = stacks;
}

void	init_st(int ac, char **av, int ***st, t_tabs *t)
{
	int	**stacks;

	stacks = *st;
	stacks = NULL;
	tabs_init(t);
	check_args(ac, av);
	create_stacks(ac, av, &stacks);
	check_recurrence(ac, stacks);
	*st = stacks;
}
