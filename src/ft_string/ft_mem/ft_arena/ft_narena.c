/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_narena.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:46:39 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/21 22:00:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena.h"
#include "ft_list.h"
#include "ft_string.h"
#include "ft_defs.h"
#include "types/ft_list_types.h"
#include "internal/debug_defs.h"

static void	ft_narena_free_all(void) __attribute__((destructor));

static t_dlist	**singleton_arena(int arena)
{
	static t_dlist	*arenas[FT_NARENA_MAX] = {0};

	if (arena < 0 || arena >= FT_NARENA_MAX)
		return (NULL);
	return (&arenas[arena]);
}

static void	ft_narena_free_all(void)
{
	size_t	i;

	i = 0;
	while (i < FT_NARENA_MAX)
		ft_narena_free(i++);
}

void	*ft_narena_alloc(int arena_nb, size_t request)
{
	t_dlist	**current_arena;
	void	*ptr;

	current_arena = singleton_arena(arena_nb);
	if (!current_arena)
		return (NULL);
	ptr = ft_malloc(request);
	if (!ptr)
		return (NULL);
	ft_dl_push(current_arena, ptr);
	return (ptr);
}

void	*ft_narena_calloc(int arena_nb, size_t count, size_t size)
{
	t_dlist	**current_arena;
	void	*ptr;

	current_arena = singleton_arena(arena_nb);
	if (!current_arena)
		return (NULL);
	ptr = ft_calloc(count, size);
	if (!ptr)
		return (NULL);
	ft_dl_push(current_arena, ptr);
	return (NULL);
}

void	ft_narena_free(int arena) {
	t_dlist	**current_arena;

	if (arena < 0 || arena >= FT_NARENA_MAX)
		return;
	current_arena = singleton_arena(arena);
	if (!current_arena || !*current_arena)
		return;
	ft_dl_delete(current_arena, ft_free);
}

