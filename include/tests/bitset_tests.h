/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitset_tests.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 01:32:13 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/20 04:01:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITSET_TESTS_H
# define BITSET_TESTS_H

# include "types/ft_bitset_types.h"
# include "ft_defs.h"

int	tb_new(void);
int	tb_create(void);
int	tb_new_from_mem(void);
int	tb_clear(void);
int	tb_free(void);
int	tb_free_inner(void);
int	tb_get_raw(void);
int	tb_get(void);
int	tb_set_raw(void);
int	tb_set(void);
int	tb_toggle(void);
int	tb_toggle_raw(void);
int	tb_print(void);
int	tb_print_binary(void);
int	tb_print_hex(void);
int	tb_print_decimal(void);
int	tb_append(void);
int	tb_remove(void);
int	tb_remove_front(void);

#endif /* BITSET_TESTS_H */
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
