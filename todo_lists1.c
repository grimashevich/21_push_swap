/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   todo_lists1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:27:34 by EClown            #+#    #+#             */
/*   Updated: 2022/02/18 13:33:58 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void do_todo(t_pushswap *ps, t_todo *item)
{
	t_todo	*tmp;

	tmp = item;
	while (tmp)
	{
		do_command(ps, tmp->value);
		tmp = tmp->next;
	}
	clear_todo_list(&item);
}

void t_todo_rotate_init(t_todo_rotate *todo4)
{
	todo4->ra = NULL;
	todo4->rb = NULL;
	todo4->rra = NULL;
	todo4->rrb = NULL;
}

void add_todo_and_scroll(char str[4], t_todo **todo_list, t_todo **scroll)
{
	*todo_list = add_todo_last(str, *todo_list);
	*scroll = (*scroll)->next;
}

t_todo *merge_todo(t_todo *todo1, t_todo *todo2)
{
	t_todo	*result;

	result = NULL;
	while (todo1)
	{
		if (ft_strncmp(todo1->value, "ra", 3) == 0 && todo2 &&
				ft_strncmp(todo2->value, "rb", 3) == 0)
			add_todo_and_scroll("rr", &result, &todo2);
		else if (ft_strncmp(todo1->value, "rra", 4) == 0 && todo2 &&
				ft_strncmp(todo2->value, "rrb", 4) == 0)
			add_todo_and_scroll("rrr", &result, &todo2);
		else
			result = add_todo_last(todo1->value, result);
		todo1 = todo1->next;
	}
	while (todo2)
		add_todo_and_scroll(todo2->value, &result, &todo2);
	result = add_todo_last("pb", result);
	return result;
}

/*
Compare and return best todo command list.
Shorter means better.
*/
t_todo *choose_best_todo(t_todo **todo1, t_todo **todo2)
{
	if (*todo1 == NULL)
	{
		if (*todo2 == NULL)
			return (NULL);
		return (*todo2);
	}
	else if (*todo2 == NULL)
		return (*todo1);

	if (todo_count(*todo1) <= todo_count(*todo2))
	{
		clear_todo_list(todo2);
		return (*todo1);
	}
	clear_todo_list(todo1);
	return (*todo2);
}

t_todo *get_best_from_todo4(t_todo_rotate *todo4)
{
	t_todo	*best;
	t_todo	*best2;

	best = merge_todo(todo4->ra, todo4->rb);
	best2 = merge_todo(todo4->rra, todo4->rrb);
	best = choose_best_todo(&best, &best2);
	best2 = merge_todo(todo4->ra, todo4->rrb);
	best = choose_best_todo(&best, &best2);
	best2 = merge_todo(todo4->rra, todo4->rb);
	best = choose_best_todo(&best, &best2);
	clear_todo_list(&(todo4->ra));
	clear_todo_list(&(todo4->rb));
	clear_todo_list(&(todo4->rra));
	clear_todo_list(&(todo4->rrb));
	return (best);
}

void update_todo4(t_todo_rotate *todo4, char stack, char direction, t_item **current)
{
	if (direction == 'd')
	{
		if (stack == 'a')
		{
			todo4->ra = add_todo_last("ra", todo4->ra);
			*current = (*current)->prev;
		}
		else if (stack == 'b')
		{
			todo4->rb = add_todo_last("rb", todo4->rb);
			*current = (*current)->next;
		}
	}
	else if (direction == 'u')
	{
		if (stack == 'a')
		{
			todo4->rra = add_todo_last("rra", todo4->rra);
			*current = (*current)->next;
		}
		else if (stack == 'b')
		{
			todo4->rrb = add_todo_last("rrb", todo4->rrb);
			*current = (*current)->prev;
		}
	}
}

int todo_count(t_todo *todo)
{
	int	count;

	count = 0;
	while (todo)
	{
		count++;
		todo = todo->next;
	}
	return (count);
	
}