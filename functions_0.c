/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:39:46 by EClown            #+#    #+#             */
/*   Updated: 2022/02/03 18:22:57 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_item	*create_item(int value)
{
	t_item	*item;

	item = malloc(sizeof(t_item));
	if (item == NULL)
		return (NULL);
	item->value = value;
	item->index = 0;
	item->next = NULL;
	item->prev = NULL;
	return (item);
}

t_dlist	*create_list()
{
	t_dlist	*list;

	list = malloc(sizeof(t_dlist));
	if (list == NULL)
		return (NULL);
	list->first = NULL;
	list->last = NULL;
	list->second = NULL;
	return (list);
}

void add_item_to_list(t_item *item, t_dlist *list)
{
	if (list == NULL || item == NULL)
		return ;
	if (list->first == NULL)
	{
		item->next = item;
		item->prev = item;
		list->first = item;
		list->last = item;
		return ;
	}
	item->next = list->first;
	item->prev = list->last;
	list->last->next = item;
	list->first->prev = item;
	list->last = item;
	list->second = list->first->next;
}

void create_add_item_to_list(int value,t_dlist *list)
{
	t_item	*item;

	item = create_item(value);
	if (! item)
		return ;
	add_item_to_list(item, list);
}

int	lst_count(t_dlist *list)
{
	t_item	*item;
	int		count;

	if (list == NULL)
		return (0);
	item = list->first;
	if (item == NULL)
		return (0);
	count = 1;
	item = item->next;
	while (item != list->first)
	{
		count++;
		item = item->next;
	}
	return (count);
}

void delete_first_item(t_dlist *lst)
{
	t_item	*first;

	if (lst->first == NULL)
		return ;
	first = lst->first;
	if (lst->first == lst->last)
	{
		lst->first = NULL;
		lst->second = NULL;
		lst->last = NULL;
	}
	else
	{
		lst->second->prev = lst->last;
		lst->last->next = lst->second;
		lst->first = first->next;
		lst->second = first->next->next;
	}
	free(first);
}

void print_lists(t_dlist *list_a, t_dlist *list_b) //TODO: Удалить перед сдачей
{
	int 	count_a;
	int 	count_b;
	int 	count_ab;
	int		i;
	char	*str_a;
	char	*str_b;
	t_item	*item_a;
	t_item	*item_b;

	count_a = lst_count(list_a);
	count_b = lst_count(list_b);
	item_a = list_a->first;
	item_b = list_b->first;
	count_ab = count_a + count_b;
	i = 0;
	
	while (i < count_a + count_b)
	{
		str_a = ft_strdup("");
		str_b = ft_strdup("");
		if (i + count_a >= count_ab)
		{
			free(str_a);
			str_a = ft_itoa(item_a->value);
			item_a = item_a->next;
		}
		if (i + count_b >= count_ab)
		{
			free(str_b);
			str_b = ft_itoa(item_b->value);
			item_b = item_b->next;
		}
		printf("\t|%2s|\t|%2s|\n", str_a, str_b);
		free(str_a);
		free(str_b);
		i++;
	}
	
}
 void free_list(t_dlist *lst)
 {
	 while (lst->first)
	 	delete_first_item(lst);
	 free(lst);
 }

void free_lists(t_dlist *lst1, t_dlist *lst2)
{
	free_list(lst1);
	free_list(lst2);
}
