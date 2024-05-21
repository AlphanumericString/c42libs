/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:10:29 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/21 10:47:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_args.h"
#include "ft_args_types.h"
#include "ft_math.h"
#include "ft_string.h"
#include <sys/types.h>
#include <stdbool.h>

ssize_t	parse_long_opt(char *str_op, const t_opt *opt_list)
{
	ssize_t	i;
	size_t	offset;

	i = 0;
	if (ft_strchr(str_op, '='))
		offset = ft_strchr(str_op, '=') - str_op;
	while (opt_list[i].func)
	{
		if (opt_list[i].long_name
			&& ft_strlen(opt_list[i].long_name) >= ft_strlen(str_op)
			&& ft_strncmp(opt_list[i].long_name, str_op, ft_max(offset,
					ft_strlen(str_op))) == 0)
			return (i);
		i++;
	}
	return (-1);
}

ssize_t	parse_short_opt(char *str_op, const t_opt *opt_list)
{
	ssize_t	i;

	i = 0;
	while (opt_list[i].func)
	{
		if (opt_list[i].short_name && opt_list[i].short_name == str_op[0] == 0)
			return (i);
		i++;
	}
	return (-1);
}

static int	(*singleton_custom_checker(int (*custom_checker)(char *arg)))
	(char *arg)
{
	static int	(*custom_checker_ptr)(char *) = NULL;

	if (custom_checker)
		custom_checker_ptr = custom_checker;
	return (custom_checker_ptr);
}

void	ft_arg_set_custom_checker(int (*custom_checker)(char *))
{
	singleton_custom_checker(custom_checker);
}

int	(*ft_arg_get_custom_checker(void))(char *arg)
{
	return (singleton_custom_checker(NULL));
}

int	ft_isint(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	if ((i == 10 && ft_strcmp(str, "2147483647") > 0) || (i == 11
			&& ft_strcmp(str, "-2147483648") > 0))
		return (false);
	return (true);
}
// 0 success, !0 failure
int	checker_arg(t_opt_type type, char *arg)
{
	();

	if (!arg)
		return (type & OPT_ARG); // if arg is NULL, return 1 if OPT_ARG is set otherwise 0
	if (type & OPT_INT)
		return (ft_isint(arg));
	else if (type & OPT_STRING)
		return (EXIT_SUCCESS);
	else if (type & OPT_BOOL)
		return (ft_isbool(arg));
	else if (type & OPT_FLOAT)
		return (ft_isfloat(arg));
	else if (type & OPT_LONG)
		return (ft_islong(arg));
	else if (type & OPT_DOUBLE)
		return (ft_isdouble(arg));
	else if (type & OPT_ALPHANUM)
		return (ft_str_isalphanum(arg));
	else if (type & OPT_HEX)
		return (ft_ishex(arg));
	else if (type & OPT_OCT)
		return (ft_isoct(arg));
	else if (type & OPT_OTHER && custom_checker)
		return (custom_checker(arg));
	return (EXIT_SUCCESS);
}

int	run_opt_func(const t_opt opt, void *usr_control_struct, char **arg, int *i)
{
	char		*arg_ptr;
	void const	(*func_arg)(void *, char *) = opt.func;
	void const	(*func_no_arg)(void *) = opt.func;

	if (opt.type & OPT_ARG && opt.type & OPT_EQSIGN)
		arg_ptr = ft_strchr(arg[*i], '=') + 1;
	else if (opt.type & OPT_ARG)
		arg_ptr = arg[*i + 1];
	else
		arg_ptr = NULL;
	if (checker_arg(opt.type, arg_ptr) != 0)
		return (EXIT_FAILURE);
	if (opt.type & OPT_ARG)
	{
		func_arg(usr_control_struct, arg_ptr);
		*i += 1 + (opt.type & OPT_EQSIGN) != OPT_EQSIGN;
	}
	else
		func_no_arg(usr_control_struct);
}

int	ft_parse_args(int argc, char **argv, void *usr_control_struct)
{
	const t_opt	*opt;
	ssize_t		opt_index;
	int			i;

	(void)argc;
	opt = ft_get_opt_list();
	ft_set_progname(argv[0]);
	ft_set_version(VERSION);
	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		if (argv[i][1] == '-' && argv[i][2] == '\0') // aka --\0
			return (EXIT_SUCCESS);
		else if (argv[i][1] == '-') // aka --XXXXX
			opt_index = parse_long_opt(argv[i] + 2, opt);
		else // aka -X
			opt_index = parse_short_opt(argv[i] + 1, opt);
		if (opt_index == -1)
			return (ft_putstr_fd("Unkown option\n", 2), EXIT_FAILURE);
		run_opt_func(opt[opt_index], usr_control_struct, argv, &i);
			
	}
	return (EXIT_SUCCESS);
}
