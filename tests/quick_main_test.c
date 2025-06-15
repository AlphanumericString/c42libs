/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_main_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:04:13 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/12 16:56:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <math.h>

#include "ft_lib.h"
#include "ft_args.h"
#include "types/ft_args_types.h"

// static double __attribute__((unused)) ieee754_to_double(t_dbl_fields f)
// {
//     double	sign = f.sign ? -1.0 : 1.0;
// 	int		exp;
// 	double	frac;
// 	double	frac_part;
//
// 	exp = 0;
// 	frac = 0.0;
// 	frac_part = (double)f.mantissa / (1ULL << 52);
// 	if (f.exponent == 2047) {
//         if (f.mantissa == 0)
//             return sign * INFINITY;
// 		return NAN;
// 	}
//     if (f.exponent == 0) {
//         frac = frac_part;
// 		exp = -1022;
//     } else {
//         frac = 1.0 + frac_part;
//         exp = f.exponent - 1023;
//     }
// 	return sign * frac * pow(2, exp);
// }

int	main(void)
{
	return (EXIT_SUCCESS);
}
