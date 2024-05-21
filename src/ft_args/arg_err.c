/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:23:49 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/21 18:49:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_char.h"
#include "ft_string.h"
#include <unistd.h>

int	arg_type_err(t_opt opt, char *arg)
{
	const char	*progname;

	progname = ft_progname();
	if (progname)
	{
		ft_putstr_fd(progname, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd("Error: invalid argument for option: ", STDERR_FILENO);
	if (opt.long_name)
		ft_putstr_fd(opt.long_name, STDERR_FILENO);
	else
		ft_putchar_fd(opt.short_name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (!arg)
		ft_putstr_fd("NULL", STDERR_FILENO);
	else
		ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	arg_opt_err(char *arg)
{
	const char	*progname;

	progname = ft_progname();
	if (progname)
	{
		ft_putstr_fd(progname, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd("Error: invalid option: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}
