/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pair_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:28:49 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/24 00:28:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pair.h"
#include "ft_pair_types.h"
#include <stdlib.h>

t_pair	*ft_pair_new(void *a, void *b)
{
	t_pair	*ret;

	ret = malloc(sizeof(*ret));
	if (!ret)
		return (NULL);
	return (ft_pair_set(ret, a, b), ret);
}
