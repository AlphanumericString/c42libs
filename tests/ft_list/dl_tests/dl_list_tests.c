/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_list_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:37:03 by iron              #+#    #+#             */
/*   Updated: 2024/05/30 12:10:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/dl_tests.h"

static const t_test	*init_tests(void)
{
	static const t_test	var[] = {
	{"add_front", test_dlistadd_front}, {"add_back", \
		test_dlistadd_back}, {"apply", test_dlistapply}, {\
		"apply_range", test_dlistapply_range}, {\
		"apply_range_node", test_dlistapply_range_node}, {\
		"clear", test_dlistclear}, {"clear_range", \
		test_dlistclear_range}, {"create", test_dlistcreate}, {\
		"copy_node", test_dlistcopy_node}, {"copy_list", \
		test_dlistcopy_list}, {"delete_self", \
		test_dlist_delete_self}, {"delete_range", \
		test_dlistdelete_range}, {"delete", test_dlistdelete}, \
		{"find", test_dlistfind}, {"get_datas", \
		test_dlistget_datas}, {"get_nodes", test_dlistget_nodes}, \
		{"at", test_dlist_at}, {"begin", \
		test_dlist_begin}, {"end", test_dlist_end}, {\
		"map", test_dlist_map}, {"new", test_dlist_new}, \
		{"pop", test_dlist_pop}, {"pop_back", \
		test_dlist_pop_back}, {"push", test_dlist_push}, \
		{"push_back", test_dlist_push_back}, {"rev", \
		test_dlist_rev}, {"size", test_dlist_size}, {\
		"size_of_data", test_dlist_size_of_data}, {\
		"subrange", test_dlist_subrange}, {NULL, NULL}};

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
