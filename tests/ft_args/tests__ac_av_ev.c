/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests__ac_av_ev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:09:50 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/06 17:01:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "tests/tests__all_modules_tests.h"

#include <stddef.h>
#include <stdio.h>

int	targ_ac(void)
{
	const int	acs[] = {0, -3, 3};
	int			ret;
	size_t		it;

	it = 0;
	while (it < sizeof(acs) / sizeof(acs[0]))
	{
		ft_set_ac(acs[it]);
		ret = ft_ac();
		if (acs[it] > 0 && acs[it] != ret)
			return (it + 1);
		it++;
	}
	return (0);
}

int	targ_ev(void)
{
	const char			*evs[][2] = {{"toto", "prout"}, {"pipi", "caca"}};
	const char *const	*prev;

	prev = ft_ev();
	ft_set_ev((const char *const *)evs[0]);
	if (ft_ev() != (const char *const *)evs[0])
		return (1);
	ft_set_ev((const char *const *)evs[1]);
	if (ft_ev() != (const char *const *)evs[1])
		return (2);
	ft_set_ev(NULL);
	if (ft_ev() != (const char *const *)evs[1])
		return (3);
	return (ft_set_ev(prev), 0);
}

int	targ_av(void)
{
	const char *const	*prev = ft_av();
	const int			prev_ac = ft_ac();
	const char			*args[][4] = {{"toto", "prout", NULL, NULL}, \
	{"0", "1", "2", NULL}};

	ft_set_av(args[0]);
	if (ft_av() != args[0] || ft_ac() != 2)
		return (1);
	ft_set_av(args[1]);
	if (ft_av() != args[1] || ft_ac() != 3)
		return (2);
	ft_set_av(NULL);
	if (ft_av() != args[1] || ft_ac() != 3)
		return (3);
	return (ft_set_av(prev), ft_set_ac(prev_ac));
}
