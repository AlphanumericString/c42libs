/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:13:51 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/10 13:13:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"
#include <stddef.h>
#include <stdlib.h>

t_vector	*ft_vec_new(void)
{
	return (ft_vec_from_size(FT_VECTOR_BASE_LEN));
}

t_vector	*ft_vec_from_size(size_t n)
{
	t_vector	*ret;

	ret = ft_calloc(sizeof(t_vector), 1);
	if (!ret)
		return (ret);
	ret->data = ft_calloc(1, n);
	if (!ret->data)
		return (ft_free(ret), NULL);
	ret->cappacity = n;
	ret->n_e = 0;
	ret->s_e = 1;
	return (ret);
}

t_vector	*ft_vec_create(size_t elem_size)
{
	t_vector	*ret;

	if (!elem_size)
		return (NULL);
	ret = ft_malloc(sizeof(t_vector));
	if (!ret)
		return (NULL);
	if (!ft_vec_init(ret, FT_VECTOR_BASE_LEN, elem_size))
		return (ft_free(ret), NULL);
	return (ret);
}

t_vector	*ft_vec_from_array(const void *data_src, size_t nmemb,
				size_t elem_size)
{
	t_vector	*ret;

	if (!nmemb || !elem_size || !data_src)
		return (NULL);
	ret = ft_malloc(sizeof(t_vector));
	if (!ret)
		return (NULL);
	if (ft_vec_ifrom_array(ret, data_src, nmemb, elem_size) == NULL)
		return (ft_free(ret), NULL);
	return (ret);
}

// calloc ->dont remplace by malloc
//		if meta_data block is set to null
t_vector	*ft_vec_convert_alloccarray(void *data, size_t nmemb, size_t e_size)
{
	t_vector	*ret;

	if (!nmemb || !e_size || !data)
		return (NULL);
	ret = ft_calloc(sizeof(t_vector), 1);
	if (!ret)
		return (ret);
	return (ft_vec_iconvert_allocarray(ret, data, nmemb, e_size));
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
