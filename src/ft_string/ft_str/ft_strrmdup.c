/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrmdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:11:37 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/08 20:23:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strnrmdup(char *str, const char *set, size_t n)
{
	const char	*str_e;
	size_t		i;
	size_t		j;
	bool		prev_in_set;

	if (!set | !str | !n || !*set)
		return (str);
	i = 0;
	j = 0;
	prev_in_set = false;
	while (i < n && str[j])
	{
		str_e = ft_strchr(set, str[j]);
		if (str_e && prev_in_set)
			j++;
		else
			str[i++] = str[j++];
		prev_in_set = str_e != NULL;
	}
	while (str[j])
		str[i++] = str[j++];
	str[i] = 0;
	return (str);
}

char	*ft_strrmdup(char *str, const char *set)
{
	return (ft_strnrmdup(str, set, -1));
}

char	*ft_strrmdup_spaceall(char *str)
{
	return (ft_strnrmdup(str, " \f\n\r\t\v", -1));
}

char	*ft_strrmdup_space(char *str)
{
	return (ft_strnrmdup(str, " ", -1));
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
