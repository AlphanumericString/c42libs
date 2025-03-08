/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_cat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:15:21 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:48:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_vector_types.h"
#include <stdbool.h>

/*
	ft_vec_add(&vec_a, &a); // 42
	ft_vec_add(&vec_a, &b); // 42 43
	ft_vec_add(&vec_a, &c); // 42 43 44
	ft_vec_add(&vec_b, &d); // 45
	ft_vec_add(&vec_b, &e); // 45 46
	ft_vec_add(&vec_b, &f); // 45 46 47
	ret = ft_vec_cat(&vec_a, vec_b); // 42 43 44 + 45 46 47
	ft_vec_add(&vec_a, &a); // 42
	ft_vec_add(&vec_a, &b); // 42 43
	ft_vec_add(&vec_a, &c); // 42 43 44
	ret = ft_vec_cat(&vec_a, vec_b); // 42 43 44 + 45 46 47
*/

void	init_vec_cat(t_vector **vec_a, t_vector **vec_b)
{
	*vec_a = ft_vec_from_size(6);
	ft_vec_add(vec_a, (void *)42);
	ft_vec_add(vec_a, (void *)43);
	ft_vec_add(vec_a, (void *)44);
	*vec_b = ft_vec_new();
	ft_vec_add(vec_b, (void *)45);
	ft_vec_add(vec_b, (void *)46);
	ft_vec_add(vec_b, (void *)47);
}

int	test_vec_cat(void)
{
	bool		ret;
	t_vector	*vec_a;
	t_vector	*vec_b;

	init_vec_cat(&vec_a, &vec_b);
	ret = ft_vec_cat(&vec_a, vec_b);
	if (ret != true || vec_a->count != 6)
		return (1);
	else if (ft_vec_at(vec_a, 0) != (void *)42 || ft_vec_at(vec_a, 1) != \
	(void *)43 || ft_vec_at(vec_a, 2) != (void *)44 || ft_vec_at(vec_a, 3) != \
	(void *)45 || ft_vec_at(vec_a, 4) != (void *)46 || ft_vec_at(vec_a, 5) != \
	(void *)47)
		return (2);
	ft_vec_destroy(&vec_a);
	vec_a = ft_vec_new();
	ft_vec_add(&vec_a, (void *)42);
	ft_vec_add(&vec_a, (void *)43);
	ft_vec_add(&vec_a, (void *)44);
	ret = ft_vec_cat(&vec_a, vec_b);
	if (ret != false || vec_a->count != 3)
		return (3);
	else if (ft_vec_at(vec_a, 0) != (void *)42 || ft_vec_at(vec_a, 1) != \
		(void *)43 || ft_vec_at(vec_a, 2) != (void *)44)
		return (4);
	return (ft_vec_destroy(&vec_a), ft_vec_destroy(&vec_b), 0);
}
/*
GPL-3.0 License:
c42libs - Library for c projects at 42.
Copyright (C) 2025  baptiste GOULARD

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
