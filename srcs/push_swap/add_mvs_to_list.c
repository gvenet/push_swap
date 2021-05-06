#include "push_swap.h"

void	add_mvs_to_list(t_ps *ps, int ***st, int mvs)
{
	int		**stacks;
	t_list	*tmp;

	stacks = *st;
	tmp = NULL;
	tmp = ft_lstnew(ps->t->tab_mvs[mvs]);
	if (!tmp)
	{
		free_lst(&ps->lst_mvs);
		exit_clear(stacks, "Error: malloc failed", 1, ps->bloc_data);
	}
	(*ps->t->fct_mvs[mvs])(ps->st_size, &stacks);
	ft_lstadd_back(&ps->lst_mvs, tmp);
}
