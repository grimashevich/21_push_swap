/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:39:46 by EClown            #+#    #+#             */
/*   Updated: 2022/02/23 15:14:26 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_item	*create_item(int value)
{
	t_item	*item;

	item = malloc(sizeof(t_item));
	if (item == NULL)
		return (NULL);
	item->value = value;
	item->index = 0;
	item->next = NULL;
	item->prev = NULL;
	return (item);
}

t_dlist	*create_list(void)
{
	t_dlist	*list;

	list = malloc(sizeof(t_dlist));
	if (list == NULL)
		return (NULL);
	list->first = NULL;
	list->last = NULL;
	list->second = NULL;
	return (list);
}

void	add_item_to_list(t_item *item, t_dlist *list)
{
	if (list == NULL || item == NULL)
		return ;
	if (list->first == NULL)
	{
		item->next = item;
		item->prev = item;
		list->first = item;
		list->last = item;
		return ;
	}
	item->next = list->first;
	item->prev = list->last;
	list->last->next = item;
	list->first->prev = item;
	list->last = item;
	list->second = list->first->next;
}

int	create_add_item_to_list(int value, t_dlist *list)
{
	t_item	*item;

	item = create_item(value);
	if (! item)
		return (0);
	add_item_to_list(item, list);
	return (1);
}

int	get_min(t_ps *ps, char stack_name)
{
	t_item	*item;
	t_dlist	*stack;
	int		min_int;

	if (stack_name == 'a')
		stack = ps->stack_a;
	else
		stack = ps->stack_b;
	item = stack->first;
	min_int = item->value;
	item = item->next;
	while (item != stack->first)
	{
		if (item->value < min_int)
			min_int = item->value;
		item = item->next;
	}
	return (min_int);
}
