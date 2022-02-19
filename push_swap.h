/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:38:10 by EClown            #+#    #+#             */
/*   Updated: 2022/02/19 20:47:56 by EClown           ###   ########.fr       */
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
	t_item	*min;
	t_item	*max;
	int		size;
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
	int		my_count;
	int		b_array;
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

typedef struct s_rotate_count
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	rr;
	int	rrr;
	int	total;
} t_rc;

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
void	do_todo(t_pushswap *ps, t_todo *item);
void	t_todo_rotate_init(t_todo_rotate *todo4);
void	add_todo_and_scroll(char str[4], t_todo **todo_list, t_todo **scroll);
t_todo	*merge_todo(t_todo *todo1, t_todo *todo2);
t_todo	*choose_best_todo(t_todo **todo1, t_todo **todo2);
t_todo	*get_best_from_todo4(t_todo_rotate *todo4);
void	update_todo4(t_todo_rotate *todo4, char stack, char direction, t_item **current);
void	do_command(t_pushswap *ps, char command[4]);
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
void	pre_fill_rc(t_pushswap *ps, int *b_array, int b_arr_size, int new, t_rc *rc, int first_b_index);
void	finish_fill_rc(t_rc *rc);
t_rc	*create_rc(void);
t_rc	*choose_best_rc(t_rc *rc1, t_rc *rc2);
void	do_rc(t_pushswap *ps, t_rc *rc);

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
	|  |	|  |
	|  |	|  |
	|  |	|  |
	|  |	|  |
	|  |	|  |  
	|  |	| 5|	 4
	|  |	| 4|	 3
	|  |	| 3|	 2
	|  |	| 1|	 1
	| 2|	| 0|	 0
	|11|	|19|	11
	|18|	|17|	10
	|14|	|16|	 9
	|10|	|15|	 8
	| 9|	|12|	 7
	|13|	| 8|	 6
	| 7|	| 6|	 5




	|  |	|  |
	|  |	|  |
	|  |	|  |
	|  |	|  |
	|  |	|  |
	| 5|	| 0|	[0]
	| 4|	| 8|	[4]
	| 2|	| 7|	[3]
	| 1|	| 6|	[2]
	| 9|	| 3|	[1]

						[0] [1] [2] [3] [4]

 Отдаю функции формирования массива min элемент, она сразу формирует правильно
 расподложенный массив.

 Функция, которая ищет правильное местов массиве для нового числа, заполняет
 пред-todo для него	
	Если новое число > max ИЛИ новое число меньше min, return max
	
 Функция, которая заполняет новую структуру с кол-вом движений в обе стороны

 Фукнция, которая формирует один оптимальный todo и отдает его на исполнение
*/