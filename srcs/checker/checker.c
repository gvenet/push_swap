#include "checker.h"

static void	run_mvs(t_tabs *t, int st_size, char *buf, int **stacks)
{
	int	cmd;

	cmd = 0;
	while (ft_strncmp(buf, t->tab_mvs[cmd], ft_strlen(buf)) && cmd < 11)
		cmd++;
	if (cmd == 11)
		exit_clear(stacks, "Error: wrong move command\n", 1, NULL);
	(*t->fct_mvs[cmd])(st_size, &stacks);
}

static void	check_result(int st_size, int **stacks)
{
	int	i;

	i = 0;
	while (++i < st_size)
	{
		if (stacks[A][i] > stacks[A][i + 1] || stacks[B][0])
		{
			write(2, "\033[31;01m", ft_strlen("\033[36;01m"));
			write(STDOUT_FILENO, "KO\n", 3);
			write(2, "\033[00m", ft_strlen("\033[00m"));
			return ;
		}
	}
	write(2, "\033[32;01m", ft_strlen("\033[36;01m"));
	write(STDOUT_FILENO, "OK\n", 3);
	write(2, "\033[00m", ft_strlen("\033[00m"));
}

int	main(int ac, char **av)
{
	t_tabs	t_;
	t_tabs	*t;
	char	*buf;
	int		**stacks;
	int		st_size;

	t = &t_;
	buf = NULL;
	st_size = ac - 1;
	if (ac <= 1)
		return (0);
	init_st(ac, av, &stacks, t);
	while (get_next_line(STDIN_FILENO, &buf))
	{
		run_mvs(t, st_size, buf, stacks);
		free(buf);
	}
	check_result(st_size, stacks);
	free(buf);
	return (exit_clear(stacks, NULL, 0, NULL));
}
