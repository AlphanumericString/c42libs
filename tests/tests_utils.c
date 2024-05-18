/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 04:18:57 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/18 17:03:57 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#ifdef FORK_TESTS

static int	run_t_test(t_test test, int *collect)
{
	int	ret;
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		ret = test.test();
		exit(ret);
	}
	else
	{
		waitpid(pid, &ret, 0);
		if (WIFSIGNALED(ret))
			printf("\n\t %s: \033[31mCRASH\033[0m\n", test.name);
		else if (ret != 0)
			printf("\n\t %s: \033[31mKO\033[0m ret %d\n", test.name,
				WEXITSTATUS(ret));
		else
			printf(" \033[32mOK\033[0m");
		*collect += ret;
	}
	return (ret);
}

#else

static int	run_t_test(t_test test, int *collect)
{
	int	ret;

	ret = test.test();
	*collect += ret;
	if (ret != 0)
		printf("\t %s: \033[31mKO\033[0m ret %d\n", test.name, ret);
	else
		printf("\t \033[32mOK\033[0m");
	return (ret);
}

#endif

void	destroy_test_file(int fd, char *file)
{
	close(fd);
	unlink(file);
}

int	run_test(const t_test *test, int *collect)
{
	size_t	i;
	int		ret;
	int		sum;

	ret = 0;
	sum = 0;
	i = 0;
	fflush(stdout);
	while (test[i].name)
	{
		fflush(stdout);
		ret = run_t_test(test[i], &sum);
		*collect += ret;
		sum += ret;
		i++;
	}
	return (sum);
}
