/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrgsort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 14:19:39 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/27 14:19:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRGSORT_H
# define MRGSORT_H

# include "ft_defs.h"

# define TMP 2
# define LEFT 0
# define RIGHT 1

typedef struct s_merge_ainfo
{
	t_data_cmp	cmp;
	size_t		n_e;
	size_t		s_e;
	void		*buf;
}	t_mainfo;

typedef struct s_merge_internal
{
	t_mainfo	anf;
	size_t		lft;
	size_t		mid;
	size_t		rgt;
}	t_minfo;

#endif // !MRGSORT_H
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
