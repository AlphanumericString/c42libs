/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tp_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:09:25 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:57 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/pair_tests.h"
#include "types/ft_pair_types.h"
#include "ft_pair.h"
#include "tests/tests__all_modules_tests.h"

int	tp_destroy(void)
{
	t_pair	*pair;

	pair = ft_pair_new("key", "value");
	ft_pair_destroy(&pair, NULL);
	if (pair != NULL)
		return (1);
	pair = ft_pair_new(ft_strdup("key"), ft_strdup("value"));
	ft_pair_destroy(&pair, &ft_free);
	if (pair != NULL)
		return (2);
	pair = ft_pair_new(ft_strdup("key"), NULL);
	ft_pair_destroy(&pair, &ft_free);
	if (pair != NULL)
		return (3);
	pair = ft_pair_new(NULL, ft_strdup("value"));
	ft_pair_destroy(&pair, &ft_free);
	if (pair != NULL)
		return (4);
	ft_pair_destroy(NULL, NULL);
	pair = NULL;
	ft_pair_destroy(&pair, NULL);
	return (0);
}

int	tp_destroy_sep(void)
{
	t_pair	*pair;

	pair = ft_pair_new("key", "value");
	ft_pair_destroy_sep(&pair, NULL, NULL);
	if (pair != NULL)
		return (1);
	pair = ft_pair_new(ft_strdup("key"), ft_strdup("value"));
	ft_pair_destroy_sep(&pair, &ft_free, &ft_free);
	if (pair != NULL)
		return (2);
	pair = ft_pair_new(ft_strdup("key"), NULL);
	ft_pair_destroy_sep(&pair, &ft_free, &ft_free);
	if (pair)
		return (3);
	pair = ft_pair_new(NULL, ft_strdup("val"));
	ft_pair_destroy_sep(&pair, &ft_free, &ft_free);
	if (pair)
		return (4);
	ft_pair_destroy_sep(NULL, NULL, NULL);
	pair = NULL;
	ft_pair_destroy_sep(&pair, NULL, NULL);
	return (0);
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
