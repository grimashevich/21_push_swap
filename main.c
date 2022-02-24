/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:38:05 by EClown            #+#    #+#             */
/*   Updated: 2022/02/24 15:02:39 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_ps	*ps;

	if (argc < 2)
		return (0);
	ps = ps_init();
	if (! ps)
		error_free_exit(NULL);
	add_argv_to_stack(ps, argc, argv);
	ps->sorted_array = update_idexes(ps->stack_a);
	if (has_double_int(ps))
		error_free_exit(ps);
	if (is_sorted(ps))
	{
		free_ps_struct(ps);
		return (0);
	}
	update_math_stat(ps);
	if (ps->size <= 10)
		sort_algov1(ps);
	else
		sort_stack(ps);
	free_ps_struct(ps);
	return (0);
}
