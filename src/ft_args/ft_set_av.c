/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_av.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:40:00 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/06 17:11:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"

#include <stdlib.h>

static const char *const	*ft_av_singleton(const char *const *av)
{
	static const char *const	*av_st = NULL;

	if (av)
		av_st = av;
	return (av_st);
}

int	ft_set_av(const char *const *const av)
{
	size_t	ac;

	if (!av)
		return (EXIT_FAILURE);
	ac = 0;
	while (av[ac])
		ac++;
	ft_set_ac(ac);
	return (ft_av_singleton(av), EXIT_SUCCESS);
}

const char *const	*ft_av(void)
{
	return (ft_av_singleton(NULL));
}
