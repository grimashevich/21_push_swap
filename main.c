/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:38:05 by EClown            #+#    #+#             */
/*   Updated: 2022/02/03 18:22:10 by EClown           ###   ########.fr       */
/*                                                                            */
/* *************************r************************************************* */

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
	int	result;

	size = (end - start + 1);
	pivot = size / 2 + start;
	if (haystack[pivot] == needle)
		return (pivot);
	if (size == 1)
		return (-1);
	result = binary_search(needle, haystack, start, pivot - 1);
	if (result < 0)
		result = binary_search(needle, haystack, pivot, end);
	return (result);
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

void update_idexes(t_dlist *lst)
{
	int		*array;
	int		size;
	int		i;
	t_item	*item;

	i = 0;
	size = lst_count(lst);
	array = create_array_from_stack(lst, size);
	if (! array)
		return ;
	array_quick_sort(array, size);
	item = lst->first;
	while (i < size)
	{
		item->index = binary_search(item->value, array, 0, size - 1);
		item = item->next;
		i++;
			
	}
	free(array);
}

int main(void)
{
	t_dlist *lst_a;
	t_dlist *lst_b;
	int		size;

	srand(time(NULL));
	size = 10;
	lst_a = get_stack(size);
	lst_b = create_list();
	update_idexes(lst_a);
	//print_lists(lst_a, lst_b);
	manual_manipulation(lst_a, lst_b);
	free_lists(lst_a, lst_b);
	return (0);
}