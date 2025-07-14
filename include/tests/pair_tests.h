/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 00:30:00 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/13 17:18:11 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_TESTS_H
# define PAIR_TESTS_H

# include "types/ft_pair_types.h"

void	triple_pair_setup(t_pair *first, t_pair *diff, t_pair *same_diffloc);

int		tp_destroy(void);
int		tp_destroy_sep(void);
int		tp_set(void);
int		tp_new(void);
int		tp_second(void);
int		tp_first(void);
int		tp_destroy(void);
int		tp_cmp(void);
int		tp_cmp_first(void);
int		tp_cmp_second(void);

#endif /* PAIR_TESTS_H */
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
