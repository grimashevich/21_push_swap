#include "push_swap.h"


/*
check 2 integers order for stack a (0) or stack b (1)
a - upper
b - lower
*/
int is_normal_order(t_pushswap *ps, int a, int b, int stack)
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


void is_stacks_sorted(t_pushswap *ps ,t_sort_stage2 *s2)
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
		if (s2->sorted1 && ! is_normal_order(ps, item->value, item->next->value, 0))
			s2->sorted1 = 0;
		if (s2->sorted2 && ! is_normal_order(ps, item2->value, item2->next->value, 1))
			s2->sorted2 = 0;
		if (! s2->sorted1 && ! s2->sorted2)
			break;
		item = item->next;
		item2 = item2->next;
	}
}

void sort_algov1_stage1(t_pushswap *ps)
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
				break;
			continue;
		}
		do_command(ps, "ra");
	}
	
}

void sort_algov1_stage2_vars_init(t_sort_stage2 *s2, t_pushswap *ps)
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

void sort_algov1_stage2(t_pushswap *ps)
{
	t_sort_stage2	s2;
	
	sort_algov1_stage2_vars_init(&s2, ps);
	while (1)
	{	
		is_stacks_sorted(ps, &s2);
		s2.swap1 = 0;
		s2.swap2 = 0;
		if (! s2.sorted1 && ! is_normal_order(ps, ps->stack_a->first->value, ps->stack_a->second->value,0))
			s2.swap1 = 1;
		if (! s2.sorted2 && ! is_normal_order(ps, ps->stack_b->first->value, ps->stack_b->second->value,1))
			s2.swap2 = 1;
		s2.ordered1 = (s2.sorted1 && ps->stack_a->first->value == ps->median);
		s2.ordered2 = (s2.sorted2 && ps->stack_b->first->value == ps->sub_median);
		if (s2.ordered1 && s2.ordered2)
			break;
		if (s2.swap1 && s2.swap2)
			do_command(ps, "ss");
		else if (s2.swap1 && ! s2.swap2)
			do_command(ps, "sa");
		else if (! s2.swap1 && s2.swap2)
			do_command(ps, "sb");
		if (! s2.ordered1 && ! s2.ordered2)
			do_command(ps, "rr");
		else if (! s2.ordered1)
			do_command(ps, "ra");
		else
			do_command(ps, "rb");
	}
}

void sort_algov1_stage3(t_pushswap *ps)
{
	int count;

	count = ps->max / 2 + 1;
	while (count--)
		do_command(ps, "pa");
	
}

void sort_3item(t_pushswap *ps)
{
	int	i;
	int	need_swap;
	int	a;
	int	b;
	int	c;

	i = 0;
	while (!(ps->stack_a->first->value == ps->min && ps->stack_a->last->value == ps->max))
	{
		a = ps->stack_a->first->value;
		b = ps->stack_a->second->value;
		c = ps->stack_a->last->value;
		need_swap = (a > b && a != ps->max);
		if (i % 2 == 0 && need_swap)
			do_command(ps, "sa");
		else
			do_command(ps, "ra");
		i++;
		if (i > 10)
			break;
	}
	
}

void sort_algov1(t_pushswap *ps)
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
		return;
	}
	if (ps->size > 3)
		sort_algov1_stage1(ps);
	sort_algov1_stage2(ps);
	sort_algov1_stage3(ps);
}