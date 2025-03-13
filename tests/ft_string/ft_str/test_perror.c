/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_perror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:04:30 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/13 08:56:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_errno.h"
#include "ft_string.h"

#include "tests/tests.h"

#include <unistd.h>
#include <stdio.h>

void	write_lines(void)
{
	errno = EPERM;
	ft_perror("toto");
	errno = EISCONN;
	ft_perror("titi");
	errno = ETIMEDOUT;
	ft_perror(NULL);
	errno = ELIBEXEC;
	ft_perror(NULL);
	errno = 9999;
	ft_perror(NULL);
}

int	test_perror(void)
{
	const char	*expected[] = {"toto: Operation not permitted\n", \
	"titi: Transport endpoint is already connected\n", "Connection timed out\n",
		"Cannot exec a shared library directly\n", "Unkown error\n"	\
	};
	char		*rd_buff;
	char		*file;
	int			fd;
	size_t		i;

	file = "perror";
	fd = open_test_file(&file);
	dup2(fd, STDERR_FILENO);
	write_lines();
	fd = (close(fd), open(file, O_RDWR));
	i = 0;
	while (i < sizeof(expected) / sizeof(expected[0]))
	{
		rd_buff = get_next_line(fd);
		if (ft_strcmp(rd_buff, expected[i++]))
			return (i);
		ft_free_clear((void **)&rd_buff);
	}
	destroy_test_file(fd, file);
	return (0);
}
