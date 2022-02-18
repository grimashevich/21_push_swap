/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:38:10 by EClown            #+#    #+#             */
/*   Updated: 2022/02/17 18:06:53 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include <stdio.h>		//TODO Удалить перед сдачей

#define USLEEP_TIME 0

typedef struct s_item
{
	int		value;
	int		index;
	struct s_item	*prev;
	struct s_item	*next;
	
} t_item;

typedef struct s_dlist
{
	t_item	*first;
	t_item	*second;
	t_item	*last;
	int		median;
} t_dlist;

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
	int		max_b;
	int		min_b;
	int		my_count;
} t_pushswap;

typedef struct s_sort_stage2
{
	int	swap1;
	int	swap2;
	int	sorted1;
	int	sorted2;
	int	ordered1;
	int	ordered2;
} t_sort_stage2;

typedef struct s_todo
{
	char			value[4];
	struct s_todo	*next;
} t_todo;

typedef struct s_todo_rotate
{
	t_todo	*ra;
	t_todo	*rb;
	t_todo	*rra;
	t_todo	*rrb;
} t_todo_rotate;

t_item	*create_item(int value);
t_dlist	*create_list();
void	add_item_to_list(t_item *item, t_dlist *list);
int		lst_count(t_dlist *list);
void	print_lists(t_dlist *list_a, t_dlist *list_b);
void	delete_first_item(t_dlist *lst);
void	free_ps_struct(t_pushswap *ps);
void	swap(t_dlist *lst);
void	push(t_dlist *lst_from, t_dlist *lst_to);
void	rotate(t_dlist *lst);
void	reverse_rotate(t_dlist *lst);
void	create_add_item_to_list(int value,t_dlist *list);
int		get_max(t_pushswap *ps, char stack_name);
int		get_min(t_pushswap *ps, char stack_name);
t_todo	*create_todo(const char *str);
void	clear_todo_list(t_todo **first_item);
t_todo	*add_todo_last(char value[4], t_todo *first_item);
t_todo *get_best_push_b(t_pushswap *ps, t_item *a_item, t_todo *prev_best);
int		todo_count(t_todo *todo);
int		min_int(int a, int b);

/*
10
	|  |    |  |
	|  |    |  |
	|  |    |  |
	| 9|    | 0|
	|  |    |  |
	| 5|    | 4|
	| 6|    | 3|
	| 7|    | 2|
	| 8|    | 1|
	| 9|    | 0|

	| 5|    | 4|
*/


/*
10
	|  |    |  |
	|  |    |  |
	|  |    |  |
	|10|    | 0|
	|  |    |  |
	| 5|    |  |
	| 6|    | 4|
	| 7|    | 3|
	| 8|    | 2|
	| 9|    | 1|
	|10|	| 0|
*/


/*
Если встретили неверно выставленные элементы в левом стэке
до того, как заполнили правый - делаем swap. ????
*/

/*
Оптимизация алгоритма 2

Можно запушить число в стэк Б на 1 ротэйт раньше, если двойной своп 
	полезен так же для стека А.

*/


/*

	|  |	|  |
	|  |	|  |
	|  |	|  |
	|  |	| 1|
	|  |	| 0|
	|  |	| 9|
	|  |	| 6|
	| 5|	| 4|
	| 8|	| 3|
	| 9|	| 2|


	|  |	|  |
	|  |	|  |
	| 2|	|  |
	| 0|	| 3|
	| 1|	| 4|


*/