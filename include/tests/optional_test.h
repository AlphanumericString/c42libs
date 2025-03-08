/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optional_test.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:39:46 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/11 14:51:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONAL_TEST_H
# define OPTIONAL_TEST_H

void	*add_4(void *val);
void	*add_fail(void *val);

int		test_optional_new(void);
int		test_optional_dup(void);
int		test_optional_copy(void);
int		test_optional_unwrap(void);
int		test_optional_from_val(void);
int		test_optional_chain(void);
int		test_optional_map(void);
int		test_optional_destroy(void);

#endif /* INCLUDE/TESTS/OPTIONAL_TEST_H */
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
