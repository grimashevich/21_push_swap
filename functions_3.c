/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:39:46 by EClown            #+#    #+#             */
/*   Updated: 2022/02/23 15:16:44 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*copy_stack(t_dlist *lst)
{
	t_dlist	*lst_copy;
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
	return (lst_copy);
}

int	*update_idexes(t_dlist *lst)
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

void	do_command(t_ps *ps, char command[4])
{
	ft_putstr_fd(command, 1);
	ft_putstr_fd("\n", 1);
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
}

void	push_b_best2(t_ps *ps, int a_size, t_int *str, int *b_array)
{
	str->current = str->current->next;
	if (min_int(str->i - 1, a_size - str->i + 1) >= str->best_rc->total)
		return ;
	str->new_rc = create_rc();
	str->new_rc->ra = str->i - 1;
	str->new_rc->rra = (a_size - str->i + 1) % a_size;
	pre_fill_rc(ps, b_array, ps->size - a_size, str);
	finish_fill_rc(str->new_rc);
	str->best_rc = choose_best_rc(str->best_rc, str->new_rc);
}

void	push_b_best(t_ps *ps, int a_size)
{
	t_int	str;
	int		*b_array;

	if (ps->size - a_size < 2)
	{
		do_command(ps, "pb");
		return ;
	}
	b_array = create_array_from_stack_rev(ps->stack_b->min, ps->size - a_size);
	str.first_b_ind = binary_search(ps->stack_b->first->value, b_array,
			0, ps->size - a_size);
	str.current = ps->stack_a->first->prev;
	str.best_rc = create_rc();
	str.best_rc->total = ps->size + 1;
	str.i = 0;
	while (str.i++ < a_size)
		push_b_best2(ps, a_size, &str, b_array);
	do_rc(ps, str.best_rc);
	free(b_array);
}
