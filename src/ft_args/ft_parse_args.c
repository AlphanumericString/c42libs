/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:10:29 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/21 15:59:57 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_args_types.h"
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>

int	ft_parse_args(char **argv, void *usr_control_struct)
{
	const t_opt	*opt;
	ssize_t		opt_index;
	int			i;

	opt = ft_get_opt_list();
	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		if (argv[i][1] == '-' && argv[i][2] == '\0')
			return (EXIT_SUCCESS);
		else if (argv[i][1] == '-')
			opt_index = parse_long_opt(argv[i], opt);
		else
			opt_index = parse_short_opt(argv[i], opt);
		if (opt_index == -1)
			return (arg_opt_err(argv[i]));
		if (run_opt_func(opt[opt_index], usr_control_struct, argv, &i) != 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
