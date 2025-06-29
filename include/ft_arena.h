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

# define FT_NARENA_MAX 64 // 64 arenas contexts max

// base
void	*ft_arena_alloc(size_t size);
void	*ft_arena_calloc(size_t count, size_t size);
void	ft_arena_free(void);

// n version
void	*ft_narena_alloc(int arena, size_t request);
void	*ft_narena_calloc(int arena, size_t count, size_t size);
void	ft_narena_free(int arena);

#endif
