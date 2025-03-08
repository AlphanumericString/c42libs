/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optional_chain.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:06:26 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/13 18:02:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"
#include <stdbool.h>

bool	ft_optional_chain(t_optional *opt, const t_data_tr_i *f)
{
	size_t	i;

	if (!f)
		return (false);
	i = 0;
	while (f[i] && opt->pres != OPT_NONE)
	{
		opt->val = f[i](opt->val);
		if (!opt->val)
			opt->pres = OPT_NONE;
		i++;
	}
	if (opt->pres == OPT_NONE)
		return (false);
	return (true);
}

t_optional	ft_optional_map(t_optional *opt, void *(**f)(void *))
{
	t_optional	ret;

	ft_optional_copy(&ret, opt);
	if (ret.pres == OPT_NONE || !f)
		return (ret.pres = OPT_NONE, ret);
	ft_optional_chain(&ret, f);
	return (ret);
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
