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

// #include <limits.h>
// #include <errno.h>
// #include <stddef.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <strings.h>
// #include <unistd.h>
// #include <string.h>
// #include <time.h>
// #include <fcntl.h>
// #include <math.h>

#include "ft_list.h"
#include "types/ft_list_types.h"
#define FT_CLASSIC_COLORS
#include "ft_colors.h"
#include "ft_allocator__dev.h"
#include "ft_arr.h"
#include "ft_defs.h"
#include "ft_lib.h"
#include "ft_args.h"
#include "ft_arena.h"
#include "ft_mem.h"
#include "ft_string.h"
#include "sys/types.h"
#include "tests/fixtures.h"
#include "types/ft_args_types.h"

// -------------
// iee754 tests
// -------------
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

// -------------
// lseek test
// -------------
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

// -------------
// quick strjustify test
// -------------
//
//int	main(int ac, char **av) {
//	if (ac < 2)
//		return (printf("./p <long line>\n"), EXIT_FAILURE);
//
//	char *str = ft_strdup(av[1]);
//	ft_strwlgn_inplace(str, 5);
//	printf("%s",str);
//	char **tb = ft_split(str, '\n');
//
//	printf("\n\n");
//	for (size_t i = 0; tb[i]; i++)
//		printf("%zu:%03zu: `%s`\n", i, strlen(tb[i]), tb[i]);
//	ft_free(str);
//}
//
// const char *str = "hello earthlings, my name is zod the terrible "
// 	"prepare for my fury... i will send my goon to this supposed goon cave "
// 	"you speak of! for I the great zod will not leave a stone un-turned and"
// 	" not one hole unexplored. (if you still didn't get it, its a joke "
// 	"about sex, Mr. Goon Commander.)";
//
// char *rep = ft_strjustify(str, 40);
//
// printf("rep:\n%s\n", rep);
// ft_free(rep);

// --------------------
// -- person_t tests --
// --------------------
// #include <stddef.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
//
// typedef struct person {
// 	char *name;
// 	int	 non_unique_id;
// } person_t;
//
// static int	person_cmp_names(const void *p1, const void *p2)
// {
// 	return (ft_strcmp(((person_t *)p1)->name, ((person_t *)p2)->name));
// }
// static int	__attribute__((unused))
//			person_cmp_ids(const void *p1, const void *p2)
// {
// 	return ((*(person_t **)p1)->non_unique_id -
//		(*(person_t **)p2)->non_unique_id);
// }
// static int	__attribute__((unused))
//			person_cmp_to_ids(const void *p1, const void *id)
// {
// 	return ((*((person_t **) p1))->non_unique_id - *(int *)id);
// }
//
// static size_t	ptr_to_raw(const void *p)
// {
// 	return ((size_t)p);
// }
// static const char	*person_to_name(const void *p)
// {
// 	if (!p)
// 		return (NULL);
// 	return (((person_t *)p)->name);
// }
// static size_t	person_to_id(const void *p)
// {
// 	if (!p)
// 		return (0);
// 	return (((person_t *)p)->non_unique_id);
// }
// static int	cmp_person_id(const void *personA, const void *personB)
// {
// 	return (person_to_id(personA) - person_to_id(personB));
// }
// static int	cmp_person_name(const void *personA, const void *personB)
// {
// 	return (ft_strcmp(person_to_name(personA), person_to_name(personB)));
// }
//

// ----------------
// -- sort tests --
// ----------------
// #define	CARR_FOR(x, act)
// 	do {
// 		for (size_t i = 0; i < sizeof(x) / sizeof(*x); i++)
// 			act;
// 	} while (0);
//
//
// #define PRINT_TABL_S(x)
// 	CARR_FOR(x,
// 		printf("%3zu%c", x[i], i + 1 == sizeof(x) / sizeof(*x) ? '\n' : ' '))
//
// #define PRINT_TABL_SS(x)
// 	CARR_FOR(x,
// 		printf("%3zd%c",
// 			(ssize_t)x[i],	i + 1 == sizeof(x) / sizeof(*x) ? '\n' : ' '));
//
// #define PRINT_TABL_V(x)
// 	CARR_FOR(x,
// 			printf("%8p%c", x[i],
// 				i + 1 == sizeof(x) / sizeof(*x) ? '\n' : ' '));
//
// #define	RESET_TABLE(x, src)
// 	do {
// 		ft_memcpy(x, src, sizeof(*x) * sample_size);
// 	} while (0);
//
// #define	ALGO_CATEGORY_COLOR	FT_CGRN
// #define	TYPE_COLOR			FT_CYEL
// #define	ORDER_COLOR			FT_CCYN
//
// void	print_adresses(void *adr);
// void	print_adresses(void *adr)
// {
// 	printf("%p\t%zu\n", adr, (size_t)adr);
// }
//
//
// 	const int sample_size = 10;
// 	size_t	sarr_rand[sample_size];
// 	ssize_t arr_rand[sample_size];
// 	void	*adr_rand[sample_size];
//
// 	size_t	sarr[sample_size];
// 	size_t	arr[sample_size];
// 	void	*adr[sample_size];
//
// 	person_t	**sample;
//
//
// 	sample = (t_any)ft_aalloc(sample_size, sizeof(person_t *),
// 	sizeof(person_t));
// 	sample[0]->name = "Alice bbb"; sample[0]->non_unique_id = 3;
// 	sample[1]->name = "Alice aaa", sample[1]->non_unique_id = 3;
// 	sample[2]->name = "john aaa",  sample[2]->non_unique_id = 5;
// 	sample[3]->name = "john aaa",  sample[3]->non_unique_id = 6;
// 	sample[4]->name = "john bbb",  sample[4]->non_unique_id = 5;
// 	sample[5]->name = "john cca",  sample[5]->non_unique_id = 6;
// 	sample[6]->name = "john ccb",  sample[6]->non_unique_id = 1;
// 	sample[7]->name = "john ccc",  sample[7]->non_unique_id = 32;
// 	sample[8]->name = "john aaa",  sample[8]->non_unique_id = 96;
// 	sample[9]->name = "john aaa",  sample[9]->non_unique_id = 69;
//
//
// 	unsigned int seed =  1758453962; //time(NULL);
// 	printf("rand seed: %u\n", seed);
// 	srand(seed);
// 	for (size_t i = 0; i < sizeof(sarr_rand) / sizeof(*sarr_rand); i++)
// 		sarr_rand[i] = (rand() % 100) - 50;
// 	for (size_t i = 0; i < sizeof(arr_rand) / sizeof(*arr_rand); i++)
// 		arr_rand[i] = rand() % 100;
// 	for (size_t i = 0; i < sizeof(adr_rand) / sizeof(*adr_rand); i++)
// 		adr_rand[i] = (void *)((size_t)rand() % 100);
// 	t_sort_order	orders[2] = {FT_SORT_ORD_ASC, FT_SORT_ORD_DES};
// 	const char		*orders_str[] = {"Ascending", "Descending"};
//
// 	RESET_TABLE(sarr, sarr_rand);
// 	RESET_TABLE(arr, arr_rand);
// 	RESET_TABLE(adr, adr_rand);
// 	printf(ALGO_CATEGORY_COLOR "bubble sort:\n" FT_C_RESET);
// 	{
// 		printf(TYPE_COLOR "\t-size_t version:\n" FT_C_RESET);
// 		{
// 			PRINT_TABL_S(arr);
// 			printf(ORDER_COLOR "Sorting in %s order:\n" FT_C_RESET,
//				orders_str[0]);
// 			ft_sbblsort(arr, sizeof(arr) / sizeof(*arr), orders[0]);
// 			PRINT_TABL_S(arr);
// 			printf(ORDER_COLOR "Sorting in %s order:\n" FT_C_RESET,
//				orders_str[1]);
// 			ft_sbblsort(arr, sizeof(arr) / sizeof(*arr), orders[1]);
// 			PRINT_TABL_S(arr);
// 		}
// 		printf(TYPE_COLOR "\t-ssize_t version:\n" FT_C_RESET);
// 		{
// 			PRINT_TABL_SS(sarr);
// 			printf(ORDER_COLOR "Sorting in %s order:\n" FT_C_RESET,
//				orders_str[0]);
// 			ft_ssbblsort((ssize_t *)sarr, sizeof(sarr) / sizeof(*sarr),
//				orders[0]);
// 			PRINT_TABL_SS(sarr);
// 			printf(ORDER_COLOR "Sorting in %s order:\n" FT_C_RESET,
//				orders_str[1]);
// 			ft_ssbblsort((ssize_t *)sarr, sizeof(sarr) / sizeof(*sarr),
//				orders[1]);
// 			PRINT_TABL_SS(sarr);
// 		}
// 		printf(TYPE_COLOR "\t-void* version:\n" FT_C_RESET);
// 		{
// 			PRINT_TABL_V(adr);
// 			printf(ORDER_COLOR "Sorting in %s order:\n" FT_C_RESET,
//				orders_str[0]);
// 			ft_bblsort(adr, (t_arrinfo){sizeof(adr) / sizeof(*adr),
//				sizeof(*adr)},
// 				(t_data_cmp)ft_cmp_szt_p, orders[0]);
// 			PRINT_TABL_V(adr);
// 			printf(ORDER_COLOR "Sorting in %s order:\n" FT_C_RESET,
//				orders_str[1]);
// 			ft_bblsort(adr, (t_arrinfo){sizeof(adr) / sizeof(*adr),
//				sizeof(*adr)},
// 				(t_data_cmp)ft_cmp_szt_p, orders[1]);
// 			PRINT_TABL_V(adr);
// 		}
// 		printf("\n\n\n");
// 	}
//
// 	RESET_TABLE(sarr, sarr_rand);
// 	RESET_TABLE(arr, arr_rand);
// 	RESET_TABLE(adr, adr_rand);
// 	printf(ALGO_CATEGORY_COLOR "bucket sort:\n" FT_C_RESET);
// 	{
// 		printf(TYPE_COLOR "\t-size_t version:\n" FT_C_RESET);
// 		{
// 			PRINT_TABL_S(arr);
// 			printf(ORDER_COLOR "Sorting in %s order:\n" FT_C_RESET,
//				orders_str[0]);
// 			ft_sbcksort(arr, sizeof(arr) / sizeof(*arr), orders[0]);
// 			PRINT_TABL_S(arr);
// 			printf(ORDER_COLOR "Sorting in %s order:\n" FT_C_RESET,
//				orders_str[1]);
// 			ft_sbcksort(arr, sizeof(arr) / sizeof(*arr), orders[1]);
// 			PRINT_TABL_S(arr);
// 		}
// 		printf(TYPE_COLOR "\t-ssize_t version:\n" FT_C_RESET);
// 		printf(TYPE_COLOR "\t-void* version:\n" FT_C_RESET);
// 			printf(FT_C_INFO "ssize_t + void* version not implemented.\n"
// 			FT_C_RESET);
// 		printf("\n\n\n");
// 	}
//
// 	RESET_TABLE(sarr, sarr_rand);
// 	RESET_TABLE(arr, arr_rand);
// 	RESET_TABLE(adr, adr_rand);
// 	printf(ALGO_CATEGORY_COLOR "isrt_sort:\n" FT_C_RESET);
// 	{
// 		printf(TYPE_COLOR "\t-size_t version:\n" FT_C_RESET);
// 		{
// 			PRINT_TABL_S(arr);
// 			printf(ORDER_COLOR "Sorting in %s order:\n" FT_C_RESET,
// 			orders_str[0]);
// 			ft_sisrtsort(arr, sizeof(arr) / sizeof(*arr), orders[0]);
// 			PRINT_TABL_S(arr);
// 			printf(ORDER_COLOR "Sorting in %s order:\n" FT_C_RESET,
// 			orders_str[1]);
// 			ft_sisrtsort(arr, sizeof(arr) / sizeof(*arr), orders[1]);
// 			PRINT_TABL_S(arr);
// 		}
// 		printf(TYPE_COLOR "\t-ssize_t version:\n" FT_C_RESET);
// 		{
// 			PRINT_TABL_SS(sarr);
// 			printf(ORDER_COLOR "%s order:\n" FT_C_RESET, orders_str[0]);
// 			ft_ssisrtsort((ssize_t *)sarr, sizeof(sarr) / sizeof(*sarr),
//				orders[0]);
// 			PRINT_TABL_SS(sarr);
// 			printf(ORDER_COLOR "%s order:\n" FT_C_RESET, orders_str[1]);
// 			ft_ssisrtsort((ssize_t *)sarr, sizeof(sarr) / sizeof(*sarr),
// 			orders[1]);
// 			PRINT_TABL_SS(sarr);
// 		}
// 		printf(TYPE_COLOR "\t-void* version:\n" FT_C_RESET);
// 		{
// 			PRINT_TABL_V(adr);
// 			printf(ORDER_COLOR "Sorting in %s order:\n" FT_C_RESET,
// 			orders_str[0]);
// 			ft_isrtsort(adr, (t_arrinfo){
// 				.nmemb = sizeof(adr) / sizeof(*adr),
// 				.sz = sizeof(*adr)}, (t_data_cmp)ft_cmp_szt_p, orders[0]);
// 			PRINT_TABL_V(adr);
// 			printf(ORDER_COLOR "Sorting in %s order:\n" FT_C_RESET,
// 			orders_str[1]);
// 			ft_isrtsort(adr, (t_arrinfo){sizeof(adr) / sizeof(*adr),
// 			sizeof(*adr)},
// 				(t_data_cmp)ft_cmp_szt_p, orders[1]);
// 			PRINT_TABL_V(adr);
// 		}
// 		printf("\n\n\n");
// 	}
//
//
// 	// printf("\n\n\n");
// 	// printf(FT_CYEL "tests on real structures:\n" FT_C_RESET);
// 	// printf("\t REAL struct test: (person_t)\n");
// 	//
// 	// printf("abin srchs:\n");
// 	// printf("seraching elem: [%d] aka %s %d\n", 42 % sample_size,
// 	// 	sample[42 % sample_size]->name,
//		sample[42 % sample_size]->non_unique_id);
// 	// printf("&sample[idx found]: %p\n", &sample[42 % sample_size]);
// 	// printf("sample[idx found]: %p\n", sample[42 % sample_size]);
// 	// int aaaa = (int)ft_binsrch(sample, (t_arrinfo){sample_size,
//		sizeof(*sample)}, &sample[42 % sample_size], person_cmp_ids);
// 	// printf("idx found:%d\n", aaaa);
// 	// printf("\n");
// 	// printf("\n");
// 	// printf("\n");
// 	//
// 	// int id = sample[42 % sample_size]->non_unique_id;
// 	// printf("seraching id: %d\n", id);
// 	// int bbbb = (int)ft_binsrch(sample,
// 	// 					   (t_arrinfo){sample_size, sizeof(*sample)},
//							&id, person_cmp_to_ids);
// 	// printf("idx found:%d\n", bbbb);
// 	//
// 	// printf("sample nb\t id\t name\tptr\n");
// 	// for (size_t i = 0; i < sample_size; i++)
// 	// {
// 	// 	printf("sample[%zu]\t%d\t%s\t%p\n", i, sample[i]->non_unique_id,
//			sample[i]->name,
// 	// 	 &sample[i]);
// 	// }
// 	// printf("\n\n");
// 	// // ft_bblsort
// 	// ft_isrtsort
// 	// 	(sample, (t_arrinfo){sample_size, sizeof(*sample)}, person_cmp_ids,
// 	FT_SORT_ORD_ASC);
// 	//
// 	// printf("sample nb\t id\t name\tptr\n");
// 	// for (size_t i = 0; i < sample_size; i++)
// 	// {
// 	// 	printf("sample[%zu]\t%d\t%s\t%p\n", i, sample[i]->non_unique_id,
// 	sample[i]->name,
// 	// 	 &sample[i]);
// 	// }
// 	// printf("\n\n");
// 	ft_anfree((t_any)sample, sample_size);
//
// // 	printf("\n\n\n");
// // 	printf("\t-person tests:\n");
// // //	shuffle(sample, 5);
// // 	for (int i = sample_size * ft_max(ft_log(sample_size), 10); i; i--)
// // 	{
// // 		size_t a, b;
// // 		a = rand() % sample_size;
// // 		b = rand() % sample_size;
// // 		void *tmp = sample[a];
// // 		sample[a] = sample[b];
// // 		sample[b] = tmp;
// //
// // 	}
// // 	for (size_t i = 0; i < sample_size ; i++)
// // 		printf("n:%s\ta:%d\n", sample[i]->name, sample[i]->non_unique_id);
// // 	printf("---\n");
// // 	ft_bblsort((t_iconst_arr)sample, sample_size, cmp_person_id, order);
// // 	for (size_t i = 0; i < sample_size ; i++)
// // 		printf("n:%s\ta:%d\n", sample[i]->name, sample[i]->non_unique_id);
// // 	printf("---\n");
// // 	ft_bblsort((t_iconst_arr)sample, sample_size, cmp_person_name, order);
// // 	for (size_t i = 0; i < sample_size ; i++)
// // 		printf("n:%s\ta:%d\n", sample[i]->name, sample[i]->non_unique_id);
// //
//

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
