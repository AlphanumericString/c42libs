/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optional_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 00:57:26 by bgoulard          #+#    #+#             */
/*   Updated: 2024/01/07 20:48:19 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional_types.h"
#include "tests/tests.h"
#include "ft_optional.h"

void *add_4(void *val)
{
	long long ptr = (long long)val;

	ptr += 4;
	return ((void *)ptr);
}

int optional_copy(void)
{
	int		*ptr;
	t_optional	opt_a;
	t_optional	opt_b;


	ptr = malloc(sizeof(int));
	*ptr = 42;
	opt_a.pres = OPT_SOME;
	opt_a.val = ptr;
	ft_optional_copy(&opt_b, &opt_a);
	if (opt_b.pres != OPT_SOME)
		return (1);
	if (*(int *)opt_b.val != 42)
		return (2);
	free(ptr);
	return (0);
}

int test_optional_new(void)
{
	t_optional *opt;

	opt = ft_optional_new();
	if (opt == NULL)
		return (1);
	if (opt->pres != OPT_NONE)
		return (2);
	if (opt->val != NULL)
		return (3);
	ft_optional_destroy(opt);
	return (0);
}

int test_optional_dup(void)
{
	t_optional opt_a;
	t_optional *opt_b;

	opt_a.pres = OPT_SOME;
	opt_a.val = (void *)42;
	opt_b = ft_optional_dup(&opt_a);
	if (opt_b == NULL)
		return (1);
	if (opt_b->pres != OPT_SOME)
		return (2);
	if (opt_b->val != (void *)42)
		return (3);
	opt_b->pres = OPT_NONE;
	ft_optional_destroy(opt_b);
	return (0);
}

int test_optional_from_val(void)
{
	int *ptr;
	t_optional *opt;

	ptr = malloc(sizeof(int));
	*ptr = 42;
	opt = ft_optional_from_val(ptr);
	if (opt == NULL)
		return (1);
	if (opt->pres != OPT_SOME)
		return (2);
	if (opt->val != ptr)
		return (3);
	opt->pres = OPT_NONE;
	ft_optional_destroy(opt);
	free(ptr);
	return (0);
}

int test_optional_chain(void)
{
	t_optional opt;
	bool ret;
	void *(*function_list[])(void *) = {
		&add_4,
		&add_4,
		NULL
	};

	opt.pres = OPT_SOME;
	opt.val = (void *)42;
	ret = ft_optional_chain(&opt, function_list);
	if (ret != true)
		return (1);
	if (opt.pres != OPT_SOME)
		return (2);
	if (opt.val != (void *)42 + 8)
		return (printf("opt.val = %lld\n", (long long)opt.val), 3);
	return (0);
}

int test_optional_map(void)
{
	t_optional opt;
	t_optional ret;
	void *(*function_list[])(void *) = {
		&add_4,
		&add_4,
		NULL
	};

	opt.pres = OPT_SOME;
	opt.val = (void *)42;
	ret = ft_optional_map(&opt, function_list);
	if (ret.pres != OPT_SOME)
		return (1);
	if (ret.val != (void *)42 + 8)
		return (printf("ret.val = %lld\n", (long long)ret.val), 2);
	return (0);
}

int test_optional_unwrap(void)
{
	t_optional opt;
	int *ptr;
	int pid;
	int status;

	opt.pres = OPT_SOME;
	ptr = malloc(sizeof(int));
	*ptr = 42;
	opt.val = ptr;
	if (ft_optional_unwrap(opt) != ptr)
		return (1);
	free(ptr);

	opt.pres = OPT_NONE;
	pid = fork();
	if (pid == 0)
	{
		ft_optional_unwrap(opt);
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (!WIFSIGNALED(status))
		return (2);
	return (0);
}

int test_optional_destroy(void)
{
	t_optional *opt_a;

	opt_a = ft_optional_new();
	opt_a->val = (void *)42;
	opt_a->pres = OPT_SOME;
	if (ft_optional_destroy(opt_a) != false)
		return (1);
	if (opt_a->pres != OPT_SOME)
		return (2);
	if (opt_a->val != (void *)42)
		return (3);
	opt_a->pres = OPT_NONE;
	if (ft_optional_destroy(opt_a) != true)
		return (4);
	if (ft_optional_destroy(NULL) != false)
		return (5);
	return (0);
}

int tests_optional(void)
{
	int		collect;
	t_test	test[] = {
		{"optional_copy", optional_copy},
		{"test_optional_new", test_optional_new},
		{"test_optional_from_val", test_optional_from_val},
		{"test_optional_dup", test_optional_dup},
		{"test_optional_chain", test_optional_chain},
		{"test_optional_map", test_optional_map},
		{"test_optional_unwrap", test_optional_unwrap},
		{"test_optional_destroy", test_optional_destroy},
		{NULL, NULL}
	};

	collect = 0;
	run_test(test, &collect);
	return (collect);
}
