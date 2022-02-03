/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manioulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:52:51 by EClown            #+#    #+#             */
/*   Updated: 2022/02/03 18:23:26 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_dlist *lst)
{
	int	n;

	if (lst_count(lst) < 2)
		return ;
	n = lst->first->value;
	lst->first->value = lst->second->value;
	lst->second->value = n;
}

void push(t_dlist *lst_from, t_dlist *lst_to)
{
	int	value;

	value = lst_from->first->value;
	delete_first_item(lst_from);
	add_item_to_list(create_item(value), lst_to);
	//TODO reverse rotate
}

//TODO Останавился тут