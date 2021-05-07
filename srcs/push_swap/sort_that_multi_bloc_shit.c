#include "push_swap.h"

static void	add_ra_rra(t_ps *ps, int ***st, int index, int bloc_range)
{
	int	mvs_cnt;
	int	**stacks;

	stacks = *st;
	mvs_cnt = 1;
	while (stacks[A][index] > ps->bloc_data[bloc_range])
	{
		mvs_cnt++;
		index++;
	}
	if (mvs_cnt < stacks[A][0] / 2)
	{
		mvs_cnt++;
		while (--mvs_cnt > 1)
			add_mvs_to_list(ps, &stacks, ra);
	}
	else
	{
		mvs_cnt = stacks[A][0] - mvs_cnt + 3;
		while (--mvs_cnt > 1)
			add_mvs_to_list(ps, &stacks, rra);
	}
}

static void	rb_rrb_trigger(t_ps *ps, int ***st, int to_push, int up_b)
{
	int	**stacks;
	int	smaller_b;
	int	smaller_i;
	int	mid_st;

	stacks = *st;
	mid_st = ps->st_size - stacks[B][0] / 2;
	smaller_i = smaller_index(ps, stacks[B]);
	smaller_b = smaller_fct(ps, stacks[B]);
	if (to_push < smaller_b && smaller_i > mid_st)
		while (stacks[B][ps->st_size] != smaller_b)
			add_mvs_to_list(ps, &stacks, rrb);
	else if (to_push < stacks[B][up_b] && to_push < stacks[B][ps->st_size])
		while (to_push < stacks[B][up_b] && to_push < stacks[B][ps->st_size] \
			&& stacks[B][ps->st_size] != smaller_b)
			add_mvs_to_list(ps, &stacks, rb);
	else if (to_push > bigger_fct(ps, stacks[B]) && smaller_i <= mid_st)
		while (stacks[B][ps->st_size] != smaller_b)
			add_mvs_to_list(ps, &stacks, rb);
	else if (to_push > stacks[B][up_b] && to_push > stacks[B][ps->st_size])
		while (to_push > stacks[B][up_b] && to_push > stacks[B][ps->st_size] \
			&& stacks[B][ps->st_size] != smaller_b)
			add_mvs_to_list(ps, &stacks, rrb);
	*st = stacks;
}

static void	add_rb_rrb(t_ps *ps, int ***st)
{
	int	**stacks;
	int	up_a;
	int	up_b;
	int	to_push;

	stacks = *st;
	up_a = ps->st_size - stacks[A][0] + 1;
	up_b = ps->st_size - stacks[B][0] + 1;
	to_push = stacks[A][up_a];
	if (to_push > stacks[B][up_b] && to_push < stacks[B][ps->st_size])
		return ;
	while (to_push < stacks[B][up_b] && to_push > stacks[B][ps->st_size])
		add_mvs_to_list(ps, &stacks, rb);
	rb_rrb_trigger(ps, &stacks, stacks[A][up_a], up_b);
	*st = stacks;
}

void	smaller_return(t_ps *ps, int ***st)
{
	int	**stacks;

	stacks = *st;
	while (stacks[B][ps->st_size] != smaller_fct(ps, stacks[B]))
	{
		if (smaller_index(ps, stacks[B]) > ps->st_size - stacks[B][0] / 2)
			add_mvs_to_list(ps, &stacks, rrb);
		else
			add_mvs_to_list(ps, &stacks, rb);
	}
	*st = stacks;
}

void	sort_that_multi_bloc_shit(int ***st, t_ps *ps)
{
	int	**stacks;
	int	current_nb;
	int	bloc_range;
	int	last_bloc_range;

	stacks = *st;
	init_sort(&current_nb, &bloc_range, &last_bloc_range);
	while (current_nb <= ps->st_size)
	{
		bloc_range = range_selector(ps->bloc_data, current_nb);
		add_ra_rra(ps, &stacks, current_nb, bloc_range);
		if (bloc_range == last_bloc_range)
			add_rb_rrb(ps, &stacks);
		else
			smaller_return(ps, &stacks);
		add_mvs_to_list(ps, &stacks, pb);
		last_bloc_range = bloc_range;
		current_nb++;
	}
	while (stacks[B][ps->st_size] != 1)
		add_mvs_to_list(ps, &stacks, rrb);
	while (stacks[B][0] > 0)
		add_mvs_to_list(ps, &stacks, pa);
	*st = stacks;
}
