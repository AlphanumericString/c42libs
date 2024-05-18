/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:33:46 by iron              #+#    #+#             */
/*   Updated: 2024/05/18 17:01:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include <stdio.h>

const t_test	*get_tests(void)
{
	static const t_test	tests[] = {
	{"string", tests_string},
	{"vec", tests_vector},
	{"map",	tests_map},
	{"simply linked lists", tests_linked_list_all},
	{"doubly linked lists", tests_doubly_linked_list_all},
	{"optional", tests_optional},
	{"args", tests_args},
	{NULL, NULL}
	};

	return (tests);
}

int	main(void)
{
	int				collect;
	int				prev;
	size_t			i;
	const t_test	*tests = get_tests();

	i = 0;
	collect = 0;
	while (tests[i].name != NULL)
	{
		prev = collect;
		printf("\n\nTesting %s...\n", tests[i].name);
		collect += tests[i].test();
		if (collect == prev)
			printf("\nModule :: %s \033[32mOK\033[0m\n", tests[i].name);
		else
			printf("\nModule :: %s \033[31mKO\033[0m\n", tests[i].name);
		i++;
	}
	return (collect);
}
