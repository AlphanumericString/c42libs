/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_membd_allocator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:03:54 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/16 17:53:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_allocator_types.h"

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

int	test_membd_allocator(void)
{
	const t_allocator_group	prev = *ft_get_allocator();
	t_allocator_group		*group_test;

	ft_set_gnu_alloc();
	group_test = ft_get_allocator();
	if (group_test->ptr_free != &free || group_test->ptr_alloc != &malloc || \
	group_test->ptr_calloc != &calloc || group_test->ptr_realloc != &realloc \
	|| group_test->ptr_reallocarray != &reallocarray)
		return (1);
	ft_set_ft_alloc();
	group_test = ft_get_allocator();
	if (group_test->ptr_free != &ft_memimpl_free || group_test->ptr_alloc != \
	&ft_memimpl_malloc || group_test->ptr_calloc != &ft_memimpl_calloc || \
	group_test->ptr_realloc != &ft_memimpl_realloc || \
	group_test->ptr_reallocarray != &ft_memimpl_reallocarray)
		return (2);
	reset_allocator(prev);
	return (0);
}
