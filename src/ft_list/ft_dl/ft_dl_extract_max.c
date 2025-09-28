/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_extract_max.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 06:04:50 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/26 06:04:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_dlist	*ft_dl_extract_max(const t_dlist *list, t_data_cmp cmp)
{
	const t_dlist	*node = ft_dl_extract_max_node(list, cmp);

	if (node)
		return (node->data);
	return (NULL);
}

t_dlist	*ft_dl_extract_max_node(const t_dlist *list, t_data_cmp cmp)
{
	t_dlist	*return_node;

	if (!list || !cmp)
		return (NULL);
	return_node = (t_dlist *)list;
	list = list->next;
	while (list)
	{
		if (cmp(return_node->data, list->data) < 0)
			return_node = (t_dlist *)list;
		list = list->next;
	}
	return (return_node);
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
