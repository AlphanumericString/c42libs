/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_fd_to_buff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:15:20 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/28 16:22:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests.h"

int	fd_to_buff_test(void)
{
	char *func_to_test = "fd_to_buff";
	char buff[100];
	char *ret;
	int fd;

	ft_bzero(buff, 100);
	ft_strlcat(buff, "Hello World\n\n\n\n\tv\vjkldqskjfsldfjsmldfkj\n", 100);
	fd = open_test_file(&func_to_test);
	write(fd, buff, ft_strlen(buff));
	close(fd);
	fd = open_test_file(&func_to_test);
	ret = fd_to_buff(fd);
	if (ft_strcmp(ret, buff) != 0)
		return (1);
	close(fd);
	return (0);
}
