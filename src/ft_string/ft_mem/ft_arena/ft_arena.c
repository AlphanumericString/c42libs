/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:46:17 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/20 04:01:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena.h"
#include "ft_defs.h"

void	*ft_arena_alloc(size_t size)
{
	return (ft_narena_alloc(0, size));
}

void	*ft_arena_calloc(size_t count, size_t size)
{
	return (ft_narena_calloc(0, count, size));
}

void	ft_arena_free(void)
{
	ft_narena_free(0);
}
