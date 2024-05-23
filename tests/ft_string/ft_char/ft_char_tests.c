/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:31:03 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/23 16:35:35 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/char_tests.h"
#include "tests/tests.h"
#include <string.h>

int	char_tests(void)
{
	int				i;
	const t_test	tests[] = {
	{"ft_isalnum", test_ft_isalnum}, {"ft_isalpha", test_ft_isalpha},
	{"ft_isascii", test_ft_isascii}, {"ft_isdigit",	test_ft_isdigit},
	{"ft_isprint", test_ft_isprint}, {"ft_tolower", test_ft_tolower},
	{"ft_toupper", test_ft_toupper}, {"ft_isalnum",	test_ft_isalnum},
	{"ft_putchar", test_ft_putchar}, {"ft_ishexdigit", test_ft_ishexdigit},
	{"ft_isoctdigit", test_ft_isoctdigit}, {"ft_isspace", test_ft_isspace},
	{NULL, NULL}
	};

	i = 0;
	run_test(tests, &i);
	return (i);
}
