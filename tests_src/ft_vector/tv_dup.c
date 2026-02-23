/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 05:44:17 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/23 05:44:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "tests/fixtures.h"
#include "types/ft_vector_types.h"
#include "tests/vector_tests.h"

static int	mt_cases(void)
{
	const int	f_po = *talloc_get_failpoint();
	t_vector	*vec;
	const int	a[] = {0, 1, 2};
	int			ret;
	t_vector	*dup;

	vec = ft_vec_from_array(a, sizeof(int), 3);
	ret = EXIT_SUCCESS;
	talloc_set_failpoint(0);
	dup = ft_vec_dup(vec);
	if (dup)
		ret = 8;
	talloc_set_failpoint(f_po);
	ft_vec_destroy(&vec);
	return (ret);
}

static int	bad_vector(void)
{
	t_vector	hold;
	t_vector	*vec;
	const int	a[] = {0, 1, 2};
	t_vector	*cpy;

	vec = ft_vec_from_array(a, sizeof(int), 3);
	cpy = ft_vec_dup(NULL);
	if (cpy)
		return (ft_vec_destroy(&vec), 4);
	hold = *vec;
	vec->s_e = 0;
	cpy = ft_vec_dup(vec);
	if (cpy)
		return (ft_vec_destroy(&vec), 5);
	*vec = hold;
	return (ft_vec_destroy(&vec), EXIT_SUCCESS);
}

int	tv_dup(void)
{
	t_vector	*vec;
	const int	a[] = {0, 1, 2};
	t_vector	*cpy;
	int			err_scenarios;

	vec = ft_vec_from_array(a, sizeof(int), 3);
	cpy = ft_vec_dup(vec);
	if (vec->data == cpy->data)
		return (ft_vec_destroy(&vec), 1);
	if (vec->n_e != cpy->n_e || vec->s_e != cpy->s_e)
		return (ft_vec_destroy(&vec), ft_vec_destroy(&cpy), 2);
	err_scenarios = bad_vector();
	if (!err_scenarios)
		err_scenarios = mt_cases();
	return (ft_vec_destroy(&vec), ft_vec_destroy(&cpy), err_scenarios);
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
