/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:39:46 by EClown            #+#    #+#             */
/*   Updated: 2022/02/23 15:13:06 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_count(t_dlist *list)
{
	t_item	*item;
	int		count;

	if (list == NULL)
		return (0);
	item = list->first;
	if (item == NULL)
		return (0);
	count = 1;
	item = item->next;
	while (item != list->first)
	{
		count++;
		item = item->next;
	}
	return (count);
}

void	delete_first_item(t_dlist *lst)
{
	t_item	*first;

	if (lst->first == NULL)
		return ;
	first = lst->first;
	if (lst->first == lst->last)
	{
		lst->first = NULL;
		lst->second = NULL;
		lst->last = NULL;
	}
	else
	{
		lst->second->prev = lst->last;
		lst->last->next = lst->second;
		lst->first = first->next;
		lst->second = first->next->next;
	}
	free(first);
}

void	free_list(t_dlist *lst)
{
	while (lst->first)
		delete_first_item(lst);
	free(lst);
}

void	free_ps_struct(t_ps *ps)
{
	if (ps->stack_a != NULL)
		free_list(ps->stack_a);
	if (ps->stack_b != NULL)
		free_list(ps->stack_b);
	free(ps->sorted_array);
	free(ps);
}

int	get_max(t_ps *ps, char stack_name)
{
	t_item	*item;
	t_dlist	*stack;
	int		max_int;

	if (stack_name == 'a')
		stack = ps->stack_a;
	else
		stack = ps->stack_b;
	item = stack->first;
	max_int = item->value;
	item = item->next;
	while (item != stack->first)
	{
		if (item->value > max_int)
			max_int = item->value;
		item = item->next;
	}
	return (max_int);
}
