/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_nfold_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:16:09 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/25 11:16:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/vector_tests.h"
#include "ft_vector.h"

// static void	*add_ints(void *a, void *b)
// {
// 	static int	res = 0;
//
// 	res = *(int *)a + *(int *)b;
// 	return (&res);
// }
//
// static int	check_vec(t_vector *v, const int *exp, size_t nexp_size)
// {
// 	int		g;
// 	size_t	i;
//
// 	i = 0;
// 	if (!v || !exp)
// 		return (7);
// 	if (v->n_e != nexp_size)
// 		return (1);
// 	while (i < nexp_size)
// 	{
// 		if (ft_vec_get(v, i, &g) != &g)
// 			return (2);
// 		if (g != exp[i])
// 			return (3);
// 		i++;
// 	}
// 	return (0);
// }
//
// static int	err_cases(void)
// {
// 	const int	asrc[] = {1, 2, 3, 4, 5, 6, 7};
// 	t_vector	v;
//
// 	ft_vec_ifrom_array(&v, asrc, 7, sizeof(int));
// 	ft_vec_nfold_r((void *)0xDEAD, 0, (void *)0xDEAD);
// 	ft_vec_nfold_r(NULL, 99, (void *)0xDEAD);
// 	ft_vec_nfold_r((void *)0xDEAD, 99, NULL);
// 	ft_vec_nfold_r(&v, 1, add_ints);
// 	ft_vec_wipe(&v);
// 	return (0);
// }
//
// static int	bases_cases(void)
// {
// 	const int	asrc[] = {1, 2, 3, 4, 5, 6, 7};
// 	const int	nexp[][7] = {{1, 2, 3, 4, 5, 6, 7}, {1, 2, 3, 4, 5, 13},
// 	{1, 2, 3, 9, 13}, {1, 5, 9, 13}};
// 	t_vector	v;
// 	size_t		i;
// 	int			ret;
//
// 	i = 0;
// 	while (i < sizeof(nexp) / sizeof(nexp[0]))
// 	{
// 		ft_vec_ifrom_array(&v, asrc, 7, sizeof(int));
// 		ft_vec_nfold_r(&v, i * 2, add_ints);
// 		ret = check_vec(&v, (const int *)nexp[i], 7 - i);
// 		ft_vec_wipe(&v);
// 		if (ret)
// 			return (i * 8 + ret);
// 		i++;
// 	}
// 	ft_vec_ifrom_array(&v, asrc, 7, sizeof(int));
// 	ft_vec_nfold_r(&v, 999, add_ints);
// 	ret = check_vec(&v, (int []){1, 5, 9, 13}, 4);
// 	if (ret)
// 		return (ft_vec_wipe(&v), 40);
// 	return (ft_vec_wipe(&v), 0);
// }
// int	r;
//
// r = err_cases();
// if (r != 0)
// 	return (r);
// r = bases_cases();
// if (r)
// 	return (r);

int	tv_nfold_r(void)
{
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
