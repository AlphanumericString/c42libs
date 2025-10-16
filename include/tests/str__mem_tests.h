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
int	tca_aaloc(void);
int	tca_aapply(void);
int	tca_acat(void);
int	tca_aclear(void);
int	tca_acmp(void);
int	tca_acmpwith(void);
int	tca_acpy(void);
int	tca_adup(void);
int	tca_afind(void);
int	tca_afindwith(void);
int	tca_afree(void);
int	tca_alcat(void);
int	tca_alcpy(void);
int	tca_alen(void);
int	tca_amap(void);
int	tca_anapply(void);
int	tca_ancmp(void);
int	tca_ancmpwith(void);
int	tca_andup(void);
int	tca_anfree(void);
int	tca_anmap(void);
int	tca_anrev(void);
int	tca_antr(void);
int	tca_arev(void);
int	tca_arfind(void);
int	tca_arfindwith(void);
int	tca_atr(void);

// test memory allocator
// tmal -> test memory allocator
int	tmal_allocator(void);
int	tmal_calloc(void);
int	tmal_free(void);
int	tmal_malloc(void);
int	tmal_reallocarray(void);
int	tmal_realloc(void);

// test memory arena
// tma -> test memory arena
int	tma_arena(void);
int	tma_narena_alloc(void);
int	tma_narena_belong(void);
int	tma_narena_calloc(void);
int	tma_narena_free(void);

// test algorithms
// talg -> test algorithms
int	talg_bblsort(void);
int	talg_binsrch(void);
int	talg_cmps(void);
int	talg_getmax(void);
int	talg_getmin(void);
int	talg_isord_ok(void);
int	talg_isrtsort_b(void);
int	talg_isrtsort(void);
int	talg_issorted(void);
int	talg_mrgsort_r(void);
int	talg_mrgsort(void);
int	talg_qsort(void);;
int	talg_rcmps(void);
int	talg_sbblsort(void);
int	talg_sbcksort(void);
int	talg_shkrsort(void);
int	talg_sisrtsort(void);
int	talg_slctsort(void);
int	talg_ssbblsort(void);
int	talg_ssisrtsort(void);

// global test memory functions
// tm -> test memory
int	tm_bzero(void);
int	tm_calloc(void);
int	tm_fd_to_buff(void);
int	tm_freecl(void);
int	tm_swap(void);
int	tm_swap_xor(void);
int	tm_free(void);
int	tm_memchr(void);
int	tm_memcmp(void);
int	tm_memcpy(void);
int	tm_memmap(void);
int	tm_memmove(void);
int	tm_memrev(void);
int	tm_memnrev(void);
int	tm_memset(void);
int	tm_realloc(void);
int	tm_swap_ptr(void);

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
