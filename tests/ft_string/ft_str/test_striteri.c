/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_striteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:39:56 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:36:35 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include "tests/tests__all_modules_tests.h"
static void	local_iteri(unsigned int i, char *c)
{
	*c = 'a';
	(void)i;
}

// last 2 calls are to test NULL protection
int	test_striteri(void)
{
	char	str[20];

	ft_strlcpy(str, "Hello World!", 20);
	ft_striteri(str, &local_iteri);
	if (ft_strcmp(str, "aaaaaaaaaaaa") != 0)
		return (1);
	ft_striteri(NULL, &local_iteri);
	ft_striteri(str, NULL);
	return (0);
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
