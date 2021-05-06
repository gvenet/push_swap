#include "checker.h"

static void	set_tab_mvs(char t[][4])
{
	ft_strncpy(t[0], "sa", 3);
	ft_strncpy(t[1], "sb", 3);
	ft_strncpy(t[2], "ss", 3);
	ft_strncpy(t[3], "pa", 3);
	ft_strncpy(t[4], "pb", 3);
	ft_strncpy(t[5], "ra", 3);
	ft_strncpy(t[6], "rb", 3);
	ft_strncpy(t[7], "rr", 3);
	ft_strncpy(t[8], "rra", 4);
	ft_strncpy(t[9], "rrb", 4);
	ft_strncpy(t[10], "rrr", 4);
}

static void	set_fct_mvs(void (*t[11])(int, int ***))
{
	t[sa] = f_sa;
	t[sb] = f_sb;
	t[ss] = f_ss;
	t[pa] = f_pa;
	t[pb] = f_pb;
	t[ra] = f_ra;
	t[rb] = f_rb;
	t[rr] = f_rr;
	t[rra] = f_rra;
	t[rrb] = f_rrb;
	t[rrr] = f_rrr;
}

void	tabs_init(t_tabs *t)
{
	set_tab_mvs(t->tab_mvs);
	set_fct_mvs(t->fct_mvs);
}
