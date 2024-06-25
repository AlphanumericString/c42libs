/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_narena.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:41:16 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/25 18:21:51 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_list.h"

#define FT_NARENAS_MAX 16
#define FT_AREA_BLOCK_SIZE 4096

t_list	*ft_narena(int n)
{
	static t_list	*arenas[FT_NARENAS_MAX] = {NULL};

	if (n < 0 || n >= FT_NARENAS_MAX)
		return (NULL);
	if (arenas[n] == NULL)
		arenas[n] = ft_ll_create(NULL);
	return (arenas[n]);
}

void	*ft_narena_alloc(size_t size, int n)
{
	t_list	*arena;
	void	*ptr;

	arena = ft_narena(n);
	size = ft_align(size, FT_AREA_BLOCK_SIZE);
	ptr = malloc(size);
	ft_ll_add(&arena, ft_ll_create(ptr));
	return (ptr);
}

