/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algov1_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:26:58 by EClown            #+#    #+#             */
/*   Updated: 2022/02/23 15:43:09 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_algov1_stage2_vars_init(t_sort_stage2 *s2, t_ps *ps)
{
	s2->swap1 = 0;
	s2->swap2 = 0;
	s2->sorted1 = 0;
	if (ps->size <= 3)
		s2->sorted2 = 1;
	else
		s2->sorted2 = 0;
	s2->ordered1 = 0;
	if (ps->size <= 3)
		s2->ordered2 = 1;
	else
		s2->ordered2 = 0;
}

void	sort_algov1_stage3(t_ps *ps)
{
	int	count;

	count = ps->size / 2 + 1;
	while (count--)
		do_command(ps, "pa");
}

void	sort_3item(t_ps *ps)
{
	int	i;
	int	need_swap;
	int	a;
	int	b;
	int	c;

	i = 0;
	while (!(ps->stack_a->first->value == ps->min
			&& ps->stack_a->last->value == ps->max))
	{
		a = ps->stack_a->first->value;
		b = ps->stack_a->second->value;
		c = ps->stack_a->last->value;
		need_swap = ((a > b) && (a != ps->max
					|| a == (ps->max && c == ps->min)));
		if (need_swap)
			do_command(ps, "sa");
		else
			do_command(ps, "ra");
		i++;
		if (i > 10)
			break ;
	}
}

void	sort_algov1(t_ps *ps)
{
	if (ps->size <= 1)
		return ;
	if (ps->size == 3)
	{
		sort_3item(ps);
		return ;
	}
	else if (ps->size == 2)
	{
		if (ps->stack_a->first->value > ps->stack_a->second->value)
			do_command(ps, "sa");
		return ;
	}
	sort_algov1_stage1(ps);
	sort_algov1_stage2(ps);
	sort_algov1_stage3(ps);
}

int	min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
