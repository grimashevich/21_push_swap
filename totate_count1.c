/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totate_count1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:46:07 by EClown            #+#    #+#             */
/*   Updated: 2022/02/19 16:07:02 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Fill only rb and rrb
*/

void fill_pre_todo(t_pushswap *ps, int *array, int arr_size, int new, t_rotate_count *rc)
{
	int first_index;
	int	new_index;

	first_index = binary_search(ps->stack_b->first->value, array, 0, arr_size - 1);
	if (new > ps->stack_b->max->value || new < ps->stack_b->min->value)
	{
		rc->rrb = arr_size - 1 - first_index;
		rc->rb = (arr_size - rc->rrb) % arr_size;
		return;
	}
	new_index = binary_search_place(new, array, 0, arr_size - 1);
	rc->rrb = new_index - first_index;
	if (rc->rrb < 0)
	{
		rc->rb = rc->rrb * -1;
		rc->rrb = arr_size - rc->rb;
	}
	else
		rc->rb = (arr_size - rc->rrb) % arr_size;
}

void finish_pre_todo (t_rotate_count *rc)
{
	int forw;
	int back;
	int diff1;
	int diff2;
	int min;

	forw = abs_int(rc->ra - rc->rb);
	back = abs_int(rc->rra - rc->rrb);
	diff1 = rc->ra + rc->rrb;
	diff2 = rc->rra + rc->rb;
	min = min_int_from4(forw, back, diff1, diff2);
	if (min == forw)
		rotate_count_forw(rc);
	else if (min == back)
		rotate_count_back(rc);
	else if (min == diff1)
		rotate_count_diff1(rc);
	else
		rotate_count_diff2(rc);
}