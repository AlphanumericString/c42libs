/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/26 11:16:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests.h"
#include <limits.h>
#include <string.h>

int	test_putnbr(void)
{
	const char	*file_name;
	const char	*expected2;
	int			fd;
	size_t		i;

	file_name = TESTS_FPREFIX "putnbr.txt";
	const int t_cases[] = {0, 1, 9, 10, 99, 100, 999, 1000, 9999, 10000, -1, -9,
		-10, -99, -100, -999, -1000, -9999, -10000};
	const char expected[] = "0\n1\n9\n10\n99\n100\n999\n1000\n9999\n10000\n-1\n-9\n-10\n-99\n-100\n-999\n-1000\n-9999\n-10000\n";
	expected2 = "-2147483648\n2147483647\n";
	char buff[sizeof(expected) / sizeof(expected[0]) + 1] = {0};
	expected2 = "-2147483648\n2147483647\n";
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	i = 0;
	for (i = 0; i < sizeof(t_cases) / sizeof(t_cases[0]); i++)
	{
		ft_putnbr_fd(t_cases[i], fd);
		ft_putstr_fd("\n", fd);
	}
	close(fd);
	fd = open(file_name, O_RDONLY);
	read(fd, buff, sizeof(expected) / sizeof(expected[0]));
	if (strncmp(buff, expected, sizeof(expected) / sizeof(expected[0])) != 0)
		return (1);
	destroy_test_file(fd, file_name);
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	ft_putnbr_fd(INT_MIN, fd);
	ft_putstr_fd("\n", fd);
	ft_putnbr_fd(INT_MAX, fd);
	ft_putstr_fd("\n", fd);
	close(fd);
	fd = open(file_name, O_RDONLY);
	bzero(buff, sizeof(buff));
	read(fd, buff, sizeof(buff));
	if (strncmp(buff, expected2, sizeof(buff)) != 0)
		return (2);
	destroy_test_file(fd, file_name);
	return (0);
}
