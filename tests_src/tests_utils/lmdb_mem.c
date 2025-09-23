/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmdb_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 00:19:20 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/22 00:19:20 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"
#include "tests/tests_lambda_functions.h"
#include <stdlib.h>

void	*randomize_iarr(int *arr, size_t size, ssize_t lower, ssize_t upper)
{
	size_t	i;

	i = 0;
	while (i < size)
		arr[i++] = (rand() % (upper - lower)) + lower;
	if (ft_is_sorted(arr, size, sizeof(int), ft_cmp_int_p))
		return (randomize_iarr(arr, size, lower, upper));
	return (arr);
}

void	*randomize_sarr(size_t *arr, size_t size, ssize_t lower, ssize_t upper)
{
	size_t	i;

	i = 0;
	while (i < size)
		arr[i++] = (rand() % (upper - lower)) + lower;
	if (ft_is_sorted(arr, size, sizeof(size_t), (t_data_cmp)ft_cmp_szt_p))
		return (randomize_sarr(arr, size, lower, upper));
	return (arr);
}

void	*randomize_ssarr(ssize_t *arr, size_t size, ssize_t lwr, ssize_t upr)
{
	size_t	i;

	i = 0;
	while (i < size)
		arr[i++] = (rand() % (upr - lwr)) + lwr;
	if (ft_is_sorted(arr, size, sizeof(ssize_t), (t_data_cmp)ft_cmp_sszt_p))
		return (randomize_ssarr(arr, size, lwr, upr));
	return (arr);
}
