/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_list_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:37:03 by iron              #+#    #+#             */
/*   Updated: 2024/05/19 17:14:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/dl_tests.h"

static const t_test	*init_tests(void)
{
	static const t_test	var[] = {
	{"test_dlistadd_front", test_dlistadd_front}, {"test_dlistadd_back", \
		test_dlistadd_back}, {"test_dlistapply", test_dlistapply}, {\
		"test_dlistapply_range", test_dlistapply_range}, {\
		"test_dlistapply_range_node", test_dlistapply_range_node}, {\
		"test_dlistclear", test_dlistclear}, {"test_dlistclear_range", \
		test_dlistclear_range}, {"test_dlistcreate", test_dlistcreate}, {\
		"test_dlistcopy_node", test_dlistcopy_node}, {"test_dlistcopy_list", \
		test_dlistcopy_list}, {"test_dlist_delete_self", \
		test_dlist_delete_self}, {"test_dlistdelete_range", \
		test_dlistdelete_range}, {"test_dlistdelete", test_dlistdelete}, \
		{"test_dlistfind", test_dlistfind}, {"test_dlistget_datas", \
		test_dlistget_datas}, {"test_dlistget_nodes", test_dlistget_nodes}, \
		{"test_dlist_at", test_dlist_at}, {"test_dlist_begin", \
		test_dlist_begin}, {"test_dlist_end", test_dlist_end}, {\
		"test_dlist_map", test_dlist_map}, {"test_dlist_new", test_dlist_new}, \
		{"test_dlist_pop", test_dlist_pop}, {"test_dlist_pop_back", \
		test_dlist_pop_back}, {"test_dlist_push", test_dlist_push}, \
		{"test_dlist_push_back", test_dlist_push_back}, {"test_dlist_rev", \
		test_dlist_rev}, {"test_dlist_size", test_dlist_size}, {\
		"test_dlist_size_of_data", test_dlist_size_of_data}, {\
		"test_dlist_subrange", test_dlist_subrange}, {NULL, NULL}};

	return (var);
}

int	tests_doubly_linked_list_all(void)
{
	int				collect;
	const t_test	*test = init_tests();

	collect = 0;
	run_test(test, &collect);
	return (collect);
}
