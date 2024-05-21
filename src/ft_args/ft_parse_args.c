/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:10:29 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/21 12:16:37 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_args.h"
#include "ft_args_types.h"
#include "ft_math.h"
#include "ft_string.h"
#include <stdio.h>
#include <sys/types.h>
#include <stdbool.h>

ssize_t	parse_long_opt(char *str_op, const t_opt *opt_list)
{
	ssize_t	i;
	size_t	offset;

	str_op += 2;
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

// 0 success, !0 failure
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
			&& ft_strcmp(str, "-2147483648") > 0) || i > 11)
		return (false);
	return (true);
}

int	ft_islong(char *str)
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
	if ((i == 19 && ft_strcmp(str, "9223372036854775807") > 0) || (i == 20
			&& ft_strcmp(str, "-9223372036854775808") > 0) || i > 20)
		return (false);
	return (true);
}

// no value check like isint due to the fact that it's a floating point
int	ft_isfloat(char *str)
{
	size_t	i;
	bool	dot;

	i = 0;
	dot = false;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.' && !dot)
			dot = true;
		else if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	if (i == 0 || (i == 1 && (str[0] == '.' || str[0] == '-')) || \
	(i == 2 && str[0] == '-' && str[1] == '.') || \
	i > 20)
		return (false);
	return (true);
}

int	ft_isdouble(char *str)
{
	return (ft_isfloat(str));
}

int	ft_isbool(char *str)
{
	if (ft_strcmp(str, "true") == 0 || ft_strcmp(str, "false") == 0 || \
	ft_strcmp(str, "0") == 0 || ft_strcmp(str, "1") == 0)
		return (true);
	return (false);
}

int ft_stris_type(char *str, int (*is_type)(int))
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!is_type(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int ft_ishexdigit(int c)
{
	return (ft_isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}

int ft_isoctdigit(int c)
{
	return (c >= '0' && c <= '7');
}

int	ft_str_isalphanum(char *str)
{
	return (ft_stris_type(str, ft_isalnum));
}

int	ft_ishex(char *str)
{
	return (ft_stris_type(str, ft_ishexdigit));
}

int	ft_isoct(char *str)
{
	return (ft_stris_type(str, ft_isoctdigit));
}

// 0 success, !0 failure
int	checker_arg(t_opt_type type, char *arg)
{
	if (!arg)
		return (type & OPT_ARG); // if arg is NULL, return 1 if OPT_ARG is set otherwise 0
	if (type & OPT_INT)
		return (!ft_isint(arg));
	else if ((type & ARG_MASK_ATYPE) == OPT_STRING)
		return (EXIT_SUCCESS);
	else if ((type & ARG_MASK_ATYPE) == OPT_BOOL)
		return (!ft_isbool(arg));
	else if ((type & ARG_MASK_ATYPE) == OPT_FLOAT)
		return (!ft_isfloat(arg));
	else if ((type & ARG_MASK_ATYPE) == OPT_LONG)
		return (!ft_islong(arg));
	else if ((type & ARG_MASK_ATYPE) == OPT_DOUBLE)
		return (!ft_isdouble(arg));
	else if ((type & ARG_MASK_ATYPE) == OPT_ALPHANUM)
		return (!ft_str_isalphanum(arg));
	else if ((type & ARG_MASK_ATYPE) == OPT_HEX)
		return (!ft_ishex(arg));
	else if ((type & ARG_MASK_ATYPE) == OPT_OCT)
		return (!ft_isoct(arg));
	else if ((type & ARG_MASK_ATYPE) == OPT_OTHER \
	&& ft_arg_get_custom_checker())
		return (!ft_arg_get_custom_checker()(arg));
	return (EXIT_SUCCESS);
}

int	arg_type_err(t_opt opt, char *arg)
{
	const char	*progname = ft_progname();

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

int	run_opt_func(const t_opt opt, void *usr_control_struct, char **arg, int *i)
{
	char	*arg_ptr;
	void	(* const func_arg)(void *, char *) = opt.func;
	void	(* const func_no_arg)(void *) = opt.func;

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

int	arg_opt_err(char *arg)
{
	const char	*progname = ft_progname();

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
