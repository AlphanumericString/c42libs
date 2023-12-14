/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_list_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:37:03 by iron              #+#    #+#             */
/*   Updated: 2023/12/14 17:24:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	compare_int(void *data1, void *data2)
{
	return (*(int *)data1 - *(int *)data2);
}

static bool	is42(void *data)
{
	return (*(int *)data == 42);
}

static void	add42(void *data)
{
	*(int *)data += 42;
}

static void	*add42_ret(void *data)
{
	int	*ret;

	ret = malloc(sizeof(int));
	*ret = *(int *)data + 42;
	return (ret);
}

static void	dnode_add42(t_dlist *node)
{
	*(int *)node->data += 42;
}

int	test_dlistadd_front(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_list_dl_create(data2);
	ft_list_dl_add_front(&list, NULL);
	if (list == NULL)
		return (1);
	else if (list->next)
		return (1);
	else
	{
		ft_list_dl_add_front(&list, ft_list_dl_create(data));
		if (list == NULL)
			return (1);
		else if (list->data != data)
			return (1);
		else if (list->next == NULL)
			return (1);
		else if (list->next->data != data2)
			return (1);
		else if (list->next->next != NULL)
			return (1);
		else if (list->next->prev != list)
			return (1);
		
	}
	ft_list_dl_clear(&list, free);
	ft_list_dl_add_front(NULL, NULL); // check for null resiliency
	return (0);
}

int	test_dlistadd_back(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = NULL;
	ft_list_dl_add_back(&list, ft_list_dl_create(data));
	ft_list_dl_add_back(&list, NULL);
	if (list == NULL)
		return (1);
	else if (list->next)
		return (1);
	else
	{
		ft_list_dl_add_back(&list, ft_list_dl_create(data2));
		if (list == NULL)
			return (1);
		else if (list->data != data)
			return (1);
		else if (list->next == NULL)
			return (1);
		else if (list->next->data != data2)
			return (1);
		else if (list->next->next != NULL)
			return (1);
		else if (list->next->prev != list)
			return (1);
		
	}
	ft_list_dl_clear(&list, free);
	ft_list_dl_add_front(NULL, NULL); // check for null resiliency
	return (0);
}

int	test_dlistapply(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	*data = 21;
	data2 = malloc(sizeof(int));
	*data2 = 42;
	list = ft_list_dl_create(data);
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	ft_list_dl_apply(list, add42);
	if (list == NULL)
		return (1);
	else if (*(int *)list->data != 63)
		return (1);
	else if (list->next == NULL)
		return (1);
	else if (*(int *)list->next->data != 84)
		return (1);
	else if (list->next->next != NULL)
		return (1);
	
	ft_list_dl_clear(&list, free);
	return (0);
}

int	test_dlistapply_range(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	*data = 21;
	data2 = malloc(sizeof(int));
	*data2 = 42;
	list = ft_list_dl_create(data);
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	ft_list_dl_apply_range(list, list->next, add42);
	if (*(int *)list->data != 63)
		return (1);
	else if (list->next == NULL)
		return (1);
	else if (*(int *)list->next->data != 42)
		return (1);
	else if (list->next->next != NULL)
		return (1);
	
	ft_list_dl_clear(&list, free);
	return (0);
}

int	test_dlistapply_range_node(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	*data = 21;
	data2 = malloc(sizeof(int));
	*data2 = 42;
	list = ft_list_dl_create(data);
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	ft_list_dl_apply_range_node(list, list->next, dnode_add42);
	if (*(int *)list->data != 63)
		return (1);
	else if (list->next == NULL)
		return (1);
	else if (*(int *)list->next->data != 42)
		return (1);
	else if (list->next->next != NULL)
		return (1);
	
	ft_list_dl_clear(&list, free);
	return (0);
}

int	test_dlistclear(void)
{
	t_dlist	*list;
	int		*data;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_list_dl_create(data);
	ft_list_dl_clear(&list, NULL);
	list = ft_list_dl_create(data);
	ft_list_dl_clear(&list, free);
	return (0);
	return (0);
}

int test_dlistclear_range(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;
	int		*data3;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	data3 = malloc(sizeof(int));
	*data3 = 63;
	list = NULL;
	ft_list_dl_add_back(&list, ft_list_dl_create(data));
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	ft_list_dl_add_back(&list, ft_list_dl_create(data3));
	ft_list_dl_clear_range(list->next, list->next->next, NULL);
	if (list == NULL)
		return (1);
	else if (list->data != data)
		return (1);
	else if (list->next == NULL)
		return (1);
	else if (list->next->data != data3)
		return (1);
	else if (list->next->next != NULL)
		return (1);
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	ft_list_dl_clear_range(list->next, list->next->next, free);
	if (list == NULL)
		return (1);
	else if (list->data != data)
		return (1);
	else if (list->next == NULL)
		return (1);
	else if (list->next->data != data2)
		return (1);
	else if (list->next->next != NULL)
		return (1);
	ft_list_dl_clear_range(list, NULL, free);
	ft_list_dl_clear_range(NULL, NULL, free);
	return (0);
}

int	test_dlistcreate(void)
{
	t_dlist	*list;
	int		*data;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_list_dl_create(data);
	if (list == NULL)
		return (1);
	else if (list->data != data)
		return (1);
	else if (list->next != NULL)
		return (1);
	else if (list->prev != NULL)
		return (1);
	
	ft_list_dl_clear(&list, free);
	return (0);
}

int	test_dlistcopy_node(void)
{
	int		*data;
	t_dlist	*list;
	t_dlist	*copy;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_list_dl_create(data);
	copy = ft_list_dl_copy_node(list);
	if (copy == NULL)
		return (1);
	else if (copy->data != list->data)
		return (1);
	else if (copy->next != list->next)
		return (1);
	else if (copy->prev != list->prev)
		return (1);
	
	ft_list_dl_clear(&list, free);
	ft_list_dl_clear(&copy, NULL);
	return (0);
}

int	test_dlistcopy_list(void)
{
	t_dlist	*list;
	t_dlist	*copy;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_list_dl_create(data);
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	copy = ft_list_dl_copy_list(list, NULL);
	if (copy == NULL)
		return (1);
	else if (copy->data != list->data)
		return (1);
	else if (copy->next == NULL)
		return (1);
	else if (copy->next->data != list->next->data)
		return (1);
	else if (copy->next->next != NULL)
		return (1);
	else if (copy->next->prev != copy)
		return (1);
	
	ft_list_dl_clear(&list, free);
	ft_list_dl_clear(&copy, NULL);
	return (0);
}

int	test_dlist_delete_self(void)
{
	int		*data;
	int		*data2;
	int		*data3;
	t_dlist	*list;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	data3 = malloc(sizeof(int));
	*data3 = 63;
	list = ft_list_dl_create(data);
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	ft_list_dl_add_back(&list, ft_list_dl_create(data3));
	ft_list_dl_delete_self(list->next, NULL);
	if (list == NULL)
		return (1);
	else if (list->data != data)
		return (1);
	else if (list->next == NULL)
		return (1);
	else if (list->next->data != data3)
		return (1);
	else if (list->next->next != NULL)
		return (1);
	ft_list_dl_clear(&list, free);
	free(data2);
	data3 = malloc(sizeof(int));
	*data3 = 63;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_list_dl_create(data3);
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	ft_list_dl_delete_self(list->next, free);
	if (list->next != NULL)
		return (1);
	else if (list->data != data3)
		return (1);
	ft_list_dl_clear(&list, free);
	ft_list_dl_delete_self(NULL, NULL);
	return (0);
}

int	test_dlistdelete_range(void)
{
	t_dlist	*list;
	t_dlist	*list2;
	int		*data;
	int		*data2;
	int		*data3;
	int		nb_deleted;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	data3 = malloc(sizeof(int));
	*data3 = 63;
	list = ft_list_dl_create(data);
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	ft_list_dl_add_back(&list, ft_list_dl_create(data3));
	list2 = list->next;
	nb_deleted = ft_list_dl_delete_range(list, list->next, NULL);
	if (nb_deleted != 1)
		return (1);
	else if (*(int *)list2->data != *data2)
		return (1);
	else if (list2->next == NULL)
		return (1);
	else if (*(int *)list2->next->data != *data3)
		return (1);
	else if (list2->next->next != NULL)
		return (1);
	
	ft_list_dl_clear(&list2, free);
	free(data);
	return (0);
}

int test_dlistdelete(void)
{
	t_dlist	*list;
	t_dlist	*list2;
	int		*data;
	int		*data2;
	int		*data3;
	int		nb_deleted;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	data3 = malloc(sizeof(int));
	*data3 = 63;
	list = ft_list_dl_create(data);
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	ft_list_dl_add_back(&list, ft_list_dl_create(data3));
	list2 = list->next;
	nb_deleted = ft_list_dl_delete(&list, NULL);
	if (nb_deleted != 3)
		return (1);
	else if (list != NULL)
		return (1);
	ft_list_dl_add_front(&list, ft_list_dl_create(data));
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	ft_list_dl_add_back(&list, ft_list_dl_create(data3));
	nb_deleted = ft_list_dl_delete(&list, free);
	if (nb_deleted != 3)
		return (1);
	else if (list != NULL)
		return (1);
	return (0);
}

int	test_dlistfind(void)
{
	t_dlist	*list;
	t_dlist	*found1;
	t_dlist	*found2;
	t_dlist	*found3;
	int		*data;
	int		*data2;
	int		*data3;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	data3 = malloc(sizeof(int));
	*data3 = 21;
	list = ft_list_dl_create(data);
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	// data-> data2
	found1 = ft_list_dl_find(list, data2, NULL);
	found2 = ft_list_dl_find(list, data3, NULL);
	found3 = ft_list_dl_find(list, data3, compare_int);
	if (found1 == NULL)
		return (1);
	else if (found1->data != data2)
		return (1);
	else if (found1->next != NULL)
		return (1);
	else if (found2 != NULL)
		return (1);
	else if (found3 == NULL)
		return (1);
	else if (found3->data != data2)
		return (1);
	else if (found3->next != NULL)
		return (1);
	
	ft_list_dl_clear(&list, free);
	free(data3);
	return (0);
}

int	test_dlistget_datas(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;
	void	**datas;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_list_dl_create(data);
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	datas = ft_list_dl_get_datas(list);
	if (datas == NULL)
		return (1);
	else if (datas[0] != data)
		return (1);
	else if (datas[1] != data2)
		return (1);
	if (ft_list_dl_get_datas(NULL) != NULL)
		return (1);
	ft_list_dl_clear(&list, free);
	free(datas);
	return (0);
}

int	test_dlistget_nodes(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;
	t_dlist	**nodes;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_list_dl_create(data);
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	nodes = ft_list_dl_get_nodes(list);
	if (nodes == NULL)
		return (1);
	else if (nodes[0] != list)
		return (1);
	else if (nodes[1] != list->next)
		return (1);
	if (ft_list_dl_get_nodes(NULL) != NULL)
		return (1);
	ft_list_dl_clear(&list, free);
	free(nodes);
	return (0);
}

int	test_dlist_at(void)
{
	t_dlist	*list;
	t_dlist	*at;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_list_dl_create(data);
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	at = ft_list_dl_at(list, 1);
	if (at == NULL)
		return (1);
	else if (at->data != data2)
		return (1);
	else if (at->next != NULL)
		return (1);
	else if (at->prev != list)
		return (1);
	
	ft_list_dl_clear(&list, free);
	return (0);
}

int	test_dlist_begin(void)
{
	t_dlist	*list;
	t_dlist	*begin;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_list_dl_create(data);
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	begin = ft_list_dl_begin(list->next);
	if (begin == NULL)
		return (1);
	else if (begin != list)
		return (1);
	else if (begin->data != data)
		return (1);
	else if (begin->next != list->next)
		return (1);
	else if (begin->prev != NULL)
		return (1);
	
	ft_list_dl_clear(&list, free);
	return (0);
}

int	test_dlist_end(void)
{
	t_dlist	*list;
	t_dlist	*end;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_list_dl_create(data);
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	end = ft_list_dl_end(list);
	if (end == NULL)
		return (1);
	else if (end->data != data2)
		return (1);
	else if (end->next != NULL)
		return (1);
	else if (end->prev != list)
		return (1);
	
	ft_list_dl_clear(&list, free);
	return (0);
}

int	test_dlist_map(void)
{
	t_dlist	*list;
	t_dlist	*map;
	t_dlist	*map2;
	int		*data1;
	int		*data2;

	data1 = malloc(sizeof(int));
	*data1 = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_list_dl_create(data1);
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	map2 = ft_list_dl_map(list, NULL, free);
	map = ft_list_dl_map(list, add42_ret, free);
	if (map == NULL)
		return (1);
	else if (*(int *)map->data != 84)
		return (1);
	else if (map->next == NULL)
		return (1);
	else if (*(int *)map->next->data != 63)
		return (1);
	else if (map->next->next != NULL)
		return (1);
	else if (map2 != NULL)
		return (1);
	
	ft_list_dl_clear(&list, free);
	ft_list_dl_clear(&map, free);
	return (0);
}

int	test_dlist_new(void)
{
	t_dlist	*list;

	list = ft_list_dl_new();
	if (list == NULL)
		return (1);
	
	ft_list_dl_clear(&list, free);
	return (0);
}

int	test_dlist_pop(void)
{
	t_dlist	*list;
	int		*data1;
	int		*data2;

	data1 = malloc(sizeof(int));
	*data1 = 42;
	list = ft_list_dl_create(data1);
	data2 = ft_list_dl_pop(&list);
	if (list != NULL)
		return (1);
	else if (data2 != data1)
		return (1);
	data2 = ft_list_dl_pop(&list);
	if (data2 != NULL)
		return (1);
	data2 = ft_list_dl_pop(NULL);
	if (data2 != NULL)
		return (1);
	free(data1);
	return (0);
}

int	test_dlist_pop_back(void)
{
	t_dlist	*list;
	int		*data1;
	int		*data2;
	int		*data3;

	data1 = malloc(sizeof(int));
	*data1 = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_list_dl_create(data1);
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	data3 = ft_list_dl_pop_back(&list);
	if (list == NULL)
		return (1);
	else if (data3 != data2)
		return (1);
	data3 = ft_list_dl_pop_back(&list);
	if (list != NULL)
		return (1);
	else if (data3 != data1)
		return (1);
	data3 = ft_list_dl_pop_back(NULL);
	if (data3 != NULL)
		return (1);
	data3 = ft_list_dl_pop_back(&list);
	if (data3 != NULL)
		return (1);
	free(data1);
	free(data2);
	return (0);
}

int	test_dlist_push(void)
{
	t_dlist	*list;
	int		*data1;

	data1 = malloc(sizeof(int));
	*data1 = 42;
	list = NULL;
	ft_list_dl_push(&list, data1);
	if (list == NULL)
		return (1);
	else if (list->data != data1)
		return (1);
	
	ft_list_dl_clear(&list, free);
	return (0);
}

int	test_dlist_push_back(void)
{
	t_dlist	*list;
	int		*data1;
	int		*data2;

	data1 = malloc(sizeof(int));
	*data1 = 42;
	list = NULL;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	ft_list_dl_push(&list, data1);
	ft_list_dl_push_back(&list, data2);
	if (list == NULL)
		return (1);
	else if (list->data != data1)
		return (1);
	else if (list->next == NULL)
		return (1);
	else if (list->next->data != data2)
		return (1);
	
	ft_list_dl_clear(&list, free);
	return (0);
}

int	test_dlist_rev(void)
{
	t_dlist	*list;
	int		*data1;
	int		*data2;
	int		*original_data1;
	int		*original_data2;

	data1 = malloc(sizeof(int));
	*data1 = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	original_data1 = data1;
	original_data2 = data2;
	list = ft_list_dl_create(data1);
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	ft_list_dl_rev(&list);
	if (list == NULL)
		return (1);
	else if (list->data != original_data2)
		return (1);
	else if (list->next == NULL)
		return (1);
	else if (list->next->data != original_data1)
		return (1);
	
	ft_list_dl_clear(&list, free);
	return (0);
}

int	test_dlist_size(void)
{
	t_dlist	*list;
	int		*data1;
	int		*data2;
	size_t	size1;
	size_t	size2;
	size_t	size3;

	data1 = malloc(sizeof(int));
	*data1 = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = NULL;
	size1 = ft_list_dl_size(list);
	ft_list_dl_add_front(&list, ft_list_dl_create(data1));
	size2 = ft_list_dl_size(list);
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	size3 = ft_list_dl_size(list);
	if (size1 != 0)
		return (1);
	else if (size2 != 1)
		return (1);
	else if (size3 != 2)
		return (1);
	ft_list_dl_clear(&list, free);
	return (0);
}

int	test_dlist_size_of_data(void)
{
	t_dlist	*list;
	int		*data1;
	int		*data2;
	size_t	size1;
	size_t	size2;
	size_t	size3;

	data1 = malloc(sizeof(int));
	*data1 = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = NULL;
	size1 = ft_list_dl_size_of_data(list, is42);
	ft_list_dl_push(&list, data1);
	size2 = ft_list_dl_size_of_data(list, is42);
	ft_list_dl_push(&list, data2);
	size3 = ft_list_dl_size_of_data(list, is42);
	if (size1 != 0)
		return (1);
	else if (size2 != 1)
		return (1);
	else if (size3 != 1)
		return (1);
	
	ft_list_dl_clear(&list, free);
	return (0);
}

int	test_dlist_subrange(void)
{
	t_dlist	*list;
	t_dlist	*sub;
	int		*data1;
	int		*data2;
	int		*data3;

	data1 = malloc(sizeof(int));
	*data1 = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	data3 = malloc(sizeof(int));
	*data3 = 63;
	list = ft_list_dl_create(data1);
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	ft_list_dl_add_back(&list, ft_list_dl_create(data3));
	sub = ft_list_dl_subrange(list, list->next);
	if (sub == NULL)
		return (1);
	else if (sub->data != data1)
		return (1);
	else if (sub->next != NULL)
		return (1);
	ft_list_dl_clear(&sub, NULL);
	sub = ft_list_dl_subrange(list, list->next->next);
	if (sub == NULL)
		return (1);
	else if (sub->data != data1)
		return (1);
	else if (sub->next == NULL)
		return (1);
	else if (sub->next->data != data2)
		return (1);
	else if (sub->next->next != NULL)
		return (1);
	ft_list_dl_clear(&list, free);
	ft_list_dl_clear(&sub, NULL);
	if (ft_list_dl_subrange(NULL, NULL) != NULL)
		return (1);
	return (0);
}

int	tests_doubly_linked_list_all(void)
{
	int ret;

	ret = 0;
	if (test_dlistadd_front())
	{
		printf("test_dlistadd_front: [FAIL]\n");
		ret++;
	}
	if (test_dlistadd_back())
	{
		printf("test_dlistadd_back: [FAIL]\n");
		ret++;
	}
	if (test_dlistapply())
	{
		printf("test_dlistapply: [FAIL]\n");
		ret++;
	}
	if (test_dlistapply_range())
	{
		printf("test_dlistapply_range: [FAIL]\n");
		ret++;
	}
	if (test_dlistapply_range_node())
	{
		printf("test_dlistapply_range_node: [FAIL]\n");
		ret++;
	}
	if (test_dlistclear())
	{
		printf("test_dlistclear: [FAIL]\n");
		ret++;
	}
	if (test_dlistclear_range())
	{
		printf("test_dlistclear_range: [FAIL]\n");
		ret++;
	}
	if (test_dlistcreate())
	{
		printf("test_dlistcreate: [FAIL]\n");
		ret++;
	}
	if (test_dlistcopy_node())
	{
		printf("test_dlistcopy_node: [FAIL]\n");
		ret++;
	}
	if (test_dlistcopy_list())
	{
		printf("test_dlistcopy_list: [FAIL]\n");
		ret++;
	}
	if (test_dlist_delete_self())
	{
		printf("test_dlist_delete_self: [FAIL]\n");
		ret++;
	}
	if (test_dlistdelete_range())
	{
		printf("test_dlistdelete_range: [FAIL]\n");
		ret++;
	}
	if (test_dlistdelete())
	{
		printf("test_dlistdelete: [FAIL]\n");
		ret++;
	}
	if (test_dlistfind())
	{
		printf("test_dlistfind: [FAIL]\n");
		ret++;
	}
	if (test_dlistget_datas())
	{
		printf("test_dlistget_datas: [FAIL]\n");
		ret++;
	}
	if (test_dlistget_nodes())
	{
		printf("test_dlistget_nodes: [FAIL]\n");
		ret++;
	}
	if (test_dlist_at())
	{
		printf("test_dlist_at: [FAIL]\n");
		ret++;
	}
	if (test_dlist_begin())
	{
		printf("test_dlist_begin: [FAIL]\n");
		ret++;
	}
	if (test_dlist_end())
	{
		printf("test_dlist_end: [FAIL]\n");
		ret++;
	}
	if (test_dlist_map())
	{
		printf("test_dlist_map: [FAIL]\n");
		ret++;
	}
	if (test_dlist_new())
	{
		printf("test_dlist_new: [FAIL]\n");
		ret++;
	}
	if (test_dlist_pop())
	{
		printf("test_dlist_pop: [FAIL]\n");
		ret++;
	}
	if (test_dlist_pop_back())
	{
		printf("test_dlist_pop_back: [FAIL]\n");
		ret++;
	}
	if (test_dlist_push())
	{
		printf("test_dlist_push: [FAIL]\n");
		ret++;
	}
	if (test_dlist_push_back())
	{
		printf("test_dlist_push_back: [FAIL]\n");
		ret++;
	}
	if (test_dlist_rev())
	{
		printf("test_dlist_rev: [FAIL]\n");
		ret++;
	}
	if (test_dlist_size())
	{
		printf("test_dlist_size: [FAIL]\n");
		ret++;
	}
	if (test_dlist_size_of_data())
	{
		printf("test_dlist_size_of_data: [FAIL]\n");
		ret++;
	}
	if (test_dlist_subrange())
	{
		printf("test_dlist_subrange: [FAIL]\n");
		ret++;
	}
	return (ret);
	// ret += test_dlistadd_front();
	// ret += test_dlistadd_back();
	// ret += test_dlistapply();
	// ret += test_dlistapply_range();
	// ret += test_dlistapply_range_node();
	// ret += test_dlistclear();
	// ret += test_dlistclear_range();
	// ret += test_dlistcreate();
	// ret += test_dlistcopy_node();
	// ret += test_dlistcopy_list();
	// ret += test_dlist_delete_self();
	// ret += test_dlistdelete_range();
	// ret += test_dlistfind();
	// ret += test_dlistget_datas();
	// ret += test_dlistget_nodes();
	// ret += test_dlist_at();
	// ret += test_dlist_begin();
	// ret += test_dlist_end();
	// ret += test_dlist_map();
	// ret += test_dlist_new();
	// ret += test_dlist_pop();
	// ret += test_dlist_pop_back();
	// ret += test_dlist_push();
	// ret += test_dlist_push_back();
	// ret += test_dlist_rev();
	// ret += test_dlist_size();
	// ret += test_dlist_size_of_data();
	// ret += test_dlist_subrange();
	return (ret);
}
