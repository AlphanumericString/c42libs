/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_ncollec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:33:18 by bgoulard          #+#    #+#             */
/*   Updated: 2026/03/12 15:33:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_string.h"
#include "ft_vector.h"
#include "tests/vector_tests.h"

static void	join_it(void *p_val, void *v_val)
{
	char	**p_val_s;
	char	*tmp;

	p_val_s = p_val;
	if (!*p_val_s)
	{
		*p_val_s = ft_strdup(*(char **)v_val);
		return ;
	}
	tmp = ft_strjoin(*p_val_s, " ");
	ft_free(*p_val_s);
	*p_val_s = tmp;
	tmp = ft_strjoin(*p_val_s, *(char **)v_val);
	ft_free(*p_val_s);
	*p_val_s = tmp;
}

static int	err_cases(void)
{
	const char	*src[] = {"this", "is", "a", "test", "zod"};
	t_vector	v;
	char		*res;

	res = NULL;
	ft_vec_ifrom_array(&v, src, 5, sizeof(const char *));
	ft_vec_ncollect(&v, 0, &res, (t_data_apply_with)join_it);
	if (res != NULL)
		return (ft_vec_wipe(&v), 1);
	ft_vec_ncollect(NULL, 12, &res, (t_data_apply_with)join_it);
	if (res != NULL)
		return (ft_vec_wipe(&v), 2);
	ft_vec_ncollect(&v, -1, &res, NULL);
	if (res != NULL)
		return (ft_vec_wipe(&v), 3);
	return (ft_vec_wipe(&v), 0);
}

int	tv_ncollect(void)
{
	const char	*exp[] = {"this is a test zod", "this is a test"};
	const char	*src[] = {"this", "is", "a", "test", "zod"};
	t_vector	v;
	char		*res;

	res = NULL;
	ft_vec_ifrom_array(&v, src, 5, sizeof(const char *));
	ft_vec_ncollect(&v, -1, &res, (t_data_apply_with) join_it);
	if (ft_strcmp(res, exp[0]) != 0)
		return (ft_vec_wipe(&v), ft_free(res), 1);
	ft_free_clear((t_any) & res);
	ft_vec_ncollect(&v, 4, &res, (t_data_apply_with) join_it);
	if (ft_strcmp(res, exp[1]) != 0)
		return (ft_vec_wipe(&v), ft_free(res), 2);
	return (ft_vec_wipe(&v), ft_free(res), err_cases());
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
