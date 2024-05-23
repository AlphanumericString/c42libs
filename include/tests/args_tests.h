/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_test.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:39:19 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/23 22:42:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_TEST_H
# define ARGS_TEST_H

/* @file: tests/ft_args/args_tests.c */
int	parse_args_test(void);
int	getset_opt_list_test(void);
int	tests_args(void);

/* @file: tests/ft_args/test_version.c */
int	getset_version_test(void);

/* @file: tests/ft_args/test_progname.c */
int	getset_program_name_test(void);

#endif /* ARGS_TEST_H */
