/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:22:28 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/11 22:53:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stddef.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dlfcn.h>
#include <strings.h>
#include <unistd.h>

#include "lib_tester.h"

void test_run_fork_space(void *library, t_function *fun)
{
	int child_id = fork();
	int status;

	if (child_id == -1) {
		dprintf(STDERR_FILENO, "\t\tfork: %s\n", strerror(errno));
		dlclose(library);
		exit(EXIT_FAILURE);
	}

	if (child_id == 0) {
		fun->test_func(fun);
		dlclose(library);
		exit(EXIT_SUCCESS);
	}
	waitpid(child_id, &status, 0);
	if (WIFSIGNALED(status)) {
		dprintf(STDERR_FILENO, RED "test '%s' crashed"RESET"\n", fun->name);
		dlclose(library);
		exit(EXIT_FAILURE);
	}
}

void run_test_suite(t_function *fun_list, size_t ar_size, void *library)
{
	for (size_t i = 0; i < ar_size; i++) {
		fun_list[i].f.raw_ptr = dlsym(library, fun_list[i].name);
		if (!fun_list[i].f.raw_ptr) {
			dprintf(STDERR_FILENO, "dlsym: %s\t", dlerror());
			dprintf(STDERR_FILENO, RED "\tfunction '%s' not found\t(zero / 20)"RESET"\n", fun_list[i].name);
			continue;
		}
		test_run_fork_space(library, &fun_list[i]);
	}
}

int main(int ac, const char *av[])
{
	char *target = "./libft.so";
	void *library;
	t_function mandatory_libft[] = {
		{"ft_strlen", {0}, test_strlen},
		{"ft_strstr", {0}, test_strstr},
		{"ft_strchr", {0}, test_strchr}
		// ...
	};
	t_function bonus_libft[] = {
		{"ft_lstnew", {0}, test_lstnew},
		// ...
	};

	if (ac > 2 && (!strcmp(av[1], "-f") || !strcmp(av[1], "--file")))
		target = (char *)av[2];

	// open lib or file provided
	library = dlopen(target, RTLD_LAZY);
	if (!library) {
		dprintf(STDERR_FILENO, "dlopen: %s\n", dlerror());
		exit(EXIT_FAILURE);
	}

	// test the functions
	dprintf(STDOUT_FILENO, "Test mandatory functions\n");
	run_test_suite(mandatory_libft, sizeof(mandatory_libft) / sizeof(t_function), library);
	dprintf(STDOUT_FILENO, "Test bonus functions\n");
	run_test_suite(bonus_libft, sizeof(bonus_libft) / sizeof(t_function), library);

	// close the lib
	dlclose(library);
	return (EXIT_SUCCESS);
}
