/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_membd_realloc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:59:52 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/16 17:49:32 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"

static void	reset_allocator(const t_allocator_group prev)
{
	t_allocator_group	*group_test;

	group_test = ft_get_allocator();
	group_test->ptr_free = prev.ptr_free;
	group_test->ptr_alloc = prev.ptr_alloc;
	group_test->ptr_calloc = prev.ptr_calloc;
	group_test->ptr_realloc = prev.ptr_realloc;
	group_test->ptr_reallocarray = prev.ptr_reallocarray;
}

int	test_membd_realloc(void)
{
	const t_allocator_group	prev = *ft_get_allocator();
	t_allocator_group		*group_test;
	char					*str;

	ft_set_ft_alloc();
	group_test = ft_get_allocator();
	if (group_test->ptr_realloc != &ft_memimpl_realloc)
		return (1);
	str = ft_calloc(10, sizeof(char));
	str[4] = '4';
	str[5] = '2';
	str = ft_realloc(str, 20 * sizeof(char));
	if (!str || str[4] != '4' || str[5] != '2')
		return (3);
	ft_free(str);
	reset_allocator(prev);
	return (0);
}
