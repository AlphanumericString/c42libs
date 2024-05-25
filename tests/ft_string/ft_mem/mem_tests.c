/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:39:27 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/25 12:27:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/str__mem_tests.h"

int	mem_tests(void)
{
	int				collect;
	const t_test	tests[] = {
	{"test_bzero", test_bzero},
	{"test_calloc", test_calloc},
	{"test_realloc", test_realloc},
	{"test_free", test_free},
	{"test_memchr", test_memchr},
	{"test_memcmp", test_memcmp},
	{"test_memcpy", test_memcpy},
	{"test_memmove", test_memmove},
	{"test_memset", test_memset},
	{"test_swap", test_swap},
	{"test_qsort", test_qsort},
	{NULL, NULL}
	};

	collect = 0;
	run_test(tests, &collect);
	return (collect);
}
