/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manipulation2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:08:58 by EClown            #+#    #+#             */
/*   Updated: 2022/02/23 15:35:43 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_rotate(t_dlist *lst_a, t_dlist *lst_b)
{
	rotate(lst_a);
	rotate(lst_b);
}

void	reverse_rotate_rotate(t_dlist *lst_a, t_dlist *lst_b)
{
	reverse_rotate(lst_a);
	reverse_rotate(lst_b);
}

void	swap_swap(t_dlist *lst_a, t_dlist *lst_b)
{
	swap(lst_a);
	swap(lst_b);
}
