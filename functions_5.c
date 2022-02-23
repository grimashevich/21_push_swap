/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:39:46 by EClown            #+#    #+#             */
/*   Updated: 2022/02/23 15:18:24 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*get_my_stack(int arr[], int size)
{
	t_dlist	*list;
	int		i;

	i = 0;
	list = create_list();
	if (! list)
		return (NULL);
	while (i < size)
		create_add_item_to_list(arr[i++], list);
	return (list);
}

int	is_numeric_str(char *str)
{
	if (*str == '-')
		str++;
	if (*str == 0)
		return (0);
	while (*str)
	{
		if (! ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	add_str_int_to_stack(t_ps *ps, char *str)
{
	long	res;

	if (ft_strlen(str) > 10 || ! is_numeric_str(str))
		print_error();
	res = ft_atoi_long(str);
	if (res > 2147483647 || res < -2147483648)
		print_error();
	if (! create_add_item_to_list((int)res, ps->stack_a))
		print_error();
	return (1);
}

int	has_double_int(t_ps *ps)
{
	int	i;

	i = 0;
	while (i < ps->size - 1)
	{
		if (ps->sorted_array[i] == ps->sorted_array[i + 1])
			return (1);
		i++;
	}
	return (0);
}
