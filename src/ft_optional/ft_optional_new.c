/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optional_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:06:55 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/28 22:35:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"
#include "ft_string.h"
#include <stdlib.h>

t_optional	*ft_optional_new(void)
{
	t_optional	*elem;

	elem = ft_malloc(sizeof(*elem));
	if (!elem)
		return (NULL);
	elem->pres = OPT_NONE;
	elem->val = NULL;
	return (elem);
}

t_optional	*ft_optional_from_val(const void *restrict ptr)
{
	t_optional	*elem;

	elem = ft_optional_new();
	if (!elem)
		return (elem);
	elem->pres = OPT_SOME;
	elem->val = (void *)ptr;
	return (elem);
}

// As this function can fail it should never be called,
// the type t_optional is supposed to be ultra reliable.
// Carefull use is preconized.
t_optional	*ft_optional_dup(const t_optional *restrict org)
{
	t_optional	*ret;

	ret = ft_optional_new();
	if (!ret)
		return (NULL);
	ft_optional_copy(ret, org);
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
