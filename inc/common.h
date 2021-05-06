#ifndef COMMON_H
# define COMMON_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"
# include "get_next_line.h"

enum	e_stacks
{
	A,
	B,
};

typedef struct s_tabs
{
	void	(*fct_mvs[11])(int, int ***);
	char	tab_mvs[11][4];
}t_tabs;

enum	e_cmd
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
};

enum	e_cnt
{
	c_ra,
	c_rb,
	c_rra,
	c_rrb,
};

void	display_stacks(int size, int **stacks, char *cmd, int fd);

void	tabs_init(t_tabs *t);
void	init_st(int ac, char **av, int ***st, t_tabs *d);

int		exit_clear(int **stacks, char *e, int ret, int *bloc_data);

void	f_sa(int size, int ***st);
void	f_sb(int size, int ***st);
void	f_ss(int size, int ***st);
void	f_pa(int size, int ***st);
void	f_pb(int size, int ***st);
void	f_ra(int size, int ***st);
void	f_rb(int size, int ***st);
void	f_rr(int size, int ***st);
void	f_rra(int size, int ***st);
void	f_rrb(int size, int ***st);
void	f_rrr(int size, int ***st);
#endif