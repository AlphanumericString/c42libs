/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:03:06 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/09 19:29:02 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	ft_vec_remove(t_vector *vector, size_t n, void (*del)(void *))
{
	if (n >= vector->count)
		return ;
	del(vector->datas[n]);
	ft_vec_shift(vector, n, 1);
	vector->datas[n] = NULL;
}

void	ft_vec_remove_if(t_vector *vector, bool (*func)(void *),
		void (*del)(void *))
{
	size_t	i;

	i = 0;
	while (i < vector->count)
	{
		if (func(vector->datas[i]))
			ft_vec_remove(vector, i, del);
		else
			i++;
	}
}
