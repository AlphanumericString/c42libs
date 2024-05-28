/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_apply_2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:05:28 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/28 16:12:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests_lambda_functions.h"

int	apply_2d_tests(void)
{
	char	*arr2d[3];
	size_t	i;

	i = 0;
	while (i < 3)
	{
		arr2d[i] = (void *)42 + i;
		i++;
	}
	ft_apply_2d((void **)arr2d, add42);
	if (arr2d[0] != (void *)42 || arr2d[1] != (void *)43 || arr2d[2] != \
	(void *)44)
		return (1);
	return (0);
}
