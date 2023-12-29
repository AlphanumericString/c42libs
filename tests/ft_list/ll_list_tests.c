/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_list_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:17:51 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/29 16:15:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "tests/tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static int	cmp_int(void *data1, void *data2)
{
	return (*(int *)data1 - *(int *)data2);
}

static void	lnode_add42(t_list *node)
{
	*(int *)node->data += 42;
}

int	test_listadd_front(void)
{
	t_list	*list;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = NULL;
	ft_listadd_front(&list, ft_listcreate(data2)); // (21)-> NULL
	ft_listadd_front(&list, ft_listcreate(data)); // (42)-> (21)-> NULL
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
	ft_listadd_front(NULL, list); // null resiliency
	ft_listclear(&list, free);
	return (0);
}

int	test_listadd_back(void)
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
		return (1);
	else if (list->data != data)
		return (1);
	else if (list->next == NULL)
		return (1);
	else if (list->next->data != data2)
		return (1);
	else if (list->next->next != NULL)
		return (1);
	ft_listclear(&list, free);
	return (0);
}

int	test_listapply(void)
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
		return (1);
	else if (*(int *)list->data != data4)
		return (1);
	else if (list->next == NULL)
		return (1);
	else if (*(int *)list->next->data != data3)
		return (1);
	else if (list->next->next != NULL)
		return (1);
	ft_listapply(list, NULL);
	if (list == NULL)
		return (1);
	else if (*(int *)list->data != data4)
		return (1);
	else if (list->next == NULL)
		return (1);
	else if (*(int *)list->next->data != data3)
		return (1);
	else if (list->next->next != NULL)
		return (1);
	ft_listclear(&list, free);
	return (0);
}

int	test_listapply_range(void)
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
		return (1);
	else if (list->next == NULL)
		return (1);
	else if (*(int *)list->next->data != 21)
		return (1);
	else if (list->next->next != NULL)
		return (1);
	ft_listapply_range(list, list->next, NULL);
	if (*(int *)list->data != data3)
		return (1);
	else if (list->next == NULL)
		return (1);
	else if (*(int *)list->next->data != 21)
		return (1);
	else if (list->next->next != NULL)
		return (1);
	ft_listapply_range(NULL, NULL, add42);
	ft_listclear(&list, free);
	return (0);
}

int	test_listapply_range_node(void)
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
		return (1);
	else if (list->next == NULL)
		return (1);
	else if (*(int *)list->next->data != 21)
		return (1);
	else if (list->next->next != NULL)
		return (1);
	ft_listapply_range_node(list, list->next, NULL);
	if (*(int *)list->data != data3)
		return (1);
	else if (list->next == NULL)
		return (1);
	else if (*(int *)list->next->data != 21)
		return (1);
	else if (list->next->next != NULL)
		return (1);
	ft_listapply_range_node(NULL, NULL, lnode_add42);
	ft_listclear(&list, free);
	return (0);
}

int	test_listclear(void)
{
	t_list	*list;
	int		*data;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_listcreate(data);
	ft_listclear(&list, NULL);
	list = ft_listcreate(data);
	ft_listclear(&list, free);
	ft_listclear(NULL, NULL);
	return (0);
}

int	test_listcreate(void)
{
	t_list	*list;
	int		*data;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_listcreate(data);
	if (list == NULL)
		return (1);
	else if (list->data != data)
		return (1);
	else if (list->next != NULL)
		return (1);
	free(data);
	free(list);
	return (0);
}

int	test_listcopy_node(void)
{
	t_list	*list;
	t_list	*copy;
	int		*data;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_listcreate(data);
	copy = ft_listcopy_node(list);
	if (copy == NULL)
		return (1);
	else if (copy->data != list->data)
		return (1);
	else if (copy->next != list->next)
		return (1);
	free(data);
	free(list);
	free(copy);
	return (0);
}

int	test_listcopy_list(void)
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
		return (1);
	else if (copy->data != list->data)
		return (1);
	else if (copy->next == NULL)
		return (1);
	else if (copy->next->data != list->next->data)
		return (1);
	else if (copy->next->next != NULL)
		return (1);
	ft_listclear(&list, free);
	ft_listclear(&copy, NULL);
	return (0);
}

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
	ft_listdelone(NULL, NULL); // null resiliency
	return (0);
}

int	test_listdelete_range(void)
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
	ft_listadd_back(&list, ft_listcreate(data2)); // (42)-> (21)-> NULL
	list2 = list->next;
	nb_deleted = ft_listdelete_range(list, list->next, NULL); // (42)-> (21)-> NULL
	nb_deleted2 = ft_listdelete_range(list, list->next, free); // (21)-> NULL
	// we use list2 to check if the list is still valid
	// list was destroyed by ft_listdelete_range
	if (nb_deleted != 0)
		return (__LINE__);
	else if (nb_deleted2 != 1)
		return (__LINE__);
	else if (list2->data != data2)
		return (__LINE__);
	else if (list2->next != NULL)
		return (__LINE__);
	ft_listclear(&list2, free); // NULL

	nb_deleted = ft_listdelete_range(NULL, NULL, free); // null resiliency
	if (nb_deleted != 0)
		return (__LINE__);

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_listcreate(data); // (42)-> NULL
	nb_deleted = ft_listdelete_range(list, NULL, free); // NULL
	if (nb_deleted != 1)
		return (__LINE__);
	return (0);
}

int	test_listfind(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	int 	*data3;
	void	*found;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	data3 = malloc(sizeof(int));
	*data3 = 63;
	list = ft_listcreate(data);
	ft_listadd_back(&list, ft_listcreate(data2));
	found = ft_listfind(list, data2, NULL);
	if (found == NULL)
		return (1);
	else if (*(int *)found != *data2)
		return (2);
	found = ft_listfind(list, data3, cmp_int);
	if (found != NULL)
		return (3);
	found = ft_listfind(NULL, data2, NULL);
	if (found != NULL)
		return (4);
	*data3 = 42;
	found = ft_listfind(list, data3, cmp_int);
	if (found == NULL)
		return (5);
	else if (*(int *)found != *data)
		return (6);
	ft_listclear(&list, free);
	free(data3);
	return (0);
}

int	test_listget_datas(void)
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
		return (1);
	else if (datas[0] != data)
		return (1);
	else if (datas[1] != data2)
		return (1);
	if (ft_listget_datas(NULL) != NULL)
		return (1);
	ft_listclear(&list, free);
	free(datas);
	return (0);
}

int	test_listget_nodes(void)
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
		return (1);
	else if (nodes[0] != list)
		return (1);
	else if (nodes[1] != list->next)
		return (1);
	if (ft_listget_nodes(NULL) != NULL)
		return (1);
	ft_listclear(&list, free);
	free(nodes);
	return (0);
}

int	test_listlast(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	t_list	*last;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = NULL;
	ft_listadd_front(&list, ft_listcreate(data2));
	ft_listadd_front(&list, ft_listcreate(data));
	last = ft_listlast(list);
	if (last == NULL)
		return (1);
	else if (last->data != data2)
		return (1);
	else if (last->next != NULL)
		return (1);
	last = ft_listlast(NULL);
	if (last != NULL)
		return (1);
	ft_listclear(&list, free);
	return (0);
}

int	test_listat(void)
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
		return (1);
	else if (at->data != data2)
		return (1);
	else if (at->next != NULL)
		return (1);
	at = ft_listat(list, 456);
	if (at != NULL)
		return (1);
	at = ft_listat(NULL, 0);
	if (at != NULL)
		return (1);
	ft_listclear(&list, free);
	return (0);
}

int	test_listmap(void)
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
	else if (map3 != NULL)
		return (1);
	else if (map4 != NULL)
		return (1);
	ft_listclear(&list, free);
	ft_listclear(&map, free);
	return (0);
}

int	test_listnew(void)
{
	t_list	*list;

	list = ft_listnew();
	if (list == NULL)
		return (1);
	free(list);
	return (0);
}

int	test_listpush(void)
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
		return (1);
	else if (list != list_rep2)
		return (1);
	else if (list->next != list_rep1)
		return (1);
	else if (list->data != data2)
		return (1);
	else if (list->next == NULL)
		return (1);
	else if (list->next->data != data)
		return (1);
	else if (list->next->next != NULL)
		return (1);
	ft_listclear(&list, free);
	// test 2
	ft_listpush(NULL, NULL);
	return (0);
}

int	test_listpush_back(void)
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
		return (1);
	else if (list->data != data)
		return (1);
	else if (list->next == NULL)
		return (1);
	else if (list->next->data != data2)
		return (1);
	else if (list->next->next != NULL)
		return (1);
	ft_listclear(&list, free);
	ft_listpush_back(NULL, NULL);
	return (0);
}

int	test_listpop(void)
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
		return (1);
	else if (list->data != data)
		return (1);
	else if (list->next != NULL)
		return (1);
	else if (pop != data2)
		return (1);
	ft_listclear(&list, free);
	free(pop);
	if (ft_listpop(&list) != NULL)
		return (1);
	if (ft_listpop(NULL) != NULL)
		return (1);
	return (0);
}

int	test_listpop_back(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	int		*data3;
	void	*pop;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	data3 = malloc(sizeof(int));
	*data3 = 63;
	list = NULL;
	ft_listpush(&list, data); // (42)-> NULL
	ft_listpush(&list, data2); // (21)-> (42)-> NULL
	ft_listpush(&list, data3); // (63)-> (21)-> (42)-> NULL
	pop = ft_listpop_back(&list); // 42 : (63)-> (21)-> NULL
	if (list == NULL) // was list destroyed ?
		return (1);
	else if (list->data != data3) // is first elem of list 63
		return (1);
	else if (list->next == NULL) // is second elem present
		return (1);
	else if (list->next->data != data2) // is second elem 21
		return (1);
	else if (list->next->next != NULL) // was the end of the list ptr set to smth bad?
		return (1);
	else if (pop != data) // was elem pulled out 42 ?
		return (1);
	pop = ft_listpop_back(&list); // 21 : (63)->NULL
	if (list == NULL)
		return (1);
	else if (list->next != NULL) 
		return (1);
	else if (list->data != data3)
		return (1);
	else if (pop != data2)
		return (1);
	pop = ft_listpop_back(&list); // 63 : NULL
	if (list != NULL)
		return (1);
	else if (pop != data3)
		return (1);
	if (ft_listpop_back(&list) != NULL)
		return (1);
	free(data);
	free(data2);
	free(data3);
	return (0);
}

int	test_listrev(void)
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
		return (1);
	else if (rev->data != data)
		return (1);
	else if (rev->next == NULL)
		return (1);
	else if (rev->next->data != data2)
		return (1);
	else if (rev->next->next != NULL)
		return (1);
	ft_listclear(&rev, free);
	rev = NULL;
	rev = ft_listrev(NULL);
	if (rev != NULL)
		return (1);
	rev = ft_listrev(&rev);
	if (rev != NULL)
		return (1);
	return (0);
}

int	test_listsize(void)
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
		return (1);
	if (size2 != 1)
		return (1);
	if (size3 != 2)
		return (1);
	ft_listclear(&list, free);
	return (0);
}

int	test_listsize_match(void)
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
		return (1);
	if (size2 != 1)
		return (1);
	if (size3 != 1)
		return (1);
	ft_listclear(&list, free);
	return (0);
}

int	test_listsubrange(void)
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
	ft_listpush(&list, data); // (42)-> NULL
	ft_listpush(&list, data2); // (21)-> (42)-> NULL
	
	sub = ft_listsubrange(list, list->next); // (21)-> NULL
	if (sub == NULL)
		return (1);
	else if (sub->data != data2)
		return (2);
	else if (sub->next != NULL)
		return (3);
	ft_listclear(&sub, NULL);
	
	sub = ft_listsubrange(list, NULL); // (21)-> (42)-> NULL
	if (sub == NULL)
		return (4);
	else if (sub->data != data2)
		return (5);
	else if (sub->next == NULL)
		return (6);
	if (sub->next->data != data)
		return (7);
	else if (sub->next->next != NULL)
		return (7);
	ft_listclear(&sub, NULL);
	
	sub = ft_listsubrange(list, (const t_list *)data2); // (21)-> (42)-> NULL
	if (sub == NULL)
		return (8);
	else if (sub->data != data2)
		return (9);
	else if (sub->next == NULL)
		return (10);
	if (sub->next->data != data)
		return (11);
	else if (sub->next->next != NULL)
		return (12);
	ft_listclear(&sub, NULL);

	sub = ft_listsubrange(NULL, NULL);
	if (sub != NULL)
		return (1);
	ft_listclear(&sub, NULL);

	sub = ft_listsubrange(list, list);
	if (sub == NULL)
		return (1);
	else if (sub->data != data2)
		return (1);
	else if (sub->next != NULL)
		return (1);
	ft_listclear(&sub, NULL);
	
	ft_listclear(&list, free);
	return (0);
}

int	tests_linked_list_all(void)
{
	int	ret;

	ret = test_listadd_front();
	LOG_TESTS(ret, test_listadd_front);

	ret = test_listadd_back();
	LOG_TESTS(ret, test_listadd_back);
	
	ret = test_listapply();
	LOG_TESTS(ret, test_listapply);
	
	ret = test_listapply_range();
	LOG_TESTS(ret, test_listapply_range);
	
	ret = test_listapply_range_node();
	LOG_TESTS(ret, test_listapply_range_node);
	
	ret = test_listclear();
	LOG_TESTS(ret, test_listclear);
	
	ret = test_listcreate();
	LOG_TESTS(ret, test_listcreate);
	
	ret = test_listcopy_node();
	LOG_TESTS(ret, test_listcopy_node);
	
	ret = test_listcopy_list();
	LOG_TESTS(ret, test_listcopy_list);
	
	ret = test_listdelone();
	LOG_TESTS(ret, test_listdelone);
	
	ret = test_listdelete_range();
	LOG_TESTS(ret, test_listdelete_range);
	
	ret = test_listfind();
	LOG_TESTS(ret, test_listfind);
	
	ret = test_listget_datas();
	LOG_TESTS(ret, test_listget_datas);
	
	ret = test_listget_nodes();
	LOG_TESTS(ret, test_listget_nodes);
	
	ret = test_listlast();
	LOG_TESTS(ret, test_listlast);
	
	ret = test_listat();
	LOG_TESTS(ret, test_listat);
	
	ret = test_listmap();
	LOG_TESTS(ret, test_listmap);
	
	ret = test_listnew();
	LOG_TESTS(ret, test_listnew);
	
	ret = test_listpush();
	LOG_TESTS(ret, test_listpush);
	
	ret = test_listpush_back();
	LOG_TESTS(ret, test_listpush_back);
	
	ret = test_listpop();
	LOG_TESTS(ret, test_listpop);
	
	ret = test_listpop_back();
	LOG_TESTS(ret, test_listpop_back);
	
	ret = test_listrev();
	LOG_TESTS(ret, test_listrev);
	
	ret = test_listsize();
	LOG_TESTS(ret, test_listsize);
	
	ret = test_listsize_match();
	LOG_TESTS(ret, test_listsize_match);
	
	ret = test_listsubrange();
	LOG_TESTS(ret, test_listsubrange);
	
	return (ret);
}
