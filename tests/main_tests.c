/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:33:46 by iron              #+#    #+#             */
/*   Updated: 2023/12/30 16:55:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include <stdio.h>

int main(void)
{
	int collect;
	t_test tests[] = {
		{"string", tests_string},
		{"vec", tests_vector},
		{"map", tests_map},
		{"simply linked lists", tests_linked_list_all},
		{"doubly linked lists", tests_doubly_linked_list_all},
		{NULL, NULL}
	};

	collect = 0;
	RUN_TEST(tests, collect);
	return (collect);
}