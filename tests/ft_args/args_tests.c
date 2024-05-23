/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:02:31 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/23 22:43:28 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_args_types.h"
#include "tests/tests.h"
#include "tests/args_tests.h"

static void	empty(void *ar, char *arg)
{
	(void)ar;
	(void)arg;
}

int	parse_args_test(void)
{
	return (0);
}

int	getset_opt_list_test(void)
{
	const t_opt	*op2 = NULL;
	const t_opt	op1[] = {
	{"--test", 't', &empty, 0},
	};

	ft_set_opt_list(op1);
	if (ft_get_opt_list() != op1)
		return (1);
	ft_set_opt_list(op2);
	if (ft_get_opt_list() != op1)
		return (2);
	return (0);
}

int	tests_args(void)
{
	int				collect;
	const t_test	test[] = {{"getset_version", getset_version_test},
	{"getset_progname", getset_program_name_test},
	{"getset_opt_list",	getset_opt_list_test}, {"parse_args", parse_args_test},
	{NULL, NULL}};

	collect = 0;
	run_test(test, &collect);
	return (collect);
}
