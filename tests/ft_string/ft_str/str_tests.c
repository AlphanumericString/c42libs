/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:39:29 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/28 09:10:30 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/str__str_tests.h"
#include "tests/tests.h"
#include <stddef.h>

int	str_tests(void)
{
	int				collect;
	const t_test	tests[] = {
	{"putstr", test_putstr}, {"putendl", test_putendl}, {"putnbr", \
		test_putnbr}, {"itoa", test_itoa}, {"utoa", test_utoa}, {"itoa_base",
		test_itoa_base}, {"atoi", test_atoi}, {"atoi_base", test_atoi_base},
	{"strtok", test_strtok}, {"split", test_split}, {"splits", tests_splits},
	{"strchr", test_strchr}, {"strdup", test_strdup}, {"striteri", \
		test_striteri}, {"strjoin", test_strjoin}, {"strlcat", test_strlcat},
	{"strlcpy", test_strlcpy}, {"strlen", test_strlen}, {"strmapi", \
		test_strmapi}, {"strcmp", test_strcmp}, {"strncmp", test_strncmp},
	{"strndup", test_strndup}, {"strnstr", test_strnstr}, {"strrchr", \
		test_strrchr}, {"strtrim", test_strtrim}, {"substr", test_substr},
	{"str_replace", test_str_replace}, {"str_replace_chr", \
		test_str_replace_chr}, {"shift_args", test_shift_args}, {"gnl", \
		test_gnl}, {"test_atof", test_atof},
	{NULL, NULL}};

	collect = 0;
	run_test(tests, &collect);
	return (collect);
}
