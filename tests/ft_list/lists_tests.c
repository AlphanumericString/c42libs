/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:57:26 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/03 12:57:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"

static const t_module	*get_tests(void)
{
	static const t_module	md[] = {
	{"simply linked lists", "sll", tests_linked_list_all},
	{"doubly linked lists", "dll", tests_doubly_linked_list_all},
	{"circular linked lists", "cll", tests_circular_linked_list_all},
	{NULL, NULL, NULL},
	};

	return (md);
}

int	tests_lists(int depth)
{
	size_t			i;
	int				collect;
	const t_module	*modules = get_tests();

	i = 0;
	collect = 0;
	while (modules[i].test)
		collect += run_module(modules[i++], depth);
	return (collect);
}
