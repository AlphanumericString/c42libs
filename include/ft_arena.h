/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:35:06 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/21 22:00:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARENA_H
# define FT_ARENA_H

# include "ft_defs.h"
# include "types/ft_list_types.h"

# define FT_NARENA_MAX		64 // 64 arenas contexts max
# define FT_DEFAULT_ARENA	0

// base
void	*ft_arena_alloc(size_t size);
void	*ft_arena_calloc(size_t count, size_t size);
void	ft_arena_free(void);
// n version
void	*ft_narena_alloc(int arena, size_t request);
void	*ft_narena_calloc(int arena, size_t count, size_t size);
void	ft_narena_free(int arena);
bool	ft_narena_belongs(int ar_nb, const void *ptr);

void	ft_narena_free_all(void) __attribute__((destructor(200)));

// todo: maybe add a 'decl_arena_space' type of stuff, that intercept
// any call to ft_malloc and auto register them in an arena?
//
// later patch idk maybe
// seems good on paper but idk, will play with the idea

#endif
