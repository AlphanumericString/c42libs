/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:39:25 by bgoulard          #+#    #+#             */
/*   Updated: 2024/01/07 10:20:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tests/tests.h"
#include "ft_string.h"

int test_string_new(void)
{
	t_string *str;

	str = ft_string_new(42);
	if (str->str == NULL)
		return (1);
	if (str->length != 0)
		return (2);
	if (str->capacity == 0)
		return (3);
	ft_string_destroy(&str);
	return (0);
}

int test_string_from(void)
{
	t_string *str;

	str = ft_string_from("Hello World");
	if (ft_string_cmp(str, "Hello World") != 0)
		return (1);
	if (str->length != 11)
		return (2);
	if (str->capacity < 11)
		return (3);
	ft_string_destroy(&str);
	return (0);
}

int test_string_from_n(void)
{
	t_string *str;

	str = ft_string_from_n("Hello World", 5);
	if (ft_string_cmp(str, "Hello") != 0)
		return (1);
	if (str->length != 5)
		return (2);
	if (str->capacity < 5)
		return (3);
	ft_string_destroy(&str);
	return (0);
}

int test_string_from_c(void)
{
	t_string *str;

	str = ft_string_from_c('c');
	if (ft_string_cmp(str, "c") != 0)
		return (1);
	if (str->length != 1)
		return (2);
	if (str->capacity < 1)
		return (3);
	ft_string_destroy(&str);
	return (0);
}

int test_string_append(void)
{
	t_string *str;

	str = ft_string_from("Hello");
	ft_string_append(str, " World");
	if (ft_string_cmp(str, "Hello World") != 0)
		return (1);
	if (str->length != 11)
		return (2);
	if (str->capacity < 11)
		return (3);
	ft_string_destroy(&str);
	return (0);
}

int test_string_append_n(void)
{
	t_string *str;

	str = ft_string_from("Hello");
	ft_string_append_n(str, " World", 5);
	if (ft_string_cmp(str, "Hello Worl") != 0)
		return (1);
	if (str->length != 10)
		return (2);
	if (str->capacity < 10)
		return (3);
	ft_string_destroy(&str);
	return (0);
}

int test_string_append_c(void)
{
	t_string *str;

	str = ft_string_from("Hello");
	ft_string_append_c(str, ' ');
	if (ft_string_cmp(str, "Hello ") != 0)
		return (1);
	if (str->length != 6)
		return (2);
	if (str->capacity < 6)
		return (3);
	ft_string_destroy(&str);
	return (0);
}

int test_string_append_s(void)
{
	t_string *str;
	t_string *str2;

	str = ft_string_from("Hello");
	str2 = ft_string_from(" World");
	ft_string_append_s(str, str2);
	if (ft_string_cmp(str, "Hello World") != 0)
		return (1);
	if (str->length != 11)
		return (2);
	if (str->capacity < 11)
		return (3);
	ft_string_destroy(&str);
	ft_string_destroy(&str2);
	return (0);
}

int test_string_append_s_n(void)
{
	t_string *str;
	t_string *str2;

	str = ft_string_from("Hello");
	str2 = ft_string_from(" World!!!!");
	ft_string_append_s_n(str, str2, 6);
	if (ft_string_cmp(str, "Hello World") != 0)
		return (1);
	if (str->length != 11)
		return (2);
	if (str->capacity < 11)
		return (3);
	ft_string_destroy(&str);
	ft_string_destroy(&str2);
	return (0);
}

int test_string_clear(void)
{
	t_string *str;
	size_t capacity;

	str = ft_string_from("Hello");
	capacity = str->capacity;
	ft_string_clear(str);
	if (ft_string_cmp(str, "") != 0)
		return (1);
	if (str->length != 0)
		return (2);
	if (str->capacity != capacity)
		return (3);
	ft_string_destroy(&str);
	return (0);
}

int test_string_destroy(void)
{
	t_string *str;

	str = ft_string_from("Hello");
	ft_string_destroy(&str);
	if (str != NULL)
		return (1);
	ft_string_destroy(&str); // null resiliancy
	ft_string_destroy(NULL); // null resiliancy
	return (0);
}

int test_string_insert(void)
{
	t_string *str;

	str = ft_string_from("Hello");
	ft_string_insert(str, " World", 0);
	if (ft_string_cmp(str, " WorldHello") != 0)
		return (1);
	if (str->length != 11)
		return (2);
	if (str->capacity < 11)
		return (3);
	ft_string_destroy(&str);
	return (0);
}

int test_string_insert_n(void)
{
	t_string *str;

	str = ft_string_from("Hello");
	ft_string_insert_n(str, " World", 0, 5);
	if (ft_string_cmp(str, " WorlHello") != 0)
		return (1);
	if (str->length != 10)
		return (2);
	if (str->capacity < 10)
		return (3);
	ft_string_destroy(&str);
	return (0);
}

int test_string_insert_c(void)
{
	t_string *str;

	str = ft_string_from("Hello");
	ft_string_insert_c(str, ' ', 0);
	if (ft_string_cmp(str, " Hello") != 0)
		return (1);
	if (str->length != 6)
		return (2);
	if (str->capacity < 6)
		return (3);
	ft_string_destroy(&str);
	return (0);
}

int test_string_insert_s(void)
{
	t_string *str;
	t_string *str2;

	str = ft_string_from("Hello");
	str2 = ft_string_from(" World");
	ft_string_insert_s(str, str2, 0);
	if (ft_string_cmp(str, " WorldHello") != 0)
		return (1);
	if (str->length != 11)
		return (2);
	if (str->capacity < 11)
		return (3);
	ft_string_destroy(&str);
	ft_string_destroy(&str2);
	return (0);
}

int test_string_insert_s_n(void)
{
	t_string *str;
	t_string *str2;

	str = ft_string_from("Hello");
	str2 = ft_string_from(" World!!!!");
	ft_string_insert_s_n(str, str2, 0, 5);
	if (ft_string_cmp(str, " WorlHello") != 0)
		return (1);
	if (str->length != 10)
		return (2);
	if (str->capacity < 10)
		return (3);
	ft_string_destroy(&str);
	ft_string_destroy(&str2);
	return (0);
}

int test_string_reserve(void)
{
	t_string *str;

	str = ft_string_from("Hello");
	ft_string_reserve(str, 42);
	if (ft_string_cmp(str, "Hello") != 0)
		return (1);
	if (str->length != 5)
		return (2);
	if (str->capacity < 42)
		return (3);
	ft_string_destroy(&str);
	return (0);
}

int test_string_resize(void)
{
	t_string *str;

	str = ft_string_from("Hello");
	ft_string_resize(str, 42);
	if (ft_string_cmp(str, "Hello") != 0)
		return (1);
	if (str->length != 5)
		return (2);
	if (str->capacity < 42)
		return (3);
	ft_string_destroy(&str);
	return (0);
}

int test_string_shrink(void)
{
	t_string *str;

	str = ft_string_from("Hello");
	ft_string_shrink(str);
	if (ft_string_cmp(str, "Hello") != 0)
		return (1);
	if (str->length != 5)
		return (2);
	if (str->capacity < 5)
		return (3);
	ft_string_destroy(&str);
	return (0);
}

int test_string_substr(void)
{
	t_string *str;
	t_string *sub;

	str = ft_string_from("Hello World");
	sub = ft_string_substr(str, 0, 6);
	if (sub == NULL)
		return (1);
	if (strcmp(sub->str, "Hello") != 0)
		return (2);
	if (sub->length != 5)
		return (3);
	if (sub->capacity < 5)
		return (4);
	ft_string_destroy(&str);
	ft_string_destroy(&sub);
	return (0);
}

int test_string_to_str(void)
{
	t_string *str;
	char *cstr;

	str = ft_string_from("Hello World");
	cstr = ft_string_to_str(str);
	if (strcmp(cstr, "Hello World") != 0)
		return (1);
	ft_string_destroy(&str);
	free(cstr);
	return (0);
}

int test_string_trim(void)
{
	t_string *str;

	str = ft_string_from("   Hello World   ");
	ft_string_trim(str);
	if (ft_string_cmp(str, "Hello World") != 0)
		return (1);
	if (str->length != 11)
		return (2);
	if (str->capacity < 11)
		return (3);
	ft_string_destroy(&str);
	return (0);
}

int test_string_trim_chr(void)
{
	t_string *str;

	str = ft_string_from("   Hello World   ");
	ft_string_trim_chr(str, ' ');
	if (ft_string_cmp(str, "Hello World") != 0)
		return (1);
	if (str->length != 11)
		return (2);
	if (str->capacity < 11)
		return (3);
	ft_string_destroy(&str);
	return (0);
}

int test_string_trimstr(void)
{
	t_string *str;

	str = ft_string_from("   Hello World   ");
	ft_string_trimstr(str, " d");
	if (ft_string_cmp(str, "Hello Worl") != 0)
		return (1);
	if (str->length != 10)
		return (2);
	if (str->capacity < 10)
		return (3);
	ft_string_destroy(&str);
	return (0);
}

int test_string_cmp(void)
{
	t_string *str;

	str = ft_string_from("Hello World");
	if (ft_string_cmp(str, "Hello World") != 0)
		return (1);
	if (ft_string_cmp(str, "Hello") == 0)
		return (2);
	if (ft_string_cmp(str, "Hello World!") == 0)
		return (3);
	ft_string_destroy(&str);
	return (0);
}

int test_string_cmp_n(void)
{
	t_string *str;

	str = ft_string_from("Hello World");
	if (ft_string_ncmp(str, "Hello World", 11) != 0)
		return (1);
	if (ft_string_ncmp(str, "Hello", 5) == 0)
		return (2);
	if (ft_string_ncmp(str, "Hello World!", 12) == 0)
		return (3);
	ft_string_destroy(&str);
	return (0);
}



int t_string_tests(void)
{
	int sum;
	t_test tests[] = {
		{"test_string_new", test_string_new},
		{"test_string_from", test_string_from},
		{"test_string_from_n", test_string_from_n},
		{"test_string_from_c", test_string_from_c},
		{"test_string_append", test_string_append},
		{"test_string_append_n", test_string_append_n},
		{"test_string_append_c", test_string_append_c},
		{"test_string_append_s", test_string_append_s},
		{"test_string_append_s_n", test_string_append_s_n},
		{"test_string_clear", test_string_clear},
		{"test_string_destroy", test_string_destroy},
		{"test_string_insert", test_string_insert},
		{"test_string_insert_n", test_string_insert_n},
		{"test_string_insert_c", test_string_insert_c},
		{"test_string_insert_s", test_string_insert_s},
		{"test_string_insert_s_n", test_string_insert_s_n},
		{"test_string_reserve", test_string_reserve},
		{"test_string_resize", test_string_resize},
		{"test_string_shrink", test_string_shrink},
		{"test_string_substr", test_string_substr},
		{"test_string_to_str", test_string_to_str},
		{"test_string_trim", test_string_trim},
		{"test_string_trim_chr", test_string_trim_chr},
		{"test_string_trimstr", test_string_trimstr},
		{"test_string_cmp", test_string_cmp},
		{"test_string_cmp_n", test_string_cmp_n},
		{NULL, NULL}
	};

	sum = 0;
	run_test(tests, &sum);
	return (sum);
}
