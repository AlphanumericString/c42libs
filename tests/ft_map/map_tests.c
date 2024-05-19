/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:27:46 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 18:24:24 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/map_tests.h"

// see with --leak-check=full
int	tests_map(void)
{
	int				collect;
	const t_test	test[] = {
	{"test_map_create", test_map_create},
	{"test_map_destroy", test_map_destroy}, // here
	{"test_map_destroy_free", test_map_destroy_free},
	{"test_map_clear", test_map_clear}, // here
	{"test_map_set", test_map_set},
	{"test_map_set_cmp", test_map_set_cmp},
	{"test_map_set_hash", test_map_set_hash},
	{"test_map_get", test_map_get},
	{"test_map_size", test_map_size},
	{"test_map_capacity", test_map_capacity},
	{"test_map_remove", test_map_remove}, // here
	{"test_map_hash", test_map_hash},
	{NULL, NULL}
	};

	collect = 0;
	run_test(test, &collect);
	return (collect);
}
