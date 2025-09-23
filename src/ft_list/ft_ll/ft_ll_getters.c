/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_getters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:54:40 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/10 23:48:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_mem.h"

void	**ft_ll_get_datas(const t_list *src)
{
	void	**datas;
	size_t	i;

	if (!src)
		return (NULL);
	datas = ft_calloc(sizeof(void *), ft_ll_size(src) + 1);
	if (!datas)
		return (NULL);
	i = 0;
	while (src)
	{
		datas[i] = src->data;
		src = src->next;
		i++;
	}
	return (datas);
}

t_list	**ft_ll_get_nodes(const t_list *src)
{
	t_list	**nodes;
	size_t	i;

	if (!src)
		return (NULL);
	nodes = ft_calloc(sizeof(t_list *), ft_ll_size(src) + 1);
	if (!nodes)
		return (NULL);
	i = 0;
	while (src)
	{
		nodes[i] = (t_list *)src;
		src = src->next;
		i++;
	}
	return (nodes);
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
