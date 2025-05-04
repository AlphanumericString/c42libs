/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_ev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:40:00 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/06 17:11:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "internal/args_helper.h"

#include <stdlib.h>

static const char *const	*ft_ev_singleton(const char *const *ev)
{
	static const char *const	*ev_st = NULL;

	if (ev)
		ev_st = ev;
	return (ev_st);
}

// Dependant on c abi - lol
// ev are always sotred after av in mem acording to c std abi
// we use this property to access ev by just reading after the first NULL;;
int	ft_set_ev_from_av(const char *const *av, int ac)
{
	if (!av || !ac || av[ac] != NULL)
		return (EXIT_FAILURE);
	return (ft_set_ev((const char *const *)(&av[ac + 1])));
}

int	ft_set_ev(const char *const *const ev)
{
	if (!ev)
		return (EXIT_FAILURE);
	return (ft_ev_singleton(ev), EXIT_SUCCESS);
}

const char *const	*ft_ev(void)
{
	return (ft_ev_singleton(NULL));
}
