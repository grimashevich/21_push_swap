/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algov1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:19:49 by EClown            #+#    #+#             */
/*   Updated: 2022/02/23 15:46:21 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_normal_order(t_ps *ps, int a, int b, int stack)
{
	if (stack == 0)
	{
		if (ps->size == 4 && ps->stack_b->size == 2 && a < b)
			return (1);
		if (a == ps->max && b == ps->median)
			return (1);
		if (a == ps->median && b == ps->max)
			return (0);
		return (a < b);
	}
	else if (stack == 1)
	{
		if (ps->stack_b->size == 2 && a >= b)
			return (1);
		if (a == ps->min && b == ps->sub_median)
			return (1);
		if (a == ps->sub_median && b == ps->min)
			return (0);
		return (a > b);
	}
	return (0);
}

void	is_stacks_sorted(t_ps *ps, t_sort_stage2 *s2)
{
	t_item	*item;
	t_item	*item2;
	int		i;

	if (s2->sorted1 && s2->sorted2)
		return ;
	item = ps->stack_a->first;
	item2 = ps->stack_b->first;
	s2->sorted1 = 1;
	s2->sorted2 = 1;
	i = 0;
	while (i++ <= ps->size / 2 + 1)
	{
		if (s2->sorted1 && ! is_normal_order(ps, item->value,
				item->next->value, 0))
			s2->sorted1 = 0;
		if (s2->sorted2 && ! is_normal_order(ps, item2->value,
				item2->next->value, 1))
			s2->sorted2 = 0;
		if (! s2->sorted1 && ! s2->sorted2)
			break ;
		item = item->next;
		item2 = item2->next;
	}
}

void	sort_algov1_stage1(t_ps *ps)
{
	int		size_b;
	int		i;

	size_b = ps->size / 2;
	i = 0;
	while (1)
	{
		if (ps->stack_a->first->value <= ps->sub_median)
		{
			do_command(ps, "pb");
			i++;
			if (i == size_b)
				break ;
			continue ;
		}
		do_command(ps, "ra");
	}	
}

void	sort_algov1_stage2(t_ps *ps)
{
	t_sort_stage2	s2;

	sort_algov1_stage2_vars_init(&s2, ps);
	while (1)
	{	
		is_stacks_sorted(ps, &s2);
		s2.swap1 = 0;
		s2.swap2 = 0;
		if (! s2.sorted1 && ! is_normal_order(ps, ps->stack_a->first->value,
				ps->stack_a->second->value, 0))
			s2.swap1 = 1;
		if (! s2.sorted2 && ! is_normal_order(ps, ps->stack_b->first->value,
				ps->stack_b->second->value, 1))
			s2.swap2 = 1;
		s2.ordered1 = (s2.sorted1 && ps->stack_a->first->value == ps->median);
		s2.ordered2 = (s2.sorted2
				&& ps->stack_b->first->value == ps->sub_median);
		if (s2.ordered1 && s2.ordered2)
			break ;
		sort_algov1_stage2_2(ps, &s2);
	}
}

void	sort_algov1_stage2_2(t_ps *ps, t_sort_stage2 *s2)
{
	if (s2->swap1 && s2->swap2)
		do_command(ps, "ss");
	else if (s2->swap1 && ! s2->swap2)
		do_command(ps, "sa");
	else if (! s2->swap1 && s2->swap2)
		do_command(ps, "sb");
	if (! s2->ordered1 && ! s2->ordered2)
		do_command(ps, "rr");
	else if (! s2->ordered1)
		do_command(ps, "ra");
	else
		do_command(ps, "rb");
}
