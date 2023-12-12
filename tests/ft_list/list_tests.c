/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:17:51 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/12 17:18:00 by bgoulard         ###   ########.fr       */
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

static void	lnode_add42(t_list *node)
{
	*(int *)node->data += 42;
}

static void	dnode_add42(t_dlist *node)
{
	*(int *)node->data += 42;
}

void	test_listadd_front(void)
{
	t_list	*list;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_listcreate(data2);
	ft_listadd_front(&list, ft_listcreate(data));
	if (list == NULL)
		printf("ft_listadd_front: [FAIL] returned NULL\n");
	else if (list->data != data)
		printf("ft_listadd_front: [FAIL] data not set\n");
	else if (list->next == NULL)
		printf("ft_listadd_front: [FAIL] next not set\n");
	else if (list->next->data != data2)
		printf("ft_listadd_front: [FAIL] next->data not set\n");
	else if (list->next->next != NULL)
		printf("ft_listadd_front: [FAIL] next->next not set\n");
	else
		printf("ft_listadd_front: [OK]\n");
	ft_listclear(&list, free);
}

void	test_listadd_back(void)
{
	t_list	*list;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_listcreate(data);
	ft_listadd_back(&list, ft_listcreate(data2));
	if (list == NULL)
		printf("ft_listadd_back: [FAIL] returned NULL\n");
	else if (list->data != data)
		printf("ft_listadd_back: [FAIL] data not set\n");
	else if (list->next == NULL)
		printf("ft_listadd_back: [FAIL] next not set\n");
	else if (list->next->data != data2)
		printf("ft_listadd_back: [FAIL] next->data not set\n");
	else if (list->next->next != NULL)
		printf("ft_listadd_back: [FAIL] next->next not set\n");
	else
		printf("ft_listadd_back: [OK]\n");
	ft_listclear(&list, free);
}

void	test_listapply(void)
{
	const int	data3 = 63;
	const int	data4 = 84;
	t_list		*list;
	int			*data;
	int			*data2;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_listcreate(data);
	ft_listadd_back(&list, ft_listcreate(data2));
	ft_listapply(list, add42);
	if (list == NULL)
		printf("ft_listapply: [FAIL] returned NULL\n");
	else if (*(int *)list->data != data4)
		printf("ft_listapply: [FAIL] data not 84\n");
	else if (list->next == NULL)
		printf("ft_listapply: [FAIL] next not set\n");
	else if (*(int *)list->next->data != data3)
		printf("ft_listapply: [FAIL] next->data not 63\n");
	else if (list->next->next != NULL)
		printf("ft_listapply: [FAIL] next->next not set correctly\n");
	else
		printf("ft_listapply: [OK]\n");
	ft_listclear(&list, free);
}

void	test_listapply_range(void)
{
	t_list		*list;
	int			*data;
	int			*data2;
	const int	data3 = 84;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_listcreate(data);
	ft_listadd_back(&list, ft_listcreate(data2));
	ft_listapply_range(list, list->next, add42);
	if (*(int *)list->data != data3)
		printf("ft_listapply_range: [FAIL] data not 84\n");
	else if (list->next == NULL)
		printf("ft_listapply_range: [FAIL] next not set\n");
	else if (*(int *)list->next->data != 21)
		printf("ft_listapply_range: [FAIL] next->data not 21\n");
	else if (list->next->next != NULL)
		printf("ft_listapply_range: [FAIL] next->next not set correctly\n");
	else
		printf("ft_listapply_range: [OK]\n");
	ft_listclear(&list, free);
}

void	test_listapply_range_node(void)
{
	const int	data3 = 84;
	t_list		*list;
	int			*data;
	int			*data2;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_listcreate(data);
	ft_listadd_back(&list, ft_listcreate(data2));
	ft_listapply_range_node(list, list->next, lnode_add42);
	if (*(int *)list->data != data3)
		printf("ft_listapply_range_node: [FAIL] data not 84\n");
	else if (list->next == NULL)
		printf("ft_listapply_range_node: [FAIL] next not set\n");
	else if (*(int *)list->next->data != 21)
		printf("ft_listapply_range_node: [FAIL] next->data not 21\n");
	else if (list->next->next != NULL)
		printf("ft_listapply_range_node: [FAIL] next->next not set correctly\n");
	else
		printf("ft_listapply_range_node: [OK]\n");
	ft_listclear(&list, free);
}

void	test_listclear(void)
{
	t_list	*list;
	int		*data;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_listcreate(data);
	ft_listclear(&list, NULL);
	list = ft_listcreate(data);
	ft_listclear(&list, free);
	printf("ft_list_clear: [OK]\n");
}

void	test_listcreate(void)
{
	t_list	*list;
	int		*data;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_listcreate(data);
	if (list == NULL)
		printf("ft_list_create: [FAIL] returned NULL\n");
	else if (list->data != data)
		printf("ft_list_create: [FAIL] data not set\n");
	else if (list->next != NULL)
		printf("ft_list_create: [FAIL] next not set\n");
	else
		printf("ft_list_create: [OK]\n");
	free(data);
	free(list);
}

void	test_listcopy_node(void)
{
	t_list	*list;
	t_list	*copy;
	int		*data;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_listcreate(data);
	copy = ft_listcopy_node(list);
	if (copy == NULL)
		printf("ft_listcopy: [FAIL] returned NULL\n");
	else if (copy->data != list->data)
		printf("ft_listcopy: [FAIL] data not set\n");
	else if (copy->next != list->next)
		printf("ft_listcopy: [FAIL] next not set\n");
	else
		printf("ft_listcopy: [OK]\n");
	free(data);
	free(list);
	free(copy);
}

void	test_listcopy_list(void)
{
	t_list	*list;
	t_list	*copy;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_listcreate(data);
	ft_listadd_back(&list, ft_listcreate(data2));
	copy = ft_listcopy_list(list);
	if (copy == NULL)
		printf("ft_listcopy: [FAIL] returned NULL\n");
	else if (copy->data != list->data)
		printf("ft_listcopy: [FAIL] data not set\n");
	else if (copy->next == NULL)
		printf("ft_listcopy: [FAIL] next not set\n");
	else if (copy->next->data != list->next->data)
		printf("ft_listcopy: [FAIL] next->data not set\n");
	else if (copy->next->next != NULL)
		printf("ft_listcopy: [FAIL] next->next not set\n");
	else
		printf("ft_listcopy: [OK]\n");
	ft_listclear(&list, free);
	ft_listclear(&copy, NULL);
}

void	test_listdelone(void)
{
	t_list	*list;
	int		*data;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_listcreate(data);
	ft_listdelone(list, NULL);
	list = ft_listcreate(data);
	ft_listdelone(list, free);
	printf("ft_listdelone: [OK]\n");
}

void	test_listdelete_range(void)
{
	t_list	*list;
	t_list	*list2;
	int		*data;
	int		*data2;
	int		nb_deleted;
	int		nb_deleted2;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_listcreate(data);
	ft_listadd_back(&list, ft_listcreate(data2));
	list2 = list->next;
	nb_deleted = ft_listdelete_range(list, list->next, NULL);
	nb_deleted2 = ft_listdelete_range(list, list->next, free);
	if (nb_deleted != 0)
		printf("ft_listdelete_range: [FAIL] nb_deleted not 0\n");
	else if (nb_deleted2 != 1)
		printf("ft_listdelete_range: [FAIL] nb_deleted2 not 1\n");
	else if (*(int *)list2->data != 21)
		printf("ft_listdelete_range: [FAIL] data not 21\n");
	else if (list2->next != NULL)
		printf("ft_listdelete_range: [FAIL] next not set\n");
	else
		printf("ft_listdelete_range: [OK]\n");
	ft_listclear(&list2, free);
}

void	test_listfind(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	void	*found;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_listcreate(data);
	ft_listadd_back(&list, ft_listcreate(data2));
	found = ft_listfind(list, data2, NULL);
	if (found == NULL)
		printf("ft_listfind: [FAIL] returned NULL\n");
	else if (*(int *)found != *data2)
		printf("ft_listfind: [FAIL] data not 21\n");
	else
		printf("ft_listfind: [OK]\n");
	ft_listclear(&list, free);
}

void	test_listget_datas(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	void	**datas;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_listcreate(data);
	ft_listadd_back(&list, ft_listcreate(data2));
	datas = ft_listget_datas(list);
	if (datas == NULL)
		printf("ft_listget_datas: [FAIL] returned NULL\n");
	else if (datas[0] != data)
		printf("ft_listget_datas: [FAIL] datas[0] not 42\n");
	else if (datas[1] != data2)
		printf("ft_listget_datas: [FAIL] datas[1] not 21\n");
	else
		printf("ft_listget_datas: [OK]\n");
	ft_listclear(&list, free);
	free(datas);
}

void	test_listget_nodes(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	t_list	**nodes;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_listcreate(data);
	ft_listadd_back(&list, ft_listcreate(data2));
	nodes = ft_listget_nodes(list);
	if (nodes == NULL)
		printf("ft_listget_nodes: [FAIL] returned NULL\n");
	else if (nodes[0] != list)
		printf("ft_listget_nodes: [FAIL] nodes[0] not list\n");
	else if (nodes[1] != list->next)
		printf("ft_listget_nodes: [FAIL] nodes[1] not list->next\n");
	else
		printf("ft_listget_nodes: [OK]\n");
	ft_listclear(&list, free);
	free(nodes);
}

void	test_listlast(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	t_list	*last;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_listcreate(data);
	ft_listadd_back(&list, ft_listcreate(data2));
	last = ft_listlast(list);
	if (last == NULL)
		printf("ft_listlast: [FAIL] returned NULL\n");
	else if (last->data != data2)
		printf("ft_listlast: [FAIL] last->data not 21\n");
	else if (last->next != NULL)
		printf("ft_listlast: [FAIL] last->next not NULL\n");
	else
		printf("ft_listlast: [OK]\n");
	ft_listclear(&list, free);
}

void	test_listat(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	t_list	*at;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_listcreate(data);
	ft_listadd_back(&list, ft_listcreate(data2));
	at = ft_listat(list, 1);
	if (at == NULL)
		printf("ft_listat: [FAIL] returned NULL\n");
	else if (at->data != data2)
		printf("ft_listat: [FAIL] at->data not 21\n");
	else if (at->next != NULL)
		printf("ft_listat: [FAIL] at->next not NULL\n");
	else
		printf("ft_listat: [OK]\n");
	ft_listclear(&list, free);
}

void	test_listmap(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	t_list	*map;
	t_list	*map2;
	t_list	*map3;
	t_list	*map4;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_listcreate(data);
	ft_listadd_back(&list, ft_listcreate(data2));
	map = ft_listmap(list, add42_ret, free);
	map2 = ft_listmap(list, NULL, free);
	map3 = ft_listmap(NULL, add42_ret, free);
	map4 = ft_listmap(list, add42_ret, NULL);
	if (map == NULL)
		printf("ft_listmap: [FAIL] returned NULL\n");
	else if (*(int *)map->data != 84)
		printf("ft_listmap: [FAIL] map->data not 84\n");
	else if (map->next == NULL)
		printf("ft_listmap: [FAIL] map->next not set\n");
	else if (*(int *)map->next->data != 63)
		printf("ft_listmap: [FAIL] map->next->data not 63\n");
	else if (map->next->next != NULL)
		printf("ft_listmap: [FAIL] map->next->next not NULL\n");
	else if (map2 != NULL)
		printf("ft_listmap: [FAIL] map2 not NULL\n");
	else if (map3 != NULL)
		printf("ft_listmap: [FAIL] map3 not NULL\n");
	else if (map4 != NULL)
		printf("ft_listmap: [FAIL] map4 not NULL\n");
	else
		printf("ft_listmap: [OK]\n");
	ft_listclear(&list, free);
	ft_listclear(&map, free);
}

void	test_listnew(void)
{
	t_list	*list;

	list = ft_listnew();
	if (list == NULL)
		printf("ft_listnew: [FAIL] returned NULL\n");
	else
		printf("ft_listnew: [OK]\n");
	free(list);
}

void	test_listpush(void)
{
	t_list	*list;
	t_list	*list_rep1;
	t_list	*list_rep2;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = NULL;
	list_rep1 = ft_listpush(&list, data);
	list_rep2 = ft_listpush(&list, data2);
	if (list == NULL || list_rep1 == NULL || list_rep2 == NULL)
		printf("ft_listpush: [FAIL] returned NULL\n");
	else if (list != list_rep2)
		printf("ft_listpush: [FAIL] list != list_rep2\n");
	else if (list->next != list_rep1)
		printf("ft_listpush: [FAIL] list->next != list_rep1\n");
	else if (list->data != data2)
		printf("ft_listpush: [FAIL] list->data not 21\n");
	else if (list->next == NULL)
		printf("ft_listpush: [FAIL] list->next not set\n");
	else if (list->next->data != data)
		printf("ft_listpush: [FAIL] list->next->data not 42\n");
	else if (list->next->next != NULL)
		printf("ft_listpush: [FAIL] list->next->next not NULL\n");
	else
		printf("ft_listpush: [OK]\n");
	ft_listclear(&list, free);
}

void	test_listpush_back(void)
{
	t_list	*list;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = NULL;
	ft_listpush_back(&list, data);
	ft_listpush_back(&list, data2);
	if (list == NULL)
		printf("ft_listpush: [FAIL] returned NULL\n");
	else if (list->data != data)
		printf("ft_listpush: [FAIL] list->data not 21\n");
	else if (list->next == NULL)
		printf("ft_listpush: [FAIL] list->next not set\n");
	else if (list->next->data != data2)
		printf("ft_listpush: [FAIL] list->next->data not 42\n");
	else if (list->next->next != NULL)
		printf("ft_listpush: [FAIL] list->next->next not NULL\n");
	else
		printf("ft_listpush: [OK]\n");
	ft_listclear(&list, free);
}

void	test_listpop(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	void	*pop;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = NULL;
	ft_listpush(&list, data);
	ft_listpush(&list, data2);
	pop = ft_listpop(&list);
	if (list == NULL)
		printf("ft_listpop: [FAIL] returned NULL\n");
	else if (list->data != data)
		printf("ft_listpop: [FAIL] list->data not 42\n");
	else if (list->next != NULL)
		printf("ft_listpop: [FAIL] list->next not NULL\n");
	else if (pop != data2)
		printf("ft_listpop: [FAIL] pop not 21\n");
	else
		printf("ft_listpop: [OK]\n");
	ft_listclear(&list, free);
	free(pop);
}

void	test_listpop_back(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	void	*pop;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = NULL;
	ft_listpush(&list, data);
	ft_listpush(&list, data2);
	pop = ft_listpop_back(&list);
	if (list == NULL)
		printf("ft_listpop_back: [FAIL] returned NULL\n");
	else if (list->data != data2)
		printf("ft_listpop_back: [FAIL] list->data not 21\n");
	else if (list->next != NULL)
		printf("ft_listpop_back: [FAIL] list->next not NULL\n");
	else if (pop != data)
		printf("ft_listpop_back: [FAIL] pop not 42\n");
	else
		printf("ft_listpop_back: [OK]\n");
	ft_listclear(&list, free);
	free(pop);
}

void	test_listrev(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	t_list	*rev;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = NULL;
	ft_listpush(&list, data);
	ft_listpush(&list, data2);
	rev = ft_listrev(&list);
	if (rev == NULL)
		printf("ft_listrev: [FAIL] returned NULL\n");
	else if (rev->data != data)
		printf("ft_listrev: [FAIL] rev->data not 42\n");
	else if (rev->next == NULL)
		printf("ft_listrev: [FAIL] rev->next not set\n");
	else if (rev->next->data != data2)
		printf("ft_listrev: [FAIL] rev->next->data not 21\n");
	else if (rev->next->next != NULL)
		printf("ft_listrev: [FAIL] rev->next->next not NULL\n");
	else
		printf("ft_listrev: [OK]\n");
	ft_listclear(&rev, free);
}

void	test_listsize(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	size_t	size1;
	size_t	size2;
	size_t	size3;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = NULL;
	size1 = ft_listsize(list);
	ft_listpush(&list, data);
	size2 = ft_listsize(list);
	ft_listpush(&list, data2);
	size3 = ft_listsize(list);
	if (size1 != 0)
		printf("ft_listsize: [FAIL] size not 0\n");
	if (size2 != 1)
		printf("ft_listsize: [FAIL] size not 1\n");
	if (size3 != 2)
		printf("ft_listsize: [FAIL] size not 2\n");
	else
		printf("ft_listsize: [OK]\n");
	ft_listclear(&list, free);
}

void	test_listsize_match(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	size_t	size1;
	size_t	size2;
	size_t	size3;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = NULL;
	size1 = ft_listsize_match(list, is42);
	ft_listpush(&list, data);
	size2 = ft_listsize_match(list, is42);
	ft_listpush(&list, data2);
	size3 = ft_listsize_match(list, is42);
	if (size1 != 0)
		printf("ft_listsize_match: [FAIL] size not 0\n");
	if (size2 != 1)
		printf("ft_listsize_match: [FAIL] size not 1\n");
	if (size3 != 1)
		printf("ft_listsize_match: [FAIL] size not 1\n");
	else
		printf("ft_listsize_match: [OK]\n");
	ft_listclear(&list, free);
}

void	test_listsubrange(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	t_list	*sub;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = NULL;
	ft_listpush(&list, data);
	ft_listpush(&list, data2);
	sub = ft_listsubrange(list, list->next);
	if (sub == NULL)
		printf("ft_listsubrange: [FAIL] returned NULL\n");
	else if (sub->data != data2)
		printf("ft_listsubrange: [FAIL] sub->data not 21\n");
	else if (sub->next != NULL)
		printf("ft_listsubrange: [FAIL] sub->next not NULL\n");
	else
		printf("ft_listsubrange: [OK]\n");
	ft_listclear(&list, free);
	ft_listclear(&sub, NULL);
}

/* ************************************************************************** */
/*                          DOUBLY LINKED LIST TESTS                          */
/* ************************************************************************** */

void	test_dlistadd_front(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_list_dl_create(data2);
	ft_list_dl_add_front(&list, ft_list_dl_create(data));
	if (list == NULL)
		printf("ft_list_dl_add_front: [FAIL] returned NULL\n");
	else if (list->data != data)
		printf("ft_list_dl_add_front: [FAIL] data not set\n");
	else if (list->next == NULL)
		printf("ft_list_dl_add_front: [FAIL] next not set\n");
	else if (list->next->data != data2)
		printf("ft_list_dl_add_front: [FAIL] next->data not set\n");
	else if (list->next->next != NULL)
		printf("ft_list_dl_add_front: [FAIL] next->next not set\n");
	else if (list->next->prev != list)
		printf("ft_list_dl_add_front: [FAIL] next->prev not set\n");
	else
		printf("ft_list_dl_add_front: [OK]\n");
	ft_list_dl_clear(&list, free);
}

void	test_dlistadd_back(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_list_dl_create(data);
	ft_list_dl_add_back(&list, ft_list_dl_create(data2));
	if (list == NULL)
		printf("ft_list_dl_add_back: [FAIL] returned NULL\n");
	else if (list->data != data)
		printf("ft_list_dl_add_back: [FAIL] data not set\n");
	else if (list->next == NULL)
		printf("ft_list_dl_add_back: [FAIL] next not set\n");
	else if (list->next->data != data2)
		printf("ft_list_dl_add_back: [FAIL] next->data not set\n");
	else if (list->next->next != NULL)
		printf("ft_list_dl_add_back: [FAIL] next->next not set\n");
	else if (list->next->prev != list)
		printf("ft_list_dl_add_back: [FAIL] next->prev not set\n");
	else
		printf("ft_list_dl_add_back: [OK]\n");
	ft_list_dl_clear(&list, free);
}

void	test_dlistapply(void)
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
		printf("ft_list_dl_apply: [FAIL] returned NULL\n");
	else if (*(int *)list->data != 63)
		printf("ft_list_dl_apply: [FAIL] data not 63\n");
	else if (list->next == NULL)
		printf("ft_list_dl_apply: [FAIL] next not set\n");
	else if (*(int *)list->next->data != 84)
		printf("ft_list_dl_apply: [FAIL] next->data not 84\n");
	else if (list->next->next != NULL)
		printf("ft_list_dl_apply: [FAIL] next->next not set correctly\n");
	else
		printf("ft_list_dl_apply: [OK]\n");
	ft_list_dl_clear(&list, free);
}

void	test_dlistapply_range(void)
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
		printf("ft_list_dl_apply_range: [FAIL] data not 63\n");
	else if (list->next == NULL)
		printf("ft_list_dl_apply_range: [FAIL] next not set\n");
	else if (*(int *)list->next->data != 42)
		printf("ft_list_dl_apply_range: [FAIL] next->data not 84\n");
	else if (list->next->next != NULL)
		printf("ft_list_dl_apply_range: [FAIL] next->next not set correctly\n");
	else
		printf("ft_list_dl_apply_range: [OK]\n");
	ft_list_dl_clear(&list, free);
}

void	test_dlistapply_range_node(void)
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
		printf("ft_list_dl_apply_range_node: [FAIL] data not 21\n");
	else if (list->next == NULL)
		printf("ft_list_dl_apply_range_node: [FAIL] next not set\n");
	else if (*(int *)list->next->data != 42)
		printf("ft_list_dl_apply_range_node: [FAIL] next->data not 84\n");
	else if (list->next->next != NULL)
		printf("ft_list_dl_apply_range_node: [FAIL] next->next not set correctly\n");
	else
		printf("ft_list_dl_apply_range_node: [OK]\n");
	ft_list_dl_clear(&list, free);
}

void	test_dlistclear(void)
{
	t_dlist	*list;
	int		*data;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_list_dl_create(data);
	ft_list_dl_clear(&list, NULL);
	list = ft_list_dl_create(data);
	ft_list_dl_clear(&list, free);
	printf("ft_list_dl_clear: [OK]\n");
}

void	test_dlistcreate(void)
{
	t_dlist	*list;
	int		*data;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_list_dl_create(data);
	if (list == NULL)
		printf("ft_list_dl_create: [FAIL] returned NULL\n");
	else if (list->data != data)
		printf("ft_list_dl_create: [FAIL] data not set\n");
	else if (list->next != NULL)
		printf("ft_list_dl_create: [FAIL] next not set\n");
	else if (list->prev != NULL)
		printf("ft_list_dl_create: [FAIL] prev not set\n");
	else
		printf("ft_list_dl_create: [OK]\n");
	ft_list_dl_clear(&list, free);
}

void	test_dlistcopy_node(void)
{
	int		*data;
	t_dlist	*list;
	t_dlist	*copy;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_list_dl_create(data);
	copy = ft_list_dl_copy_node(list);
	if (copy == NULL)
		printf("ft_list_dl_copy_node: [FAIL] returned NULL\n");
	else if (copy->data != list->data)
		printf("ft_list_dl_copy_node: [FAIL] data not set\n");
	else if (copy->next != list->next)
		printf("ft_list_dl_copy_node: [FAIL] next not set\n");
	else if (copy->prev != list->prev)
		printf("ft_list_dl_copy_node: [FAIL] prev not set\n");
	else
		printf("ft_list_dl_copy_node: [OK]\n");
	ft_list_dl_clear(&list, free);
	ft_list_dl_clear(&copy, NULL);
}

void	test_dlistcopy_list(void)
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
		printf("ft_list_dl_copy_list: [FAIL] returned NULL\n");
	else if (copy->data != list->data)
		printf("ft_list_dl_copy_list: [FAIL] data not set\n");
	else if (copy->next == NULL)
		printf("ft_list_dl_copy_list: [FAIL] next not set\n");
	else if (copy->next->data != list->next->data)
		printf("ft_list_dl_copy_list: [FAIL] next->data not set\n");
	else if (copy->next->next != NULL)
		printf("ft_list_dl_copy_list: [FAIL] next->next not set\n");
	else if (copy->next->prev != copy)
		printf("ft_list_dl_copy_list: [FAIL] next->prev not set\n");
	else
		printf("ft_list_dl_copy_list: [OK]\n");
	ft_list_dl_clear(&list, free);
	ft_list_dl_clear(&copy, NULL);
}

void	test_dlist_delete_self(void)
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
	ft_list_dl_delete_self(list->next, NULL);
	if (list == NULL)
		printf("ft_list_dl_delete_self: [FAIL] returned NULL\n");
	else if (list->data != data)
		printf("ft_list_dl_delete_self: [FAIL] data not set\n");
	else if (list->next == NULL)
		printf("ft_list_dl_delete_self: [FAIL] next not set\n");
	else if (list->next->data != data3)
		printf("ft_list_dl_delete_self: [FAIL] next->data not set\n");
	else if (list->next->next != NULL)
		printf("ft_list_dl_delete_self: [FAIL] next->next not set\n");
	else
		printf("ft_list_dl_delete_self: [OK]\n");
	ft_list_dl_clear(&list, free);
	free(data2);
	list = ft_list_dl_create(data3);
	ft_list_dl_delete_self(list, free);
}

void	test_dlistdelete_range(void)
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
	// data-> data2-> data3
	list2 = list->next;
	nb_deleted = ft_list_dl_delete_range(list, list->next, NULL);
	if (nb_deleted != 1)
		printf("ft_list_dl_delete_range: [FAIL] nb_deleted not 2\n");
	else if (*(int *)list2->data != *data2)
		printf("ft_list_dl_delete_range: [FAIL] data not 42\n");
	else if (list2->next == NULL)
		printf("ft_list_dl_delete_range: [FAIL] next not set\n");
	else if (*(int *)list2->next->data != *data3)
		printf("ft_list_dl_delete_range: [FAIL] next->data not 63\n");
	else if (list2->next->next != NULL)
		printf("ft_list_dl_delete_range: [FAIL] next->next not set correctly\n");
	else
		printf("ft_list_dl_delete_range: [OK]\n");
	ft_list_dl_clear(&list2, free);
	free(data);
}

void	test_dlistfind(void)
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
		printf("ft_list_dl_find: [FAIL] returned NULL\n");
	else if (found1->data != data2)
		printf("ft_list_dl_find: [FAIL] data not 21\n");
	else if (found1->next != NULL)
		printf("ft_list_dl_find: [FAIL] next not set\n");
	else if (found2 != NULL)
		printf("ft_list_dl_find: [FAIL] found2 not NULL\n");
	else if (found3 == NULL)
		printf("ft_list_dl_find: [FAIL] found3 NULL\n");
	else if (found3->data != data2)
		printf("ft_list_dl_find: [FAIL] found3->data not 21\n");
	else if (found3->next != NULL)
		printf("ft_list_dl_find: [FAIL] found3->next not NULL\n");
	else
		printf("ft_list_dl_find: [OK]\n");
	ft_list_dl_clear(&list, free);
	free(data3);
}

void	test_dlistget_datas(void)
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
		printf("ft_list_dl_get_datas: [FAIL] returned NULL\n");
	else if (datas[0] != data)
		printf("ft_list_dl_get_datas: [FAIL] datas[0] not 42\n");
	else if (datas[1] != data2)
		printf("ft_list_dl_get_datas: [FAIL] datas[1] not 21\n");
	else
		printf("ft_list_dl_get_datas: [OK]\n");
	ft_list_dl_clear(&list, free);
	free(datas);
}


void test_dlistget_nodes(void)
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
		printf("ft_list_dl_get_nodes: [FAIL] returned NULL\n");
	else if (nodes[0] != list)
		printf("ft_list_dl_get_nodes: [FAIL] nodes[0] not list\n");
	else if (nodes[1] != list->next)
		printf("ft_list_dl_get_nodes: [FAIL] nodes[1] not list->next\n");
	else
		printf("ft_list_dl_get_nodes: [OK]\n");
	ft_list_dl_clear(&list, free);
	free(nodes);
}

void test_dlist_at(void)
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
		printf("ft_list_dl_at: [FAIL] returned NULL\n");
	else if (at->data != data2)
		printf("ft_list_dl_at: [FAIL] at->data not 21\n");
	else if (at->next != NULL)
		printf("ft_list_dl_at: [FAIL] at->next not NULL\n");
	else if (at->prev != list)
		printf("ft_list_dl_at: [FAIL] at->prev not list\n");
	else
		printf("ft_list_dl_at: [OK]\n");
	ft_list_dl_clear(&list, free);
}

void test_dlist_begin(void)
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
		printf("ft_list_dl_begin: [FAIL] returned NULL\n");
	else if (begin != list)
		printf("ft_list_dl_begin: [FAIL] begin not list\n");
	else if (begin->data != data)
		printf("ft_list_dl_begin: [FAIL] begin->data not 42\n");
	else if (begin->next != list->next)
		printf("ft_list_dl_begin: [FAIL] begin->next not list->next\n");
	else if (begin->prev != NULL)
		printf("ft_list_dl_begin: [FAIL] begin->prev not NULL\n");
	else
		printf("ft_list_dl_begin: [OK]\n");
	ft_list_dl_clear(&list, free);
}

void test_dlist_end(void)
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
		printf("ft_list_dl_end: [FAIL] returned NULL\n");
	else if (end->data != data2)
		printf("ft_list_dl_end: [FAIL] end->data not 21\n");
	else if (end->next != NULL)
		printf("ft_list_dl_end: [FAIL] end->next not NULL\n");
	else if (end->prev != list)
		printf("ft_list_dl_end: [FAIL] end->prev not list\n");
	else
		printf("ft_list_dl_end: [OK]\n");
	ft_list_dl_clear(&list, free);
}

void test_dlist_map(void)
{
	t_dlist *list;
	t_dlist *map;
	t_dlist *map2;
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
		printf("ft_list_dl_map: [FAIL] returned NULL\n");
	else if (*(int *)map->data != 84)
		printf("ft_list_dl_map: [FAIL] map->data not 84\n");
	else if (map->next == NULL)
		printf("ft_list_dl_map: [FAIL] map->next not set\n");
	else if (*(int *)map->next->data != 63)
		printf("ft_list_dl_map: [FAIL] map->next->data not 63\n");
	else if (map->next->next != NULL)
		printf("ft_list_dl_map: [FAIL] map->next->next not NULL\n");
	else if (map2 != NULL)
		printf("ft_list_dl_map: [FAIL] map2 not NULL\n");
	else
		printf("ft_list_dl_map: [OK]\n");
	ft_list_dl_clear(&list, free);
	ft_list_dl_clear(&map, free);
}

void test_dlist_new(void)
{
	t_dlist *list;
	
	list = ft_list_dl_new();
	if (list == NULL)
		printf("ft_list_dl_new: [FAIL] returned NULL\n");
	else
		printf("ft_list_dl_new: [OK]\n");
	ft_list_dl_clear(&list, free);
	return ;
}

void test_dlist_pop(void)
{
	t_dlist *list;
	int		*data1;
	int		*data2;

	data1 = malloc(sizeof(int));
	*data1 = 42;
	list = ft_list_dl_create(data1);
	data2 = ft_list_dl_pop(&list);
	if (list != NULL)
		printf("ft_list_dl_pop: [FAIL] list not NULL\n");
	else if (data2 != data1)
		printf("ft_list_dl_pop: [FAIL] data2 not data1\n");
	else
		printf("ft_list_dl_pop: [OK]\n");
	free(data2);
	return ;
}

void test_dlist_pop_back(void)
{
	t_dlist *list;
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
		printf("ft_list_dl_pop_back: [FAIL] list not NULL\n");
	else if (data3 != data2)
		printf("ft_list_dl_pop_back: [FAIL] data3 not data2\n");
	else
		printf("ft_list_dl_pop_back: [OK]\n");
	ft_list_dl_clear(&list, free);
	free(data3);
	return ;
}

void test_dlist_push(void)
{
	t_dlist *list;
	int		*data1;

	data1 = malloc(sizeof(int));
	*data1 = 42;
	list = NULL;
	ft_list_dl_push(&list, data1);
	if (list == NULL)
		printf("ft_list_dl_push: [FAIL] list not NULL\n");
	else if (list->data != data1)
		printf("ft_list_dl_push: [FAIL] list->data not data1\n");
	else
		printf("ft_list_dl_push: [OK]\n");
	ft_list_dl_clear(&list, free);
	return ;
}

void test_dlist_push_back(void)
{
	t_dlist *list;
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
		printf("ft_list_dl_push_back: [FAIL] list not NULL\n");
	else if (list->data != data1)
		printf("ft_list_dl_push_back: [FAIL] list->data not data1\n");
	else if (list->next == NULL)
		printf("ft_list_dl_push_back: [FAIL] list->next not set\n");
	else if (list->next->data != data2)
		printf("ft_list_dl_push_back: [FAIL] list->next->data not data2\n");
	else
		printf("ft_list_dl_push_back: [OK]\n");
	ft_list_dl_clear(&list, free);
	return ;
}

void test_dlist_rev(void)
{
	t_dlist *list;
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
		printf("ft_list_dl_rev: [FAIL] list should not NULL\n");
	else if (list->data != original_data2)
		printf("ft_list_dl_rev: [FAIL] list->data not original_data2\n");
	else if (list->next == NULL)
		printf("ft_list_dl_rev: [FAIL] list->next not set\n");
	else if (list->next->data != original_data1)
		printf("ft_list_dl_rev: [FAIL] list->next->data not original_data1\n");
	else
		printf("ft_list_dl_rev: [OK]\n");
	ft_list_dl_clear(&list, free);
	return ;
}

void test_dlist_size(void)
{
	t_dlist *list;
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
		printf("ft_list_dl_size: [FAIL] size not 0\n");
	else if (size2 != 1)
		printf("ft_list_dl_size: [FAIL] size not 1\n");
	else if (size3 != 2)
		printf("ft_list_dl_size: [FAIL] size not 2\n");
	else
		printf("ft_list_dl_size: [OK]\n");
	ft_list_dl_clear(&list, free);
}

void test_dlist_size_of_data(void)
{
	t_dlist *list;
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
		printf("ft_list_dl_size_of_data: [FAIL] size not 0\n");
	else if (size2 != 1)
		printf("ft_list_dl_size_of_data: [FAIL] size2 not 1\n");
	else if (size3 != 1)
		printf("ft_list_dl_size_of_data: [FAIL] size3 not 1\n");
	else
		printf("ft_list_dl_size_of_data: [OK]\n");
	ft_list_dl_clear(&list, free);
}

void test_dlist_subrange(void)
{
	t_dlist *list;
	t_dlist *sub;
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
		printf("ft_list_dl_subrange: [FAIL] returned NULL\n");
	else if (sub->data != data1)
		printf("ft_list_dl_subrange: [FAIL] sub->data not 21\n");
	else if (sub->next != NULL)
		printf("ft_list_dl_subrange: [FAIL] sub->next not NULL\n");
	else
		printf("ft_list_dl_subrange: [OK]\n");
	ft_list_dl_clear(&list, free);
	ft_list_dl_clear(&sub, NULL);
}

/* ************************************************************************** */
/*                          TESTS ALL FUNCTIONS                               */
/* ************************************************************************** */

void tests_linked_list_all(void)
{
	printf("== ft_list ==\n");
	test_listadd_front();
	test_listadd_back();
	test_listapply();
	test_listapply_range();
	test_listapply_range_node();
	test_listclear();
	test_listcreate();
	test_listcopy_node();
	test_listcopy_list();
	test_listdelone();
	test_listdelete_range();
	test_listfind();
	test_listget_datas();
	test_listget_nodes();
	test_listlast();
	test_listat();
	test_listmap();
	test_listnew();
	test_listpush();
	test_listpush_back();
	test_listpop();
	test_listpop_back();
	test_listrev();
	test_listsize();
	test_listsize_match();
	test_listsubrange();
	printf("== end ==\n");
}

void	tests_doubly_linked_list_all(void)
{
	printf("== ft_dlist ==\n");
	test_dlistadd_front();
	test_dlistadd_back();
	test_dlistapply();
	test_dlistapply_range();
	test_dlistapply_range_node();
	test_dlistclear();
	test_dlistcreate();
	test_dlistcopy_node();
	test_dlistcopy_list();
	test_dlist_delete_self();
	test_dlistdelete_range();
	test_dlistfind();
	test_dlistget_datas();
	test_dlistget_nodes();
	test_dlist_at();
	test_dlist_begin();
	test_dlist_end();
	test_dlist_map();
	test_dlist_new();
	test_dlist_pop();
	test_dlist_pop_back();
	test_dlist_push();
	test_dlist_push_back();
	test_dlist_rev();
	test_dlist_size();
	test_dlist_size_of_data();
	test_dlist_subrange();
	printf("== end ==\n");
}

int	main(void)
{
//	tests_linked_list_all();
	tests_doubly_linked_list_all();
	return (0);
}
