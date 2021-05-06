#include "push_swap.h"

void	free_lst(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

static void	init_ps(t_ps *ps, int ac)
{
	ps->st_size = ac - 1;
	ps->t = &ps->t_;
	ps->bloc_data = NULL;
	ps->lst_mvs = NULL;
}

int	main(int ac, char **av)
{
	t_ps	ps_;
	t_ps	*ps;
	int		**stacks;

	ps = &ps_;
	init_ps(ps, ac);
	init_st(ac, av, &stacks, ps->t);
	simplify_data(ac, &stacks);
	if (is_sort(stacks[A], ps))
		return (exit_clear(stacks, NULL, 0, NULL));
	bloc_data_fct(stacks, ps);
	if (ps->st_size <= 3)
		sort_that_little_shit(&stacks, ps, 0);
	else if (ps->st_size == 5)
		sort_that_shit(&stacks, ps);
	else
		sort_that_multi_bloc_shit(&stacks, ps);
	lst_post_treatment(ps->lst_mvs);
	display_lst(ps->lst_mvs);
	free_lst(&ps->lst_mvs);
	return (exit_clear(stacks, NULL, 0, ps->bloc_data));
}
