/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_7.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:34:11 by EClown            #+#    #+#             */
/*   Updated: 2022/02/23 16:34:22 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	auto_manipulation(t_dlist *lst_a, t_dlist *lst_b, char input[4])
{
	if (! ft_strncmp("ra", input, 3))
		rotate(lst_a);
	else if (! ft_strncmp("rb", input, 3))
		rotate(lst_b);
	else if (! ft_strncmp("rr", input, 3))
		rotate_rotate(lst_a, lst_b);
	else if (! ft_strncmp("rra", input, 3))
		reverse_rotate(lst_a);
	else if (! ft_strncmp("rrb", input, 3))
		reverse_rotate(lst_b);
	else if (! ft_strncmp("rrr", input, 3))
		reverse_rotate_rotate(lst_a, lst_b);
	else if (! ft_strncmp("ss", input, 3))
		swap_swap(lst_a, lst_b);
	else if (! ft_strncmp("pa", input, 3))
		push(lst_b, lst_a);
	else if (! ft_strncmp("pb", input, 3))
		push(lst_a, lst_b);
	else if (! ft_strncmp("sa", input, 3))
		swap(lst_a);
	else if (! ft_strncmp("sb", input, 3))
		swap(lst_b);
}

void	swap_int(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	binary_search(int needle, int *haystack, int start, int end)
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

int	binary_search_place(int needle, int *haystack, int start, int end)
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
