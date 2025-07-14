/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tma_narena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 13:42:22 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 13:52:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena.h"
#include "ft_string.h"
#include "tests/str__mem_tests.h"

// cant really check that free was ok -
// check on valgrind i guess
//
// to annoying to modify test fixture just to prove that yes it frees
int	tma_narena_free(void)
{
	void	*ptr;

	ft_narena_free(-1);
	ft_narena_free(FT_NARENA_MAX + 1);
	ft_narena_free(FT_NARENA_MAX / 2);
	ft_narena_free(FT_NARENA_MAX / 2);
	ft_narena_free(FT_NARENA_MAX / 2);
	ptr = ft_narena_alloc(FT_NARENA_MAX / 2, 42);
	ft_strlcpy(ptr, "test", 42);
	ft_narena_free(FT_NARENA_MAX / 2);
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
