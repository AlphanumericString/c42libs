/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:39:27 by bgoulard          #+#    #+#             */
/*   Updated: 2024/01/07 20:57:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "ft_string.h"
#include <string.h>
#include <stdint.h>

static int cmp_int(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int test_bzero(void)
{
	char str[10] = "123456789";
	char str2[10] = "123456789";

	ft_bzero(str, 10);
	bzero(str2, 10);
	if (memcmp(str, str2, 10) != 0)
		return (1);
	return (0);
}

int test_calloc(void)
{
	char *str;
	char *str2;

	str = ft_calloc(10, sizeof(char));
	str2 = calloc(10, sizeof(char));
	if (memcmp(str, str2, 10) != 0)
		return (1);
	free(str);
	free(str2);

	str = ft_calloc(0, sizeof(char));
	str2 = calloc(0, sizeof(char));
	if (memcmp(str, str2, 0) != 0)
		return (printf("got %p, expected %p\n", str, str2), 2);
	free(str);
	free(str2);

	str = ft_calloc(SIZE_MAX, SIZE_MAX);
	str2 = calloc(SIZE_MAX, SIZE_MAX);
	if (str != NULL || str2 != NULL)
		return (3);
	return (0);
}

int test_realloc(void)
{
	char *str;
	char *str2;

	str = ft_calloc(10, sizeof(char));
	str2 = calloc(10, sizeof(char));

	str = ft_realloc(str, 20, 10);
	str2 = realloc(str2, 20);

	memset(str, 'a', 20);
	memset(str2, 'a', 20);
	if (memcmp(str, str2, 20) != 0)
		return (printf("got %s, expected %s\n", str, str2), 1);
	free(str);
	free(str2);
	
	str = ft_calloc(10, sizeof(char));
	str2 = calloc(10, sizeof(char));

	str = ft_realloc(str, 2, 10);
	str2 = realloc(str2, 2);
	memset(str, 'a', 2);
	memset(str2, 'a', 2);
	if (memcmp(str, str2, 2) != 0)
		return (printf("got %s, expected %s\n", str, str2), 2);
	free(str);
	free(str2);
	return (0);
}

int test_free(void)
{
	char *str;

	str = ft_calloc(10, sizeof(char));
	ft_free((void **)&str);
	if (str != NULL)
		return (1);
	return (0);
}

int test_memchr(void)
{
	char str[] = {'1', '2', '3', '4', '5', '6', '7', '\0', '9', '\0'};

	if (ft_memchr(str, '1', 10) != memchr(str, '1', 10))
		return (1);
	if (ft_memchr(str, '5', 10) != memchr(str, '5', 10))
		return (2);
	if (ft_memchr(str, '9', 10) != memchr(str, '9', 10))
		return (3);
	if (ft_memchr(str, '0', 10) != memchr(str, '0', 10))
		return (4);
	if (ft_memchr(str, 'a', 10) != memchr(str, 'a', 10))
		return (5);
	if (ft_memchr(str, 'A', 10) != memchr(str, 'A', 10))
		return (6);
	if (ft_memchr(str, '\0', 10) != memchr(str, '\0', 10))
		return (7);
	return (0);
}

int test_memcmp(void)
{
	char str[] = {'1', '2', '3', '4', '5', '6', '7', '\0', '9', '\0'};
	char str2[] = {'1', '2', '3', '4', '5', '6', '7', '\0', '9', '\0'};
	char str3[] = {'1', '2', '3', '4', '5', '6', '7', '\0', 'a', '\0'};
	char str4[] = {'1', '2', '3', '4', '5', '6', 'a', '\0', '9', '\0'};

	if (ft_memcmp(str, str2, 10) != memcmp(str, str2, 10))
		return (1);
	if (ft_memcmp(str, str3, 10) != memcmp(str, str3, 10))
	{
		if (!(ft_memcmp(str, str3, 10) < 0 && memcmp(str, str3, 10) < 0))
			return (2);
	}
	if (ft_memcmp(str, str2, 0) != memcmp(str, str2, 0))
		return (3);
	if (ft_memcmp(str, str4, 10) != memcmp(str, str4, 10))
		return (4);
	return (0);
}

int test_memcpy(void)
{
	char str[10] = "123456789";
	char str2[10] = "123456789";
	char str3[10] = {'1', '2', '3', '4', '5', '6', '7', '\0', '9', '\0'};

	ft_memcpy(str, "abc", 10);
	memcpy(str2, "abc", 10);
	if (memcmp(str, str2, 10) != 0)
		return (1);
	
	ft_memcpy(str, str3, 10);
	memcpy(str2, str3, 10);
	if (memcmp(str, str2, 10) != 0)
		return (2);
	
	return (0);
}

int test_memmove(void)
{
	char str[10] = "123456789";
	char str2[10] = "123456789";
	char str3[10] = {'1', '2', '3', '4', '5', '6', '7', '\0', '9', '\0'};

	ft_memmove(str, "abc", 10);
	memmove(str2, "abc", 10);
	if (memcmp(str, str2, 10) != 0)
		return (1);
	
	ft_memmove(str, str3, 10);
	memmove(str2, str3, 10);
	if (memcmp(str, str2, 10) != 0)
		return (2);
	
	ft_memmove(str, str + 2, 5);
	memmove(str2, str2 + 2, 5);
	if (memcmp(str, str2, 10) != 0)
		return (3);
	
	ft_memmove(str + 2, str, 5);
	memmove(str2 + 2, str2, 5);
	if (memcmp(str, str2, 10) != 0)
		return (4);
	
	return (0);
}

// ignore warning for memset args
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmemset-transposed-args"

int test_memset(void)
{
	char str[10] = "123456789";
	char str2[10] = "123456789";

	ft_memset(str, 'a', 10);
	memset(str2, 'a', 10);
	if (memcmp(str, str2, 10) != 0)
		return (1);
	ft_memset(str, 'b', 0);
	if (memcmp(str, str2, 10) != 0)
		return (2);
	ft_memset(str, 'c', 5);
	memset(str2, 'c', 5);
	if (memcmp(str, str2, 10) != 0)
		return (3);
	return (0);
}

#pragma clang diagnostic pop

int test_swap(void)
{
	int *a, *b;
	int *c, *d;
	int tmp_int;

	a = malloc(sizeof(int));
	b = malloc(sizeof(int));
	c = malloc(sizeof(int));
	d = malloc(sizeof(int));

	*a = 1;
	*c = 1;
	*b = 2;
	*d = 2;
	ft_swap((void **)&a, (void **)&b);
	tmp_int = *c;
	*c = *d;
	*d = tmp_int;
	if (*a != *c || *b != *d)
		return (1);
	
	free(a);
	free(b);
	free(c);
	free(d);
	return (0);
}

int test_qsort(void)
{
	(void)cmp_int;	// unused
	// non stable
// 	int tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 9};
// 	int tab2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 9};
// 	int tab3[10] = {1, 256, 3, 4, -6, 7, 81, 10, 9};
// 	int tab4[10] = {1, 256, 3, 4, -6, 7, 81, 10, 9};

// 	ft_qsort(tab, 10, sizeof(int), cmp_int);
// 	qsort(tab2, 10, sizeof(int), cmp_int);
// 	if (memcmp(tab, tab2, 10) != 0)
// 		return (1);

// 	ft_qsort(tab3, 10, sizeof(int), cmp_int);
// 	qsort(tab4, 10, sizeof(int), cmp_int);
// 	if (memcmp(tab3, tab4, 10) != 0)
// 		return (2);
	return (0);
}

int mem_tests(void)
{
	int collect = 0;
	t_test tests[] = {
		{"test_bzero", test_bzero},
		{"test_calloc", test_calloc},
		{"test_realloc", test_realloc},
		{"test_free", test_free},
		{"test_memchr", test_memchr},
		{"test_memcmp", test_memcmp},
		{"test_memcpy", test_memcpy},
		{"test_memmove", test_memmove},
		{"test_memset", test_memset},
		{"test_swap", test_swap},
		{"test_qsort", test_qsort},
		{NULL, NULL}
	};

	collect = 0;
	run_test(tests, &collect);
	return (collect);
}
