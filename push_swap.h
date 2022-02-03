/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:38:10 by EClown            #+#    #+#             */
/*   Updated: 2022/02/03 18:08:53 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include <stdio.h>		//TODO Удалить перед сдачей

typedef struct s_item
{
	int				value;
	int				index;
	struct s_item	*prev;
	struct s_item	*next;
} t_item;

typedef struct s_dlist
{
	t_item	*first;
	t_item	*second;
	t_item	*last;
} t_dlist;

t_item	*create_item(int value);
t_dlist	*create_list();
void add_item_to_list(t_item *item, t_dlist *list);
int	lst_count(t_dlist *list);
void print_lists(t_dlist *list_a, t_dlist *list_b);
void delete_first_item(t_dlist *lst);
