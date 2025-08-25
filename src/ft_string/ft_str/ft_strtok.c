/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:19:26 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:35:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strtok(char *str, const char *token)
{
	static char	*ptr;

	if (str)
		ptr = str;
	return (ft_strtok_r(str, token, &ptr));
}

char	*ft_strtok_r(char *str, const char *delim, char **saveptr)
{
	char	*ptr;

	ptr = str;
	if (!ptr && saveptr)
		ptr = *saveptr;
	if (!ptr)
		return (NULL);
	while (*ptr && ft_strchr(delim, *ptr))
		ptr++;
	*saveptr = ptr;
	while (!ft_strchr(delim, **saveptr))
		(*saveptr)++;
	if (**saveptr)
	{
		**saveptr = 0;
		*saveptr = *saveptr + 1;
	}
	else
		*saveptr = NULL;
	return (ptr);
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
