/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:39:46 by EClown            #+#    #+#             */
/*   Updated: 2022/02/23 15:15:32 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs_int(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	*create_array_from_stack(t_item *item, int size)
{
	int		*result;
	int		i;

	result = malloc(sizeof(int) * size);
	if (! result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i++] = item->value;
		item = item->next;
	}
	return (result);
}

int	*create_array_from_stack_rev(t_item *item, int size)
{
	int		*result;
	int		i;

	result = malloc(sizeof(int) * size);
	if (! result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i++] = item->value;
		item = item->prev;
	}
	return (result);
}

int	min_int_from4(int m1, int m2, int m3, int m4)
{
	return (min_int(min_int(m1, m2), min_int(m3, m4)));
}

void	array_quick_sort(int *arr, int size)
{
	int	wall;
	int	pivot;
	int	j;

	if (size <= 1)
		return ;
	wall = -1;
	pivot = arr[size - 1];
	j = 0;
	while (j < size - 1)
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
