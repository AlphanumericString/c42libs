/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_fold.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 08:48:06 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/25 08:48:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "tests/vector_tests.h"

static void	*add_ints(void *a, void *b)
{
	static int	res = 0;

	res = *(int *)a + *(int *)b;
	return (&res);
}

static int	check_fold(const int *asrc, const int *aexp, size_t nb_as)
{
	size_t		i;
	t_vector	v;
	int			g;

	ft_vec_ifrom_array(&v, asrc, nb_as, sizeof(int));
	ft_vec_fold(&v, add_ints);
	i = 0;
	while (i < (nb_as / 2) + nb_as % 2)
	{
		if (ft_vec_get(&v, i, &g) != &g)
			return (i * 2 + 1);
		if (g != aexp[i])
			return (i * 2 + 2);
		i++;
	}
	ft_vec_wipe(&v);
	return (0);
}

int	tv_fold(void)
{
	const int	asrcevn[] = {1, 2, 3, 4, 5, 6, 7, 8};
	const int	aexpevn[] = {3, 7, 11, 15};
	const int	asrcodd[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	const int	aexpodd[] = {1, 5, 9, 13, 8};
	int			ret;

	ret = check_fold(asrcevn, aexpevn, sizeof(asrcevn) / sizeof(asrcevn[0]));
	if (ret)
		return (ret);
	ret = check_fold(asrcodd, aexpodd, sizeof(asrcodd) / sizeof(asrcodd[0]));
	if (ret)
		return (ret + 32);
	ft_vec_fold((void *)0xDEAD, NULL);
	ft_vec_fold(NULL, (void *)0xDEAD);
	return (0);
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
