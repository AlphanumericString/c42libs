/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:39:25 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/25 17:44:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/str__t_str_test.h"
#include "tests/tests.h"

int	t_string_tests(void)
{
	int				sum;
	const t_test	tests[] = {\
	{"test_string_new", test_string_new}, {"test_string_from", \
	test_string_from}, {"test_string_from_n", test_string_from_n}, \
	{"test_string_from_c", test_string_from_c}, {"test_string_append", \
	test_string_append}, {"test_string_append_n", test_string_append_n}, \
	{"test_string_append_c", test_string_append_c}, {"test_string_append_s", \
		test_string_append_s}, {"test_string_append_s_n", \
		test_string_append_s_n}, {"test_string_clear", test_string_clear}, \
	{"test_string_destroy", test_string_destroy}, {"test_string_insert", \
		test_string_insert}, {"test_string_insert_n", test_string_insert_n}, \
	{"test_string_insert_c", test_string_insert_c}, {"test_string_insert_s", \
		test_string_insert_s}, {"test_string_insert_s_n", \
		test_string_insert_s_n}, {"test_string_reserve", test_string_reserve}, \
	{"test_string_resize", test_string_resize}, {"test_string_shrink", \
		test_string_shrink}, {"test_string_substr", test_string_substr}, \
	{"test_string_to_str", test_string_to_str}, {"test_string_trim", \
		test_string_trim}, {"test_string_trim_chr", test_string_trim_chr}, \
	{"test_string_trimstr", test_string_trimstr}, {"test_string_cmp", \
		test_string_cmp}, {"test_string_cmp_n", test_string_cmp_n}, \
	{NULL, NULL}
	};

	sum = 0;
	return (run_test(tests, &sum), sum);
}
