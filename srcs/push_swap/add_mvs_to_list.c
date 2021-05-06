#include "push_swap.h"

void	add_mvs_to_list(t_ps *ps, int ***st, int mvs)
{
	int	**stacks;

	stacks = *st;
	(*ps->t->fct_mvs[mvs])(ps->st_size, &stacks);
	ft_lstadd_back(&ps->lst_mvs, ft_lstnew(ps->t->tab_mvs[mvs]));
}
