/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:30:26 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 11:31:15 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_vector_types.h"
#include <stdlib.h>

int	test_vec_remove(void)
{
	t_vector	*vec;
	int			a, b, c;
	int			*pa, *pb, *pc;

	a = 42;
	b = 43;
	c = 44;
	vec = ft_vec_new();
	ft_vec_add(&vec, &a);
	ft_vec_add(&vec, &b);
	ft_vec_add(&vec, &c);
	ft_vec_remove(vec, 1, NULL);
	if (vec->count != 2)
		return (1);
	else if (*(int *)ft_vec_at(vec, 0) != 42)
		return (1);
	else if (*(int *)ft_vec_at(vec, 1) != 44)
		return (1);
	// try to remoove outside of vector
	ft_vec_remove(vec, 42, NULL);
	if (vec->count != 2)
		return (1);
	ft_vec_destroy(&vec);
	// create vector of allocated ints
	// and try to call free on it.
	vec = ft_vec_new();
	pa = malloc(sizeof(int));
	pb = malloc(sizeof(int));
	pc = malloc(sizeof(int));
	*pa = a;
	*pb = b;
	*pc = c;
	ft_vec_add(&vec, pa);
	ft_vec_add(&vec, pb);
	ft_vec_add(&vec, pc);
	if (vec->count != 3)
		return (1);
	ft_vec_remove(vec, 1, free);
	if (vec->count != 2)
		return (1);
	if (ft_vec_at(vec, 0) != pa)
		return (1);
	if (ft_vec_at(vec, 1) != pc)
		return (1);
	ft_vec_apply(vec, free);
	ft_vec_destroy(&vec);
	return (0);
}

