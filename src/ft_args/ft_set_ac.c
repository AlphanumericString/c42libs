/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_ac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:40:00 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/06 17:11:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"

#include <stdlib.h>

static int	ft_ac_singleton(int ac)
{
	static int	ac_st = 0;

	if (ac)
		ac_st = ac;
	return (ac_st);
}

int	ft_set_ac(int ac)
{
	if (ac < 1)
		return (EXIT_FAILURE);
	return (ft_ac_singleton(ac), EXIT_SUCCESS);
}

int	ft_ac(void)
{
	return (ft_ac_singleton(0));
}
