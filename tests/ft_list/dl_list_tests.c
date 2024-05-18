/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_list_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:37:03 by iron              #+#    #+#             */
/*   Updated: 2024/05/18 17:34:25 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "tests/tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	compare_int(const void *data1, const void *data2)
{
	return (*(int *)data1 - *(int *)data2);
}

static bool	is42(const void *data)
{
	return (*(int *)data == 42);
}

static void	add42(void *data)
{
	*(int *)data += 42;
}

static void	*add42_ret(const void *data)
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
	if (list == NULL || list->next)
		return (1);
	else
	{
		ft_list_dl_add_front(&list, ft_list_dl_create(data));
		if (list == NULL || list->data != data || list->next == NULL)
			return (1);
		else if (list->next->data != data2 || list->next->next != NULL)
			return (1);
		else if (list->next->prev != list)
			return (1);
	}
	ft_list_dl_clear(&list, free);
	ft_list_dl_add_front(NULL, NULL);
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
	if (!list || list->next)
		return (1);
	else
	{
		ft_list_dl_add_back(&list, ft_list_dl_create(data2));
		if (!list || list->data != data || !list->next || \
		list->next->data != data2)
			return (1);
		else if (list->next->next != NULL || list->next->prev != list)
			return (1);
	}
	ft_list_dl_clear(&list, free);
	ft_list_dl_add_front(NULL, NULL);
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
}

//
//ft_list_dl_add_back(&list, ft_list_dl_create(data3))
//	data -> data2 -> data3
//ft_list_dl_clear_range(list->next, list->next->next, NULL)
//	data -> NULL -> data3
//ft_list_dl_add_back(&list, ft_list_dl_create(data2))
//	data -> NULL -> data3 -> data2
//ft_list_dl_clear_range(list->next->next, NULL, free)
//	data -> NULL -> NULL -> NULL
//ft_list_dl_delete_range(list, NULL, NULL)
//	delete nodes
//
int	test_dlistclear_range(void)
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
	else if (list->next->data != NULL)
		return (1);
	else if (list->next->next == NULL)
		return (1);
	else if (list->next->next->data != data3)
		return (1);
	else if (list->next->next->next != NULL)
		return (1);
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	ft_list_dl_clear_range(list->next->next, NULL, free);
	if (list == NULL)
		return (1);
	else if (list->data != data)
		return (1);
	else if (list->next == NULL)
		return (1);
	else if (list->next->data != NULL)
		return (1);
	else if (list->next->next == NULL)
		return (1);
	else if (list->next->next->data != NULL)
		return (1);
	else if (list->next->next->next == NULL)
		return (1);
	else if (list->next->next->next->data != NULL)
		return (1);
	else if (list->next->next->next->next != NULL)
		return (1);
	ft_list_dl_clear_range(list, NULL, free);
	ft_list_dl_clear_range(NULL, NULL, free);
	ft_list_dl_delete_range(list, NULL, NULL);
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
	copy = ft_list_dl_copy_list(list);
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
	if (!list || list->data != data || !list->next || \
	list->next->data != data3 || list->next->next != NULL)
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
	if (list->next != NULL || list->data != data3)
		return (1);
	ft_list_dl_clear(&list, free);
	ft_list_dl_delete_self(NULL, NULL);
	return (0);
}
/*
	ft_list_dl_add_back(&list, ft_list_dl_create(data3));
		// NULL <-(42)<=>(21)<=>(63)-> NULL
	list2 = list->next;                                          
		// 42 <-(21)<=>(63)-> NULL
	nb_deleted = ft_list_dl_delete_range(list, list->next, NULL);
		// NULL <-(21)<=>(63)-> NULL
	ft_list_dl_add_front(&list2, ft_list_dl_create(data));
		// NULL <-(42)<=>(21)<=>(63)-> NULL
	list = list2;
	nb_deleted = ft_list_dl_delete_range(list->next, list->next->next, free);
		// NULL <-(42)<=>(63)-> NULL
*/

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
	ft_list_dl_add_front(&list2, ft_list_dl_create(data));
	list = list2;
	nb_deleted = ft_list_dl_delete_range(list->next, list->next->next, free);
	if (nb_deleted != 1)
		return (1);
	else if (*(int *)list2->data != *data)
		return (1);
	else if (list2->next == NULL)
		return (1);
	else if (*(int *)list2->next->data != *data3)
		return (1);
	else if (list2->next->next != NULL)
		return (1);
	ft_list_dl_clear(&list2, free);
	return (0);
}

int	test_dlistdelete(void)
{
	t_dlist	*list;
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

/*
ft_list_dl_add_back(&list, ft_list_dl_create(data2));
// data-> data2
*/
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
	int		*ret;

	data1 = malloc(sizeof(int));
	data2 = malloc(sizeof(int));
	*data1 = 42;
	*data2 = 84;
	list = ft_list_dl_create(data1);
	ft_list_dl_push(&list, data2);
	ret = ft_list_dl_pop(&list);
	if (list == NULL)
		return (1);
	else if (ret != data2)
		return (1);
	ret = ft_list_dl_pop(&list);
	if (ret != data1)
		return (1);
	if (list != NULL)
		return (1);
	ret = ft_list_dl_pop(&list);
	if (ret != NULL)
		return (1);
	ret = ft_list_dl_pop(NULL);
	if (ret != NULL)
		return (1);
	free(data1);
	free(data2);
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
	int		*data3;

	data1 = malloc(sizeof(int));
	*data1 = 42;
	list = NULL;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	data3 = malloc(sizeof(int));
	*data3 = 63;
	ft_list_dl_push_back(&list, data1);
	ft_list_dl_push_back(&list, data2);
	ft_list_dl_push_back(&list, data3);
	if (list == NULL)
		return (1);
	else if (list->data != data1)
		return (1);
	else if (list->next == NULL)
		return (1);
	else if (list->next->data != data2)
		return (1);
	else if (list->next->next == NULL)
		return (1);
	else if (list->next->next->data != data3)
		return (1);
	else if (list->next->next->next != NULL)
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
	if (ft_list_dl_rev(NULL) != NULL)
		return (1);
	list = NULL;
	if (ft_list_dl_rev(&list) != NULL)
		return (1);
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
	ft_list_dl_clear(&sub, NULL);
	sub = ft_list_dl_subrange(NULL, NULL);
	if (sub != NULL)
		return (1);
	sub = ft_list_dl_subrange(list, list);
	if (sub == NULL)
		return (1);
	else if (sub->data != data1)
		return (1);
	else if (sub->next != NULL)
		return (1);
	ft_list_dl_clear(&sub, NULL);
	ft_list_dl_clear(&list, free);
	return (0);
}

int	tests_doubly_linked_list_all(void)
{
	int				collect;
	const t_test	test[] = {
	{"test_dlistadd_front", test_dlistadd_front},
	{"test_dlistadd_back", test_dlistadd_back},
	{"test_dlistapply", test_dlistapply},
	{"test_dlistapply_range", test_dlistapply_range},
	{"test_dlistapply_range_node", test_dlistapply_range_node},
	{"test_dlistclear", test_dlistclear},
	{"test_dlistclear_range", test_dlistclear_range},
	{"test_dlistcreate", test_dlistcreate},
	{"test_dlistcopy_node", test_dlistcopy_node},
	{"test_dlistcopy_list", test_dlistcopy_list},
	{"test_dlist_delete_self", test_dlist_delete_self},
	{"test_dlistdelete_range", test_dlistdelete_range},
	{"test_dlistdelete", test_dlistdelete},
	{"test_dlistfind", test_dlistfind},
	{"test_dlistget_datas", test_dlistget_datas},
	{"test_dlistget_nodes", test_dlistget_nodes},
	{"test_dlist_at", test_dlist_at},
	{"test_dlist_begin", test_dlist_begin},
	{"test_dlist_end", test_dlist_end},
	{"test_dlist_map", test_dlist_map},
	{"test_dlist_new", test_dlist_new},
	{"test_dlist_pop", test_dlist_pop},
	{"test_dlist_pop_back", test_dlist_pop_back},
	{"test_dlist_push", test_dlist_push},
	{"test_dlist_push_back", test_dlist_push_back},
	{"test_dlist_rev", test_dlist_rev},
	{"test_dlist_size", test_dlist_size},
	{"test_dlist_size_of_data", test_dlist_size_of_data},
	{"test_dlist_subrange", test_dlist_subrange},
	{NULL, NULL}
	};

	collect = 0;
	run_test(test, &collect);
	return (collect);
}
