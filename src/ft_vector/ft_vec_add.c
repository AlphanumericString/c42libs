/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:59:23 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/04 10:38:11 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

bool	ft_vec_add(t_vector **vec, void *data)
{
	size_t	nw_size;

	if ((*vec)->count == (*vec)->cappacity)
	{
		nw_size = ((*vec)->cappacity / FT_VECTOR_BASE_LEN) + 1;
		if (ft_vec_reserve(vec, nw_size) == false)
			return (ft_vec_destroy(vec), false);
	}
	(*vec)->datas[(*vec)->count++] = data;
	return (true);
}
