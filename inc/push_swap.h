#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "common.h"

typedef struct s_ps
{
	int		*bloc_data;
	int		st_size;
	t_list	*lst_mvs;
	t_tabs	t_;
	t_tabs	*t;
}t_ps;

void	init_sort(int *current_nb, int *bloc_range, int *last_bloc_range);
void	free_lst(t_list **lst);
void	display_lst(t_list *l);
void	display_lst_bloc(t_list *pb_start, t_list *pb_end, int fd);
void	simplify_data(int ac, int ***st);
void	sort_that_shit(int ***st, t_ps *ps);
void	sort_that_little_shit(int ***st, t_ps *ps, int p);
int		is_sort(int *stack, t_ps *ps);
void	add_mvs_to_list(t_ps *ps, int ***st, int mvs);
void	bloc_data_fct(int **stacks, t_ps *ps);
void	sort_that_multi_bloc_shit(int ***st, t_ps *ps);
int		range_selector(int *bloc_data, int current_nb);
int		smaller_index(t_ps *ps, int *stack);
int		smaller_fct(t_ps *ps, int *stack);
int		bigger_fct(t_ps *ps, int *stack);
void	lst_post_treatment(t_list *l);
int		is_mvs(char **content, t_list *l, char *mvs);
void	cnt_init(int cnt[4]);
void	cnt_mvs(char *mvs, int cnt[4]);

#endif