/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:33:46 by iron              #+#    #+#             */
/*   Updated: 2023/12/29 16:31:54 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include <stdio.h>

int main(void)
{
	int ret;
	int sum;

	sum = 0;
	
	ret = tests_map();
	sum += ret;
	LOG_TESTS(ret, tests_map);

	ret = tests_linked_list_all();
	sum += ret;
	LOG_TESTS(ret, tests_linked_list_all);

	ret = tests_doubly_linked_list_all();
	sum += ret;
	LOG_TESTS(ret, tests_doubly_linked_list_all);

	ret = tests_vector();
	sum += ret;
	LOG_TESTS(ret, tests_vector);

	return (sum);
}