/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:39:29 by bgoulard          #+#    #+#             */
/*   Updated: 2024/01/01 17:40:34 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests.h"
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void	local_iteri(unsigned int i, char *s)
{
	(void)i;
	*s = 'a';
}

static char	local_mapi(unsigned int i, char c)
{
	(void)i;
	return (c + 1);
}

int	test_is_alphanum(void)
{
	if (ft_isalnum('a') != 1)
		return (1);
	if (ft_isalnum('z') != 1)
		return (2);
	if (ft_isalnum('A') != 1)
		return (3);
	if (ft_isalnum('Z') != 1)
		return (4);
	if (ft_isalnum('0') != 1)
		return (5);
	if (ft_isalnum('9') != 1)
		return (6);
	if (ft_isalnum(' ') != 0)
		return (7);
	if (ft_isalnum('\n') != 0)
		return (8);
	if (ft_isalnum('\t') != 0)
		return (9);
	if (ft_isalnum('\0') != 0)
		return (10);
	return (0);
}

int	test_is_alpa(void)
{
	if (ft_isalpha('a') != 1)
		return (1);
	if (ft_isalpha('z') != 1)
		return (2);
	if (ft_isalpha('A') != 1)
		return (3);
	if (ft_isalpha('Z') != 1)
		return (4);
	if (ft_isalpha('0') != 0)
		return (5);
	if (ft_isalpha('9') != 0)
		return (6);
	if (ft_isalpha(' ') != 0)
		return (7);
	if (ft_isalpha('\n') != 0)
		return (8);
	if (ft_isalpha('\t') != 0)
		return (9);
	if (ft_isalpha('\0') != 0)
		return (10);
	return (0);
}

int	test_is_digit(void)
{
	if (ft_isdigit('a') != 0)
		return (1);
	if (ft_isdigit('z') != 0)
		return (2);
	if (ft_isdigit('A') != 0)
		return (3);
	if (ft_isdigit('Z') != 0)
		return (4);
	if (ft_isdigit('0') != 1)
		return (5);
	if (ft_isdigit('9') != 1)
		return (6);
	if (ft_isdigit(' ') != 0)
		return (7);
	if (ft_isdigit('\n') != 0)
		return (8);
	if (ft_isdigit('\t') != 0)
		return (9);
	if (ft_isdigit('\0') != 0)
		return (10);
	return (0);
}

int	test_is_ascii(void)
{
	if (ft_isascii('a') != 1)
		return (1);
	if (ft_isascii('z') != 1)
		return (2);
	if (ft_isascii('A') != 1)
		return (3);
	if (ft_isascii('Z') != 1)
		return (4);
	if (ft_isascii('0') != 1)
		return (5);
	if (ft_isascii('9') != 1)
		return (6);
	if (ft_isascii(' ') != 1)
		return (7);
	if (ft_isascii('\n') != 1)
		return (8);
	if (ft_isascii('\t') != 1)
		return (9);
	if (ft_isascii('\0') != 1)
		return (10);
	if (ft_isascii(127) != 1)
		return (11);
	if (ft_isascii(128) != 0)
		return (12);
	if (ft_isascii(-1) != 0)
		return (13);
	return (0);
}

int	test_is_lower(void)
{
	if (ft_islower('a') != 1)
		return (1);
	if (ft_islower('z') != 1)
		return (2);
	if (ft_islower('a' - 1) != 0)
		return (13);
	if (ft_islower('z' + 1) != 0)
		return (14);
	if (ft_islower('A') != 0)
		return (3);
	if (ft_islower('Z') != 0)
		return (4);
	if (ft_islower('0') != 0)
		return (5);
	if (ft_islower('9') != 0)
		return (6);
	if (ft_islower(' ') != 0)
		return (7);
	if (ft_islower('\n') != 0)
		return (8);
	if (ft_islower('\t') != 0)
		return (9);
	if (ft_islower('\0') != 0)
		return (10);
	if (ft_islower('q') != 1)
		return (11);
	if (ft_islower('Q') != 0)
		return (12);
	return (0);
}

int	test_is_upper(void)
{
	if (ft_isupper('a') != 0)
		return (1);
	if (ft_isupper('z') != 0)
		return (2);
	if (ft_isupper('A') != 1)
		return (3);
	if (ft_isupper('Z') != 1)
		return (4);
	if (ft_isupper('0') != 0)
		return (5);
	if (ft_isupper('9') != 0)
		return (6);
	if (ft_isupper(' ') != 0)
		return (7);
	if (ft_isupper('\n') != 0)
		return (8);
	if (ft_isupper('\t') != 0)
		return (9);
	if (ft_isupper('\0') != 0)
		return (10);
	if (ft_isupper('Q') != 1)
		return (11);
	if (ft_isupper('q') != 0)
		return (12);
	return (0);
}

int	test_is_print(void)
{
	if (ft_isprint('a') != 1)
		return (1);
	if (ft_isprint('z') != 1)
		return (2);
	if (ft_isprint('A') != 1)
		return (3);
	if (ft_isprint('Z') != 1)
		return (4);
	if (ft_isprint('0') != 1)
		return (5);
	if (ft_isprint('9') != 1)
		return (6);
	if (ft_isprint(' ') != 1)
		return (7);
	if (ft_isprint('\n') != 0)
		return (8);
	if (ft_isprint('\t') != 0)
		return (9);
	if (ft_isprint('\0') != 0)
		return (10);
	if (ft_isprint(127) != 0)
		return (11);
	return (0);
}

int	test_is_space(void)
{
	if (ft_isspace('a') != 0)
		return (1);
	if (ft_isspace('z') != 0)
		return (2);
	if (ft_isspace('A') != 0)
		return (3);
	if (ft_isspace('Z') != 0)
		return (4);
	if (ft_isspace('0') != 0)
		return (5);
	if (ft_isspace('9') != 0)
		return (6);
	if (ft_isspace(' ') != 1)
		return (7);
	if (ft_isspace('\n') != 1)
		return (8);
	if (ft_isspace('\t') != 1)
		return (9);
	if (ft_isspace('\v') != 1)
		return (10);
	if (ft_isspace('\f') != 1)
		return (11);
	if (ft_isspace('\r') != 1)
		return (12);
	if (ft_isspace('\0') != 0)
		return (13);
	return (0);
}

int	test_to_lower(void)
{
	if (ft_tolower('a') != 'a')
		return (1);
	if (ft_tolower('z') != 'z')
		return (2);
	if (ft_tolower('A') != 'a')
		return (3);
	if (ft_tolower('Z') != 'z')
		return (4);
	if (ft_tolower('0') != '0')
		return (5);
	if (ft_tolower('9') != '9')
		return (6);
	if (ft_tolower(' ') != ' ')
		return (7);
	if (ft_tolower('\n') != '\n')
		return (8);
	if (ft_tolower('\t') != '\t')
		return (9);
	if (ft_tolower('\0') != '\0')
		return (10);
	return (0);
}

int	test_to_upper(void)
{
	if (ft_toupper('a') != 'A')
		return (1);
	if (ft_toupper('z') != 'Z')
		return (2);
	if (ft_toupper('A') != 'A')
		return (3);
	if (ft_toupper('Z') != 'Z')
		return (4);
	if (ft_toupper('0') != '0')
		return (5);
	if (ft_toupper('9') != '9')
		return (6);
	if (ft_toupper(' ') != ' ')
		return (7);
	if (ft_toupper('\n') != '\n')
		return (8);
	if (ft_toupper('\t') != '\t')
		return (9);
	if (ft_toupper('\0') != '\0')
		return (10);
	return (0);
}

int	test_itoa(void)
{
	int		t_cases[] = {0, 123, -456, 7890, -12345};
	char	*expected_results[] = {"0", "123", "-456", "7890", "-12345"};
	char	*res;
	size_t	i;

	i = 0;
	for (i = 0; i < sizeof(t_cases) / sizeof(t_cases[0]); i++)
	{
		res = ft_itoa(t_cases[i]);
		if (strcmp(res, expected_results[i]) != 0)
			return (i + 1);
		free(res);
	}
	return (0);
}

int	test_utoa(void)
{
	unsigned int	t_cases[] = {0, 123, 456, 7890, 12345};
	char			*expected_results[] = {"0", "123", "456", "7890", "12345"};
	char			*res;
	size_t			i;

	i = 0;
	for (i = 0; i < sizeof(t_cases) / sizeof(t_cases[0]); i++)
	{
		res = ft_utoa(t_cases[i]);
		if (strcmp(res, expected_results[i]) != 0)
			return (i + 1);
		free(res);
	}
	return (0);
}

int	test_itoa_base(void)
{
	int		t_cases[] = {0, 123, -456, 7890, -12345};
	char	*bases[] = {"0123456789abcdef", "0123456789", "01",
			"0123456789ABCDEF"};
	char	*expected_results[sizeof(bases) / sizeof(bases[0])][sizeof(t_cases)
			/ sizeof(t_cases[0])] = {{"0", "7b", "-1c8", "1ed2", "-3039"}, {"0",
			"123", "-456", "7890", "-12345"}, {"0", "1111011", "-111001000",
			"1111011010010", "-11000000111001"}, {"0", "7B", "-1C8", "1ED2",
			"-3039"}};
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	for (i = 0; i < sizeof(t_cases) / sizeof(t_cases[0]); i++)
	{
		for (j = 0; j < sizeof(bases) / sizeof(bases[0]); j++)
		{
			res = ft_itoa_base(t_cases[i], bases[j]);
			if (strcmp(res, expected_results[j][i]) != 0)
			{
				printf("expected: %s got: %s\n", expected_results[j][i], res);
				free(res);
				return (j + i + 1);
			}
			free(res);
		}
	}
	return (0);
}

int	test_log(void)
{
	int		t_cases[] = {0, 1, 9, 10, 99, 100, 999, 1000, 9999, 10000};
	int		expected_results[] = {-1, 0, 0, 1, 1, 2, 2, 3, 3, 4};
	size_t	i;

	i = 0;
	for (i = 0; i < sizeof(t_cases) / sizeof(t_cases[0]); i++)
	{
		if (ft_log(t_cases[i]) != expected_results[i])
			return (i + 1);
	}
	return (0);
}

int	test_logof(void)
{
	int		t_cases[] = {0, 1, 9, 10, 99, 100, 999, 1000, 9999, 10000};
	int		expected_results[] = {-1, 0, 0, 1, 1, 2, 2, 3, 3, 4};
	size_t	i;

	i = 0;
	for (i = 0; i < sizeof(t_cases) / sizeof(t_cases[0]); i++)
	{
		if (ft_logof(t_cases[i], 10) != expected_results[i])
			return (i + 1);
	}
	return (0);
}

int	test_llogof(void)
{
	long long	t_cases[] = {0, 1, 9, 10, 99, 100, 999, 1000, 9999, 10000};
	int			expected_results[] = {-1, 0, 0, 1, 1, 2, 2, 3, 3, 4};
	size_t		i;

	i = 0;
	for (i = 0; i < sizeof(t_cases) / sizeof(t_cases[0]); i++)
	{
		if (ft_llogof(t_cases[i], 10) != expected_results[i])
			return (i + 1);
	}
	return (0);
}

int	test_ullogof(void)
{
	unsigned long long	t_cases[] = {0, 1, 9, 10, 99, 100, 999, 1000, 9999,
			10000};
	int					expected_results[] = {-1, 0, 0, 1, 1, 2, 2, 3, 3, 4};
	size_t				i;

	i = 0;
	for (i = 0; i < sizeof(t_cases) / sizeof(t_cases[0]); i++)
	{
		if (ft_ullogof(t_cases[i], 10) != expected_results[i])
			return (i + 1);
	}
	return (0);
}

int	test_putstr(void)
{
	char	file_name[] = TESTS_FPREFIX "putstr.txt";
	char	*str;
	int		fd;
	char	buff[100] = {0};
	int		bread;

	str = "Hello World!";
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	ft_putstr_fd(str, fd);
	close(fd);
	fd = open(file_name, O_RDONLY);
	read(fd, buff, 100);
	if (strcmp(buff, str) != 0)
		return (1);
	DESTROY_TEST_FILE(fd, file_name);
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	ft_putstr_fd(NULL, fd);
	close(fd);
	fd = open(file_name, O_RDONLY);
	bread = read(fd, buff, 100);
	if (bread != 0)
		return (2);
	DESTROY_TEST_FILE(fd, file_name);
	return (0);
}

int	test_putendl(void)
{
	char	file_name[] = TESTS_FPREFIX "putendl.txt";
	char	*str;
	int		fd;
	char	buff[100] = {0};
	int		bread;

	str = "Hello World!";
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	ft_putendl_fd(str, fd);
	close(fd);
	fd = open(file_name, O_RDONLY);
	read(fd, buff, 100);
	if (strncmp(buff, str, strlen(str)) != 0 || buff[strlen(str)] != '\n')
		return (1);
	DESTROY_TEST_FILE(fd, file_name);
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	ft_putendl_fd(NULL, fd);
	close(fd);
	fd = open(file_name, O_RDONLY);
	bread = read(fd, buff, 100);
	if (bread != 0)
		return (2);
	DESTROY_TEST_FILE(fd, file_name);
	return (0);
}

int	test_putnbr(void)
{
	char	file_name[] = TESTS_FPREFIX "putnbr.txt";
	int		t_cases[] = {0, 1, 9, 10, 99, 100, 999, 1000, 9999, 10000, -1, -9,
				-10, -99, -100, -999, -1000, -9999, -10000};
	char	expected[] = "0\n1\n9\n10\n99\n100\n999\n1000\n9999\n10000\n-1\n-9\n-10\n-99\n-100\n-999\n-1000\n-9999\n-10000\n";
	char	*expected2;
	int		fd;
	size_t	i;
	char	buff[sizeof(expected) / sizeof(expected[0]) + 1] = {0};

	expected2 = "-2147483648\n2147483647\n";
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	i = 0;
	for (i = 0; i < sizeof(t_cases) / sizeof(t_cases[0]); i++)
	{
		ft_putnbr_fd(t_cases[i], fd);
		ft_putchar_fd('\n', fd);
	}
	close(fd);
	fd = open(file_name, O_RDONLY);
	read(fd, buff, sizeof(expected) / sizeof(expected[0]));
	if (strncmp(buff, expected, sizeof(expected) / sizeof(expected[0])) != 0)
		return (1);
	DESTROY_TEST_FILE(fd, file_name);
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	ft_putnbr_fd(INT_MIN, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(INT_MAX, fd);
	ft_putchar_fd('\n', fd);
	close(fd);
	fd = open(file_name, O_RDONLY);
	bzero(buff, sizeof(buff));
	read(fd, buff, sizeof(buff));
	if (strncmp(buff, expected2, sizeof(buff)) != 0)
		return (2);
	DESTROY_TEST_FILE(fd, file_name);
	return (0);
}

int	test_putchar(void)
{
	char	file_name[] = TESTS_FPREFIX "putchar.txt";
	char	test_str[] = "Hello World!\n\t\012\15";
	int		fd;
	char	buff[100] = {0};
	int		bread;
	size_t	i;

	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	for (i = 0; i < strlen(test_str); i++)
		ft_putchar_fd(test_str[i], fd);
	close(fd);
	fd = open(file_name, O_RDONLY);
	bread = read(fd, buff, 100);
	if (strcmp(buff, test_str) != 0 || (size_t)bread != strlen(test_str))
		return (1);
	DESTROY_TEST_FILE(fd, file_name);
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	ft_putchar_fd('\0', fd);
	close(fd);
	fd = open(file_name, O_RDONLY);
	bread = read(fd, buff, 100);
	if (bread != 1 || buff[0] != '\0')
		return (2);
	DESTROY_TEST_FILE(fd, file_name);
	return (0);
}

int	test_min(void)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;

	a = 0;
	b = 1;
	c = -1;
	d = INT_MAX;
	e = INT_MIN;
	if (ft_min(a, b) != a)
		return (1);
	if (ft_min(b, a) != a)
		return (2);
	if (ft_min(a, c) != c)
		return (3);
	if (ft_min(c, a) != c)
		return (4);
	if (ft_min(a, d) != a)
		return (5);
	if (ft_min(d, a) != a)
		return (6);
	if (ft_min(a, e) != e)
		return (7);
	return (0);
}

int	test_max(void)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;

	a = 0;
	b = 1;
	c = -1;
	d = INT_MAX;
	e = INT_MIN;
	if (ft_max(a, b) != b)
		return (1);
	if (ft_max(b, a) != b)
		return (2);
	if (ft_max(a, c) != a)
		return (3);
	if (ft_max(c, a) != a)
		return (4);
	if (ft_max(a, d) != d)
		return (5);
	if (ft_max(d, a) != d)
		return (6);
	if (ft_max(a, e) != a)
		return (7);
	return (0);
}

int	test_atoi(void)
{
	int		t_cases[] = {0, 1, 9, 10, 99, 100, 999, 1000, 9999, 10000, -1, -9,
				-10, -99, -100, -999, -1000, -9999, -10000};
	char	*t_str[] = {"0", "1", "9", "10", "99", "100", "999", "1000", "9999",
			"10000", "-1", "-9", "-10", "-99", "-100", "-999", "-1000", "-9999",
			"-10000"};
	size_t	i;

	//  normal cases
	i = 0;
	for (i = 0; i < sizeof(t_cases) / sizeof(t_cases[0]); i++)
	{
		if (ft_atoi(t_str[i]) != t_cases[i])
			return (i + 1);
	}
	//  sign cases
	if (ft_atoi(" --99") != 99)
		return (21);
	if (ft_atoi(" -0") != 0)
		return (22);
	if (ft_atoi(" -++--1") != -1)
		return (23);
	//  error cases
	if (ft_atoi("toto") != 0)
		return (24);
	if (ft_atoi("-toto") != 0)
		return (25);
	if (ft_atoi("toto-") != 0)
		return (26);
	if (ft_atoi("a") != 0)
		return (27);
	if (ft_atoi("01234\t56789") != 1234)
		return (28);
	return (0);
}

int	test_atoi_base(void)
{
	char	*b10;
	char	*b2;
	char	*b16;
	char	*binvalid1;
	char	*binvalid2;
	char	*binvalid3;
	char	*binvalid4;
	char	*binvalid5;
	char	*binvalid6;

	b10 = "0123456789";
	b2 = "01";
	b16 = "0123456789abcdef";
	binvalid1 = "toto";
	binvalid2 = "-0123456789";
	binvalid3 = "0123456789-";
	binvalid4 = "a";
	binvalid5 = "01234\t56789";
	binvalid6 = "+0123456789";
	if (ft_atoi_base("0", b10) != 0)
		return (1);
	if (ft_atoi_base("1", b10) != 1)
		return (2);
	if (ft_atoi_base("9", b10) != 9)
		return (3);
	if (ft_atoi_base("10", b10) != 10)
		return (4);
	if (ft_atoi_base("99", b10) != 99)
		return (5);
	if (ft_atoi_base("-0", b10) != 0)
		return (6);
	if (ft_atoi_base("-1", b10) != -1)
		return (7);
	if (ft_atoi_base("-9", b10) != -9)
		return (8);
	if (ft_atoi_base("-10", b10) != -10)
		return (9);
	if (ft_atoi_base("-99", b10) != -99)
		return (10);
	if (ft_atoi_base("0", b2) != 0)
		return (11);
	if (ft_atoi_base("1", b2) != 1)
		return (12);
	if (ft_atoi_base("10", b2) != 2)
		return (13);
	if (ft_atoi_base("11", b2) != 3)
		return (14);
	if (ft_atoi_base("100", b2) != 4)
		return (15);
	if (ft_atoi_base("-0", b2) != 0)
		return (16);
	if (ft_atoi_base("-1", b2) != -1)
		return (17);
	if (ft_atoi_base("-10", b2) != -2)
		return (18);
	if (ft_atoi_base("-11", b2) != -3)
		return (19);
	if (ft_atoi_base("-100", b2) != -4)
		return (20);
	if (ft_atoi_base("0", b16) != 0)
		return (21);
	if (ft_atoi_base("1", b16) != 1)
		return (22);
	if (ft_atoi_base("9", b16) != 9)
		return (23);
	if (ft_atoi_base("a", b16) != 10)
		return (24);
	if (ft_atoi_base("f", b16) != 15)
		return (25);
	if (ft_atoi_base("10", b16) != 16)
		return (26);
	if (ft_atoi_base("99", b16) != 153)
		return (27);
	if (ft_atoi_base("-0", b16) != 0)
		return (28);
	if (ft_atoi_base("-1", b16) != -1)
		return (29);
	if (ft_atoi_base("-9", b16) != -9)
		return (30);
	if (ft_atoi_base("-a", b16) != -10)
		return (31);
	if (ft_atoi_base("-f", b16) != -15)
		return (32);
	if (ft_atoi_base("-10", b16) != -16)
		return (33);
	if (ft_atoi_base("-99", b16) != -153)
		return (34);
	// error cases
	if (ft_atoi_base("23", binvalid1) != 0)
		return (35);
	if (ft_atoi_base("23", binvalid2) != 0)
		return (36);
	if (ft_atoi_base("23", binvalid3) != 0)
		return (37);
	if (ft_atoi_base("23", binvalid4) != 0)
		return (38);
	if (ft_atoi_base("23", binvalid5) != 0)
		return (39);
	if (ft_atoi_base("23", binvalid6) != 0)
		return (40);
	// space cases
	if (ft_atoi_base(" 0", b10) != 0)
		return (41);
	if (ft_atoi_base(" 1", b10) != 1)
		return (42);
	if (ft_atoi_base(" 9", b10) != 9)
		return (43);
	if (ft_atoi_base(" 10", b10) != 10)
		return (44);
	// multiple sign cases
	if (ft_atoi_base(" --99", b10) != 99)
		return (45);
	if (ft_atoi_base(" -0", b10) != 0)
		return (46);
	if (ft_atoi_base(" -++--1", b10) != -1)
		return (47);
	return (0);
}

int	test_strtok(void)
{
	char	test[] = "path/to/file:another/path:yet/another/path";

	char lorem[] = "Lorem ipsum dolor sit amet, "
					"consectetur adipiscing elit. Sed non risus. Suspendisse";
	if (strcmp(ft_strtok(lorem, " "), "Lorem") != 0)
		return (1);
	if (strcmp(ft_strtok(NULL, " "), "ipsum") != 0)
		return (2);
	if (strcmp(ft_strtok(NULL, " "), "dolor") != 0)
		return (3);
	if (strcmp(ft_strtok(NULL, " "), "sit") != 0)
		return (4);
	if (strcmp(ft_strtok(NULL, " "), "amet,") != 0)
		return (5);
	if (strcmp(ft_strtok(NULL, " "), "consectetur") != 0)
		return (6);
	if (strcmp(ft_strtok(NULL, " "), "adipiscing") != 0)
		return (7);
	if (strcmp(ft_strtok(NULL, " "), "elit.") != 0)
		return (8);
	if (strcmp(ft_strtok(NULL, " "), "Sed") != 0)
		return (9);
	if (strcmp(ft_strtok(NULL, " "), "non") != 0)
		return (10);
	if (strcmp(ft_strtok(NULL, " "), "risus.") != 0)
		return (11);
	if (strcmp(ft_strtok(NULL, " "), "Suspendisse") != 0)
		return (12);
	if (ft_strtok(NULL, " ") != NULL)
		return (13);
	if (strcmp(ft_strtok(test, ":"), "path/to/file") != 0)
		return (14);
	if (strcmp(ft_strtok(NULL, ":/"), "another") != 0)
		return (15);
	if (strcmp(ft_strtok(NULL, ":"), "path") != 0)
		return (16);
	return (0);
}

int	test_split(void)
{
	char	*str;
	char	*str2;
	char	*str3;
	char	*str4;
	char	**res;
	char	**res2;
	char	**res3;
	char	**res4;
	size_t	i;

	str = "Hello World!";
	str2 = "Hello World!  ";
	str3 = "  Hello World!";
	str4 = "  Hello World!  ";
	res = ft_split(str, ' ');
	res2 = ft_split(str2, ' ');
	res3 = ft_split(str3, ' ');
	res4 = ft_split(str4, ' ');
	if (strcmp(res[0], "Hello") != 0)
		return (1);
	if (strcmp(res[1], "World!") != 0)
		return (2);
	if (res[2] != NULL)
		return (3);
	if (strcmp(res2[0], "Hello") != 0)
		return (4);
	if (strcmp(res2[1], "World!") != 0)
		return (5);
	if (res2[2] != NULL)
		return (6);
	if (strcmp(res3[0], "Hello") != 0)
		return (7);
	if (strcmp(res3[1], "World!") != 0)
		return (8);
	if (res3[2] != NULL)
		return (9);
	if (strcmp(res4[0], "Hello") != 0)
		return (10);
	if (strcmp(res4[1], "World!") != 0)
		return (11);
	if (res4[2] != NULL)
		return (12);
	for (i = 0; res[i] != NULL; i++)
		free(res[i]);
	free(res);
	for (i = 0; res2[i] != NULL; i++)
		free(res2[i]);
	free(res2);
	for (i = 0; res3[i] != NULL; i++)
		free(res3[i]);
	free(res3);
	for (i = 0; res4[i] != NULL; i++)
		free(res4[i]);
	free(res4);
	return (0);
}

int tests_splits(void)
{
	char	*str = "path/to/file:another/path:yet/another/path";
	char	**res;
	size_t	i;

	res = ft_splits(str, " /:");
	if (strcmp(res[0], "path") != 0)
		return (1);
	if (strcmp(res[1], "to") != 0)
		return (2);
	if (strcmp(res[2], "file") != 0)
		return (3);
	if (strcmp(res[3], "another") != 0)
		return (4);
	if (strcmp(res[4], "path") != 0)
		return (5);
	if (strcmp(res[5], "yet") != 0)
		return (6);
	if (strcmp(res[6], "another") != 0)
		return (7);
	if (strcmp(res[7], "path") != 0)
		return (8);
	if (res[8] != NULL)
		return (9);
	for (i = 0; res[i] != NULL; i++)
		free(res[i]);
	free(res);
	return (0);
}

int	test_strchr(void)
{
	char	*str;
	char	s;
	char	s2;
	char	*res;

	str = "Hello World!";
	s = 'o';
	s2 = 'z';
	res = ft_strchr(str, s);
	if (res != str + 4)
		return (1);
	res = ft_strchr(str, s2);
	if (res != NULL)
		return (2);
	res = ft_strchr(str, '\0');
	if (res != str + strlen(str))
		return (3);
	return (0);
}

int	test_strdup(void)
{
	char	*str;
	char	*res;

	str = "Hello World!";
	res = ft_strdup(str);
	if (strcmp(res, str) != 0)
		return (1);
	free(res);
	return (0);
}

int	test_striteri(void)
{
	char	str[] = "Hello World!";

	ft_striteri(str, &local_iteri);
	if (strcmp(str, "aaaaaaaaaaaa") != 0)
		return (1);
	return (0);
}

int	test_strjoin(void)
{
	char	*str;
	char	*str2;
	char	*res;

	str = "Hello World!";
	str2 = "Hello World!";
	res = ft_strjoin(str, str2);
	if (strcmp(res, "Hello World!Hello World!") != 0)
		return (1);
	free(res);
	str2 = "";
	res = ft_strjoin(str, str2);
	if (strcmp(res, "Hello World!") != 0)
		return (2);
	free(res);
	str2 = NULL;
	res = ft_strjoin(str, str2);
	if (strcmp(res, "Hello World!") != 0)
		return (3);
	free(res);
	str = "";
	str2 = "Hello World!";
	res = ft_strjoin(str, str2);
	if (strcmp(res, "Hello World!") != 0)
		return (4);
	free(res);
	str = NULL;
	res = ft_strjoin(str, str2);
	if (strcmp(res, "Hello World!") != 0)
		return (5);
	free(res);
	return (0);
}

int	test_strlcat(void)
{
	char	*str;
	char	*str2;
	char	*res;
	size_t	size;
	int		ret;

	str = "Hello";
	str2 = " World!";
	size = 15;
	res = malloc(sizeof(char) * size);
	bzero(res, size);
	ret = ft_strlcat(res, str, size);
	if (strcmp(res, "Hello") != 0 || ret != 5)
		return (1);
	ret = ft_strlcat(res, str2, size);
	if (strcmp(res, "Hello World!") != 0 || ret != 12)
		return (2);
	ret = ft_strlcat(res, "This is zod!", size);
	if (strcmp(res, "Hello World!Th") != 0 || ret != 24)
		return (3);
	free(res);
	return (0);
}

int	test_strlcpy(void)
{
	char	*str;
	char	*res;
	size_t	size;
	int		ret;

	str = "Hello World!";
	size = 15;
	res = malloc(sizeof(char) * size);
	bzero(res, size);
	ret = ft_strlcpy(res, str, size);
	if (strcmp(res, "Hello World!") != 0 || ret != 12)
		return (1);
	free(res);
	res = malloc(sizeof(char) * size);
	ret = ft_strlcpy(res, "This is zod!", size);
	if (strcmp(res, "This is zod!") != 0 || ret != 12)
		return (2);
	free(res);
	res = malloc(sizeof(char) * size);
	ret = ft_strlcpy(res, "This is too large!", size);
	if (strncmp(res, "This is too large!", size - 1) != 0
		|| ret != strlen("This is too large!"))
		return (3);
	free(res);
	return (0);
}

int	test_strlen(void)
{
	char	*str;
	char	*str2;
	char	*str3;

	str = "Hello World!";
	str2 = "";
	str3 = "Hello\0World!";
	if (ft_strlen(str) != 12)
		return (1);
	if (ft_strlen(str2) != 0)
		return (2);
	if (ft_strlen(str3) != 5)
		return (3);
	return (0);
}

int	test_strmapi(void)
{
	char	*str;
	char	*res;

	str = "Hello World!";
	res = ft_strmapi(str, &local_mapi);
	if (strcmp(res, "Ifmmp!Xpsme\"") != 0)
		return (1);
	free(res);
	return (0);
}

int	test_strcmp(void)
{
	char	*str;
	char	*str2;
	char	*str3;
	char	*str4;
	char	*str5;
	char	*str6;

	str = "none";
	str2 = "some";
	str3 = "nonethensome";
	str4 = "nonethensome";
	str5 = "!\0a";
	str6 = "!\0b";
	if (ft_strcmp(str, str2) >= 0)
		return (1);
	if (ft_strcmp(str, str3) >= 0)
		return (2);
	if (ft_strcmp(str3, str4) != 0)
		return (3);
	if (ft_strcmp(str5, str6) != 0)
		return (4);
	return (0);
}

int	test_strncmp(void)
{
	char	*str;
	char	*str2;
	char	*str3;
	char	*str4;
	char	*str5;
	char	*str6;

	str = "none";
	str2 = "some";
	str3 = "nonethensome";
	str4 = "nonethensome";
	str5 = "!\0a";
	str6 = "!\0b";
	if (ft_strncmp(str, str2, 4) >= 0)
		return (1);
	if (ft_strncmp(str, str3, 4) != 0)
		return (2);
	if (ft_strncmp(str3, str4, 4) != 0)
		return (3);
	if (ft_strncmp(str5, str6, 4) != 0)
		return (4);
	if (ft_strncmp(str5, str, 0) != 0)
		return (5);
	return (0);
}

int	test_strndup(void)
{
	char	*str;
	char	*res;

	str = "Hello World!";
	res = ft_strndup(str, 5);
	if (strcmp(res, "Hello") != 0)
		return (1);
	free(res);
	res = ft_strndup(str, 0);
	if (strcmp(res, "") != 0)
		return (2);
	free(res);
	res = ft_strndup(str, 12);
	if (strcmp(res, "Hello World!") != 0)
		return (3);
	free(res);
	res = ft_strndup(str, 15);
	if (strcmp(res, "Hello World!") != 0)
		return (4);
	free(res);
	return (0);
}

int	test_strnstr(void)
{
	char	*str;
	char	*res;

	str = "The cake is a lie !\0I'm hidden lol\n";
	res = ft_strnstr(str, "The cake is a lie !", 100);
	if (res != str)
		return (1);
	res = ft_strnstr(str, "The cake is a lie !", 20);
	if (res != str)
		return (2);
	res = ft_strnstr(str, "The cake is a lie !", 19);
	if (res == NULL)
		return (3);
	res = ft_strnstr(str, "The cake is a lie !", 0);
	if (res != NULL)
		return (4);
	res = ft_strnstr(str, "hidden", 100);
	if (res != NULL)
		return (5);
	return (0);
}

int	test_strrchr(void)
{
	char	*str;
	char	s;
	char	s2;
	char	*res;

	str = "Hello World!";
	s = 'o';
	s2 = 'z';
	res = ft_strrchr(str, s);
	if (res != str + 7)
		return (1);
	res = ft_strrchr(str, s2);
	if (res != NULL)
		return (2);
	res = ft_strrchr(str, '\0');
	if (res != str + strlen(str))
		return (3);
	return (0);
}

int	test_strtrim(void)
{
	char	*str;
	char	*str2;
	char	*str3;
	char	*str4;
	char	*res;

	str = "Hello World!";
	str2 = "  Hello World!";
	str3 = "Hello World!  ";
	str4 = "  Hello World!  ";
	res = NULL;
	res = ft_strtrim(str, " ");
	if (strcmp(res, "Hello World!") != 0)
		return (1);
	free(res);
	res = ft_strtrim(str2, " ");
	if (strcmp(res, "Hello World!") != 0)
		return (2);
	free(res);
	res = ft_strtrim(str3, " ");
	if (strcmp(res, "Hello World!") != 0)
		return (3);
	free(res);
	res = ft_strtrim(str4, " ");
	if (strcmp(res, "Hello World!") != 0)
		return (4);
	free(res);
	res = ft_strtrim(str4, " !W");
	if (strcmp(res, "Hello World") != 0)
		return (5);
	free(res);
	return (0);
}

int	test_substr(void)
{
	char	*str;
	char	*res;

	str = "Hello World!";
	res = NULL;
	res = ft_substr(str, 0, 5);
	if (strcmp(res, "Hello") != 0)
		return (1);
	free(res);
	res = ft_substr(str, 6, 6);
	if (strcmp(res, "World!") != 0)
		return (2);
	free(res);
	res = ft_substr(str, 6, 100);
	if (strcmp(res, "World!") != 0)
		return (3);
	free(res);
	res = ft_substr(str, 6, 0);
	if (strcmp(res, "") != 0)
		return (4);
	free(res);
	res = ft_substr(str, 12, 0);
	if (strcmp(res, "") != 0)
		return (5);
	free(res);
	res = ft_substr(str, 12, 100);
	if (strcmp(res, "") != 0)
		return (6);
	free(res);
	return (0);
}

int	test_str_replace(void)
{
	char	*str;
	char	*res;

	str = "Hello World!";
	// char *str2 = "Hello World! World! World!";
	res = NULL;
	res = ft_str_replace(str, "World", "Zod");
	if (strcmp(res, "Hello Zod!") != 0)
		return (1);
	free(res);
	res = ft_str_replace(str, "World", "");
	if (strcmp(res, "Hello !") != 0)
		return (2);
	free(res);
	res = ft_str_replace(str, "World", NULL);
	if (res != NULL)
		return (3);
	free(res);
	// not implemented yet
	// res = ft_str_replace(str2, "World", "Zod");
	// if (strcmp(res, "Hello Zod! Zod! Zod!") != 0)
	// 	return (4);
	// free(res);
	return (0);
}

int	test_str_replace_chr(void)
{
	char	*str;
	char	*res;

	str = ft_strdup("Hello World!");
	res = NULL;
	res = ft_str_replace_chr(str, 'o', 'a');
	if (strcmp(res, "Hella Warld!") != 0)
		return (1);
	free(res);
	str = ft_strdup("Hello World!");
	res = ft_str_replace_chr(str, '!', '?');
	if (strcmp(res, "Hello World?") != 0)
		return (2);
	free(res);
	str = ft_strdup("Hello World!");
	res = ft_str_replace_chr(str, '!', '\0');
	if (strcmp(res, "Hello World") != 0)
		return (3);
	free(res);
	str = ft_strdup("Hello World!");
	res = ft_str_replace_chr(str, 'o', '\0');
	if (strcmp(res, "Hell") != 0 || strcmp(res + 5, " W") != 0 || strcmp(res
			+ 8, "rld!") != 0)
		return (4);
	free(res);
	return (0);
}

int	test_shift_args(void)
{
	const char	*fake_args[] = (const char *[]){"test", "1", "2", "3", "4",
			NULL};
	const char	**test = fake_args;
	int			fake_argc;
	const char	*ret = NULL;

	fake_argc = 5;
	ret = ft_shift_args(&test, &fake_argc);
	if (fake_argc != 4)
		return (1);
	if (strcmp(test[0], "1") != 0)
		return (2);
	if (strcmp(test[1], "2") != 0)
		return (3);
	if (strcmp(test[2], "3") != 0)
		return (4);
	if (strcmp(test[3], "4") != 0)
		return (5);
	if (strcmp(ret, "test") != 0)
		return (6);
	ret = ft_shift_args(&test, &fake_argc);
	ret = ft_shift_args(&test, &fake_argc);
	ret = ft_shift_args(&test, &fake_argc);
	ret = ft_shift_args(&test, &fake_argc);
	ret = ft_shift_args(&test, &fake_argc);
	if (fake_argc != 0)
		return (7);
	if (ret != NULL)
		return (8);
	return (0);
}

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
	DESTROY_TEST_FILE(fd, TESTS_FPREFIX "gnl.txt");
	return (0);
}

int	str_tests(void)
{
	int collect = 0;
	t_test tests[] = {
// char sub module
		{"is_alphanum", test_is_alphanum},
		{"is_alpha", test_is_alpa},
		{"is_digit", test_is_digit},
		{"is_ascii", test_is_ascii},
		{"is_lower", test_is_lower},
		{"is_upper", test_is_upper},
		{"is_print", test_is_print},
		{"is_space", test_is_space},
		{"to_lower", test_to_lower},
		{"to_upper", test_to_upper},
// nbr sub module
		{"log", test_log},
		{"logof", test_logof},
		{"llogof", test_llogof},
		{"ullogof", test_ullogof},
		{"min", test_min},
		{"max", test_max},
// put sub module
		{"putstr", test_putstr},
		{"putendl", test_putendl},
		{"putnbr", test_putnbr},
		{"putchar", test_putchar},
// str main module
		{"itoa", test_itoa},
		{"utoa", test_utoa},
		{"itoa_base", test_itoa_base},
		{"atoi", test_atoi},
		{"atoi_base", test_atoi_base},
		{"strtok", test_strtok},
		{"split", test_split},
		{"splits", tests_splits},
		{"strchr", test_strchr},
		{"strdup", test_strdup},
		{"striteri", test_striteri},
		{"strjoin", test_strjoin},
		{"strlcat", test_strlcat},
		{"strlcpy", test_strlcpy},
		{"strlen", test_strlen},
		{"strmapi", test_strmapi},
		{"strcmp", test_strcmp},
		{"strncmp", test_strncmp},
		{"strndup", test_strndup},
		{"strnstr", test_strnstr},
		{"strrchr", test_strrchr},
		{"strtrim", test_strtrim},
		{"substr", test_substr},
		{"str_replace", test_str_replace},
		{"str_replace_chr", test_str_replace_chr},
		{"shift_args", test_shift_args},
		{"gnl", test_gnl},
		{NULL, NULL}
	};
	RUN_TEST(tests, collect);

	return (collect);
}