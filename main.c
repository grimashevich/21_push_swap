/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:38:05 by EClown            #+#    #+#             */
/*   Updated: 2022/02/23 17:38:36 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



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
	update_math_stat(ps);
	if (is_sorted(ps))
		exit(0);
	if (ps->size <= 10)
		sort_algov1(ps);
	else
		sort_stack(ps);
	free_ps_struct(ps);
	return (0);
}
