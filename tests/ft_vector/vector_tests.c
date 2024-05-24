/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:30:25 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 09:40:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "tests/tests.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static void	add42(void *data)
{
	int	*ptr;

	ptr = (int *)data;
	*ptr += 42;
}

static bool	is42(void *data)
{
	if (!data)
		return (false);
	return (*(int *)data == 42);
}

static void	*add42_ret(void *data)
{
	int	*ret;

	ret = malloc(sizeof(int));
	*ret = *(int *)data;
	*ret += 42;
	return ((void *)ret);
}

static int	cmp_int(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}

int	test_vec_add(void)
{
	t_vector	*vec;

	vec = ft_vec_new();
	ft_vec_add(&vec, (void *)42);
	if (vec->count != 1)
		return (1);
	if (vec->datas[0] != (void *)42)
		return (1);
	ft_vec_add(&vec, (void *)43);
	ft_vec_add(&vec, (void *)44);
	ft_vec_add(&vec, (void *)45);
	ft_vec_add(&vec, (void *)46);
	ft_vec_add(&vec, (void *)47);
	if (vec->count != 6)
		return (1);
	if (vec->datas[0] != (void *)42 || vec->datas[1] != (void *)43 || \
	vec->datas[2] != (void *)44 || vec->datas[3] != (void *)45 || \
	vec->datas[4] != (void *)46 || vec->datas[5] != (void *)47)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}

int	test_vec_apply(void)
{
	t_vector	*vec;
	int			i;

	i = 0;
	vec = ft_vec_new();
	ft_vec_add(&vec, &i);
	ft_vec_apply(vec, add42);
	if (*(int *)vec->datas[0] != 42)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}

int	test_vec_at(void)
{
	t_vector	*vec;
	int			a;
	int			b;
	int			c;

	a = 0;
	b = 1;
	c = 2;
	vec = ft_vec_new();
	ft_vec_add(&vec, &a);
	ft_vec_add(&vec, &b);
	ft_vec_add(&vec, &c);
	if (*(int *)ft_vec_at(vec, 0) != 0)
		return (1);
	else if (*(int *)ft_vec_at(vec, 1) != 1)
		return (1);
	else if (*(int *)ft_vec_at(vec, 2) != 2)
		return (1);
	else if (ft_vec_at(vec, 3) != NULL)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}

/*
	ft_vec_add(&vec_a, &a); // 42
	ft_vec_add(&vec_a, &b); // 42 43
	ft_vec_add(&vec_a, &c); // 42 43 44
	ft_vec_add(&vec_b, &d); // 45
	ft_vec_add(&vec_b, &e); // 45 46
	ft_vec_add(&vec_b, &f); // 45 46 47
	ret = ft_vec_cat(&vec_a, vec_b); // 42 43 44 + 45 46 47
	ft_vec_add(&vec_a, &a); // 42
	ft_vec_add(&vec_a, &b); // 42 43
	ft_vec_add(&vec_a, &c); // 42 43 44
	ret = ft_vec_cat(&vec_a, vec_b); // 42 43 44 + 45 46 47
*/

int	test_vec_cat(void)
{
	bool		ret;
	t_vector	*vec_a;
	t_vector	*vec_b;
	int			a, b, c, d, e, f;

	vec_a = ft_vec_from_size(6);
	vec_b = ft_vec_new();
	a = 42;
	b = 43;
	c = 44;
	d = 45;
	e = 46;
	f = 47;
	ft_vec_add(&vec_a, &a);
	ft_vec_add(&vec_a, &b);
	ft_vec_add(&vec_a, &c);
	ft_vec_add(&vec_b, &d);
	ft_vec_add(&vec_b, &e);
	ft_vec_add(&vec_b, &f);
	ret = ft_vec_cat(&vec_a, vec_b);
	if (ret != true)
		return (1);
	else if (vec_a->count != 6)
		return (1);
	else if (*(int *)ft_vec_at(vec_a, 0) != 42)
		return (1);
	else if (*(int *)ft_vec_at(vec_a, 1) != 43)
		return (1);
	else if (*(int *)ft_vec_at(vec_a, 2) != 44)
		return (1);
	else if (*(int *)ft_vec_at(vec_a, 3) != 45)
		return (1);
	else if (*(int *)ft_vec_at(vec_a, 4) != 46)
		return (1);
	else if (*(int *)ft_vec_at(vec_a, 5) != 47)
		return (1);
	ft_vec_destroy(&vec_a);
	vec_a = ft_vec_new();
	ft_vec_add(&vec_a, &a);
	ft_vec_add(&vec_a, &b);
	ft_vec_add(&vec_a, &c);
	ret = ft_vec_cat(&vec_a, vec_b);
	if (ret != false)
		return (1);
	else if (vec_a->count != 3)
		return (1);
	else if (*(int *)ft_vec_at(vec_a, 0) != 42)
		return (1);
	else if (*(int *)ft_vec_at(vec_a, 1) != 43)
		return (1);
	else if (*(int *)ft_vec_at(vec_a, 2) != 44)
		return (1);
	ft_vec_destroy(&vec_a);
	ft_vec_destroy(&vec_b);
	return (0);
}

int	test_vec_clear(void)
{
	t_vector	*vec;
	int			a;
	int			b;
	int			c;

	a = 0;
	b = 1;
	c = 2;
	vec = ft_vec_new();
	ft_vec_add(&vec, &a);
	ft_vec_add(&vec, &b);
	ft_vec_add(&vec, &c);
	ft_vec_clear(vec);
	if (vec->count != 0)
		return (1);
	else if (vec->cappacity == 0)
		return (1);
	else if (vec->datas[0] != NULL)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}

int	test_vec_destroy(void)
{
	t_vector	*vec;
	int			a;
	int			b;
	int			c;

	a = 0;
	b = 1;
	c = 2;
	vec = ft_vec_new();
	ft_vec_add(&vec, &a);
	ft_vec_add(&vec, &b);
	ft_vec_add(&vec, &c);
	ft_vec_destroy(&vec);
	if (vec != NULL)
		return (1);
	return (0);
}

int	test_vec_filter(void)
{
	t_vector	*vec;
	int			a;
	int			b;
	int			c;
	int			*pp[3];

	a = 42;
	b = 43;
	c = 44;
	vec = ft_vec_new();
	ft_vec_add(&vec, &a);
	ft_vec_add(&vec, &b);
	ft_vec_add(&vec, &c);
	ft_vec_filter(vec, is42, NULL);
	if (vec->count != 1)
		return (1);
	else if (*(int *)ft_vec_at(vec, 0) != 42)
		return (1);
	ft_vec_clear(vec);
	pp[0] = malloc(sizeof(int));
	*pp[0] = 21;
	pp[1] = malloc(sizeof(int));
	*pp[1] = 42;
	pp[2] = malloc(sizeof(int));
	*pp[2] = 63;
	ft_vec_add(&vec, pp[0]);
	ft_vec_add(&vec, pp[1]);
	ft_vec_add(&vec, pp[2]);
	ft_vec_filter(vec, is42, free);
	if (vec->count != 1)
		return (1);
	else if (ft_vec_at(vec, 0) != pp[1])
		return (1);
	ft_vec_apply(vec, free);
	ft_vec_destroy(&vec);
	return (0);
}

int	test_vec_map(void)
{
	t_vector	*vec;
	t_vector	*ret;
	int			a, b, c;

	a = 0;
	b = 1;
	c = 2;
	vec = ft_vec_new();
	ft_vec_add(&vec, &a);
	ft_vec_add(&vec, &b);
	ft_vec_add(&vec, &c);
	ret = ft_vec_map(vec, add42_ret);
	if (ret->count != 3)
		return (1);
	else if (*(int *)ft_vec_at(ret, 0) != 42)
		return (1);
	else if (*(int *)ft_vec_at(ret, 1) != 43)
		return (1);
	else if (*(int *)ft_vec_at(ret, 2) != 44)
		return (1);
	ft_vec_apply(ret, free); // allocated in add42_ret
	ft_vec_destroy(&vec);
	ft_vec_destroy(&ret);
	return (0);
}

int	test_vec_new(void)
{
	t_vector	*vec;

	vec = ft_vec_new();
	if (vec->count != 0)
		return (1);
	else if (vec->cappacity != FT_VECTOR_BASE_LEN)
		return (1);
	else if (vec->datas == NULL)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}

int	test_vec_from_size(void)
{
	t_vector	*vec;

	vec = ft_vec_from_size(42);
	if (vec->count != 0)
		return (1);
	else if (vec->cappacity != 42)
		return (1);
	else if (vec->datas == NULL)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}

// TODO: test_vec_from_array with bigger array to test the cappacity when
// 		it's bigger than FT_VECTOR_BASE_LEN
int	test_vec_from_array(void)
{
	void		*data[3];
	void		*data2[6];
	t_vector	*vec;
	int			a, b, c, d, e, f;

	a = 42;
	b = 43;
	c = 44;
	d = 45;
	e = 46;
	f = 47;
	data[0] = (void *)&a;
	data[1] = (void *)&b;
	data[2] = (void *)&c;
	//////// data2
	data2[0] = (void *)&a;
	data2[1] = (void *)&b;
	data2[2] = (void *)&c;
	data2[3] = (void *)&d;
	data2[4] = (void *)&e;
	data2[5] = (void *)&f;
	vec = ft_vec_from_array(data, sizeof(data) / sizeof(data[0]));
	if (vec->count != 3)
		return (1);
	else if (vec->cappacity != FT_VECTOR_BASE_LEN)
		return (1);
	else if (vec->datas == NULL)
		return (1);
	else if (*(int *)ft_vec_at(vec, 0) != 42)
		return (1);
	else if (*(int *)ft_vec_at(vec, 1) != 43)
		return (1);
	else if (*(int *)ft_vec_at(vec, 2) != 44)
		return (1);
	ft_vec_destroy(&vec);
	vec = ft_vec_from_array(data2, sizeof(data2) / sizeof(*data2));
	if (vec->count != 6)
		return (1);
	else if (vec->cappacity != 6)
		return (1);
	else if (vec->datas == NULL)
		return (1);
	else if (*(int *)ft_vec_at(vec, 0) != 42)
		return (1);
	else if (*(int *)ft_vec_at(vec, 1) != 43)
		return (1);
	else if (*(int *)ft_vec_at(vec, 2) != 44)
		return (1);
	else if (*(int *)ft_vec_at(vec, 3) != 45)
		return (1);
	else if (*(int *)ft_vec_at(vec, 4) != 46)
		return (1);
	else if (*(int *)ft_vec_at(vec, 5) != 47)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}

int	test_vec_convert_alloc_array(void)
{
	void		**data;
	t_vector	*vec;
	int			a, b, c;

	a = 42;
	b = 43;
	c = 44;
	data = malloc(sizeof(void *) * 3);
	data[0] = (void *)&a;
	data[1] = (void *)&b;
	data[2] = (void *)&c;
	vec = ft_vec_convert_alloccarray(data, 3);
	if (vec->count != 3)
		return (1);
	else if (vec->cappacity != 3)
		return (1);
	else if (vec->datas != data)
		return (1);
	else if (*(int *)ft_vec_at(vec, 0) != 42)
		return (1);
	else if (*(int *)ft_vec_at(vec, 1) != 43)
		return (1);
	else if (*(int *)ft_vec_at(vec, 2) != 44)
		return (1);
	ft_vec_destroy(&vec);
	//  free(data); -> segfault : double free or corruption.
	// 	ft_vec_convert_alloccarray takes ownership of the data. refert to the doc.
	return (0);
}

int	test_vec_remove(void)
{
	t_vector	*vec;
	int			a, b, c;
	int			*pa, *pb, *pc;

	a = 42;
	b = 43;
	c = 44;
	vec = ft_vec_new();
	ft_vec_add(&vec, &a);
	ft_vec_add(&vec, &b);
	ft_vec_add(&vec, &c);
	ft_vec_remove(vec, 1, NULL);
	if (vec->count != 2)
		return (1);
	else if (*(int *)ft_vec_at(vec, 0) != 42)
		return (1);
	else if (*(int *)ft_vec_at(vec, 1) != 44)
		return (1);
	// try to remoove outside of vector
	ft_vec_remove(vec, 42, NULL);
	if (vec->count != 2)
		return (1);
	ft_vec_destroy(&vec);
	// create vector of allocated ints
	// and try to call free on it.
	vec = ft_vec_new();
	pa = malloc(sizeof(int));
	pb = malloc(sizeof(int));
	pc = malloc(sizeof(int));
	*pa = a;
	*pb = b;
	*pc = c;
	ft_vec_add(&vec, pa);
	ft_vec_add(&vec, pb);
	ft_vec_add(&vec, pc);
	if (vec->count != 3)
		return (1);
	ft_vec_remove(vec, 1, free);
	if (vec->count != 2)
		return (1);
	if (ft_vec_at(vec, 0) != pa)
		return (1);
	if (ft_vec_at(vec, 1) != pc)
		return (1);
	ft_vec_apply(vec, free);
	ft_vec_destroy(&vec);
	return (0);
}

int	test_vec_remove_if(void)
{
	t_vector	*vec;
	int			a;
	int			b;
	int			c;

	a = 42;
	b = 43;
	c = 44;
	vec = ft_vec_new();
	ft_vec_add(&vec, &a);
	ft_vec_add(&vec, &b);
	ft_vec_add(&vec, &c);
	ft_vec_remove_if(vec, is42, NULL);
	if (vec->count != 2)
		return (1);
	else if (*(int *)ft_vec_at(vec, 0) != 43)
		return (1);
	else if (*(int *)ft_vec_at(vec, 1) != 44)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}

int	test_vec_reserve(void)
{
	t_vector	*vec;

	bool ret1, ret2, ret3;
	vec = ft_vec_from_size(FT_VECTOR_BASE_LEN - 1);
	ret1 = ft_vec_reserve(&vec, FT_VECTOR_BASE_LEN - 2);
	ret2 = ft_vec_reserve(&vec, FT_VECTOR_BASE_LEN);
	ret3 = ft_vec_reserve(&vec, FT_VECTOR_BASE_LEN + 2);
	if (ret1 != true)
		return (1);
	else if (ret2 != true)
		return (1);
	else if (ret3 == false)
		return (1);
	else if (vec->cappacity != FT_VECTOR_BASE_LEN + 2)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}

int	test_vec_reverse(void)
{
	t_vector	*vec;
	int			a;
	int			b;
	int			c;

	a = 42;
	b = 43;
	c = 44;
	vec = ft_vec_new();
	ft_vec_add(&vec, &a);
	ft_vec_add(&vec, &b);
	ft_vec_add(&vec, &c);
	ft_vec_shrink(vec);
	ft_vec_reverse(vec);
	if (vec->count != 3)
		return (1);
	else if (*(int *)ft_vec_at(vec, 0) != 44)
		return (1);
	else if (*(int *)ft_vec_at(vec, 1) != 43)
		return (1);
	else if (*(int *)ft_vec_at(vec, 2) != 42)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}

int	test_vec_shift(void)
{
	t_vector	*vec;
	int			a;
	int			b;
	int			c;
	int			d;

	a = 42;
	b = 43;
	c = 44;
	d = 45;
	vec = ft_vec_new();
	ft_vec_add(&vec, &a);
	ft_vec_add(&vec, &b);
	ft_vec_add(&vec, &c);
	ft_vec_add(&vec, &d);
	ft_vec_shift(vec, 1, 2);
	if (vec->count != 2)
		return (1);
	else if (*(int *)ft_vec_at(vec, 0) != 42)
		return (1);
	else if (*(int *)ft_vec_at(vec, 1) != 45)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}

int	test_vec_sort(void)
{
	t_vector	*vec;
	void		*data[3];
	int			a, b, c;

	a = 42;
	b = 43;
	c = 44;
	data[0] = (void *)&a;
	data[1] = (void *)&b;
	data[2] = (void *)&c;
	vec = ft_vec_from_array(data, sizeof(data) / sizeof(data[0]));
	// 44, 43, 42
	ft_vec_sort(vec, cmp_int);
	// 42, 43, 44
	if (vec->count != 3)
		return (1);
	else if (*(int *)ft_vec_at(vec, 0) != 42)
		return (1);
	else if (*(int *)ft_vec_at(vec, 1) != 43)
		return (1);
	else if (*(int *)ft_vec_at(vec, 2) != 44)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}

int	test_vec_shrink(void)
{
	t_vector	*vec;
	void		*data[3];
	int			a, b, c;

	a = 42;
	b = 43;
	c = 44;
	data[0] = (void *)&a;
	data[1] = (void *)&b;
	data[2] = (void *)&c;
	vec = ft_vec_from_array(data, sizeof(data) / sizeof(data[0]));
	ft_vec_shrink(vec);
	if (vec->count != 3)
		return (1);
	else if (vec->cappacity != 3)
		return (1);
	else if (*(int *)ft_vec_at(vec, 0) != 42)
		return (1);
	else if (*(int *)ft_vec_at(vec, 1) != 43)
		return (1);
	else if (*(int *)ft_vec_at(vec, 2) != 44)
		return (1);
	// try to shrink an already shrunk vector
	ft_vec_shrink(vec);
	if (!vec)
		return (1);
	else if (vec->count != vec->cappacity)
		return (1);
	else if (vec->count != 3)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}

int	test_vec_swap(void)
{
	t_vector	*vec;
	void		*data[3];
	int			a, b, c;

	a = 42;
	b = 43;
	c = 44;
	data[0] = (void *)&a;
	data[1] = (void *)&b;
	data[2] = (void *)&c;
	vec = ft_vec_from_array(data, sizeof(data) / sizeof(data[0]));
	ft_vec_swap(vec, 0, 2);
	if (vec->count != 3)
		return (1);
	else if (*(int *)ft_vec_at(vec, 0) != 44)
		return (1);
	else if (*(int *)ft_vec_at(vec, 1) != 43)
		return (1);
	else if (*(int *)ft_vec_at(vec, 2) != 42)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}

int	tests_vector(void)
{
	int				collect;
	const t_test	tests[] = {
	{"test_vec_add", test_vec_add}, {"test_vec_apply", test_vec_apply},
	{"test_vec_at", test_vec_at}, {"test_vec_cat", test_vec_cat},
	{"test_vec_clear", test_vec_clear}, {"test_vec_destroy", test_vec_destroy},
	{"test_vec_filter", test_vec_filter}, {"test_vec_map", test_vec_map},
	{"test_vec_new", test_vec_new}, {"test_vec_from_size", test_vec_from_size},
	{"test_vec_from_array", test_vec_from_array},
	{"test_vec_convert_alloc_array", test_vec_convert_alloc_array},
	{"test_vec_remove", test_vec_remove},
	{"test_vec_remove_if", test_vec_remove_if},
	{"test_vec_reserve", test_vec_reserve}, {"test_vec_reverse",
		test_vec_reverse}, {"test_vec_shift", test_vec_shift},
	{"test_vec_sort", test_vec_sort}, {"test_vec_shrink", test_vec_shrink},
	{"test_vec_swap", test_vec_swap},
	{NULL, NULL}
	};

	collect = 0;
	run_test(tests, &collect);
	return (collect);
}
