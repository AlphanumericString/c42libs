/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:04:13 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/01 13:02:20 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ft_arena.h"
#include "ft_string.h"

void	*ft_narena_destroy(int arena_n);

int main(int argc, char *argv[])
{
	char *jc_1 = NULL;
	char *jc_2 = NULL;
	char *jc_3 = NULL;

	jc_1 = ft_narena_alloc(16, 2);
	jc_2 = ft_narena_alloc(16, 2);
	jc_3 = ft_narena_alloc(16, 2);
	ft_strlcpy(jc_1, "this\t...\n", 16);
	ft_strlcpy(jc_2, "is a\t...\n", 16);
	ft_strlcpy(jc_3, "test\t...\n", 16);
	ft_putstr_fd(jc_1, STDOUT_FILENO);
	ft_putstr_fd(jc_2, STDOUT_FILENO);
	ft_putstr_fd(jc_3, STDOUT_FILENO);
	ft_narena_free(jc_1, 2);
	ft_narena_destroy(2); // correct use
	ft_narena_destroy(2); // incorect (double free)
	ft_narena_destroy(1); // incorrect (not used)
	ft_narena_destroy(-1); // OOB - inf
	ft_narena_destroy(9999); // OOB - sup
	return EXIT_SUCCESS;
}
