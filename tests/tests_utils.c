/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 04:18:57 by bgoulard          #+#    #+#             */
/*   Updated: 2024/01/07 20:43:20 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int run_test(t_test *test, int *collect)
{
	size_t	i;
	int		pid;
	int		ret;
	int 	sum;

	ret = 0;
	sum = 0;
	fflush(stdout);
	if (FORK_TESTS)
	{
		for(i = 0; test[i].name; i++)
		{
			fflush(stdout);
			pid = fork();
			if (pid == 0)
			{
				ret = test[i].test();
				exit(ret);
			}
			else
			{
				waitpid(pid, &ret, 0);
				if (WIFSIGNALED(ret))
					printf("\n\t %s: \033[31mCRASH\033[0m\n", test[i].name);
				else if (ret != 0)
					printf("\n\t %s: \033[31mKO\033[0m ret %d\n", test[i].name, WEXITSTATUS(ret));
				else
					printf(" \033[32mOK\033[0m");
				*collect += ret;
				sum += ret;
			}
		}
	} 
	else {
		for(i = 0; test[i].name; i++)
		{
			fflush(stdout);
			ret = test[i].test();
			if (ret != 0)
				printf("\n\t %s: \033[31mKO\033[0m ret %d\n", test[i].name, ret);
			else
				printf("\t \033[32mOK\033[0m");
			*collect += ret;
			sum += ret;
		}
	}
	return (sum);

}
