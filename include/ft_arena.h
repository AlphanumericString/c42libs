/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:35:06 by bgoulard          #+#    #+#             */
/*   Updated: 2024/09/01 15:06:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"

// base
void	*ft_arena_alloc(size_t size);
void	*ft_arena_realloc(void *ptr, size_t size);
void	*ft_arena_calloc(size_t count, size_t size);
void	ft_arena_free(void *ptr);

// n version
void	*ft_narena_alloc(size_t	request, int arena);
void	*ft_narena_realloc(void *ptr, size_t request, int arena);
void	*ft_narena_calloc(size_t count, size_t size, int arena);
void	ft_narena_free(void *ptr, int arena);
