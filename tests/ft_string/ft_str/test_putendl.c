/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putendl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/26 11:58:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests.h"
#include <string.h>

int	test_putendl(void)
{
	const char	*str;
	int			fd;
	char		buff[100];
	int			bread;
	const char	file_name[] = TESTS_FPREFIX "putendl.txt";

	str = "Hello World!";
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	ft_putendl_fd(str, fd);
	close(fd);
	fd = open(file_name, O_RDONLY);
	bread = read(fd, buff, 100);
	if (bread < 0 || strncmp(buff, str, strlen(str)) != 0
		|| buff[strlen(str)] != '\n')
		return (1);
	destroy_test_file(fd, file_name);
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	ft_putendl_fd(NULL, fd);
	close(fd);
	fd = open(file_name, O_RDONLY);
	bread = read(fd, buff, 100);
	if (bread != 0)
		return (2);
	destroy_test_file(fd, file_name);
	return (0);
}
