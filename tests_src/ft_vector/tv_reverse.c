/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:30:26 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:09:19 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "types/ft_vector_types.h"
#include "tests/vector_tests.h"

int	tv_nrev(void)
{
	t_vector	vec;
	const int	a[3] = {42, 43, 44};
	const int	exp[3] = {43, 42, 44};

	ft_vec_ifrom_array(&vec, a, 3, sizeof(int));
	ft_vec_nreverse(&vec, 2);
	if (vec.n_e != 3 || ft_vec_acmp(&vec, exp, NULL))
		return (ft_vec_wipe(&vec), 1);
	ft_vec_wipe(&vec);
	return (EXIT_SUCCESS);
}

int	tv_reverse(void)
{
	t_vector	*vec;
	const int	a[3] = {42, 43, 44};
	const int	exp[3] = {44, 43, 42};

	vec = ft_vec_from_array(a, 3, sizeof(int));
	ft_vec_reverse(vec);
	if (vec->n_e != 3)
		return (ft_vec_destroy(&vec), 1);
	if (ft_vec_acmp(vec, exp, NULL) != 0)
		return (ft_vec_destroy(&vec), 2);
	ft_vec_destroy(&vec);
	ft_vec_reverse(NULL);
	return (EXIT_SUCCESS);
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
