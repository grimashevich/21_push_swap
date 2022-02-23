/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:19:50 by EClown            #+#    #+#             */
/*   Updated: 2022/02/23 16:19:58 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_free_exit(t_ps *ps)
{
	if (ps != NULL)
		free_ps_struct(ps);
	print_error();
}

t_ps	*ps_init(void)
{
	t_ps	*ps;

	ps = malloc(sizeof(t_ps));
	if (! ps)
		return (NULL);
	ps->sorted_array = NULL;
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	ps->stack_a = create_list();
	ps->stack_b = create_list();
	ps->size = 0;
	if (! ps->stack_a || ! ps->stack_b)
		error_free_exit(ps);
	return (ps);
}

void	free_split_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

void	add_argv_to_stack(t_ps *ps, int argc, char **argv)
{
	int		i;
	int		j;
	char	**arr;

	i = 1;
	while (i < argc)
	{
		j = 0;
		arr = ft_split(argv[i++], ' ');
		while (arr[j] != NULL)
		{
			if (! add_str_int_to_stack(ps, arr[j++]))
				error_free_exit(ps);
			ps->size++;
		}
		free_split_array(arr);
	}
}

int	is_sorted(t_ps *ps)
{
	t_item	*item;
	int		i;

	i = 0;
	item = ps->stack_a->first;
	while (i++ < ps->size - 1)
	{
		if (item->value > item->next->value)
			return (0);
		item = item->next;
	}
	return (1);
}
