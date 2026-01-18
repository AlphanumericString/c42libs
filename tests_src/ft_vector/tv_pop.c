/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:47:14 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:09:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "tests/vector_tests.h"

// NOTE:
// vec_pop returns the place in the vector of the last element and
// decreases the number of elements by 1
// so we need to do `*(char **)` each time because we registered 'strs'
// aka char *[3] aka list of adresses of strings in the vector
// ft_vec_pop(vec) -> get the emplacement of last element
// (char **) -> this emplacement is the adress of a char *
// * -> dereference to get the char * aka the string
// might be a tad confusing at first but it is what it is with void* as ret

// TODO: ft_vec_popi(vec, &ret); returns and puts the value in ret
// to avoid all the hasle of *(type *)ft_vec_pop ....
static int	error_cases(void)
{
	t_vector	*vec;
	size_t		tmp;
	const char	*strs[3] = {"value1", "value2", "value3"};

	vec = ft_vec_from_array(strs, 3, sizeof(char *));
	if (ft_vec_pop(NULL) != NULL)
		return (ft_vec_destroy(&vec), 1);
	tmp = vec->s_e;
	vec->s_e = 0;
	if (ft_vec_pop(vec))
		return (ft_vec_destroy(&vec), 2);
	vec->s_e = tmp;
	ft_vec_pop(vec);
	ft_vec_pop(vec);
	ft_vec_pop(vec);
	if (ft_vec_pop(vec) != NULL)
		return (ft_vec_destroy(&vec), 3);
	return (ft_vec_destroy(&vec), EXIT_SUCCESS);
}

static int	normal_cases(void)
{
	t_vector	*vec;
	const char	*strs[3] = {"value1", "value2", "value3"};
	const char	*str;

	vec = ft_vec_from_array(strs, 3, sizeof(char *));
	str = *(char **)ft_vec_pop(vec);
	if (!str || ft_strcmp(str, "value3") != 0 || vec->n_e != 2)
		return (1);
	str = *(char **)ft_vec_pop(vec);
	if (!str || ft_strcmp(str, "value2") != 0 || vec->n_e != 1)
		return (2);
	str = *(char **)ft_vec_pop(vec);
	if (!str || ft_strcmp(str, "value1") != 0 || vec->n_e != 0)
		return (4);
	return (ft_vec_destroy(&vec), EXIT_SUCCESS);
}

int	tv_pop(void)
{
	int ret = 0;

	ret = normal_cases();
	if (ret)
	  return (ret);
	ret = error_cases();
	if (ret)
	  return (ret + 32);
	return (EXIT_SUCCESS);
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
