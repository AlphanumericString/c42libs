/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_getters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:34:21 by iron              #+#    #+#             */
/*   Updated: 2025/01/28 11:18:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_mem.h"
#include <stdlib.h>

void	**ft_dl_get_datas(const t_dlist *src)
{
	size_t	size;
	void	**ret;

	if (!src)
		return (NULL);
	size = ft_dl_size(src);
	ret = ft_calloc(sizeof(void *), (size + 1));
	if (!ret)
		return (NULL);
	ret[size] = NULL;
	size = 0;
	while (src)
	{
		ret[size++] = (void *)src->data;
		src = src->next;
	}
	return (ret);
}

t_dlist	**ft_dl_get_nodes(const t_dlist *src)
{
	size_t	size;
	t_dlist	**ret;

	size = ft_dl_size(src);
	ret = NULL;
	if (!src)
		return (NULL);
	ret = ft_calloc(sizeof(t_dlist *), (size + 1));
	if (!ret)
		return (ret);
	ret[size] = NULL;
	size = 0;
	while (src)
	{
		ret[size++] = (t_dlist *)src;
		src = src->next;
	}
	return (ret);
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
