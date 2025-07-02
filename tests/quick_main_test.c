/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_main_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:04:13 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/20 14:51:45 by bgoulard         ###   ########.fr       */
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
#include "ft_arena.h"
#include "types/ft_args_types.h"

// iee754 tests
//
// typedef struct s_dbl_fields
// {
// 	unsigned long	mantissa : 52;
// 	unsigned long	exponent : 11;
// 	unsigned int	sign : 1;
// }					t_dbl_fields;
//
// typedef union s_double_explicit
// {
// 	double			value;
// 	t_dbl_fields	fields;
// }			t_double_explicit;
//
//
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

// lseek test
// {
// 	char buffer[256 + 1] = {0};
// 	int fd = open("./test.txt", O_RDONLY | O_CLOEXEC);
// 	int ret;
//
// 	if (fd < 0)
// 		return (perror("Failed to open file"), EXIT_FAILURE);
// 	ret = read(fd, buffer, 256);
// 	if (ret < 0) {
// 		return (perror("Failed to read file"), EXIT_FAILURE);
// 	}
// 	buffer[ret] = '\0'; // Null-terminate the string
// 	printf("Read %d bytes: %s\n", ret, buffer);
// 	lseek(fd, 0, SEEK_SET);
// 	ret = read(fd, buffer, 256);
// 	if (ret < 0) {
// 		return (perror("Failed to read file again"), EXIT_FAILURE);
// 	}
// 	buffer[ret] = '\0'; // Null-terminate the string
// 	printf("Read again %d bytes: %s\n", ret, buffer);
// 	close(fd);
//
// 	FILE *file = fopen("./test.txt", "r");
// 	char buffer_2[256 + 1] = {0};
// 	if (!file) return (perror("Failed to open file with fopen"), EXIT_FAILURE);
// 	printf("File opened: %p\n", file);
// 	while (fgets(buffer_2, sizeof(buffer_2), file) != NULL)
//		{ printf("Read line: %s", buffer_2); }
// 	if (ferror(file)) {
// 		fclose(file);
// 		return (perror("Error reading file with fgets"), EXIT_FAILURE);
// 	}
// 	if (feof(file)) printf("End of file reached.\n");
// 	else printf("File not fully read.\n");
// 	return (fclose(file), EXIT_SUCCESS);
// }

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	return (EXIT_SUCCESS);
}
/*
GPL-3.0 License:
c42libs - Library for c projects at 42.
Copyright (C) 2025  baptiste GOULARD

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
