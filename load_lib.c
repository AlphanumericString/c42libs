/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:22:28 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/21 15:17:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dlfcn.h>
#include <strings.h>
#include <unistd.h>

typedef union {
	void *raw_ptr;
	int (*f_is)(const char *s);
} t_func;

typedef struct s_library t_library;
struct s_library {
	const char	*lib_name;
	const void	*handle;
	t_func		*currently_loaded;
};

int main(int ac, const char *av[])
{
	t_library	lib;
	char *target = "libft.so";
	void *library;
	t_func f;

	bzero(&lib, sizeof(lib));
	if (!strcmp(av[1], "-f") || !strcmp(av[1], "--file"))
		target = (char *)av[2];
	library = dlopen(target, RTLD_LAZY);
	if (!library) {
		dprintf(STDERR_FILENO, "dlopen: %s\n", dlerror());
		exit(EXIT_FAILURE);
	}
	f.raw_ptr = dlsym(library, "ft_strlen");
	if (!f.raw_ptr)
		dprintf(STDERR_FILENO, "didn't find %s function\n", "ft_strlen");
	else {	
		int ret = f.f_is("this is zod");
		printf("ret : %d", ret);
	}
	dlclose(library);
	return (EXIT_SUCCESS);
}
