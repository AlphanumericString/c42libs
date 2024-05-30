/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_list_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:17:51 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 12:11:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/ll_tests.h"

int	tests_linked_list_all(void)
{
	int				collect;
	const t_test	test[] = {
	{"add_front", test_listadd_front}, {"add_back",
		test_listadd_back},	{"apply", test_listapply},	{
		"apply_range", test_listapply_range}, {
		"apply_range_node", test_listapply_range_node}, {
		"clear", test_listclear}, {"create",
		test_listcreate}, {"copy_node", test_listcopy_node},
	{"copy_list", test_listcopy_list},	{"delone",
		test_listdelone}, {"delete_range", test_listdelete_range},
	{"find", test_listfind}, {"get_datas",
		test_listget_datas}, {"get_nodes", test_listget_nodes}, {
		"end", test_listend}, {"at", test_listat}, {
		"map", test_listmap}, {"new", test_listnew}, {
		"push", test_listpush}, {"push_back",
		test_listpush_back}, {"pop", test_listpop}, {
		"pop_back", test_listpop_back}, {"rev", test_listrev},
	{"size", test_listsize}, {"size_match",
		test_listsize_match}, {"subrange", test_listsubrange},
	{NULL, NULL}
	};

	collect = 0;
	run_test(test, &collect);
	return (collect);
}
