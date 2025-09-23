/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_rev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:21:34 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/22 15:21:34 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_mem.h"
#include "ft_sort.h"
#include "tests/str__mem_tests.h"
#include <stdio.h>
#include <stdlib.h>

int	tm_memrev(void)
{
	const t_arrinfo	inf = {.n_ele = FT_MICRO_BUF_SIZE, .ele_s = sizeof(char)};
	char			arr[FT_MICRO_BUF_SIZE];
	size_t			off;
	char			i;

	i = 0;
	off = 0;
	while (off < inf.n_ele)
		arr[off++] = i++;
	ft_memrev(arr, inf.n_ele);
	off = 0;
	i = 0;
	while (off < inf.n_ele)
		if (arr[off++] != inf.n_ele - 1 - i++)
			return (1);
	ft_memrev(arr, 1);
	ft_memrev(arr, 0);
	off = 0;
	i = 0;
	while (off < inf.n_ele)
		if (arr[off++] != inf.n_ele - 1 - i++)
			return (1);
	return (EXIT_SUCCESS);
}

int	tm_memnrev(void)
{
	const int		arr_src[5] = {1, 2, 3, 4, 5};
	int				arr[2][5];

	ft_memcpy(arr[0], arr_src, sizeof(arr_src));
	ft_memcpy(arr[1], arr_src, sizeof(arr_src));
	ft_memnrev(arr[0], 3, sizeof(int));
	if (arr[0][0] != 3 || arr[0][1] != 2 || arr[0][2] != 1)
		return (1);
	ft_memnrev(arr[0], 5, sizeof(int));
	if (arr[0][0] != 5 || arr[0][1] != 4 || arr[0][2] != 1
		|| arr[0][3] != 2 || arr[0][4] != 3)
		return (2);
	ft_memnrev(arr[1], 1, sizeof(int));
	ft_memnrev(arr[1], 5, 0);
	if (ft_memcmp(arr[1], arr_src, sizeof(arr_src)) != 0)
		return (3);
	return (EXIT_SUCCESS);
}
