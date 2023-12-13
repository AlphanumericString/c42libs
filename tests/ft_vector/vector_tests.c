/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:30:25 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/13 11:14:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include <stdio.h>
#include <stdlib.h>

static void	add42(void *data)
{
	int *ptr;
	
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
	int *ret = malloc(sizeof(int));

	*ret = *(int *)data;
	*ret += 42;
	return ((void *)ret);
}

static int	cmpInt(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}

void	test_vec_add(void)
{
	t_vector	*vec;

	vec = ft_vec_new();
	ft_vec_add(&vec, (void *)42);
	if (vec->count != 1)
	{
		printf("ft_vec_add : [FAIL] wrong count after adding an element\n");
	}
	if (*(int *)vec->datas != 42)
	{
		printf("ft_vec_add : [FAIL] wrong value after adding an element\n");
	}
	printf("ft_vec_add : [OK]\n");
	ft_vec_destroy(&vec);
}

void	test_vec_apply(void)
{
	t_vector	*vec;
	int			i;

	i = 0;
	vec = ft_vec_new();
	ft_vec_add(&vec, &i);
	ft_vec_apply(vec, add42);
	if (*(int *)vec->datas[0] != 42)
		printf("ft_vec_apply : [FAIL] wrong value after applying a function \n");
	else
		printf("ft_vec_apply : [OK]\n");
	ft_vec_destroy(&vec);
}

void	test_vec_at(void)
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
		printf("ft_vec_at : [FAIL] wrong value after getting an element\n");
	else if (*(int *)ft_vec_at(vec, 1) != 1)
		printf("ft_vec_at : [FAIL] wrong value after getting an element\n");
	else if (*(int *)ft_vec_at(vec, 2) != 2)
		printf("ft_vec_at : [FAIL] wrong value after getting an element\n");
	else if (ft_vec_at(vec, 3) != NULL)
		printf("ft_vec_at : [FAIL] wrong value after getting an element\n");
	else
		printf("ft_vec_at : [OK]\n");
	ft_vec_destroy(&vec);
}

void	test_vec_cat(void)
{
	t_vector	*vec_a;
	t_vector	*vec_b;

	int a, b, c, d, e, f;
	vec_a = ft_vec_new();
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
	ft_vec_cat(&vec_a, vec_b);
	if (vec_a->count != 6)
		printf("ft_vec_cat : [FAIL] wrong count after concatenating\n");
	else if (*(int *)ft_vec_at(vec_a, 0) != 42)
		printf("ft_vec_cat : [FAIL] wrong value after concatenating\n");
	else if (*(int *)ft_vec_at(vec_a, 1) != 43)
		printf("ft_vec_cat : [FAIL] wrong value after concatenating\n");
	else if (*(int *)ft_vec_at(vec_a, 2) != 44)
		printf("ft_vec_cat : [FAIL] wrong value after concatenating\n");
	else if (*(int *)ft_vec_at(vec_a, 3) != 45)
		printf("ft_vec_cat : [FAIL] wrong value after concatenating\n");
	else if (*(int *)ft_vec_at(vec_a, 4) != 46)
		printf("ft_vec_cat : [FAIL] wrong value after concatenating\n");
	else if (*(int *)ft_vec_at(vec_a, 5) != 47)
		printf("ft_vec_cat : [FAIL] wrong value after concatenating\n");
	else
		printf("ft_vec_cat : [OK]\n");
	ft_vec_destroy(&vec_a);
	ft_vec_destroy(&vec_b);
}

void	test_vec_clear(void)
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
		printf("ft_vec_clear : [FAIL] wrong count after clearing\n");
	else if (vec->cappacity == 0)
		printf("ft_vec_clear : [FAIL] wrong cappacity after clearing\n");
	else if (vec->datas[0] != NULL)
		printf("ft_vec_clear : [FAIL] wrong datas after clearing\n");
	else
		printf("ft_vec_clear : [OK]\n");
	ft_vec_destroy(&vec);
}

void	test_vec_destroy(void)
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
		printf("ft_vec_destroy : [FAIL] wrong value after destroying\n");
	else
		printf("ft_vec_destroy : [OK]\n");
}

void	test_vec_filter(void)
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
	ft_vec_filter(vec, is42, NULL);
	if (vec->count != 1)
		printf("ft_vec_filter : [FAIL] wrong count after filtering\n");
	else if (*(int *)ft_vec_at(vec, 0) != 42)
		printf("ft_vec_filter : [FAIL] wrong value after filtering\n");
	else
		printf("ft_vec_filter : [OK]\n");
	ft_vec_destroy(&vec);
}

void	test_vec_map(void)
{
	t_vector	*vec;
	t_vector	*ret;

	int a, b, c;
	a = 0;
	b = 1;
	c = 2;
	vec = ft_vec_new();
	ft_vec_add(&vec, &a);
	ft_vec_add(&vec, &b);
	ft_vec_add(&vec, &c);
	ret = ft_vec_map(vec, add42_ret);
	if (ret->count != 3)
		printf("ft_vec_map : [FAIL] wrong count after mapping\n");
	else if (*(int *)ft_vec_at(ret, 0) != 42)
		printf("ft_vec_map : [FAIL] wrong value after mapping\n");
	else if (*(int *)ft_vec_at(ret, 1) != 43)
		printf("ft_vec_map : [FAIL] wrong value after mapping\n");
	else if (*(int *)ft_vec_at(ret, 2) != 44)
		printf("ft_vec_map : [FAIL] wrong value after mapping\n");
	else
		printf("ft_vec_map : [OK]\n");
	ft_vec_apply(ret, free); // allocated in add42_ret
	ft_vec_destroy(&vec);
	ft_vec_destroy(&ret);
}

void	test_vec_new(void)
{
	t_vector	*vec;

	vec = ft_vec_new();
	if (vec->count != 0)
		printf("ft_vec_new : [FAIL] wrong count after creating a new vector\n");
	else if (vec->cappacity != FT_VECTOR_BASE_LEN)
		printf("ft_vec_new : [FAIL] wrong cappacity after creating a new vector\n");
	else if (vec->datas == NULL)
		printf("ft_vec_new : [FAIL] wrong datas after creating a new vector\n");
	else
		printf("ft_vec_new : [OK]\n");
	ft_vec_destroy(&vec);
}

void	test_vec_from_size(void)
{
	t_vector	*vec;

	vec = ft_vec_from_size(42);
	if (vec->count != 0)
		printf("ft_vec_from_size : [FAIL] wrong count after creating a new vector\n");
	else if (vec->cappacity != 42)
		printf("ft_vec_from_size : [FAIL] wrong cappacity after creating a new vector\n");
	else if (vec->datas == NULL)
		printf("ft_vec_from_size : [FAIL] wrong datas after creating a new vector\n");
	else
		printf("ft_vec_from_size : [OK]\n");
	ft_vec_destroy(&vec);
}

// TODO: test_vec_from_array with bigger array to test the cappacity when
// 		it's bigger than FT_VECTOR_BASE_LEN
void	test_vec_from_array(void)
{
	int			a;
	int			b;
	int			c;
	void		*data[3];
	t_vector	*vec;

	a = 42;
	b = 43;
	c = 44;
	data[0] = (void *)&a;
	data[1] = (void *)&b;
	data[2] = (void *)&c;
	vec = ft_vec_from_array(data, sizeof(data) / sizeof(data[0]));
	if (vec->count != 3)
		printf("ft_vec_from_array : [FAIL] wrong count after creating a new vector\n");
	else if (vec->cappacity != FT_VECTOR_BASE_LEN)
		printf("ft_vec_from_array : [FAIL] wrong cappacity after creating a new vector\n");
	else if (vec->datas == NULL)
		printf("ft_vec_from_array : [FAIL] wrong datas after creating a new vector\n");
	else if (*(int *)ft_vec_at(vec, 0) != 42)
		printf("ft_vec_from_array : [FAIL] wrong value after creating a new vector\n");
	else if (*(int *)ft_vec_at(vec, 1) != 43)
		printf("ft_vec_from_array : [FAIL] wrong value after creating a new vector\n");
	else if (*(int *)ft_vec_at(vec, 2) != 44)
		printf("ft_vec_from_array : [FAIL] wrong value after creating a new vector\n");
	else
		printf("ft_vec_from_array : [OK]\n");
	ft_vec_destroy(&vec);
}

void	test_vec_convert_alloc_array(void)
{
	int			a, b, c;
	void		**data;
	t_vector	*vec;

	a = 42;
	b = 43;
	c = 44;
	data = malloc(sizeof(void *) * 3);
	data[0] = (void *)&a;
	data[1] = (void *)&b;
	data[2] = (void *)&c;
	vec = ft_vec_convert_alloccarray(data, 3);
	if (vec->count != 3)
		printf("ft_vec_convert_alloccarray : [FAIL] wrong count after creating a new vector\n");
	else if (vec->cappacity != 3)
		printf("ft_vec_convert_alloccarray : [FAIL] wrong cappacity after creating a new vector\n");
	else if (vec->datas != data)
		printf("ft_vec_convert_alloccarray : [FAIL] wrong datas after creating a new vector\n");
	else if (*(int *)ft_vec_at(vec, 0) != 42)
		printf("ft_vec_convert_alloccarray : [FAIL] wrong value after creating a new vector\n");
	else if (*(int *)ft_vec_at(vec, 1) != 43)
		printf("ft_vec_convert_alloccarray : [FAIL] wrong value after creating a new vector\n");
	else if (*(int *)ft_vec_at(vec, 2) != 44)
		printf("ft_vec_convert_alloccarray : [FAIL] wrong value after creating a new vector\n");
	else
		printf("ft_vec_convert_alloccarray : [OK]\n");
	ft_vec_destroy(&vec);
	//  free(data); -> segfault : double free or corruption.
	// 	ft_vec_convert_alloccarray takes ownership of the data. refert to the doc.
}

void	test_vec_remove(void)
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
	ft_vec_remove(vec, 1, NULL);
	if (vec->count != 2)
		printf("ft_vec_remove : [FAIL] wrong count after removing an element\n");
	else if (*(int *)ft_vec_at(vec, 0) != 42)
		printf("ft_vec_remove : [FAIL] wrong value after removing an element\n");
	else if (*(int *)ft_vec_at(vec, 1) != 44)
		printf("ft_vec_remove : [FAIL] wrong value after removing an element\n");
	else
		printf("ft_vec_remove : [OK]\n");
	ft_vec_destroy(&vec);
}

void	test_vec_remove_if(void)
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
		printf("ft_vec_remove_if : [FAIL] wrong count after removing an element\n");
	else if (*(int *)ft_vec_at(vec, 0) != 43)
		printf("ft_vec_remove_if : [FAIL] wrong value after removing an element\n");
	else if (*(int *)ft_vec_at(vec, 1) != 44)
		printf("ft_vec_remove_if : [FAIL] wrong value after removing an element\n");
	else
		printf("ft_vec_remove_if : [OK]\n");
	ft_vec_destroy(&vec);
}

void	test_vec_reserve(void)
{
	t_vector	*vec;

	bool ret1, ret2, ret3;
	vec = ft_vec_from_size(FT_VECTOR_BASE_LEN - 1);
	ret1 = ft_vec_reserve(&vec, FT_VECTOR_BASE_LEN - 2);
	ret2 = ft_vec_reserve(&vec, FT_VECTOR_BASE_LEN);
	ret3 = ft_vec_reserve(&vec, FT_VECTOR_BASE_LEN + 2);
	if (ret1 != true)
		printf("ft_vec_reserve : [FAIL] wrong return (value %d - r1)\n", ret1);
	else if (ret2 != true)
		printf("ft_vec_reserve : [FAIL] wrong return (value %d - r2)\n", ret2);
	else if (ret3 == false)
		printf("ft_vec_reserve : [FAIL] wrong return (value %d - r3)\n", ret3);
	else if (vec->cappacity != FT_VECTOR_BASE_LEN + 2)
		printf("ft_vec_reserve : [FAIL] wrong cappacity after reserving\n");
	else
		printf("ft_vec_reserve : [OK]\n");
	ft_vec_destroy(&vec);
}

void	test_vec_reverse(void)
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
		printf("ft_vec_reverse : [FAIL] wrong count after reversing\n");
	else if (*(int *)ft_vec_at(vec, 0) != 44)
		printf("ft_vec_reverse : [FAIL] wrong value after reversing\n");
	else if (*(int *)ft_vec_at(vec, 1) != 43)
		printf("ft_vec_reverse : [FAIL] wrong value after reversing\n");
	else if (*(int *)ft_vec_at(vec, 2) != 42)
		printf("ft_vec_reverse : [FAIL] wrong value after reversing\n");
	else
		printf("ft_vec_reverse : [OK]\n");
	ft_vec_destroy(&vec);
}

void	test_vec_shift(void)
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
		printf("ft_vec_shift : [FAIL] wrong count after shifting\n");
	else if (*(int *)ft_vec_at(vec, 0) != 42)
		printf("ft_vec_shift : [FAIL] wrong value after shifting\n");
	else if (*(int *)ft_vec_at(vec, 1) != 45)
		printf("ft_vec_shift : [FAIL] wrong value after shifting\n");
	else
		printf("ft_vec_shift : [OK]\n");
	ft_vec_destroy(&vec);
}

void test_vec_sort(void)
{
	int			a, b, c;
	t_vector	*vec;
	void		*data[3];

	a = 42;
	b = 43;
	c = 44;
	data[0] = (void *)&a;
	data[1] = (void *)&b;
	data[2] = (void *)&c;
	vec = ft_vec_from_array(data, sizeof(data) / sizeof(data[0]));
	// 44, 43, 42
	ft_vec_sort(vec, cmpInt);
	// 42, 43, 44
	if (vec->count != 3)
		printf("ft_vec_sort : [FAIL] wrong count after sorting\n");
	else if (*(int *)ft_vec_at(vec, 0) != 42)
		printf("ft_vec_sort : [FAIL] wrong value after sorting\n");
	else if (*(int *)ft_vec_at(vec, 1) != 43)
		printf("ft_vec_sort : [FAIL] wrong value after sorting\n");
	else if (*(int *)ft_vec_at(vec, 2) != 44)
		printf("ft_vec_sort : [FAIL] wrong value after sorting\n");
	else
		printf("ft_vec_sort : [OK]\n");
	ft_vec_destroy(&vec);
}

void test_vec_shrink(void)
{
	int			a, b, c;
	t_vector	*vec;
	void		*data[3];

	a = 42;
	b = 43;
	c = 44;
	data[0] = (void *)&a;
	data[1] = (void *)&b;
	data[2] = (void *)&c;
	vec = ft_vec_from_array(data, sizeof(data) / sizeof(data[0]));
	ft_vec_shrink(vec);
	if (vec->count != 3)
		printf("ft_vec_shrink : [FAIL] wrong count after shrinking\n");
	else if (vec->cappacity != 3)
		printf("ft_vec_shrink : [FAIL] wrong cappacity after shrinking\n");
	else if (*(int *)ft_vec_at(vec, 0) != 42)
		printf("ft_vec_shrink : [FAIL] wrong value after shrinking\n");
	else if (*(int *)ft_vec_at(vec, 1) != 43)
		printf("ft_vec_shrink : [FAIL] wrong value after shrinking\n");
	else if (*(int *)ft_vec_at(vec, 2) != 44)
		printf("ft_vec_shrink : [FAIL] wrong value after shrinking\n");
	else
		printf("ft_vec_shrink : [OK]\n");
	ft_vec_destroy(&vec);
}

void test_vec_swap(void)
{
	int			a, b, c;
	t_vector	*vec;
	void		*data[3];

	a = 42;
	b = 43;
	c = 44;
	data[0] = (void *)&a;
	data[1] = (void *)&b;
	data[2] = (void *)&c;
	vec = ft_vec_from_array(data, sizeof(data) / sizeof(data[0]));
	ft_vec_swap(vec, 0, 2);
	if (vec->count != 3)
		printf("ft_vec_swap : [FAIL] wrong count after swapping\n");
	else if (*(int *)ft_vec_at(vec, 0) != 44)
		printf("ft_vec_swap : [FAIL] wrong value after swapping\n");
	else if (*(int *)ft_vec_at(vec, 1) != 43)
		printf("ft_vec_swap : [FAIL] wrong value after swapping\n");
	else if (*(int *)ft_vec_at(vec, 2) != 42)
		printf("ft_vec_swap : [FAIL] wrong value after swapping\n");
	else
		printf("ft_vec_swap : [OK]\n");
	ft_vec_destroy(&vec);
}

int	tests_vector(void)
{
	printf("== VECTOR ==\n");
	test_vec_add();
	test_vec_apply();
	test_vec_at();
	test_vec_cat();
	test_vec_clear();
	test_vec_destroy();
	test_vec_filter();
	test_vec_map();
	test_vec_new();
	test_vec_from_size();
	test_vec_from_array();
	test_vec_convert_alloc_array();
	test_vec_remove();
	test_vec_remove_if();
	test_vec_reserve();
	test_vec_reverse();
	test_vec_shift();
	test_vec_sort();
	test_vec_shrink();
	test_vec_swap();
	printf("== END ==\n");
	return (0);
}