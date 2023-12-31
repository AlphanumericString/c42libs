/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:36:16 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/30 16:01:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"

int		t_string_tests(void);
int		mem_tests(void);
int		str_tests(void);


int tests_string()
{
	int collect;
	t_test tests[] = {
		{"mem", mem_tests},
		{"str", str_tests},
		{"t_string", t_string_tests},
		{NULL, NULL}
	};

	collect = 0;
	RUN_TEST(tests, collect);
	return (collect);
}