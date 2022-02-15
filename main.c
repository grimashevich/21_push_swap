/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:38:05 by EClown            #+#    #+#             */
/*   Updated: 2022/02/15 22:08:42 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h> //TODO Удалить перед сдачей

t_dlist *get_stack(int size) //TODO Удалить перед сдачей
{
	t_dlist	*list;
	t_dlist	*list2;
	int		i;
	int		tmp;

	i = 0;
	list = create_list();
	if (! list)
		return (NULL);
	list2 = create_list();
	if (! list2)
		return (NULL);
	
	while (i < size)
		create_add_item_to_list(i++, list);
	while (i > 0)
	{
		tmp = rand() % i;
		while (tmp-- >= 0)
			rotate(list);
		push(list, list2);
		i--;
	}
	free(list);
	return(list2);
}


void auto_manipulation(t_dlist *lst_a, t_dlist *lst_b, char input[4])
{
	if (! ft_strncmp("sa", input, 3))
	{
		swap(lst_a);
		print_lists(lst_a, lst_b);
	}
	else if (! ft_strncmp("sb", input, 3))
	{
		swap(lst_b);
		print_lists(lst_a, lst_b);
	}
	else if (! ft_strncmp("ss", input, 3))
	{
		swap(lst_a);
		swap(lst_b);
		print_lists(lst_a, lst_b);
	}
	else if (! ft_strncmp("pa", input, 3))
	{
		push(lst_b, lst_a);
		print_lists(lst_a, lst_b);
	}
	else if (! ft_strncmp("pb", input, 3))
	{
		push(lst_a, lst_b);
		print_lists(lst_a, lst_b);
	}
	else if (! ft_strncmp("ra", input, 3))
	{
		rotate(lst_a);
		print_lists(lst_a, lst_b);	
	}
	else if (! ft_strncmp("rb", input, 3))
	{
		rotate(lst_b);
		print_lists(lst_a, lst_b);	
	}
	else if (! ft_strncmp("rr", input, 3))
	{
		rotate(lst_a);
		rotate(lst_b);
		print_lists(lst_a, lst_b);	
	}
	else if (! ft_strncmp("rra", input, 3))
	{
		reverse_rotate(lst_a);
		print_lists(lst_a, lst_b);	
	}
	else if (! ft_strncmp("rrb", input, 3))
	{
		reverse_rotate(lst_b);
		print_lists(lst_a, lst_b);	
	}
	else if (! ft_strncmp("rrr", input, 3))
	{
		reverse_rotate(lst_a);
		reverse_rotate(lst_b);
		print_lists(lst_a, lst_b);	
	}
}


void manual_manipulation(t_dlist *lst_a, t_dlist *lst_b)
{
	int	count;
	
	count = 0;
	print_lists(lst_a, lst_b);	
	printf("- - - - - - - - - - - - - -\n");
	while (1)
	{
		char input[256];

		printf("Enter command for stack: (%d)\n", count++);
		scanf("%s",input);
		if (! ft_strncmp("sa", input, 3))
		{
			swap(lst_a);
			print_lists(lst_a, lst_b);
		}
		else if (! ft_strncmp("sb", input, 3))
		{
			swap(lst_b);
			print_lists(lst_a, lst_b);
		}
		else if (! ft_strncmp("ss", input, 3))
		{
			swap(lst_a);
			swap(lst_b);
			print_lists(lst_a, lst_b);
		}
		else if (! ft_strncmp("pa", input, 3))
		{
			push(lst_b, lst_a);
			print_lists(lst_a, lst_b);
		}
		else if (! ft_strncmp("pb", input, 3))
		{
			push(lst_a, lst_b);
			print_lists(lst_a, lst_b);
		}
		else if (! ft_strncmp("ra", input, 3))
		{
			rotate(lst_a);
			print_lists(lst_a, lst_b);	
		}
		else if (! ft_strncmp("rb", input, 3))
		{
			rotate(lst_b);
			print_lists(lst_a, lst_b);	
		}
		else if (! ft_strncmp("rr", input, 3))
		{
			rotate(lst_a);
			rotate(lst_b);
			print_lists(lst_a, lst_b);	
		}
		else if (! ft_strncmp("rra", input, 3))
		{
			reverse_rotate(lst_a);
			print_lists(lst_a, lst_b);	
		}
		else if (! ft_strncmp("rrb", input, 3))
		{
			reverse_rotate(lst_b);
			print_lists(lst_a, lst_b);	
		}
		else if (! ft_strncmp("rrr", input, 3))
		{
			reverse_rotate(lst_a);
			reverse_rotate(lst_b);
			print_lists(lst_a, lst_b);	
		}
		else if (! ft_strncmp("0", input, 2))
			break ;
		else
			count--;
	}
}

void swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

int binary_search(int needle, int *haystack, int start, int end)
{
	int	pivot;
	int	size;

	size = (end - start + 1);
	pivot = size / 2 + start;
	if (haystack[pivot] == needle)
		return (pivot);
	if (size == 1)
		return (-1);
	if (needle < haystack[pivot])
		return (binary_search(needle, haystack, start, pivot - 1));
	return (binary_search(needle, haystack, pivot, end));
}

void array_quick_sort(int *arr, int size)
{
	int	wall;
	int pivot;
	int	j;

	if (size <= 1)
		return;

	wall = -1;
	pivot = arr[size - 1];
	j = 0;
	while (j < size -1)
	{
		if (arr[j] < pivot)
		{
			wall++;
			swap_int(&(arr[wall]), &(arr[j]));
		}
		j++;
	}
	wall++;
	swap_int(&(arr[wall]), &(arr[size - 1]));
	array_quick_sort(arr, wall);
	array_quick_sort(&(arr[wall + 1]), size - wall - 1);
}

t_dlist *copy_stack(t_dlist *lst)
{
	t_dlist *lst_copy;
	t_item	*item;
	int		size;

	size = lst_count(lst);
	lst_copy = create_list();
	if (! lst_copy)
		return (NULL);
	item = lst->first;
	while (size)
	{
		create_add_item_to_list(item->value, lst_copy);
		item = item->next;
		size--;
	}
	return(lst_copy);
}

void print_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		printf("%5d", arr[i++]);
	printf("\n");
}

int *create_array_from_stack(t_dlist *lst, int size)
{
	int		*result;
	t_item	*item;
	int		i;

	result = malloc(sizeof(int) * size);
	if (! result)
		return (NULL);
	item = lst->first;
	i = 0;
	while (i < size)
	{
		result[i++] = item->value;
		item = item->next;
	}
	return (result);	
}

int *update_idexes(t_dlist *lst)
{
	int		*array;
	int		size;
	int		i;
	t_item	*item;

	i = 0;
	size = lst_count(lst);
	array = create_array_from_stack(lst, size);
	if (! array)
		return (NULL);
	array_quick_sort(array, size);
	item = lst->first;
	while (i < size)
	{
		item->index = binary_search(item->value, array, 0, size - 1);
		item = item->next;
		i++;
	}
	return (array);
}

//TODO Перед сдачей переделать в принтер команд
void do_command(t_pushswap *ps, char command[4])
{
	static int count;
	printf("   - - - - - %d - - - - -\n", ++count);
	auto_manipulation(ps->stack_a, ps->stack_b, command);
	usleep(USLEEP_TIME);
}

/*
check 2 integers order for stack a (0) or stack b (1)
a - upper
b - lower
*/
int is_normal_order(t_pushswap *ps, int a, int b, int stack)
{
	if (stack == 0)
	{
		if (a == ps->max && b == ps->median)
			return (1);
		if (a == ps->median && b == ps->max)
			return (0);
		return (a < b);
	}
	else if (stack == 1)
	{
		if (a == ps->min && b == ps->sub_median)
			return (1);
		if (a == ps->sub_median && b == ps->min)
			return (0);
		return (a > b);
	}
	return (0);
}

void is_stacks_sorted(t_pushswap *ps ,t_sort_stage2 *s2)
{
	t_item	*item;
	t_item	*item2;
	int		i;

	if (s2->sorted1 && s2->sorted2)
		return ;
	item = ps->stack_a->first;
	item2 = ps->stack_b->first;
	s2->sorted1 = 1;
	s2->sorted2 = 1;
	i = 0;
	while (i++ <= ps->size / 2 + 1)
	{
		if (s2->sorted1 && ! is_normal_order(ps, item->value, item->next->value, 0))
			s2->sorted1 = 0;
		if (s2->sorted2 && ! is_normal_order(ps, item2->value, item2->next->value, 1))
			s2->sorted2 = 0;
		if (! s2->sorted1 && ! s2->sorted2)
			break;
		item = item->next;
		item2 = item2->next;
	}
}


void do_todo(t_pushswap *ps, t_todo *item)
{
	t_todo	*tmp;

	tmp = item;
	while (tmp)
	{
		do_command(ps, tmp->value);
		tmp = tmp->next;
	}
	clear_todo_list(&item);
}

int is_place_for_push(t_pushswap *ps, t_item *a_item, t_item *b_item)
{
	return (b_item->value < a_item->value  && 
			(b_item->prev->value > a_item->value || 
				b_item->prev->value == get_min(ps, 'b')));
}

/*
1. Создает 4 стека команд по 2 для a и b (прямой и обратный проход)
2. Компанует, выбирает оптимальный по стоимости.
3. Сравнивает со стеком prev_best, выбирает лучший, а второй удаляет.
*/

t_todo *get_best_push_b(t_pushswap *ps, t_item *a_item, t_todo *prev_best)
{
	t_item	*current;
	t_todo	*todo_a;
	t_todo	*todo_b;

	todo_a = NULL;
	todo_b = NULL;
	current = ps->stack_a->first;
	while (current != a_item)
	{
		todo_a = add_todo_last("ra", todo_a);
		current = current->next;
	}
	current = ps->stack_b->first;
	while (! is_place_for_push(ps, a_item, current))
	{
		todo_b = add_todo_last("rb", todo_b);
		current = current->next;
	}
	/* TODO Остановился тут, сделать 2 обратных прохода и желательно внутренности циклов
	в одну функцию */

	
}

void push_b_best(t_pushswap *ps, int a_size)
{
	t_todo	*best_push_b;
	t_item	*current;

	if (ps->size - a_size < 2)
	{
		do_todo(ps, create_todo("pb"));
		return ;
	}
	current = ps->stack_a->first;
	best_push_b = NULL;
	while (1)
	{
		best_push_b = get_best_push_b(ps, current, best_push_b);
		current = current->next;
		if (current == ps->stack_a->first)
			break;
	}
	
}

void sort_stage1(t_pushswap *ps)
{
	int	stack_a_size;

	stack_a_size = lst_count(ps->stack_a);
	while (stack_a_size > 0)
	{
		push_b_best(ps, stack_a_size);
		stack_a_size--;
	}	
}

void sort_stack(t_pushswap *ps)
{
	sort_stage1(ps);
}

void update_math_stat(t_pushswap *ps)
{
	int	median_index = ps->size / 2 - 1;

	ps->median = ps->sorted_array[median_index + 1];
	ps->sub_median = ps->sorted_array[median_index];
	ps->min = ps->sorted_array[0];
	ps->max = ps->sorted_array[ps->size - 1];
}

int main(void)
{
	t_pushswap	*ps;
	ps = malloc(sizeof(t_pushswap));
	if (! ps)
		return (1);

	srand(time(NULL));
	ps->size = 10;
	ps->stack_a = get_stack(ps->size);
	ps->stack_b = create_list();
	ps->sorted_array = update_idexes(ps->stack_a);
	update_math_stat(ps);
	
	print_lists(ps->stack_a, ps->stack_b);
	usleep(USLEEP_TIME);
	sort_stack(ps);
	//manual_manipulation(ps->stack_a, ps->stack_b);
	free_ps_struct(ps);
	return (0);
}