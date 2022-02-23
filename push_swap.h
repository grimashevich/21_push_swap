/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:38:10 by EClown            #+#    #+#             */
/*   Updated: 2022/02/23 15:46:38 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

# define USLEEP_TIME 0

typedef struct s_item
{
	int				value;
	int				index;
	struct s_item	*prev;
	struct s_item	*next;
}	t_item;

typedef struct s_dlist
{
	t_item	*first;
	t_item	*second;
	t_item	*last;
	int		median;
	t_item	*min;
	t_item	*max;
	int		size;
}	t_dlist;

typedef struct s_pushswap
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;
	int		size;
	int		*sorted_array;
	int		median;
	int		sub_median;
	int		min;
	int		max;
	int		my_count;
	int		b_array;
}	t_ps;

typedef struct s_sort_stage2
{
	int	swap1;
	int	swap2;
	int	sorted1;
	int	sorted2;
	int	ordered1;
	int	ordered2;
}	t_sort_stage2;

typedef struct s_todo
{
	char			value[4];
	struct s_todo	*next;
}	t_todo;

typedef struct s_todo_rotate
{
	t_todo	*ra;
	t_todo	*rb;
	t_todo	*rra;
	t_todo	*rrb;
}	t_todo_rotate;

typedef struct s_rotate_count
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	rr;
	int	rrr;
	int	total;
}	t_rc;

typedef struct s_int
{
	int		i;
	int		first_b_ind;
	t_rc	*new_rc;
	t_rc	*best_rc;
	t_item	*current;
}	t_int;

t_item	*create_item(int value);
t_dlist	*create_list(void);
void	add_item_to_list(t_item *item, t_dlist *list);
int		lst_count(t_dlist *list);
void	print_lists(t_dlist *list_a, t_dlist *list_b);
void	delete_first_item(t_dlist *lst);
void	free_ps_struct(t_ps *ps);
void	swap(t_dlist *lst);
void	push(t_dlist *lst_from, t_dlist *lst_to);
void	rotate(t_dlist *lst);
void	reverse_rotate(t_dlist *lst);
int		create_add_item_to_list(int value, t_dlist *list);
int		get_max(t_ps *ps, char stack_name);
int		get_min(t_ps *ps, char stack_name);
int		min_int(int a, int b);
void	do_command(t_ps *ps, char command[4]);
int		binary_search_place(int needle, int *haystack, int start, int end);
int		abs_int(int n);
int		*create_array_from_stack(t_item *item, int size);
int		*create_array_from_stack_rev(t_item *item, int size);
int		binary_search(int needle, int *haystack, int start, int end);
int		binary_search_place(int needle, int *haystack, int start, int end);
int		min_int_from4(int m1, int m2, int m3, int m4);
void	rotate_count_sum(t_rc *rc);
void	rotate_count_forw(t_rc *rc);
void	rotate_count_back(t_rc *rc);
void	rotate_count_diff1(t_rc *rc);
void	rotate_count_diff2(t_rc *rc);
void	pre_fill_rc(t_ps *ps, int *b_array, int b_arr_size, t_int *str);
void	finish_fill_rc(t_rc *rc);
t_rc	*create_rc(void);
t_rc	*choose_best_rc(t_rc *rc1, t_rc *rc2);
void	do_rc(t_ps *ps, t_rc *rc);
int		is_normal_order(t_ps *ps, int a, int b, int stack);
void	sort_algov1_stage1(t_ps *ps);
void	sort_algov1_stage2_vars_init(t_sort_stage2 *s2, t_ps *ps);
void	sort_algov1_stage2(t_ps *ps);
void	sort_algov1_stage2_2(t_ps *ps, t_sort_stage2 *s2);
void	sort_algov1_stage3(t_ps *ps);
void	sort_algov1(t_ps *ps);
void	is_stacks_sorted(t_ps *ps, t_sort_stage2 *s2);
long	ft_atoi_long(const char *str);
void	rotate_rotate(t_dlist *lst_a, t_dlist *lst_b);
void	reverse_rotate_rotate(t_dlist *lst_a, t_dlist *lst_b);
void	swap_swap(t_dlist *lst_a, t_dlist *lst_b);
void	auto_manipulation(t_dlist *lst_a, t_dlist *lst_b, char input[4]);
void	swap_int(int *a, int *b);
void	array_quick_sort(int *arr, int size);
t_dlist	*copy_stack(t_dlist *lst);
int		*update_idexes(t_dlist *lst);
void	push_b_best2(t_ps *ps, int a_size, t_int *str, int *b_array);
void	push_b_best(t_ps *ps, int a_size);
void	sort_stage1(t_ps *ps);
void	sort_stage2(t_ps *ps);
void	sort_stage3(t_ps *ps);
void	sort_stack(t_ps *ps);
void	update_math_stat(t_ps *ps);
t_dlist	*get_my_stack(int arr[], int size);
int		is_numeric_str(char *str);
int		print_error(void);
int		add_str_int_to_stack(t_ps *ps, char *str);
int		has_double_int(t_ps *ps);
void	error_free_exit(t_ps *ps);
t_ps	*ps_init(void);
void	free_split_array(char **arr);
void	add_argv_to_stack(t_ps *ps, int argc, char **argv);
int		is_sorted(t_ps *ps);

#endif