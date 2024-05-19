/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:11:13 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 18:24:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_map_types.h"

int	test_map_clear(void)
{
	t_map	*map;

	map = ft_map_create(10);
	ft_map_clear(map);
	ft_map_destroy(map);
	return (0);
}
