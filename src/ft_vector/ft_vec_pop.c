/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:00:25 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 23:01:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector_types.h"

void	*ft_vec_pop(t_vector *vec)
{
	void	*data;

	if (vec->count == 0)
		return (NULL);
	data = vec->datas[vec->count - 1];
	vec->datas[vec->count - 1] = NULL;
	return (data);
}
