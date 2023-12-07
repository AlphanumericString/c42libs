/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_reserve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:01:18 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/04 10:39:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include <stdlib.h>

bool	ft_vec_reserve(t_vector **vec, size_t size)
{
	t_vector	*ret;
	size_t		i;

	if ((*vec)->cappacity > size)
		return (true);
	ret = ft_vec_from_size(size);
	if (ret == NULL)
		return (false);
	i = 0;
	while (i < (*vec)->count)
	{
		ret->datas[i] = (*vec)->datas[i];
		i++;
	}
	ret->count = (*vec)->count;
	free(*vec);
	*vec = ret;
	return (true);
}
