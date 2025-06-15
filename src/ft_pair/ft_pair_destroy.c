/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pair_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:04:56 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/25 19:45:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/ft_pair_types.h"

#include "ft_defs.h"
#include "ft_string.h"
#include "ft_pair.h"

void	ft_pair_destroy(t_pair **pair, const t_data_apply del_f)
{
	if (!pair)
		return ;
	if (!del_f)
		return (ft_free_clear((void **)pair));
	if ((*pair)->first)
		del_f((*pair)->first);
	if ((*pair)->second)
		del_f((*pair)->second);
	return (ft_free_clear((void **)pair));
}

void	ft_pair_destroy_sep(t_pair **pair, const t_data_apply del_f,
			const t_data_apply del_s)
{
	if (!pair)
		return ;
	if (del_f && (*pair)->first)
		del_f((*pair)->first);
	if (del_s && (*pair)->second)
		del_s((*pair)->second);
	ft_free_clear((void **)pair);
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
