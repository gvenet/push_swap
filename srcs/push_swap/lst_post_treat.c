#include "push_swap.h"

static void	replace_rra(t_list *pb_start, t_list *pb_end, int i)
{
	int		j;
	t_list	*p;
	t_list	*q;

	j = i;
	while (pb_start != pb_end && pb_start)
	{
		if (!ft_strncmp(pb_start->content, "rra", 4) && i)
		{
			i--;
			pb_start->content = "rrr";
		}
		if (!ft_strncmp(pb_start->content, "rrb", 4) && j)
		{
			j--;
			q = pb_start;
			free(pb_start);
			p->next = q->next;
			pb_start = p;
		}
		p = pb_start;
		pb_start = pb_start->next;
	}
}

static void	replace_ra(t_list *pb_start, t_list *pb_end, int i)
{
	int		j;
	t_list	*p;
	t_list	*q;

	j = i;
	p = pb_start;
	while (pb_start != pb_end && pb_start)
	{
		if (!ft_strncmp(pb_start->content, "ra", 3) && i)
		{
			i--;
			pb_start->content = "rr";
		}
		if (!ft_strncmp(pb_start->content, "rb", 3) && j)
		{
			j--;
			q = pb_start;
			free(pb_start);
			p->next = q->next;
			pb_start = p;
		}
		p = pb_start;
		pb_start = pb_start->next;
	}
}

static void	delete_elems(int cnt[4], t_list *pb_start, t_list *pb_end)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (cnt[c_ra] > 0 && cnt[c_rb] > 0)
	{
		while (cnt[c_ra] > 0 && cnt[c_rb] > 0)
		{
			i++;
			cnt[c_ra]--;
			cnt[c_rb]--;
		}
		replace_ra(pb_start, pb_end, i);
	}
	else if (cnt[c_rra] > 0 && cnt[c_rrb] > 0)
	{
		while (cnt[c_rra] > 0 && cnt[c_rrb] > 0)
		{
			j++;
			cnt[c_rra]--;
			cnt[c_rrb]--;
		}
		replace_rra(pb_start, pb_end, j);
	}
}

void	lst_post_treatment(t_list *l)
{
	t_list	*pb_start;
	t_list	*pb_end;
	char	*mvs;
	int		cnt[4];

	while (l)
	{
		if (is_mvs(&mvs, l, "pb"))
		{
			pb_start = l->next;
			pb_end = l->next;
			cnt_init(cnt);
			while (!is_mvs(&mvs, pb_end, "pb") && !is_mvs(&mvs, pb_end, "pa"))
			{
				cnt_mvs(mvs, cnt);
				pb_end = pb_end->next;
			}
			delete_elems(cnt, pb_start, pb_end);
		}
		l = l->next;
	}
}
