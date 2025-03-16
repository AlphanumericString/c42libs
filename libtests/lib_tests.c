/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:24:14 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/11 22:25:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "lib_tester.h"

typedef struct s_list {
	void	*content;
	struct s_list *next;
} t_list;

CREATE_TEST(strlen)
	ASSER_CMP_GNU(func->raw_ptr, strlen, "Hello World");
	ASSER_CMP_GNU(func->raw_ptr, strlen, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	ASSER_CMP_GNU(func->raw_ptr, strlen, "");
	ASSER_CMP_GNU(func->raw_ptr, strlen, "loremp ipsum dolor sit amet, " \
	"consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut " \
	"labore et dolore");
END_TEST

CREATE_TEST(strstr)
	ASSER_CMP_GNU(func->raw_ptr, strstr, "Hello World", "World");
	ASSER_CMP_GNU(func->raw_ptr, strstr, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaa");
	ASSER_CMP_GNU(func->raw_ptr, strstr, "", "");
	ASSER_CMP_GNU(func->raw_ptr, strstr, "loremp ipsum dolor sit amet, " \
	"consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut " \
	"labore et dolore", "dolor");
END_TEST

CREATE_TEST(strchr)
	ASSER_CMP_GNU(func->raw_ptr, strchr, "Hello World", 'W');
	ASSER_CMP_GNU(func->raw_ptr, strchr, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 'a');
	ASSER_CMP_GNU(func->raw_ptr, strchr, "", 'a');
	ASSER_CMP_GNU(func->raw_ptr, strchr, "loremp ipsum dolor sit amet, " \
	"consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut " \
	"labore et dolore", 'd');
END_TEST

CREATE_TEST(lstnew)
	t_list *(*f_type)(const void *content) = func->raw_ptr;
	t_list *list = f_type("Hello World");
	ASSERT_MSG(strcmp(list->content, "Hello World"), 0);
	ASSERT_MSG(list->next, NULL);
	free(list);
END_TEST
