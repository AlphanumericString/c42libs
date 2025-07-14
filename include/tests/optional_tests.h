/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optional_tests.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:39:46 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/13 17:15:51 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONAL_TESTS_H
# define OPTIONAL_TESTS_H

void	*add_4(void *val);
void	*add_fail(void *val);

int		to_new(void);
int		to_dup(void);
int		to_copy(void);
int		to_unwrap(void);
int		to_from_val(void);
int		to_chain(void);
int		to_map(void);
int		to_destroy(void);

#endif /* OPTIONAL_TESTS_H */
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
