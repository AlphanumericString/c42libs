/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:12:14 by bgoulard          #+#    #+#             */
/*   Updated: 2025/08/26 12:12:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_string.h"
#include <stddef.h>

char	*ft_strcapitalize_grammar(char *str)
{
	const char	*punctuations = ".!?";
	const char	*ignore = " \f\n\r\t\v{[()]}";
	bool		sep;
	size_t		i;

	sep = true;
	i = 0;
	while (str[i])
	{
		if (ft_strchr(punctuations, str[i]))
			sep = true;
		else if (sep && !ft_strchr(ignore, str[i]))
		{
			str[i] = ft_toupper(str[i]);
			sep = false;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	return (ft_strncapitalize(str, -1));
}

char	*ft_strncapitalize(char *str, size_t n)
{
	bool	space;
	size_t	i;

	space = true;
	i = 0;
	while (str[i] && i < n)
	{
		if (ft_isspace(str[i]))
			space = true;
		else
		{
			if (space)
				str[i] = ft_toupper(str[i]);
			else
				str[i] = ft_tolower(str[i]);
			space = false;
		}
		i++;
	}
	return (str);
}

char	*ft_strnwcapitalize(char *str, size_t n)
{
	bool	space;
	size_t	i;
	size_t	w_count;

	space = true;
	i = 0;
	w_count = 0;
	while (str[i] && w_count < n)
	{
		if (ft_isspace(str[i]))
			space = true;
		else if (space && ft_isalpha(str[i]))
		{
			str[i] = ft_toupper(str[i]);
			space = (w_count++, false);
		}
		else if (space)
			space = (w_count++, false);
		i++;
	}
	return (str);
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
