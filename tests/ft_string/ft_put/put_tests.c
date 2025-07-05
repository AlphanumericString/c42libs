/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:10:22 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/05 13:20:04 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/str__put_tests.h"

int	put_tests(int depth)
{
	int				i;
	const t_test	tests[] = {
	{"putstr", tsp_putstr}, {"putendl", tsp_putendl},
	{"putnbr", tsp_putnbr},
	{"putchar", tsp_putchar}, {"putnchar", tsp_putnchar},
	{"perror", tsp_perror},
	{NULL, NULL}};

	i = 0;
	run_test(tests, &i, depth);
	return (i);
}
