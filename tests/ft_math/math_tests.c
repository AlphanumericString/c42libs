/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:16:35 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/26 12:35:16 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/math_tests.h"

int	tests_math(void)
{
	int				i;
	const t_test	tests[] = {
	{"ft_abs", test_ft_abs}, {"ft_clamp", test_ft_clamp}, {"ft_complex_abs", \
		test_ft_complex_abs}, {"ft_complex_addl", test_ft_complex_addl},
	{"ft_complex_mull", test_ft_complex_mull}, {"ft_complex_muld", \
		test_ft_complex_muld}, {"ft_range", test_ft_range}, {"ft_range_f", \
		test_ft_range_f}, {"ft_range_d", test_ft_range_d}, {"ft_log", \
		test_ft_log}, {"ft_llogof", test_ft_llogof}, {"ft_ullogof", \
		test_ft_ullogof}, {"ft_logof", test_ft_logof}, {"ft_min", test_ft_min},
	{"ft_max", test_ft_max}, {"ft_pow", test_ft_pow}, {"ft_round", \
		test_ft_round}, {"ft_sqrt", test_ft_sqrt}, {NULL, NULL}};

	i = 0;
	run_test(tests, &i);
	return (i);
}
