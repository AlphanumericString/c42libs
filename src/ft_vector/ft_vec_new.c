/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:13:51 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/04 10:38:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include <stdlib.h>

t_vector	*ft_vec_new(void)
{
	return (ft_vec_from_size(FT_VECTOR_BASE_LEN));
}

t_vector	*ft_vec_from_size(size_t n)
{
	t_vector	*ret;

	ret = malloc(sizeof(t_vector));
	if (!ret)
		return (ret);
	ret->datas = malloc(sizeof(void *) * n);
	if (!ret->datas)
		return (free(ret), NULL);
	ret->cappacity = n;
	ret->count = 0;
	return (ret);
}

t_vector	*ft_vec_from_array(void **data, size_t count)
{
	t_vector	*ret;
	size_t		i;

	ret = ft_vec_from_size(count);
	i = 0;
	while (i < count)
		ft_vec_add(&ret, data[i++]);
	return (ret);
}

t_vector	*ft_vec_convert_alloccarray(void **data, size_t count)
{
	t_vector	*ret;

	ret = malloc(sizeof(t_vector));
	ret->datas = data;
	ret->count = count;
	ret->cappacity = count;
	return (ret);
}
