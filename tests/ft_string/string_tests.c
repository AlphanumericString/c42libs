/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:36:16 by bgoulard          #+#    #+#             */
/*   Updated: 2024/01/07 04:03:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"

int		t_string_tests(void);
int		mem_tests(void);
int		str_tests(void);


int tests_string()
{
	int collect;
	int prev;
	t_test tests[] = {
		{"mem", mem_tests},
		{"str", str_tests},
		{"t_string", t_string_tests},
		{NULL, NULL}
	};

	collect = 0;
	prev = collect;
	for (int i = 0; tests[i].name != NULL; i++)
	{
		prev = collect;
		printf("\nTesting %s...\n", tests[i].name);
		collect += tests[i].test();
		if (prev != collect)
			printf("Testing %s... \033[31m%d\033[0m tests failed\n", tests[i].name, collect - prev);
		else
			printf("Testing %s... \033[32mOK\033[0m\n", tests[i].name);
	}
	return (collect);
}
