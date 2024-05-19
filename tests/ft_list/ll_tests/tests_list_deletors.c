/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_listdeletors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:25:58 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 16:26:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	ft_listdelone(NULL, NULL); // null resiliency

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"
#include <stdlib.h>

int	test_listdelone(void)
{
	t_list	*list;
	int		*data;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_listcreate(data);
	ft_listdelone(list, NULL);
	list = ft_listcreate(data);
	ft_listdelone(list, free);
	ft_listdelone(NULL, NULL);
	return (0);
}

/*
	ft_listadd_back(&list, ft_listcreate(data2)); // (42)-> (21)-> NULL
	list2 = list->next;
	nb_deleted = ft_listdelete_range(list, list->next, NULL); 
	// (42)-> (21)-> NULL
	nb_deleted2 = ft_listdelete_range(list, list->next, free); 
	// (21)-> NULL
	// we use list2 to check if the list is still valid
	// list was destroyed by ft_listdelete_range
	---
	ft_listclear(&list2, free); // NULL
	---
	nb_deleted = ft_listdelete_range(NULL, NULL, free); // null resiliency
	---
	list = ft_listcreate(data); // (42)-> NULL
	nb_deleted = ft_listdelete_range(list, NULL, free); // NULL
	---
	
*/

int	test_listdelete_range(void)
{
	t_list	*list;
	t_list	*list2;
	int		*data;
	int		*data2;
	int		nb_del[2];

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	list2 = list->next;
	nb_del[0] = ft_listdelete_range(list, list->next, NULL);
	nb_del[1] = ft_listdelete_range(list, list->next, free);
	if ((nb_del[0] != 0 || nb_del[1] != 1) || \
	(list2->data != data2 || list2->next != NULL))
		return (__LINE__);
	ft_listclear(&list2, free);
	nb_del[0] = ft_listdelete_range(NULL, NULL, free);
	if (nb_del[0] != 0)
		return (__LINE__);
	data = malloc(sizeof(int));
	*data = 42;
	list = ft_listcreate(data);
	nb_del[0] = ft_listdelete_range(list, NULL, free);
	if (nb_del[0] != 1)
		return (__LINE__);
	return (0);
}
