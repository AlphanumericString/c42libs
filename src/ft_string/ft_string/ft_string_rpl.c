/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_rpl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:53:23 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:37:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_tstring.h"

bool	ft_string_rpl(t_string *str, const char *to_replace,
		const char *replace_by)
{
	char	*tmp;
	char	*tmp2;

	if (!str)
		return (false);
	tmp = (char *)ft_string_get(str);
	if (!tmp)
		return (false);
	tmp2 = ft_strrpl(tmp, to_replace, replace_by);
	if (!tmp2)
		return (false);
	ft_string_set_inplace(str, tmp2);
	return (true);
}

bool	ft_string_rpl_chr(t_string *str, char to_replace, char replace_by)
{
	size_t	i;
	size_t	nb_rep;

	if (!str || !str->str)
		return (false);
	i = 0;
	nb_rep = 0;
	while (i < str->length)
	{
		if (str->str[i] == to_replace)
		{
			str->str[i] = replace_by;
			nb_rep++;
		}
		i++;
	}
	if (nb_rep == 0)
		return (false);
	return (true);
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
