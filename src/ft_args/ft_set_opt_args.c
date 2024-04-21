/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_opt_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 00:01:33 by bgoulard          #+#    #+#             */
/*   Updated: 2024/04/20 01:17:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_args.h"
#include "ft_args_types.h"

static const t_opt *singleton_opt_list(const t_opt *opt_list)
{
	static const t_opt *singleton_opt_list = NULL;

	if (opt_list)
		singleton_opt_list = opt_list;
	return (singleton_opt_list);
}

void ft_set_opt_list(const t_opt *opt_list)
{
	if (opt_list)
		singleton_opt_list(opt_list);
}

const t_opt *ft_get_opt_list(void)
{
	return (singleton_opt_list(NULL));
}
