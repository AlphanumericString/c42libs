/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:33:46 by iron              #+#    #+#             */
/*   Updated: 2023/12/14 14:49:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		tests_map(void);
int		tests_linked_list_all(void);
int		tests_doubly_linked_list_all(void);
int		tests_vector(void);

int main(void)
{
	int ret;

	ret = 0;

	if (tests_map())
	{
		printf("Map tests failed\n");
		ret++;
	}
	if (tests_linked_list_all())
	{
		printf("Linked list tests failed\n");
		ret++;
	}
	if (tests_doubly_linked_list_all())
	{
		printf("Doubly linked list tests failed\n");
		ret++;
	}
	if (tests_vector())
	{
		printf("Vector tests failed\n");
		ret++;
	}
	return (ret);
}