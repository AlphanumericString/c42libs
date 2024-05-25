/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:36:16 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/25 10:50:19 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"

int		t_string_tests(void);
int		mem_tests(void);
int		str_tests(void);
int		char_tests(void);

int	tests_string(void)
{
	size_t			i;
	int				collect;
	int				prev;
	const t_test	tests[] = {
	{"mem", mem_tests},
	{"str", str_tests},
	{"char", char_tests},
	{"t_string", t_string_tests},
	{NULL, NULL}
	};

	i = 0;
	collect = 0;
	while (tests[i].name != NULL)
	{
		prev = collect;
		printf("\nTesting %s...\n", tests[i].name);
		collect += tests[i++].test();
		if (prev != collect)
			printf("\nTesting %s... \033[31m%d\033[0m tests failed\n", \
			tests[i - 1].name, collect - prev);
		else
			printf("\nTesting %s... \033[32mOK\033[0m\n", tests[i - 1].name);
	}
	return (collect);
}
