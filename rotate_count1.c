/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_count1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:46:07 by EClown            #+#    #+#             */
/*   Updated: 2022/02/23 15:46:52 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_rc	*create_rc(void)
{
	t_rc	*rc;

	rc = malloc(sizeof(t_rc));
	if (! rc)
		return (NULL);
	rc->ra = 0;
	rc->rb = 0;
	rc->rr = 0;
	rc->rra = 0;
	rc->rrb = 0;
	rc->rrr = 0;
	rc->total = 0;
	return (rc);
}

t_rc	*choose_best_rc(t_rc *rc1, t_rc *rc2)
{
	if (rc1->total <= rc2->total)
	{
		free(rc2);
		return (rc1);
	}
	free(rc1);
	return (rc2);
}

void	do_rc(t_ps *ps, t_rc *rc)
{
	while (rc->rr--)
		do_command(ps, "rr");
	while (rc->rrr--)
		do_command(ps, "rrr");
	while (rc->ra--)
		do_command(ps, "ra");
	while (rc->rb--)
		do_command(ps, "rb");
	while (rc->rra--)
		do_command(ps, "rra");
	while (rc->rrb--)
		do_command(ps, "rrb");
	do_command(ps, "pb");
	free(rc);
}

void	pre_fill_rc(t_ps *ps, int *b_array, int b_arr_size, t_int *str)
{
	int	new_index;

	new_index = -10;
	if (str->current->value > ps->stack_b->max->value
		|| str->current->value < ps->stack_b->min->value)
	{
		str->new_rc->rrb = b_arr_size - 1 - str->first_b_ind;
		str->new_rc->rb = (b_arr_size - str->new_rc->rrb) % b_arr_size;
		return ;
	}
	new_index = binary_search_place(str->current->value, b_array, 0,
			b_arr_size - 1);
	str->new_rc->rrb = (new_index - str->first_b_ind - 1) % b_arr_size;
	if (str->new_rc->rrb < 0)
	{
		str->new_rc->rb = str->new_rc->rrb * -1;
		str->new_rc->rrb = (b_arr_size - str->new_rc->rb) % b_arr_size;
	}
	else
		str->new_rc->rb = (b_arr_size - str->new_rc->rrb) % b_arr_size;
}

void	finish_fill_rc(t_rc *rc)
{
	int	forw;
	int	back;
	int	diff1;
	int	diff2;
	int	min;

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
