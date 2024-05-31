/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_custom_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:13:26 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 18:21:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	(*singleton_custom_checker(int (*custom_checker)(const char *arg)))
	(const char *arg)
{
	static int	(*custom_checker_ptr)(const char *) = NULL;

	if (custom_checker)
		custom_checker_ptr = custom_checker;
	return (custom_checker_ptr);
}

void	ft_arg_set_custom_checker(int (*custom_checker)(const char *))
{
	singleton_custom_checker(custom_checker);
}

int	(*ft_arg_get_custom_checker(void))(const char *arg)
{
	return (singleton_custom_checker(NULL));
}
