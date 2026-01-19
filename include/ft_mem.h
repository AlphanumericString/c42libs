/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:57:54 by bgoulard          #+#    #+#             */
/*   Updated: 2026/01/15 14:21:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

# include "ft_defs.h"

/// @brief fill the memory with 0
/// @param s start of the memory
/// @param n size of the memory
void		ft_bzero(void *s, size_t n);

// NOTE: bindings for to directly call memallocator associated in current
//	context
void		*ft_malloc(size_t size);
void		ft_free(void *ptr);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_realloc(void *ptr, size_t size);

/// @brief free the memory and set ptr to NULL
/// @param ptr pointer to the memory to free (set to NULL after)
void		ft_free_clear(void **ptr);

/// @brief search for the first occurence of c in the memory
/// @param s start of the memory
/// @param c char to search
/// @param n size of the memory
/// @return pointer to the first occurence of c in the memory otherwise NULL
void		*ft_memchr(const void *s, int c, size_t n);

/// @brief compare the memory
/// @param s1 start of the first memory
/// @param s2 start of the second memory
/// @param n size of the memory to compare
/// @return 0 if the memory are identical, otherwise the difference between the
/// first different char
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/// @brief copy the memory
/// @param dest start of the destination memory
/// @param src start of the source memory
/// @param n size of the memory to copy
/// @return pointer to the destination memory
void		*ft_memcpy(void *dest, const void *src, size_t n);

/// @brief copies then transform a memory array region pointed by src using a
///  function f of form 'void *(*f)(const void *) on a region delimited by
///  the number of elements nb_e.
/// @param src start of the source memory
/// @param nb_e number of void* elements in the source array
/// @param f function to apply
/// @return pointer to the new memory or NULL
void		**ft_memmap(void **src, size_t nb_e, t_data_tr f);

/// @brief copy the memory
/// @param dest start of the destination memory
/// @param src start of the source memory
/// @param n size of the memory to copy
/// @return pointer to the destination memory
void		*ft_memmove(void *dest, const void *src, size_t n);

/// @brief set the memory with c
/// @param s start of the memory
/// @param c char to set
/// @param n size of the memory
/// @return pointer to the memory
void		*ft_memset(void *s, int c, size_t n);

/// @brief swap the memory
/// @param a first memory
/// @param b second memory
void		ft_swap_ptr(void **a, void **b);

/// @brief swap the memory uses a static buff if size is less
///		than FT_STD_BUF_SIZE otherwise justs allocates.
/// @param a first memory
/// @param b second memory
/// @param size size of the memory to swap
/// @warning if a and b overlap this function will ALWAYS bias
///		towards a. If you need to swap overlapping memory use
///		something else.
///	@warning if overlap and n > FT_STD_BUF_SIZE the function will
///		try to allocate a temp buffer. allocation might fail and no swap
///		will occur.
void		ft_swap(void *a, void *b, size_t size)
			__attribute__((hot));

/// @brief swap the memory but uses the xor operation
/// @param a first memory
/// @param b second memory
/// @param size size of the memory to swap
void		ft_swap_xor(void *a, void *b, size_t size)
			__attribute__((hot));

/// @brief reverse the memory in chunks of n bytes
/// @param data start of the memory
/// @param nmemb number of chunks
/// @param n size of each chunk
/// @return pointer to the memory
void		*ft_memnrev(void *data, size_t nmemb, size_t n);

/// @brief reverse the memory
/// @param data start of the memory
/// @param n size of the memory
/// @return pointer to the memory
void		*ft_memrev(void *data, size_t n);

// TODO: ft_memrevn -> reverse each chunk separately
//  aka literally call ft_memrev nmemb times on each member
//  -> usefull for :LE <=> BE, ARGB <=> BGRA,
//		UTF-16 <=> UTF-16BE, md5, sha1, sha256, sha512 etc...

// NOTE: maybe move to ft_algorithms.h ?

#endif /* FT_MEM_H */
