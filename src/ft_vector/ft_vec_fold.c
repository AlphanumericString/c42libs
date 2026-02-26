/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_fold.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:19:56 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/24 19:19:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

// INFO: leave new_val for debugging when things inevitably break please.

void	ft_vec_fold(t_vector *v, void *(*f)(void *, void *))
{
	if (!v || !f)
		return ;
	return (ft_vec_nfold(v, v->n_e, f));
}

void	ft_vec_nfold(t_vector *v, size_t n, void *(*f)(void *, void *))
{
	size_t	i;
	size_t	w_offset;
	void	*new_val;

	if (!v || n < 2 || !f)
		return ;
	if (n >= v->n_e)
		n = v->n_e;
	i = 1;
	w_offset = 0;
	while (i < n)
	{
		new_val = f(ft_vec_at(v, i - 1), ft_vec_at(v, i));
		ft_vec_set(v, w_offset++, new_val);
		i += 2;
	}
	ft_vec_nremove(v, w_offset, n / 2, NULL);
}

void	ft_vec_nfold_r(t_vector *v, size_t n, void *(*f)(void *, void *))
{
	size_t	w_off;
	size_t	i;
	void	*new_val;

	if (!v || !f || n < 2)
		return ;
	i = 0;
	if (n >= v->n_e)
		n = v->n_e - 1;
	w_off = v->n_e - 1;
	while (i < n)
	{
		new_val = f(ft_vec_at(v, (v->n_e - 1) - i - 1), ft_vec_at(v, (v->n_e - 1) - i));
		ft_vec_set(v, w_off--, new_val);
		i += 2;
	}
	ft_vec_nremove(v, v->n_e - n, n / 2, NULL);
}

void	ft_vec_nfold_mltp(t_vector *v, size_t n, void *(*f)(void *, void *),
			size_t mlt)
{
	if (!v || n < 2 || !f || !mlt)
		return ;
	while (mlt && n > 1)
	{
		ft_vec_nfold(v, n, f);
		n = (n / 2) + (n % 2);
		mlt--;
	}
}

void	ft_vec_nfold_r_mltp(t_vector *v, size_t n, void *(*f)(void *, void *),
			size_t mlt)
{
	if (!v || n < 2 || !f || !mlt)
		return ;
	while (mlt && n > 1)
	{
		ft_vec_nfold_r(v, n, f);
		n = (n / 2) + (n % 2);
		mlt--;
	}
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
