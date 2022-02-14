/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:38:05 by EClown            #+#    #+#             */
/*   Updated: 2022/02/14 22:47:18 by EClown           ###   ########.fr       */
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
	usleep(600000);
}
void sort_stage1(t_pushswap *ps)
{
	int		size_b;
	int		i;

	size_b = ps->size / 2;
	i = 0;
	while (1)
	{
		if (ps->stack_a->first->value <= ps->sub_median)
		{
			do_command(ps, "pb");
			i++;
			if (i == size_b)
				break;
			continue;
		}
		do_command(ps, "ra");
	}
	
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

void sort_stage2_vars_init(t_sort_stage2 *s2)
{
	s2->swap1 = 0;
	s2->swap2 = 0;
	s2->sorted1 = 0;
	s2->sorted2 = 0;
	s2->ordered1 = 0;
	s2->ordered2 = 0;
}

void sort_stage2(t_pushswap *ps)
{
	t_sort_stage2	s2;
	
	sort_stage2_vars_init(&s2);
	while (1)
	{	is_stacks_sorted(ps, &s2);
		s2.swap2 = 0;
		if (! s2.sorted1 && ! is_normal_order(ps, ps->stack_a->first->value, ps->stack_a->second->value,0))
			s2.swap1 = 1;
		s2.swap2 = 0;
		if (! s2.sorted2 && ! is_normal_order(ps, ps->stack_b->first->value, ps->stack_b->second->value,1))
			s2.swap2 = 1;
		s2.ordered1 = (s2.sorted1 && ps->stack_a->first->value == ps->median);
		s2.ordered2 = (s2.sorted2 && ps->stack_b->first->value == ps->sub_median);
		if (s2.ordered1 && s2.ordered2)
			break;
		if (s2.swap1 && s2.swap2)
			do_command(ps, "ss");
		else if (s2.swap1 && ! s2.swap2)
			do_command(ps, "sa");
		else if (! s2.swap1 && s2.swap2)
			do_command(ps, "sb");
		if (! s2.ordered1 && ! s2.ordered2)
			do_command(ps, "rr");
		else if (! s2.ordered1)
			do_command(ps, "ra");
		else
			do_command(ps, "rb");
	}
}

void sort_stack(t_pushswap *ps)
{
	sort_stage1(ps);
	sort_stage2(ps);
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
	
	sort_stack(ps);
	sleep(5);
	//print_lists(lst_a, lst_b);
	//manual_manipulation(ps->stack_a, ps->stack_b);
	free_ps_struct(ps);
	return (0);
}