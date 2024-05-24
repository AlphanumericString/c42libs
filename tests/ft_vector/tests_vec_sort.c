/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:27:57 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 11:52:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_vector_types.h"
#include "tests/tests_lambda_functions.h"

int	test_vec_sort(void)
{
	t_vector	*vec;
	void		*data[3];
	int			a, b, c;

	a = 42;
	b = 43;
	c = 44;
	data[0] = (void *)&a;
	data[1] = (void *)&b;
	data[2] = (void *)&c;
	vec = ft_vec_from_array(data, sizeof(data) / sizeof(data[0]));
	// 44, 43, 42
	ft_vec_sort(vec, cmp_int);
	// 42, 43, 44
	if (vec->count != 3)
		return (1);
	else if (*(int *)ft_vec_at(vec, 0) != 42)
		return (1);
	else if (*(int *)ft_vec_at(vec, 1) != 43)
		return (1);
	else if (*(int *)ft_vec_at(vec, 2) != 44)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}
