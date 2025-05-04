/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:04:13 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/14 00:49:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>

#include "ft_arena.h"
#include "ft_args.h"
#include "ft_bitset_types.h"
#include "ft_char.h"
#include "ft_defs.h"
#include "ft_list.h"
#include "ft_list_types.h"
#include "ft_math.h"
#include "ft_bitset.h"
#include "ft_pair_types.h"
#include "ft_string.h"
#include "ft_map.h"
#include "ft_pair.h"

static void print_addr(const void *ptr, const char *base, int fd)
{
	char			addr[9];
	size_t			len;
	unsigned long	l_ptr;

	len = 7;
	l_ptr = (unsigned long)ptr;
	addr[8] = 0;
	ft_memset(addr, '0', sizeof(addr));
	while (len && l_ptr)
	{
		addr[len] = base[l_ptr % 16];
		l_ptr = l_ptr / 16;
		len--;
	}
	ft_putstr_fd(addr, fd);
}

static void print_hex(const char *s_ptr, const char *base, size_t size, int fd)
{
	char	str[3 * 16 + 1];
	size_t	j;

	j = 0;
	str[sizeof(str) - 1] = '\0';
	while (j < 16 && j < size)
	{
		str[j * 3] = base[s_ptr[j] / 16];
		str[j * 3 + 1] = base[s_ptr[j] % 16];
		str[j * 3 + 2] = ' ';
		j++;
	}
	while (j < 16)
		ft_memset(str + j++ * 3, ' ', 3);
	str[j * 3] = '\0';
	ft_putstr_fd(str, fd);
}

static void print_abc(const unsigned char *s_ptr, size_t size, int fd)
{
	size_t	j;
	char	str_abc[16 + 1];
	char	c;

	j = 0;
	while (j < 16 && j < size)
	{
		c = s_ptr[j];
		if (!ft_isprint(c) || ft_isspace(c))
			str_abc[j] = '.';
		else
			str_abc[j] = c;
		j++;
	}
	while (j < 16)
		str_abc[j++] = '.';
	str_abc[j] = '\0';
	ft_putstr_fd("|", fd);
	ft_putstr_fd(str_abc, fd);
	ft_putstr_fd("|", fd);
}

static void ft_printhex(const void *ptr, size_t size, int fd)
{
	const unsigned char	*s_ptr = ptr;
	const char			*base = "0123456789abcdef";
	size_t				i;

	i = 0;
	while (i < size)
	{
		print_addr((void *)i, base, fd);
		ft_putstr_fd("\t", fd);
		print_hex(ptr + i, base, size - i, fd);
		ft_putstr_fd("\t", fd);
		print_abc(ptr + i, size - i, fd);
		ft_putstr_fd("\n", fd);
		i += 16;
	}
	print_addr((void *)size, base, fd);
	ft_putstr_fd("\n", fd);
}

/// void * transform function for LRU tests
/// takes a string as void * and return a string with +1 on chars as void *
static void *transform_fn(void *data)
{
	char	*str;
	size_t	i;

	str = ft_strdup(data);
	i = 0;
	while (str[i])
	{
		str[i] += +1;
		i++;
	}
	return (str);
}

int main(int ac, char **av)
{
	size_t		i;
	void		*data;

	printf("%zu\n", sizeof(size_t));
	printf("%zu\n", sizeof(ssize_t));
	return (EXIT_SUCCESS);
}
/*
	t_bitset	*bs;

	bs = ft_bs_new(7);
	ft_bs_print_binary(bs, STDOUT_FILENO);
	ft_bs_print_hex(bs, STDOUT_FILENO);
	ft_bs_toggle_raw(bs, 0);
	ft_bs_set(bs, 4, false);
	ft_bs_set(bs, 6, false);
	ft_bs_print_binary(bs, STDOUT_FILENO);
	ft_bs_print_hex(bs, STDOUT_FILENO);
	ft_bs_print_decimal(bs, STDOUT_FILENO);
	ft_bs_print(bs, STDOUT_FILENO);

	t_bitset *bs2;
	bs2 = ft_bs_new_from_str(str, ft_strlen(str));
	ft_bs_print_decimal(bs2, STDOUT_FILENO);
	ft_bs_print_hex(bs2, STDOUT_FILENO);
*/
/*
	ft_bs_free(&bs);
	ft_bs_free(&bs2);
*/

