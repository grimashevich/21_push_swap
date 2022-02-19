/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totate_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:23:54 by EClown            #+#    #+#             */
/*   Updated: 2022/02/19 15:40:09 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_count_sum(t_rotate_count *rc)
{
	rc->total = rc->ra;
	rc->total += rc->rb;
	rc->total += rc->rra;
	rc->total += rc->rrb;
	rc->total += rc->rr;
	rc->total += rc->rrr;
}

void rotate_count_forw(t_rotate_count *rc)
{
	rc->rr = min_int(rc->ra, rc->rb);
	rc->ra = rc->ra - rc->rr;
	rc->rb = rc->rb - rc->rr;
	rc->rrr = 0;
	rc->rra = 0;
	rc->rrb = 0;
	rotate_count_sum(rc);	
}
void rotate_count_back(t_rotate_count *rc)
{
	rc->rr = 0;
	rc->ra = 0;
	rc->rb = 0;
	rc->rrr = min_int(rc->rra, rc->rrb);
	rc->rra = rc->rra - rc->rrr;
	rc->rrb = rc->rrb - rc->rrr;
	rotate_count_sum(rc);
}
void rotate_count_diff1(t_rotate_count *rc)
{
	rc->rr = 0;
	rc->rb = 0;
	rc->rrr = 0;
	rc->rra = 0;
	rotate_count_sum(rc);
}
void rotate_count_diff2(t_rotate_count *rc)
{
	rc->rr = 0;
	rc->ra = 0;
	rc->rrr = 0;
	rc->rrb = 0;
	rotate_count_sum(rc);
}