/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_from_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:19:37 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 13:06:08 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_vector_types.h"

// TODO: test_vec_from_array with bigger array to test the cappacity when
// 		it's bigger than FT_VECTOR_BASE_LEN
int	test_vec_from_array(void)
{
	void		*data[3];
	void		*data2[6];
	t_vector	*vec;

	data[0] = (void *)12;
	data[1] = (void *)13;
	data[2] = (void *)14;
	//////// data2
	data2[0] = (void *)20;
	data2[1] = (void *)21;
	data2[2] = (void *)22;
	data2[3] = (void *)23;
	data2[4] = (void *)24;
	data2[5] = (void *)25;
	vec = ft_vec_from_array(data, sizeof(data) / sizeof(data[0]));
	if (vec->count != 3 || vec->cappacity != FT_VECTOR_BASE_LEN || \
	vec->datas == NULL)
		return (1);
	else if (ft_vec_at(vec, 0) != data[0] || ft_vec_at(vec, 1) != data[1] || \
	ft_vec_at(vec, 2) != data[2])
		return (1);
	ft_vec_destroy(&vec);
	vec = ft_vec_from_array(data2, sizeof(data2) / sizeof(*data2));
	if (vec->count != 6 || vec->cappacity != 6 || vec->datas == NULL)
		return (1);
	else if (ft_vec_at(vec, 0) != data2[0] || ft_vec_at(vec, 1) != data2[1] || \
	ft_vec_at(vec, 2) != data2[2] || ft_vec_at(vec, 3) != data2[3] || \
	ft_vec_at(vec, 4) != data2[4] || ft_vec_at(vec, 5) != data2[5])
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}
