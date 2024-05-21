/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_opt_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:55:18 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/21 19:04:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args_types.h"
#include "ft_args.h"
#include "ft_string.h"
#include <stddef.h>

int	run_opt_func(const t_opt opt, void *usr_control_struct, char **arg, int *i)
{
	char	*arg_ptr;
	void	(*func_arg)(void *, char *);
	void	(*func_no_arg)(void *);

	func_arg = opt.func;
	func_no_arg = opt.func;
	if (opt.type & OPT_ARG && opt.type & OPT_EQSIGN)
		arg_ptr = ft_strchr(arg[*i], '=') + 1;
	else if (opt.type & OPT_ARG)
		arg_ptr = arg[*i + 1];
	else
		arg_ptr = NULL;
	if (checker_arg(opt.type, arg_ptr) != 0)
		return (arg_type_err(opt, arg_ptr));
	if (opt.type & OPT_ARG)
		func_arg(usr_control_struct, arg_ptr);
	else
		func_no_arg(usr_control_struct);
	*i += opt.type & OPT_ARG;
	*i += (opt.type & OPT_EQSIGN) != OPT_EQSIGN;
	return (EXIT_SUCCESS);
}
