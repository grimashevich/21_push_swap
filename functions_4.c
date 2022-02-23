/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:39:46 by EClown            #+#    #+#             */
/*   Updated: 2022/02/23 15:17:14 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stage1(t_ps *ps)
{
	int	stack_a_size;

	stack_a_size = lst_count(ps->stack_a);
	while (stack_a_size > 0)
	{
		push_b_best(ps, stack_a_size);
		stack_a_size--;
	}	
}

void	sort_stage2(t_ps *ps)
{
	if (ps->stack_b->first->value <= ps->median)
	{
		while (ps->stack_b->first->value != ps->max)
			do_command(ps, "rb");
		return ;
	}
	while (ps->stack_b->first->value != ps->max)
		do_command(ps, "rrb");
}

void	sort_stage3(t_ps *ps)
{
	int	i;

	i = ps->size;
	while (i-- > 0)
		do_command(ps, "pa");
}

void	sort_stack(t_ps *ps)
{
	sort_stage1(ps);
	sort_stage2(ps);
	sort_stage3(ps);
}

void	update_math_stat(t_ps *ps)
{
	int	median_index;

	median_index = ps->size / 2 - 1;
	ps->median = ps->sorted_array[median_index + 1];
	ps->sub_median = ps->sorted_array[median_index];
	ps->min = ps->sorted_array[0];
	ps->max = ps->sorted_array[ps->size - 1];
	ps->my_count = 0;
}
