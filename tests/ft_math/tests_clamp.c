/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_clamp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:46:19 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 00:52:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	test_ft_clamp(void)
{
	const int	max = 42;
	const int	min = 21;
	int			x;

	x = 0;
	if (ft_clamp(x, min, max) != min)
		return (1);
	x = 21;
	if (ft_clamp(x, min, max) != min)
		return (1);
	x = 42;
	if (ft_clamp(x, min, max) != max)
		return (1);
	x = 84;
	if (ft_clamp(x, min, max) != max)
		return (1);
	x = 23;
	if (ft_clamp(x, min, max) != x)
		return (1);
	return (0);
}

// todo: add test_ft_clamp_f
// todo: add test_ft_clamp_d
