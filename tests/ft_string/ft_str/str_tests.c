/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:39:29 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 00:55:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/str__str_tests.h"
#include "tests/tests.h"
#include <stddef.h>

static const t_test	*load_tests(void)
{
	static t_test tb[] = {{"putstr", test_putstr}, {"putendl", test_putendl},
	{"putnbr", test_putnbr}, {"itoa", test_itoa}, {"utoa", test_utoa}, \
	{"itoa_base", test_itoa_base}, {"atoi", test_atoi}, {"atoi_base", \
	test_atoi_base}, {"strtok", test_strtok}, {"split", test_split},
	{"splits", tests_splits}, {"strchr", test_strchr}, {"strdup", \
	test_strdup}, {"striteri", test_striteri}, {"strjoin", test_strjoin}, \
	{"strlcat", test_strlcat}, {"strlcpy", test_strlcpy}, {"strlen", \
	test_strlen}, {"strmapi", test_strmapi}, {"strcmp", test_strcmp}, \
	{"strncmp", test_strncmp}, {"strndup", test_strndup}, {"strnstr", \
	test_strnstr}, {"strrchr", test_strrchr}, {"strtrim", test_strtrim}, \
	{"substr", test_substr}, {"replace", test_str_replace}, \
	{"replace_chr", test_str_replace_chr}, {"shift_args", \
	test_shift_args}, {"gnl", test_gnl}, {"atof", test_atof}, \
	{"isalpha", test_str_isalpha}, {"isbool", test_str_isbool}, \
	{"alnum", test_str_isalnum}, {"isdigit", test_str_isdigit}, \
	{"isdouble", test_str_isdouble}, {"test_str_ishex", test_str_ishex}, \
	{"islong", test_str_islong}, {"isnum", test_str_isnum}, \
	{"isoct", test_str_isoct}, {"isint", test_str_isint}, \
	{"isfloat", test_str_isfloat}, {"isvalid", test_str_isvalid}, \
	{NULL, NULL}};

	return (tb);
}

int	str_tests(void)
{
	int				collect;
	const t_test	*tests = load_tests();

	collect = 0;
	run_test(tests, &collect);
	return (collect);
}
