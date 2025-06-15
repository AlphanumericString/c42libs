/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pair_cmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:58:24 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 17:54:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pair.h"

int	ft_pair_cmp(const t_pair *pair1, const t_pair *pair2, const t_data_cmp cmp)
{
	if (!pair1 && !pair2)
		return (0);
	if (!pair1)
		return (-(pair2 != NULL));
	if (!pair2)
		return (pair1 != NULL);
	if (cmp)
		return (cmp(pair1, pair2));
	return (pair1 - pair2);
}

int	ft_pair_cmp_first(const t_pair *pair1, const t_pair *pair2,
		const t_data_cmp cmp)
{
	if (!pair1 && !pair2)
		return (0);
	if (!pair1)
		return (-(pair2->first != NULL));
	if (!pair2)
		return (pair1->first != NULL);
	if (cmp)
		return (cmp(pair1->first, pair2->first));
	return (pair1->first - pair2->first);
}

int	ft_pair_cmp_second(const t_pair *pair1, const t_pair *pair2,
		const t_data_cmp cmp)
{
	if (!pair1 && !pair2)
		return (0);
	if (!pair1)
		return (-(pair2->second != NULL));
	if (!pair2)
		return (pair1->second != NULL);
	if (cmp)
		return (cmp(pair1->second, pair2->second));
	return (pair1->second - pair2->second);
}
/*
GPL-3.0 License:
c42libs - Library for c projects at 42.
Copyright (C) 2025  baptiste GOULARD

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
