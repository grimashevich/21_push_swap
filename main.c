/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:38:05 by EClown            #+#    #+#             */
/*   Updated: 2022/02/03 18:22:10 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h> //TODO Удалить перед сдачей

int main(void)
{
	t_dlist *lst_a;
	t_dlist *lst_b;

	srand(time(NULL));
	lst_a = create_list();
	lst_b = create_list();
	for (size_t i = 10; i < 20; i++)
		add_item_to_list(create_item(i), lst_a);
		//add_item_to_list(create_item(rand()% 100), lst_a);
	for (size_t j = 20; j < 23; j++)
		add_item_to_list(create_item(j), lst_b);
	print_lists(lst_a, lst_b);	
	printf("- - - - - - - - - - - - - -\n");
	delete_first_item(lst_a);
	delete_first_item(lst_a);
	delete_first_item(lst_a);
	print_lists(lst_a, lst_b);	

	return (0);
}