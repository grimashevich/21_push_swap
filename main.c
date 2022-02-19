/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:38:05 by EClown            #+#    #+#             */
/*   Updated: 2022/02/19 21:12:20 by EClown           ###   ########.fr       */
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

int binary_search_place(int needle, int *haystack, int start, int end)
{
	int	pivot;
	int	size;

	size = (end - start + 1);
	pivot = size / 2 + start;
	if (haystack[pivot] > needle && haystack[pivot - 1] < needle)
		return (pivot);
	if (size == 2)
		return (-1);
	if (needle < haystack[pivot])
		return (binary_search_place(needle, haystack, start, pivot - 1));
	return (binary_search_place(needle, haystack, pivot, end));
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

int *update_idexes(t_dlist *lst)
{
	int		*array;
	int		size;
	int		i;
	t_item	*item;

	i = 0;
	size = lst_count(lst);
	array = create_array_from_stack(lst->first, size);
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
	// printf("   - - - - - %d - - - - -| %s\n", ++count, command);
	auto_manipulation(ps->stack_a, ps->stack_b, command);
	ps->my_count++;
	if (! ft_strncmp("pb", command, 3))
	{
		if (ps->stack_b->first == ps->stack_b->last)
		{
			ps->stack_b->max = ps->stack_b->first;
			ps->stack_b->min = ps->stack_b->first;
			ps->stack_b->size = 1;
		}
		else
		{
			if (ps->stack_b->first->value > ps->stack_b->max->value)
				ps->stack_b->max = ps->stack_b->first;
			else if (ps->stack_b->first->value < ps->stack_b->min->value)
				ps->stack_b->min = ps->stack_b->first;
			ps->stack_b->size++;
		}
	}
	
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



//TODO Will die
int is_place_for_push(t_pushswap *ps, t_item *a_item, t_item *b_item)
{
	// if (a_item->value > b_item->value && a_item->value > b_item->prev->value)
	// 	return (0);
	// if (a_item->value < b_item->value && a_item->value < b_item->prev->value)
	// 	return (0);
	if (a_item->value > b_item->value && a_item->value < b_item->prev->value)
		return (1);
	// if (a_item->value < ps->min_b && 
	// 		ps->min_b == b_item->prev->value && ps->max_b == b_item->value)
	// 	return (1);
	// if (a_item->value > ps->max_b &&
	// 		ps->min_b == b_item->prev->value && ps->max_b == b_item->value)
	// 	return (1);
	if (a_item->value > ps->stack_b->max->value && b_item == ps->stack_b->max)
		return (1);
	if (a_item->value < ps->stack_b->min->value &&  b_item->prev == ps->stack_b->min)
		return (1);
	return (0);

}

/*
1. Создает 4 стека команд по 2 для a и b (прямой и обратный проход)
2. Компанует, выбирает оптимальный по стоимости.
3. Сравнивает со стеком prev_best, выбирает лучший, а второй удаляет.
*/

//TODO Will die
t_todo *get_best_push_b(t_pushswap *ps, t_item *a_item, t_todo *prev_best)
{
	t_item			*current;
	t_todo_rotate	todo4;
	t_todo			*best;

	t_todo_rotate_init(&todo4);
	current = a_item;
	while (current != ps->stack_a->first)
		update_todo4(&todo4, 'a', 'd', &current);
	current = ps->stack_b->first;
	while (! is_place_for_push(ps, a_item, current))
		update_todo4(&todo4, 'b', 'd', &current);
	current = a_item;
	while (current != ps->stack_a->first)
		update_todo4(&todo4, 'a', 'u', &current);
	current = ps->stack_b->first;
	while (! is_place_for_push(ps, a_item, current))
		update_todo4(&todo4, 'b', 'u', &current);
	best = get_best_from_todo4(&todo4);
	best = choose_best_todo(&prev_best, &best);
	return (best);
}

/*
Функция выбирает лучшый вариант для пуша в stack_b и вызывает его
*/
void push_b_best(t_pushswap *ps, int a_size)
{
	/*
	t_todo	*best_push_b;
	t_todo	*prev_best_push_b;
	int		best_push_size;
	int		border_distance;
	*/

	int		i;
	t_rc	*new_rc;
	t_rc	*best_rc;
	t_item	*current;
	int		*b_array;
	int		first_b_index;

	if (ps->size - a_size < 2)
	{
		do_command(ps, "pb");
		//do_todo(ps, create_todo("pb"));
		return ;
	}
/*
		current = ps->stack_a->first;
		best_push_b = NULL;
		i = 0;
		best_push_size = 1;
		while (1)
		{
			border_distance = min_int(i, a_size - i);
			i++;
			if (border_distance > best_push_size )
			{
				current = current->next;
				continue;
			}
			prev_best_push_b = best_push_b;
			best_push_b = get_best_push_b(ps, current, best_push_b);
			if (prev_best_push_b != best_push_b)
				best_push_size = todo_count(best_push_b);
			current = current->next;
			if (current == ps->stack_a->first || i > ps->size)
				break;
		}
*/	
	b_array = create_array_from_stack_rev(ps->stack_b->min, ps->size - a_size);
	first_b_index = binary_search(ps->stack_b->first->value, b_array, 0, ps->size - a_size);
	current = ps->stack_a->first->prev;
	best_rc = create_rc();
	best_rc->total = ps->size + 1;
	//best_rc->ra = 0;
	//best_rc->rra = 0;
	//pre_fill_rc(ps, b_array, ps->size - a_size, current->value, best_rc, first_b_index);
	//finish_fill_rc(best_rc);
	i = 0;
	while (i++ < a_size)
	{
		current = current->next;
		if (min_int(i - 1, a_size - i + 1) >= best_rc->total)
			continue;
		new_rc = create_rc();
		new_rc->ra = i - 1;
		new_rc->rra = (a_size - i + 1) % a_size;
		pre_fill_rc(ps, b_array, ps->size - a_size, current->value, new_rc, first_b_index);
		finish_fill_rc(new_rc);
		best_rc = choose_best_rc(best_rc, new_rc);
	}
	do_rc(ps, best_rc);
	free(b_array);
}


/*
Until stack a elements count > 0 make push to stack b
*/
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

void sort_stage2(t_pushswap *ps)
{
	if (ps->stack_b->first->value <= ps->median)
	{
		while (ps->stack_b->first->value != ps->max)
			do_command(ps, "rb");
		return ;
	}
	while (ps->stack_b->first->value != ps->max)
		do_command(ps, "rrb");
}

void sort_stage3(t_pushswap *ps)
{
	int	i;

	i = ps->size;
	while (i-- > 0)
		do_command(ps, "pa");
}

void sort_stack(t_pushswap *ps)
{
	sort_stage1(ps);
	sort_stage2(ps);
	sort_stage3(ps);
}

void update_math_stat(t_pushswap *ps)
{
	int	median_index = ps->size / 2 - 1;

	ps->median = ps->sorted_array[median_index + 1];
	ps->sub_median = ps->sorted_array[median_index];
	ps->min = ps->sorted_array[0];
	ps->max = ps->sorted_array[ps->size - 1];
	ps->my_count = 0;
}

t_dlist *get_my_stack(int arr[], int size)
{
	t_dlist	*list;
	int		i;

	i = 0;
	list = create_list();
	if (! list)
		return (NULL);
	
	while (i < size)
		create_add_item_to_list(arr[i++], list);
	return(list);
}

void check_stack(t_pushswap *ps) //TODO Удалить перед сдачей
{
	t_item *tmp;
	tmp = ps->stack_a->first;
	for (int i = 0; i < ps->size - 1; i++)
	{
		if (tmp->value > tmp->next->value)
		{
			printf("ERROR: i=%d\n", i);
			return;
		}
		tmp = tmp->next;
	}
	printf("stack order is OK...\n");
}

int main(int argc, char *argv[])
{	/*
	int a[6] = {0,1,2,3,5,9};
	printf("%d\n", binary_search_place(8, &a[0], 0, 5));
	return (0);
	*/

	#include <sys/time.h>
	struct timeval stop, start;
	gettimeofday(&start, NULL);

	t_pushswap	*ps;
	//unsigned long curtime =  time(NULL);
	ps = malloc(sizeof(t_pushswap));
	if (! ps)
		return (1);

	srand(time(NULL));
	
	if (argc < 2)
		ps->size = 10;
	else
		ps->size = ft_atoi(argv[1]);
	ps->stack_a = get_stack(ps->size);
	//int arr[10] = {6,8,3,9,5,2,7,1,4,0};
	//ps->stack_a = get_my_stack(arr, 10);
	ps->stack_b = create_list();
	ps->sorted_array = update_idexes(ps->stack_a);
	update_math_stat(ps);
	
	print_lists(ps->stack_a, ps->stack_b);
	usleep(USLEEP_TIME);
	sort_stack(ps);
	printf("\n\n");
	//manual_manipulation(ps->stack_a, ps->stack_b);
	//printf("Execution time: %lu sec.\n", time(NULL) - curtime);
	gettimeofday(&stop, NULL);
	printf("Work time: %lu ms, (%d moves)\n", ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec) / 1000,
			ps->my_count);
	check_stack(ps);

	
	free_ps_struct(ps);
	return (0);
}