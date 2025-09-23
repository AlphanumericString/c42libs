/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:08:28 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/05 14:05:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdio.h>

void	ft_strnrev(char *s, size_t n)
{
	size_t	i;
	char	tmp;

	if (!n | !s || !*s)
		return ;
	i = 0;
	n = ft_strnlen(s, n) - 1;
	while (i < n)
	{
		tmp = s[i];
		s[i] = s[n];
		s[n] = tmp;
		i++;
		n--;
	}
}

void	ft_strrev(char *s)
{
	return (ft_strnrev(s, -1));
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
