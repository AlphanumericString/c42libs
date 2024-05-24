/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_convert_alloc_array.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:30:26 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 11:31:27 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_vector_types.h"
#include <stdlib.h>

int	test_vec_convert_alloc_array(void)
{
	void		**data;
	t_vector	*vec;
	int			a, b, c;

	a = 42;
	b = 43;
	c = 44;
	data = malloc(sizeof(void *) * 3);
	data[0] = (void *)&a;
	data[1] = (void *)&b;
	data[2] = (void *)&c;
	vec = ft_vec_convert_alloccarray(data, 3);
	if (vec->count != 3)
		return (1);
	else if (vec->cappacity != 3)
		return (1);
	else if (vec->datas != data)
		return (1);
	else if (*(int *)ft_vec_at(vec, 0) != 42)
		return (1);
	else if (*(int *)ft_vec_at(vec, 1) != 43)
		return (1);
	else if (*(int *)ft_vec_at(vec, 2) != 44)
		return (1);
	ft_vec_destroy(&vec);
	//  free(data); -> segfault : double free or corruption.
	// 	ft_vec_convert_alloccarray takes ownership of the data. refert to the doc.
	return (0);
}
