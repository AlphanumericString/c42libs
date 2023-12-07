/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:10:51 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/04 10:38:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	ft_vec_filter(t_vector *vec, bool (*func)(void *), void (*del)(void *))
{
	size_t	i;
	size_t	ret;

	i = 0;
	while (vec->count > i)
	{
		ret = 0;
		while (func(vec->datas[i]) == false && vec->count > i)
		{
			del(vec->datas[i]);
			ret++;
			i++;
		}
		ft_vec_shift(vec, i, ret);
		i++;
	}
	return ;
}
