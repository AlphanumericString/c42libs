/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_tester.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:53:55 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/11 22:48:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* Lib Tester:                                                                */
/*                                                                            */
/* Since this project started from the 42's libft project i found interesting */
/*  to make a tester for it plus it was a nice experience to link a lib at    */
/*  runtime using dlopen.                                                     */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>

#define RED "\033[0;31m"
#define RESET "\033[0m"

typedef union {
	void		*raw_ptr;

	int			(*f_i_cs)(const char *s);
	int			(*f_i_s)(char *s);
	char		*(*f_s_cs)(const char *s);
	char		*(*f_s_s)(char *s);
} t_func;

typedef struct s_function {
	char *name;
	t_func f;
	void (*test_func)(struct s_function *fun);
} t_function;

#define ASSERT_MSG(value, exp) \
	do { \
		if ((value) != (exp)) { \
			dprintf(STDOUT_FILENO, "test '%s == %s' failed\n", #value, #exp); \
			dprintf(STDOUT_FILENO, "expected : '%s'\tgot: '%s'\n", #exp, #value); \
			exit(EXIT_FAILURE); \
		} \
		else \
			dprintf(STDOUT_FILENO, "Ok..."); \
	} while (0)	\

#define ASSER_CMP_GNU(func_self, func_gnu, args...) \
	do {\
		typeof(func_gnu) *f = func_self; \
		ASSERT_MSG(f(args), func_gnu(args)); \
	} while (0) \

#define CREATE_TEST(name) \
	void test_##name(t_function *fun) { \
		t_func *func = &fun->f; \
		dprintf(STDOUT_FILENO, "%s\n", __func__); \

#define END_TEST \
		dprintf(STDOUT_FILENO, "%s : ok\n", fun->name); \
	} \

void test_strlen(t_function *fun);
void test_strstr(t_function *fun);
void test_strchr(t_function *fun);
void test_lstnew(t_function *fun);

