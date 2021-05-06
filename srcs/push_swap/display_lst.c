#include "push_swap.h"

void	display_lst(t_list *l)
{
	char	*mvs;

	while (l)
	{
		mvs = l->content;
		write(1, mvs, ft_strlen(mvs));
		write(1, "\n", 1);
		l = l->next;
	}
}

void	display_lst_bloc(t_list *pb_start, t_list *pb_end, int fd)
{
	char	*mvs;

	write(fd, "--------------------\n", 21);
	while (pb_start != pb_end)
	{
		mvs = pb_start->content;
		write(fd, mvs, ft_strlen(mvs));
		write(fd, "\n", 1);
		pb_start = pb_start->next;
	}
	write(fd, "--------------------\n", 21);
}
