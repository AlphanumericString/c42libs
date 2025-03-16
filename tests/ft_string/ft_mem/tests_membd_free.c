/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_membd_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:59:47 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/16 17:50:16 by bgoulard         ###   ########.fr       */
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

int	test_membd_free(void)
{
	const t_allocator_group	prev = *ft_get_allocator();
	t_allocator_group		*group_test;
	void					*ret;

	ft_set_ft_alloc();
	group_test = ft_get_allocator();
	if (group_test->ptr_free != &ft_memimpl_free)
		return (1);
	ret = ft_calloc(1, 1);
	if (!ret)
		return (2);
	ft_free(ret);
	reset_allocator(prev);
	return (0);
}
