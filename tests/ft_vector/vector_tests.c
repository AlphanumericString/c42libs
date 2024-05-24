/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:30:25 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 11:31:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/vector_tests.h"

int	tests_vector(void)
{
	int				collect;
	const t_test	tests[] = {
	{"test_vec_add", test_vec_add}, {"test_vec_apply", test_vec_apply},
	{"test_vec_at", test_vec_at}, {"test_vec_cat", test_vec_cat},
	{"test_vec_clear", test_vec_clear}, {"test_vec_destroy", test_vec_destroy},
	{"test_vec_filter", test_vec_filter}, {"test_vec_map", test_vec_map},
	{"test_vec_new", test_vec_new}, {"test_vec_from_size", test_vec_from_size},
	{"test_vec_from_array", test_vec_from_array},
	{"test_vec_convert_alloc_array", test_vec_convert_alloc_array},
	{"test_vec_remove", test_vec_remove},
	{"test_vec_remove_if", test_vec_remove_if},
	{"test_vec_reserve", test_vec_reserve}, {"test_vec_reverse",
		test_vec_reverse}, {"test_vec_shift", test_vec_shift},
	{"test_vec_sort", test_vec_sort}, {"test_vec_shrink", test_vec_shrink},
	{"test_vec_swap", test_vec_swap},
	{NULL, NULL}
	};

	collect = 0;
	run_test(tests, &collect);
	return (collect);
}
