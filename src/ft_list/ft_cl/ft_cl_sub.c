/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cl_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:34:45 by iron              #+#    #+#             */
/*   Updated: 2025/06/18 19:20:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_clist	*ft_cl_subrange(const t_clist *src, const t_clist *restrict end)
{
	const t_clist	*it;
	t_clist			*new_list;

	if (!src)
		return (NULL);
	if (!end)
		return (ft_cl_copy_list(src));
	if (src == end)
		return (ft_cl_create(src->data));
	new_list = NULL;
	it = src;
	while (it != end)
	{
		if (ft_cl_push_back(&new_list, it->data) == NULL)
			return (ft_cl_clear(&new_list, NULL), NULL);
		it = it->next;
	}
	return (new_list);
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
