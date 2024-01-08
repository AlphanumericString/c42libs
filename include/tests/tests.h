/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:15:14 by bgoulard          #+#    #+#             */
/*   Updated: 2024/01/07 03:37:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <string.h>
# include <errno.h>
# define TESTS_FPREFIX "build/test_"

# ifndef FORK_TESTS
#  define FORK_TESTS 1
# endif

# define OPEN_TEST_FILE (x) \
	open(x, O_CREAT | O_RDWR | O_TRUNC, 0666)

# define CLOSE_TEST_FILE(x) \
	close(x)

# define DESTROY_TEST_FILE(fd, x) 	\
	CLOSE_TEST_FILE(fd); 			\
	unlink(x)

# define LOG_TESTS(y, x)                            \
	do                                              \
	{                                               \
		if (y != 0)                                 \
		{                                           \
			printf("%s:%s :: %d\n", __func__, #x, y); \
			return (y);                             \
		}                                           \
	} while (0);

#define RUN_TEST(x, collect)                        \
	do                                              \
	{                                               \
		int i = 0;                                  \
		int ret;                        			\
		for (i = 0; tests[i].name != NULL; i++) {   \
			ret = tests[i].test();					\
			collect += ret;							\
			if (ret != 0)							\
				printf("\tmodule %s %s %d failed\n",\
				__func__, tests[i].name, ret);		\
		}											\
	} while (0);

typedef struct s_test
{
	char	*name;
	int		(*test)(void);
}				t_test;


int run_test(t_test *test, int *collect);

int	tests_map(void);
int	tests_linked_list_all(void);
int	tests_doubly_linked_list_all(void);
int	tests_vector(void);
int	tests_string(void);
int tests_optional(void);

#endif /* TEST_H */
