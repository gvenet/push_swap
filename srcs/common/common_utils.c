#include "common.h"

int	exit_clear(int **stacks, char *e, int ret, int *bloc_data)
{
	if (e)
		write(1, e, ft_strlen(e));
	if (stacks)
	{
		if (stacks[A])
			free(stacks[A]);
		if (stacks[B])
			free(stacks[B]);
		free(stacks);
	}
	if (bloc_data)
		free (bloc_data);
	if (ret)
		exit (1);
	return (0);
}

void	display_stacks(int size, int **stacks, char *cmd, int fd)
{
	int	i;
	int	cnt;

	write(fd, "\n---- ", 7);
	if (cmd)
		write(fd, cmd, ft_strlen(cmd));
	write(fd, " -----\n", 7);
	if (stacks[A][0] >= stacks[B][0])
		cnt = stacks[A][0];
	else
		cnt = stacks[B][0];
	i = 0;
	while (++i <= size)
	{
		if (stacks[A][0] + i > size)
			ft_putnbr_fd(stacks[A][i], fd);
		if (cnt + i > size)
			write(fd, "\t", 1);
		if (stacks[B][0] + i > size)
			ft_putnbr_fd(stacks[B][i], fd);
		if (cnt + i > size)
			ft_putendl_fd(NULL, fd);
	}
	write(fd, "_\t_\nA\tB\n", 8);
}
