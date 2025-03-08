/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:21:43 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:18:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_dlist	*ft_dl_map(const t_dlist *lst, t_data_tr f, t_data_apply del)
{
	t_dlist	*ret;
	t_dlist	*tmp;

	if (!lst || !f)
		return (NULL);
	ret = NULL;
	while (lst)
	{
		tmp = ft_dl_create(f(lst->data));
		if (!tmp)
			return (ft_dl_clear(&ret, del), NULL);
		ft_dl_add_back(&ret, tmp);
		lst = lst->next;
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
