/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targ_get_envp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:50:59 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:02:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_string.h"
#include "internal/args_helper.h"
#include "internal/debug_defs.h"
#include "tests/args_tests.h"

int	targ_getenvp(void)
{
	const char *s;
	const char *const *prev_ev = ft_ev();
	const char *test_ev[] = {
		"TOTO=TITI", "HOME=notapath", "user=tests", NULL
	};

	ft_set_ev(test_ev);
	if (ft_get_env("giberish") || ft_get_env("") || ft_get_env(NULL))
		return (1);
	s = ft_get_env("user");
	if (!s || ft_strcmp(s, "tests"))
		return (2);
	s = ft_get_env("TOTO");
	if (!s || ft_strcmp(s, "TITI"))
		return (3);
	ft_set_ev(NULL);
	if (ft_get_env("TOTO"))
		return (4);
	return (ft_set_ev(prev_ev), 0);
}
