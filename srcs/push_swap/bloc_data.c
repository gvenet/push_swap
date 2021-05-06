#include "push_swap.h"

static int	nb_bloc_calc(int size)
{
	int	nb_bloc;

	nb_bloc = 1;
	if (size <= 10)
		nb_bloc = 0.2 * size;
	else if (size <= 100)
		nb_bloc = 0.0444 * size + 1.56;
	else if (size <= 300)
		nb_bloc = 0.015 * size + 4.5;
	else if (size <= 1000)
		nb_bloc = 0.02 * size + 3;
	if (nb_bloc == 0)
		return (1);
	return (nb_bloc);
}

void	bloc_data_fct(int **stacks, t_ps *ps)
{
	int	nb_bloc;
	int	i;

	nb_bloc = nb_bloc_calc(stacks[A][0]);
	ps->bloc_data = (int *)malloc(sizeof(int) * (nb_bloc + 1));
	if (!ps->bloc_data)
		exit_clear(stacks, "Error: malloc failed\n", 1, NULL);
	ps->bloc_data[0] = nb_bloc;
	i = 1;
	while (i < nb_bloc)
	{
		if (i == 1)
			ps->bloc_data[i] = stacks[A][0] / nb_bloc;
		else
			ps->bloc_data[i] = stacks[A][0] / nb_bloc + ps->bloc_data[i - 1];
		i++;
	}
	ps->bloc_data[i] = stacks[A][0];
}
