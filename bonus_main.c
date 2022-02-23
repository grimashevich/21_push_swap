/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:02:21 by EClown            #+#    #+#             */
/*   Updated: 2022/02/23 18:22:49 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_do_command(t_ps *ps, char *input)
{
	if (! ft_strncmp("ra", input, 3))
		rotate(ps->stack_a);
	else if (! ft_strncmp("rb", input, 3))
		rotate(ps->stack_b);
	else if (! ft_strncmp("rr", input, 3))
		rotate_rotate(ps->stack_a, ps->stack_b);
	else if (! ft_strncmp("rra", input, 4))
		reverse_rotate(ps->stack_a);
	else if (! ft_strncmp("rrb", input, 4))
		reverse_rotate(ps->stack_b);
	else if (! ft_strncmp("rrr", input, 4))
		reverse_rotate_rotate(ps->stack_a, ps->stack_b);
	else if (! ft_strncmp("ss", input, 3))
		swap_swap(ps->stack_a, ps->stack_b);
	else if (! ft_strncmp("pa", input, 3))
		push(ps->stack_b, ps->stack_a);
	else if (! ft_strncmp("pb", input, 3))
		push(ps->stack_a, ps->stack_b);
	else if (! ft_strncmp("sa", input, 3))
		swap(ps->stack_a);
	else if (! ft_strncmp("sb", input, 3))
		swap(ps->stack_b);
	else
		return (0);
	return (1);
}


void	input_command(t_ps *ps)
{
	char	str[5];
	int		i;

	(void) ps;

	i = 0;
	while (read(0, &str[i], 1))
	{
		if (i >= 4)
			error_free_exit(ps);
		if (str[i] == '\n')
		{
			str[i] = 0;
			if (! check_do_command(ps, &str[0]))
				error_free_exit(ps);
			i = 0;
			continue ;
		}
		i++;
	}
}

void	check_stack(t_ps *ps)
{
	t_item	*tmp;
	int		i;

	tmp = ps->stack_a->first;
	i = 0;
	while (i < ps->size - 1)
	{
		if (tmp->value > tmp->next->value)
		{
			error_free_exit(ps);
			return ;
		}
		tmp = tmp->next;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_ps	*ps;

	ps = ps_init();
	if (! ps)
		error_free_exit(NULL);
	if (argc < 2)
		error_free_exit(ps);
	add_argv_to_stack(ps, argc, argv);
	ps->sorted_array = update_idexes(ps->stack_a);
	if (has_double_int(ps))
		error_free_exit(ps);
	input_command(ps);
	check_stack(ps);
	ft_putstr_fd("OK\n", 1);
}
