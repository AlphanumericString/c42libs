/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/26 11:15:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests.h"
#include <fcntl.h>
#include <string.h>

int	test_gnl(void)
{
	int		fd;
	char	*line;
	size_t	i;

	line = NULL;
	char *test_lines[] = {
		"Hello World!\n",
		"This is Zod!\n",
		"Zod shall henceforth be the new earth emperor. Prepare yourself earthilings to the terrible rule of zod the space warrior and self proclaimed emperor of the gallaxy. this is a really long line btw... i sure hop gnl will parse it............................\n",
		"Goodbye World!\n",
	};
	fd = open(TESTS_FPREFIX "gnl.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	for (i = 0; i < sizeof(test_lines) / sizeof(test_lines[0]); i++)
		write(fd, test_lines[i], strlen(test_lines[i]));
	close(fd);
	fd = open(TESTS_FPREFIX "gnl.txt", O_RDONLY);
	for (i = 0; i < sizeof(test_lines) / sizeof(test_lines[0]); i++)
	{
		line = get_next_line(fd);
		if (strcmp(line, test_lines[i]) != 0)
			return (i + 1);
		free(line);
	}
	line = get_next_line(fd);
	if (line != NULL)
		return (2);
	free(line);
	destroy_test_file(fd, TESTS_FPREFIX "gnl.txt");
	return (0);
}
