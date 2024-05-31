/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:39:25 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 21:41:16 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/str__t_str_test.h"
#include "tests/tests.h"

static const t_test	*loadtests01(void)
{
	static const t_test	tests[] = {
	{"append_c", test_string_append_c}, {"append_n", test_string_append_n},
	{"append_s_n", test_string_append_s_n}, {"append_s", test_string_append_s},
	{"append", test_string_append},
	{"cap", test_string_cap},
	{"chr", test_string_chr}, {"clear", test_string_clear},
	{"ncmp_str", test_string_ncmp_str},
	{"ncmp", test_string_ncmp},
	{"cmp_str", test_string_cmp_str}, 
	{"cmp", test_string_cmp},
	{"destroy", test_string_destroy}, {"from_c", test_string_from_c},
	{"from_n", test_string_from_n},
	{"from_sn", test_string_from_sn},
	{"from_s", test_string_from_s}, 
	{"from", test_string_from},
	{"get", test_string_get},
	{"insert_c", test_string_insert_c},
	{"insert_n", test_string_insert_n},
	{"insert_s_n", test_string_insert_s_n},
	{"insert_s", test_string_insert_s},
	{"insert", test_string_insert},
	{"length", test_string_len},
	{"new", test_string_new},
	{"replace_c", test_string_replace_chr},
	{"replace", test_string_replace},
	{"reserve", test_string_reserve}, {"resize", test_string_resize},
	{"shrink", test_string_shrink}, {"substr", test_string_substr},
	{"to_str", test_string_to_str}, {"trim_chr", test_string_trim_chr}, 
	{"trimstr", test_string_trimstr}, {"trim", test_string_trim},
	{NULL, NULL}
	};

	return (tests);
}

int	t_string_tests(void)
{
	int				sum;
	const t_test	*tests = loadtests01();

	sum = 0;
	return (run_test(tests, &sum), sum);
}
