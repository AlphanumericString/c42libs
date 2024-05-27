/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_list_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:17:51 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 17:11:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/ll_tests.h"

int	tests_linked_list_all(void)
{
	int				collect;
	const t_test	test[] = {
	{"test_listadd_front", test_listadd_front}, {"test_listadd_back",
		test_listadd_back},	{"test_listapply", test_listapply},	{
		"test_listapply_range", test_listapply_range}, {
		"test_listapply_range_node", test_listapply_range_node}, {
		"test_listclear", test_listclear}, {"test_listcreate",
		test_listcreate}, {"test_listcopy_node", test_listcopy_node},
	{"test_listcopy_list", test_listcopy_list},	{"test_listdelone",
		test_listdelone}, {"test_listdelete_range", test_listdelete_range},
	{"test_listfind", test_listfind}, {"test_listget_datas",
		test_listget_datas}, {"test_listget_nodes", test_listget_nodes}, {
		"test_listend", test_listend}, {"test_listat", test_listat}, {
		"test_listmap", test_listmap}, {"test_listnew", test_listnew}, {
		"test_listpush", test_listpush}, {"test_listpush_back",
		test_listpush_back}, {"test_listpop", test_listpop}, {
		"test_listpop_back", test_listpop_back}, {"test_listrev", test_listrev},
	{"test_listsize", test_listsize}, {"test_listsize_match",
		test_listsize_match}, {"test_listsubrange", test_listsubrange},
	{NULL, NULL}
	};

	collect = 0;
	run_test(test, &collect);
	return (collect);
}
