/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:15:14 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/29 13:51:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# define TESTS_PATH "tests/"
# define LOG_TESTS(y, x)                             \
	do                                              \
	{                                               \
		if (y != 0)                                 \
		{                                           \
			printf("%s:%s :: %d\n", __func__, #x, y); \
			return (y);                             \
		}                                           \
	} while (0);

int	tests_map(void);
int	tests_linked_list_all(void);
int	tests_doubly_linked_list_all(void);
int	tests_vector(void);

#endif /* TEST_H */
