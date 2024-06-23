/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pair_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:04:56 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/24 00:12:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_pair.h"
#include "ft_pair_types.h"
#include <stdlib.h>

void	ft_pair_destroy(t_pair *pair, t_data_apply del)
{
	if (!pair)
		return ;
	if (del)
	{
		del(pair->first);
		del(pair->second);
	}
	ft_pair_cmp(NULL, NULL, NULL);
	ft_pair_cmp_second(NULL, NULL, NULL);
	free(pair);
}
