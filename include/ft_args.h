/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:42:28 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/21 19:05:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARGS_H
# define FT_ARGS_H

// Change version with -DVERSION="x.y.z-W" via Makefile
# ifndef VERSION
#  define VERSION "1.0.0"
# endif

# include <sys/types.h>
# include "ft_args_types.h"

/* @file: src/ft_args/parse_short_opt.c */
ssize_t		parse_short_opt(char *str_op, const t_opt *opt_list);

/* @file: src/ft_args/ft_arg_custom_checker.c */
void		ft_arg_set_custom_checker(int (*custom_checker)(char *));
int			(*ft_arg_get_custom_checker(void))(char *arg);

/* @file: src/ft_args/run_opt_func.c */
int			run_opt_func(const t_opt opt, void *usr_control_struct, char **arg,
				int *i);

/* @file: src/ft_args/checker_arg.c */
int			checker_arg(t_opt_type type, char *arg);

/* @file: src/ft_args/ft_parse_long.c */
ssize_t		parse_long_opt(char *str_op, const t_opt *opt_list);

/* @file: src/ft_args/ft_setup_prog.c */
void		ft_setup_prog(char **av);

/* @file: src/ft_args/arg_err.c */
int			arg_type_err(t_opt opt, char *arg);
int			arg_opt_err(char *arg);

/// @file: src/ft_args/ft_parse_args
int			ft_parse_args(char **argv, void *usr_control_struct);

void		ft_set_opt_list(const t_opt *opt_list);
const t_opt	*ft_get_opt_list(void);

void		ft_set_progname(const char *program_name);
const char	*ft_progname(void);

void		ft_set_version(const char *version);
const char	*ft_progversion(void);
#endif
