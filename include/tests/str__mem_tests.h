/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str__mem_tests.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:26:09 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/16 17:57:54 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR__MEM_TESTS_H
# define STR__MEM_TESTS_H

// test array
// tca -> test c-style array
int	tca_apply_2d(void);
int	tca_free_2d(void);
int	tca_len_2d(void);

// test memory allocator
// tmal -> test memory allocator
int	tmal_allocator(void);
int	tmal_calloc(void);
int	tmal_free(void);
int	tmal_malloc(void);
int	tmal_realloc(void);
int	tmal_reallocarray(void);

// test memory arena
// tma -> test memory arena
int	tma_arena(void);
int	tma_narena(void);

// global test memory functions
// tm -> test memory
int	tm_bzero(void);
int	tm_calloc(void);
int	tm_fd_to_buff(void);
int	tm_freecl(void);
int	tm_free(void);
int	tm_memchr(void);
int	tm_memcmp(void);
int	tm_memcpy(void);
int	tm_memmap(void);
int	tm_memmove(void);
int	tm_memset(void);
int	tm_qsort(void);
int	tm_realloc(void);
int	tm_swap(void);

#endif /* STR__MEM_TESTS_H */
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
