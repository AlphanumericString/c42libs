/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_custom_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:15:10 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 18:32:20 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"

static int	loc_checker(const char *arg)
{
	if (arg[0] == 'a')
		return (1);
	return (0);
}

int	getset_custom_checker_test(void)
{
	ft_arg_set_custom_checker(loc_checker);
	if (ft_arg_get_custom_checker() != loc_checker)
		return (-1);
	return (0);
}
