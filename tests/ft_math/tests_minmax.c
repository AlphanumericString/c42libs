/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_minmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:49:30 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 00:34:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	test_ft_min(void)
{
	const int	a = 0xdeadbeef;
	const int	b = 0xdeadbaaf;
	const int	c = 0xdeadbccf;

	if (ft_min(a, b) != b)
		return (1);
	if (ft_min(a, c) != a)
		return (1);
	return (0);
}

int	test_ft_max(void)
{
	const int	a = 0xdeadbeef;
	const int	b = 0xdeadbaaf;
	const int	c = 0xdeadbccf;

	if (ft_max(a, b) != a)
		return (1);
	if (ft_max(a, c) != c)
		return (1);
	return (0);
}
