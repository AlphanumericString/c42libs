/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_short_opt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:56:18 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/21 16:00:24 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args_types.h"
#include <unistd.h>

ssize_t	parse_short_opt(char *str_op, const t_opt *opt_list)
{
	ssize_t	i;

	i = 0;
	str_op++;
	while (opt_list[i].func)
	{
		if (opt_list[i].short_name && \
		opt_list[i].short_name == str_op[0])
			return (i);
		i++;
	}
	return (-1);
}
