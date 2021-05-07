#include "push_swap.h"

int	is_mvs(char **content, t_list *l, char *mvs)
{
	*content = l->content;
	if (!ft_strncmp(*content, mvs, ft_strlen(*content)))
		return (1);
	return (0);
}

void	cnt_init(int cnt[4])
{
	int	i;

	i = -1;
	while (++i < 4)
		cnt[i] = 0;
}

void	cnt_mvs(char *mvs, int cnt[4])
{
	if (!ft_strncmp(mvs, "rra", 4))
		cnt[c_rra]++;
	else if (!ft_strncmp(mvs, "rrb", 4))
		cnt[c_rrb]++;
	else if (!ft_strncmp(mvs, "ra", 3))
		cnt[c_ra]++;
	else if (!ft_strncmp(mvs, "rb", 3))
		cnt[c_rb]++;
}
